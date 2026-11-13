<p align="center">
  <a href="https://commons.wikimedia.org/wiki/File:KiCad-Logo.svg" title="KiCad logo, KiCad Developers Team">
    <img src="https://upload.wikimedia.org/wikipedia/commons/5/59/KiCad-Logo.svg" alt="KiCad logo" width="150">
  </a>
</p>
<p align="center">
  <a href="https://www.st.com/content/st_com/en/about/st-trademark-list.html" title="STM32 trademark, STMicroelectronics">
    <img src="https://www.st.com/content/dam/aboutus/trademarks/stm32new-logo.png" alt="STM32 logo" height="48">
  </a>
  &nbsp;&nbsp;&nbsp;
  <a href="https://support.arm.com/documentation/dui0552/a/introduction/about-the-cortex-m3-processor-and-core-peripherals" title="Arm Cortex-M3 processor documentation"><strong>Arm® Cortex®-M3</strong></a>
</p>
<p align="center"><sub>STM32 adalah keluarga mikrokontroler dari STMicroelectronics. Arm menyediakan arsitektur dan desain core CPU; core yang digunakan bergantung pada seri/part number STM32. Contohnya, STM32F103 memakai Arm Cortex-M3. STM32 logo adalah identitas keluarga produk, sedangkan Arm Cortex-M3 di atas adalah nama core, bukan logo arsitektur STM32.</sub></p>


# ATmega16–STM32 Adapter (SMD)

Varian SMD dari adapter breakout ATmega16–STM32. README ini merangkum mapping dari workbook, file manufaktur yang sudah di-commit, dan dimensi area board yang dihitung dari outline PCB.

## Preview board dan luas area

![Adapter SMD board area](Adapter%20PCB%20Area.png)

| Parameter | Nilai |
| --- | ---: |
| Lebar bounding outline | 25.40 mm |
| Tinggi bounding outline | 57.15 mm |
| Radius sudut | 1.00 mm |
| Luas bounding rectangle | 1,451.61 mm² |
| Koreksi empat sudut membulat | 0.86 mm² |
| **Luas bidang PCB aktual** | **1,450.75 mm²** |
| **Konversi** | **14.5075 cm²** |

Perhitungan memakai geometri rounded rectangle dari `Edge.Cuts` pada file PCB/Gerber: `A = W × H − (4 − π)r²`. Nilai area tidak memasukkan area luar board atau clearance manufaktur.

## Fungsi board dan komponen

Board ini merutekan sinyal antar-header ATmega16 dan sisi konektor STM32 Blue Pill. Schematic SMD menunjukkan:

| Ref. | Komponen | Fungsi |
| --- | --- | --- |
| J1, J2 | Socket 1×20, pitch 2.54 mm | Konektor socket pada salah satu sisi antarmuka |
| J3, J4 | Pin header 1×20, pitch 2.54 mm | Konektor header pada sisi lainnya |
| Net labels | ATM16.PA/PB/PC/PD, RESET, dan label periferal | Memberi identitas jalur sinyal |
| Power symbols | 3V3, 5V/VCC, GND, PWR_FLAG | Penamaan rail dan pemeriksaan ERC |

Tidak ada IC level-shifter aktif yang terlihat pada schematic ini. Board adalah adapter routing, bukan rangkaian pengubah level. Verifikasi toleransi setiap pin STM32 terhadap sinyal ATmega16 sebelum koneksi langsung.

## Pin mapping dari workbook

Tabel berikut mempertahankan pemetaan yang dicatat dalam workbook **ATmega16-STM32-Mapping.xlsx**, sheet “Routing dan Sinkronisasi Fungsi Pin”. Tujuan pin dan alternate function tetap harus divalidasi terhadap MCU/board aktual dan firmware yang digunakan.

| Pin ATmega16 (DIP-40) | Sinyal/fungsi ATmega16 | Tujuan STM32 | Fungsi STM32 / catatan |
| ---: | --- | --- | --- |
| 40–33 | PA0–PA7 / ADC0–ADC7 | PA0–PA7 | Input analog |
| 14 | PD0 / RXD | PA10 | USART1_RX |
| 15 | PD1 / TXD | PA9 | USART1_TX |
| 5 | PB4 / SS | PB12 | SPI2_NSS, chip select |
| 6 | PB5 / MOSI | PB15 | SPI2_MOSI |
| 7 | PB6 / MISO | PB14 | SPI2_MISO |
| 8 | PB7 / SCK | PB13 | SPI2_SCK |
| 22 | PC0 / SCL | PB6 | I2C1_SCL |
| 23 | PC1 / SDA | PB7 | I2C1_SDA |
| 16 | PD2 / INT0 | PB8 | GPIO + EXTI |
| 17 | PD3 / INT1 | PB9 | GPIO + EXTI |
| 18 | PD4 / OC1B | PA8 | TIM1_CH1 |
| 19 | PD5 / OC1A | PB0 | TIM3_CH3 |
| 20 | PD6 / ICP1 | PB1 | TIM3_CH4 |
| 21 | PD7 / OC2 | PB4 | TIM3_CH1 |
| 1 | PB0 / XCK-T0 | PB10 | TIM2_CH3 menurut workbook |
| 2 | PB1 / T1 | PA14 (tertulis di workbook) | **Perlu koreksi:** PA14 adalah JTCK/SWCLK pada STM32F103; jangan anggap sebagai TIM1_ETR. Verifikasi pin timer yang benar sebelum memakai fungsi ini. |
| 3 | PB2 / INT2-AIN0 | PB2 | GPIO + EXTI2; workbook mencatat cek BOOT1 strap |
| 4 | PB3 / OC0-AIN1 | PB3 | TIM2_CH2; workbook mencatat perlu remapping |
| 9 | RESET | RESET | Hardware reset |
| 10 | VCC | 5V+ | Sumber daya menurut workbook; verifikasi rancangan power aktual |
| 11 | GND | GND | Ground |
| 12 | XTAL2 | NC | Gunakan clock onboard Blue Pill menurut workbook |
| 13 | XTAL1 | NC | Gunakan clock onboard Blue Pill menurut workbook |
| 30 | AVCC | NC (tertulis di workbook) | **Perlu review:** datasheet ATmega16 mensyaratkan AVCC terhubung ke VCC, meskipun ADC tidak digunakan |
| 32 | AREF | NC | Tidak diberi pin AREF terpisah pada tabel sisi STM32 |
| 24 | PC2 / TCK | NC | Workbook mencatat sebagai pin khusus/debug |
| 25 | PC3 / TMS | NC | Workbook mencatat sebagai pin khusus/debug |
| 26 | PC4 / TDO | NC | JTAG AVR / GPIO sesuai konfigurasi |
| 27 | PC5 / TDI | NC | Periksa label/fungsi terhadap datasheet |
| 28 | PC6 / TOSC1 | PC14 / OSC32_IN | Muncul pada tabel referensi tambahan, bukan tabel routing utama |
| 29 | PC7 / TOSC2 | PC15 / OSC32_OUT | Muncul pada tabel referensi tambahan, bukan tabel routing utama |
| 31 | GND | GND | Pin GND kedua pada pinout ATmega16 DIP-40 |

### Catatan review elektrik

1. **AVCC:** workbook menandai AVCC sebagai NC. Datasheet Microchip menyatakan AVCC harus dihubungkan ke VCC walaupun ADC tidak digunakan; bila ADC dipakai, ikuti rekomendasi filter yang sesuai. Periksa net PCB sebelum fabrikasi.
2. **PA14:** workbook menuliskan PB1/T1 → PA14/TIM1_ETR. PA14 adalah JTCK/SWCLK pada STM32F103; mapping alternate function tersebut perlu ditinjau dan dikoreksi.
3. **GND pin 31:** pastikan kedua pin GND ATmega16 (pin 11 dan 31) ditangani pada koneksi board.
4. **Level tegangan:** jangan anggap semua input STM32 toleran terhadap 5 V. Schematic tidak memperlihatkan level-shifter aktif.
5. **Pin khusus:** cek BOOT1/PB2, remapping TIM2/PB3, dan konflik pin debug sebelum menetapkan firmware.

Referensi: [datasheet ATmega16 Microchip](https://www.microchip.com/content/dam/mchp/documents/OTH/ProductDocuments/DataSheets/doc2466.pdf), [datasheet STM32F103 ST](https://www.st.com/resource/en/datasheet/cd00210843.pdf).

## Paket Gerber dan drill

**Status: Gerber dan drill tersedia.**

Arsip ZIP di repository bernama **`ATMega16-STM32 BP Adapter_SMD_Geber.zip`** (ejaan “Geber” mengikuti nama file yang sudah ada di GitHub).

[Unduh arsip Gerber](ATMega16-STM32%20BP%20Adapter_SMD_Geber.zip)

Layer individual yang tersedia:

| Layer / file | Isi |
| --- | --- |
| [F_Cu](ATMega16-STM32%20BP%20Adapter_SMD-F_Cu.gbr) | Front copper |
| [B_Cu](ATMega16-STM32%20BP%20Adapter_SMD-B_Cu.gbr) | Back copper |
| [F_Mask](ATMega16-STM32%20BP%20Adapter_SMD-F_Mask.gbr), [B_Mask](ATMega16-STM32%20BP%20Adapter_SMD-B_Mask.gbr) | Solder mask |
| [F_Paste](ATMega16-STM32%20BP%20Adapter_SMD-F_Paste.gbr), [B_Paste](ATMega16-STM32%20BP%20Adapter_SMD-B_Paste.gbr) | Paste |
| [F_Silkscreen](ATMega16-STM32%20BP%20Adapter_SMD-F_Silkscreen.gbr), [B_Silkscreen](ATMega16-STM32%20BP%20Adapter_SMD-B_Silkscreen.gbr) | Silkscreen |
| [Edge_Cuts](ATMega16-STM32%20BP%20Adapter_SMD-Edge_Cuts.gbr) | Board outline / profile |
| [PTH drill](ATMega16-STM32%20BP%20Adapter_SMD-PTH.drl), [NPTH drill](ATMega16-STM32%20BP%20Adapter_SMD-NPTH.drl) | Data pengeboran |
| [Job file](ATMega16-STM32%20BP%20Adapter_SMD-job.gbrjob) | Metadata job Gerber |

Gerber individual dihasilkan dengan KiCad 10.0.5. Cocokkan file dari satu paket/revisi yang sama ketika dikirim ke manufaktur.

## Status pemeriksaan PCB

Laporan DRC yang diberikan sebelumnya mencatat 102 warning yang seluruhnya berhubungan dengan silkscreen: 48 `silk_overlap` dan 54 `silk_over_copper`, dengan 0 unconnected pads dan 0 footprint errors. ERC dinyatakan aman berdasarkan konfirmasi pemilik desain.

**Catatan versi:** laporan tersebut berasal dari pemeriksaan sebelumnya (22 Oktober 2026), sedangkan PCB dan Gerber yang sekarang ada di repository diperbarui pada 12 November 2026. Karena itu, angka warning lama tidak boleh dianggap sebagai hasil DRC untuk revisi Gerber terbaru. Jalankan ERC/DRC ulang pada revisi PCB yang akan diproduksi; isu silkscreen lama tetap relevan sebagai item yang perlu dicek, tetapi statusnya belum terkonfirmasi untuk revisi terbaru.

## File project

- `ATMega16-STM32 BP Adapter_SMD.kicad_pro`: project.
- `ATMega16-STM32 BP Adapter_SMD.kicad_sch`: schematic/net mapping.
- `ATMega16-STM32 BP Adapter_SMD.kicad_pcb`: PCB layout.
- `ATMega16-STM32 BP Adapter_SMD.csv`: data pendamping.
- `fp-lib-table`: konfigurasi footprint library.

---

[README adapter (parent)](../README.md) · [README KiCad](../../README.md)
