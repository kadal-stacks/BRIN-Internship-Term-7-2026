# ATmega16–STM32 Breakout/Adapter

Adapter ini ditujukan untuk menyediakan breakout konektor antara pin ATmega16 dan header/board STM32 Blue Pill. Tujuan utamanya adalah merapikan pemetaan sinyal supaya jalur GPIO dan periferal dapat diakses dari satu board ke board lainnya. Adapter ini **bukan level shifter** dan tidak otomatis membuat semua fungsi ATmega16 setara secara elektrik dengan pin STM32.

<p align="center">
  <a href="https://www.mikroe.com/atmega16"><img src="https://cdn1-shop.mikroe.com/img/product/atmega16/atmega16-large_default-12x.jpg" alt="Foto referensi ATmega16 DIP-40" width="34%"></a>
  <a href="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG"><img src="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG" alt="Foto referensi STM32 Blue Pill" width="34%"></a>
</p>
<sub>Foto referensi non-AI: <a href="https://www.mikroe.com/atmega16">halaman produk ATmega16</a> dan foto Blue Pill yang tersimpan di repository. Gambar tidak merepresentasikan hasil fabrikasi adapter.</sub>

## Varian proyek

- [SMD](ATMega16-STM32%20BP%20Adapter_SMD/README.md): project, schematic, PCB layout, dan konektor 1×20; detail mapping pin dan status DRC dibahas di README varian.
- [THT](ATMega16-STM32%20BP%20Adapter_THT/README.md): versi header/socket through-hole.

## Ikhtisar mapping

Data utama diambil dari workbook **ATmega16-STM32-Mapping.xlsx**, sheet “Routing dan Sinkronisasi Fungsi Pin”. Mapping yang terdokumentasi mencakup:

- PA0–PA7 / ADC0–ADC7 ATmega16 ke PA0–PA7 STM32.
- USART: PD0/RXD → PA10/USART1_RX dan PD1/TXD → PA9/USART1_TX.
- SPI: PB4/SS → PB12/SPI2_NSS, PB5/MOSI → PB15/SPI2_MOSI, PB6/MISO → PB14/SPI2_MISO, dan PB7/SCK → PB13/SPI2_SCK.
- I²C/TWI: PC0/SCL → PB6/I2C1_SCL dan PC1/SDA → PB7/I2C1_SDA.
- GPIO/interrupt dan timer/PWM/input capture seperti yang dirinci di [tabel mapping varian SMD](ATMega16-STM32%20BP%20Adapter_SMD/README.md#pin-mapping-dari-workbook).

Workbook juga memuat catatan NC, clock dan pin khusus. Sebelum fabrikasi, ada dua hal yang perlu dibereskan dari workbook: AVCC ATmega16 ditandai NC, padahal Microchip menyatakan AVCC harus dihubungkan ke VCC walaupun ADC tidak digunakan; dan pin 28/29 PC6/PC7 muncul di tabel referensi tambahan tetapi tidak di tabel utama. Rujuk bagian [review elektrik](ATMega16-STM32%20BP%20Adapter_SMD/README.md#review-elektrik-sebelum-fabrikasi).

## Komponen dan fungsi rangkaian

Adapter tersusun terutama dari konektor/header, jalur PCB, net label, dan rail suplai. Schematic SMD memakai empat konektor 1×20 (J1–J4), label sinyal ATM16.PA/PB/PC/PD, RESET, serta penamaan rail 3V3, 5V/VCC, dan GND. Tidak terlihat IC level-shifter aktif pada schematic SMD.

Fungsi desain adalah **routing/pemetaan sinyal**, bukan konversi tegangan atau regenerasi sinyal. Level logika dari setiap pin perlu dicek terhadap board yang disambungkan.

## Status pemeriksaan desain

Untuk varian SMD, laporan DRC terlampir bertanggal **22 Oktober 2026** mencatat 102 warning dan semuanya terkait silkscreen:

| Kategori DRC | Jumlah | Makna |
| --- | ---: | --- |
| silk_overlap | 48 | Elemen silkscreen footprint U2 bertumpang tindih dengan silkscreen/referensi konektor. |
| silk_over_copper | 54 | Elemen silkscreen berpotensi terpotong solder mask karena mendekati/menimpa area pad. |
| Unconnected pads | 0 | DRC tidak melaporkan pad tidak terhubung. |
| Footprint errors | 0 | DRC tidak melaporkan footprint errors. |

ERC dinyatakan aman sesuai hasil pemeriksaan proyek. Warning DRC yang tersisa adalah masalah keterbacaan/clearance silkscreen, bukan kategori short atau unrouted pada laporan ini. Tetap rapikan silkscreen untuk produksi: pindahkan reference text, sederhanakan garis outline U2 yang melewati pad, lalu jalankan DRC ulang setelah revisi.

## Sumber teknis

- Workbook mapping yang digunakan: `ATmega16-STM32-Mapping.xlsx` (Sheet1).
- Laporan pemeriksaan PCB: `DRC.rpt`, dibuat pada 2026-10-22.
- [Datasheet ATmega16 dari Microchip](https://www.microchip.com/content/dam/mchp/documents/OTH/ProductDocuments/DataSheets/doc2466.pdf), termasuk pinout dan persyaratan AVCC.
- [Datasheet STM32F103 dari ST](https://www.st.com/resource/en/datasheet/cd00210843.pdf), untuk pengecekan alternate function dan pin debug.

---

[README utama repository](../../README.md)
