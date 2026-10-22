# ATmega16–STM32 Adapter (SMD)

Varian SMD dari adapter breakout ATmega16–STM32. Referensi mapping di bawah diekstrak dari workbook **ATmega16-STM32-Mapping.xlsx**, kemudian dibaca bersama schematic PCB SMD dan laporan DRC yang diberikan.

<p align="center">
  <a href="https://www.mikroe.com/atmega16"><img src="https://cdn1-shop.mikroe.com/img/product/atmega16/atmega16-large_default-12x.jpg" alt="Foto referensi ATmega16 DIP-40" width="34%"></a>
  <a href="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG"><img src="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG" alt="Foto referensi modul STM32 Blue Pill" width="34%"></a>
</p>
<sub>Foto referensi non-AI dari <a href="https://www.mikroe.com/atmega16">halaman produk ATmega16</a> dan aset foto Blue Pill di repository; bukan foto PCB adapter hasil fabrikasi.</sub>

## Fungsi board

Board ini merutekan sinyal antar-header ATmega16 dan sisi konektor STM32 Blue Pill. Pada schematic, komponen utama yang terlihat adalah empat konektor 1×20 (J1–J4), label net ATM16.PA/PB/PC/PD, RESET, serta rail yang diberi nama 3V3, 5V/VCC dan GND. Schematic tidak menunjukkan IC level shifter aktif.

Karena itu, fungsi board adalah **routing/breakout**, bukan penyesuaian level tegangan. Kesesuaian tegangan I/O tetap harus diperiksa secara terpisah.

## Pin mapping dari workbook

Tabel berikut mempertahankan pemetaan dan catatan utama dari workbook. Pin STM32 ditulis sebagai target pin/peripheral, bukan jaminan bahwa semua alternate function dapat dipakai bersamaan tanpa konfigurasi firmware.

| Pin ATmega16 (DIP-40) | Sinyal/fungsi ATmega16 | Tujuan STM32 | Fungsi STM32 / catatan dalam workbook |
| ---: | --- | --- | --- |
| 40–33 | PA0–PA7 / ADC0–ADC7 | PA0–PA7 | Input analog |
| 14 | PD0 / RXD | PA10 | USART1_RX |
| 15 | PD1 / TXD | PA9 | USART1_TX |
| 5 | PB4 / SS | PB12 | SPI2_NSS, chip select |
| 6 | PB5 / MOSI | PB15 | SPI2_MOSI, data keluar |
| 7 | PB6 / MISO | PB14 | SPI2_MISO, data masuk |
| 8 | PB7 / SCK | PB13 | SPI2_SCK, clock |
| 22 | PC0 / SCL | PB6 | I2C1_SCL, clock I²C |
| 23 | PC1 / SDA | PB7 | I2C1_SDA, data I²C |
| 16 | PD2 / INT0 | PB8 | GPIO + EXTI |
| 17 | PD3 / INT1 | PB9 | GPIO + EXTI |
| 18 | PD4 / OC1B | PA8 | TIM1_CH1, contoh output timer/PWM |
| 19 | PD5 / OC1A | PB0 | TIM3_CH3, contoh output timer/PWM |
| 20 | PD6 / ICP1 | PB1 | TIM3_CH4, contoh input capture |
| 21 | PD7 / OC2 | PB4 | TIM3_CH1, fungsi timer menurut workbook |
| 1 | PB0 / XCK-T0 | PB10 | TIM2_CH3, input pencacah timer eksternal |
| 2 | PB1 / T1 | PA14 (tertulis di workbook) | **Mapping perlu dikoreksi/diverifikasi:** PA14 pada STM32F103 adalah JTCK/SWCLK; jangan anggap PA14 sebagai TIM1_ETR. Datasheet keluarga ini menempatkan TIM1_ETR pada PA12 untuk varian yang relevan. |
| 3 | PB2 / INT2-AIN0 | PB2 | GPIO + EXTI2; workbook menyarankan cek BOOT1 strap |
| 4 | PB3 / OC0-AIN1 | PB3 | TIM2_CH2; workbook mencatat perlu TIM2 remapping |
| 9 | RESET | RESET | Hardware reset |
| 10 | VCC | 5V+ | Sumber daya menurut workbook |
| 11 | GND | GND | Ground |
| 12 | XTAL2 | NC | Gunakan clock onboard Blue Pill |
| 13 | XTAL1 | NC | Gunakan clock onboard Blue Pill |
| 30 | AVCC | NC (seperti ditulis di workbook) | **Perlu review; lihat catatan elektrik di bawah** |
| 32 | AREF | NC | Workbook mencatat tidak ada pin AREF terpisah pada sisi STM32 |
| 24 | PC2 / TCK | NC | Workbook: reserve STM32 SWD |
| 25 | PC3 / TMS | NC | Workbook: reserve STM32 SWD |
| 26 | PC4 / TDO | NC | AVR JTAG saja, kecuali digunakan sebagai GPIO aplikasi |
| 27 | PC5 / TDI | NC | Workbook memakai label TD1; periksa nama fungsi/pin terhadap datasheet |
| 28 | PC6 / TOSC1 | PC14 / OSC32_IN | Ada pada tabel referensi tambahan workbook, tidak tercantum di tabel routing utama |
| 29 | PC7 / TOSC2 | PC15 / OSC32_OUT | Ada pada tabel referensi tambahan workbook, tidak tercantum di tabel routing utama |
| 31 | GND | GND | Pin GND kedua pada pinout ATmega16; tidak diberi nomor tersendiri di tabel routing utama |

### Tabel referensi tambahan di sisi kanan workbook

Workbook juga menunjukkan kelompok pasangan berikut untuk pengecekan pinout/posisi:

| ATmega16 | STM32 |
| --- | --- |
| PA0 (ADC0) – PA7 (ADC7) | PA0 (ADC0) – PA7 (ADC7), satu per satu |
| AREF | NC |
| GND | GND |
| AVCC | NC (seperti tercantum di workbook; jangan diterapkan sebelum review datasheet) |
| PC7 (TOSC2) | PC15 (OSC32_OUT) |
| PC6 (TOSC1) | PC14 (OSC32_IN) |
| PC5 (TD1) | NC |
| PC4 (TD0) | NC |
| PC3 (TMS) | NC |
| PC2 (TCK) | NC |
| PC1 (SDA) | PB7 (I2C1_SDA) |
| PC0 (SCL) | PB6 (I2C1_SCL) |
| PD7 (OC2) | PB4 (TIM3_CH1) |

Tabel tambahan ini sengaja dipisahkan dari tabel routing utama karena workbook tidak menggabungkan semua barisnya menjadi satu daftar konsisten. Khusus PC6/PC7, pastikan koneksi pada schematic/PCB final memang sesuai keputusan desain.

## Review elektrik sebelum fabrikasi

1. **AVCC ATmega16 jangan dibiarkan NC tanpa peninjauan.** Workbook menulis pin 30 AVCC → NC, tetapi datasheet Microchip menyatakan AVCC adalah catu untuk Port A dan ADC dan harus dihubungkan secara eksternal ke VCC walaupun ADC tidak digunakan. Jika ADC digunakan, datasheet menyarankan koneksi ke VCC melalui low-pass filter. Periksa dan koreksi mapping/net PCB jika memang belum tersambung. [Sumber resmi Microchip](https://onlinedocs.microchip.com/oxy/GUID-74F8229E-4C43-4FA0-BE7D-1AA303C6F8A4-en-US-6/GUID-06BED1CC-0D2D-41F7-B7B9-66FC2466E2C5.html).
2. **Koreksi mapping PA14/TIM1_ETR sebelum fabrikasi.** Workbook memetakan PB1/T1 ke PA14 dan memberi keterangan TIM1_ETR. Namun datasheet STM32F103 menunjukkan PA14 sebagai JTCK/SWCLK dan tidak mencantumkan TIM1_ETR sebagai alternate function PA14; pada varian terkait, TIM1_ETR tersedia pada PA12. Karena itu, mapping di baris workbook tersebut harus diperlakukan sebagai usulan yang belum benar, lalu tentukan pin target dan perbarui schematic/PCB. [Datasheet resmi ST STM32F103x4/x6](https://www.st.com/resource/en/datasheet/stm32f103t4.pdf) dan [datasheet performa menengah](https://www.st.com/resource/en/datasheet/cd00210843.pdf).
3. **Periksa pin 31 GND.** Pinout ATmega16 DIP-40 memuat GND pada pin 11 dan 31, sedangkan tabel routing utama hanya menyebut pin 11. Pastikan kedua pin GND yang dibutuhkan benar-benar terhubung ke ground pada implementasi adapter. [Datasheet ATmega16](https://www.microchip.com/content/dam/mchp/documents/OTH/ProductDocuments/DataSheets/doc2466.pdf).
4. **Level tegangan:** net yang diberi nama 5V+ tidak membuktikan semua sinyal 5 V aman masuk ke STM32. Pastikan toleransi input setiap pin, arah sinyal, serta cara mencatu kedua board. Schematic tidak menunjukkan level-shifter aktif.
5. **Pin khusus dan alternate function:** cek BOOT1 strap pada PB2, konfigurasi/remap TIM2 pada PB3, dan kebutuhan debug pada pin yang mempunyai fungsi ganda sebelum firmware dibuat.

## Status ERC/DRC

ERC dinyatakan aman sesuai hasil pemeriksaan yang diberikan. Laporan DRC untuk file PCB ini dibuat pada **22 Oktober 2026 15:27:58** dan hanya mencatat warning silkscreen:

| Kategori DRC | Jumlah | Rincian |
| --- | ---: | --- |
| silk_overlap | 48 | Segmen/field silkscreen U2 saling tumpang tindih dengan referensi/segmen silkscreen J1/J2. |
| silk_over_copper | 54 | Silkscreen U2 masuk ke area pad atau solder-mask clearance sehingga hasil cetak dapat terpotong. |
| Total warning yang dilaporkan | 102 | Seluruh warning pada report masuk dua kategori silkscreen di atas. |
| Unconnected pads | 0 | Tidak ada pad unconnected yang dilaporkan DRC. |
| Footprint errors | 0 | Tidak ada footprint error yang dilaporkan DRC. |

Warning tersebut adalah masalah grafis/fabrikasi silkscreen, bukan laporan short atau unrouted net. Untuk hasil produksi yang lebih rapi, pindahkan atau kecilkan reference J1/J2 dan sederhanakan garis/teks silkscreen footprint U2 yang melintas dekat pad. Jalankan DRC lagi setelah perubahan. Tidak ada file ERC terpisah di lampiran, jadi status ERC di atas mengikuti konfirmasi pemilik desain.

## File project

- <code>ATMega16-STM32 BP Adapter_SMD.kicad_pro</code>: project KiCad.
- <code>ATMega16-STM32 BP Adapter_SMD.kicad_sch</code>: schematic dan net mapping.
- <code>ATMega16-STM32 BP Adapter_SMD.kicad_pcb</code>: layout PCB.
- <code>ATMega16-STM32 BP Adapter_SMD.csv</code>: data pendamping; periksa kolom dan konsistensinya.
- <code>fp-lib-table</code>: konfigurasi footprint library.

## Cara melanjutkan

Buka file project di KiCad, periksa mapping pada tabel di atas terhadap net labels dan pad PCB, jalankan Update PCB from Schematic bila ada perubahan, lalu ERC/DRC. Sebelum fabrikasi, cek pin 1, orientasi konektor, footprint, dimensi mekanik, rail suplai, dan warning silkscreen.

---

[README adapter (parent)](../README.md) · [README utama repository](../../../README.md)
