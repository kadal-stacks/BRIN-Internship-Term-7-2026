# ATmega16–STM32 Adapter (THT)

Varian through-hole (THT) dari adapter breakout ATmega16–STM32.

<p align="center">
  <a href="https://www.mikroe.com/atmega16"><img src="https://cdn1-shop.mikroe.com/img/product/atmega16/atmega16-large_default-12x.jpg" alt="Foto referensi ATmega16 DIP-40" width="34%"></a>
  <a href="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG"><img src="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG" alt="Foto referensi modul STM32 Blue Pill" width="34%"></a>
</p>
<sub>Foto referensi non-AI untuk mengenali komponen, bukan foto adapter hasil fabrikasi.</sub>

## Komponen yang tampak pada schematic

| Ref. / jenis | Komponen | Peran |
| --- | --- | --- |
| J1–J2 | Socket 1×20, pitch 2.54 mm | Antarmuka header socket |
| J3–J4 | Pin header 1×20, pitch 2.54 mm | Koneksi antar-sisi |
| U2 | Simbol/library Blue Pill | Referensi modul dan pin breakout STM32 |
| Power symbols | 3V3, 5V/VCC, GND, PWR_FLAG | Penamaan rail serta pemeriksaan ERC |

## Mapping pin dan catatan elektrik

Workbook [ATmega16-STM32-Mapping.xlsx] yang diberikan merupakan referensi mapping untuk adapter ATmega16–STM32. Tabel lengkap dan catatan validasinya tersedia pada [README varian SMD, bagian pin mapping](../ATMega16-STM32%20BP%20Adapter_SMD/README.md#pin-mapping-dari-workbook).

Beberapa hal yang berlaku untuk review kedua varian:

- Pastikan pin GND ATmega16 (pin 11 dan pin 31 pada pinout DIP-40) terhubung sebagaimana diperlukan.
- Workbook menandai AVCC sebagai NC, tetapi datasheet Microchip menyatakan AVCC harus dihubungkan ke VCC walaupun ADC tidak digunakan. Jangan fabrikasi sebelum titik ini ditinjau.
- Pastikan pin khusus/alternate function dan level tegangan cocok dengan board STM32 yang aktual. Adapter tidak menunjukkan level-shifter aktif.
- Varian THT mempunyai footprint mekanik berbeda dari SMD. Periksa pitch socket/header, orientasi pin 1, diameter drill, dan dimensi modul secara fisik.

## Status desain

Laporan DRC yang tersedia pada lampiran merujuk ke file **SMD**, bukan varian THT. Untuk varian SMD, report mencatat 102 warning yang semuanya terkait silkscreen (48 silk_overlap dan 54 silk_over_copper), dengan 0 unconnected pads dan 0 footprint errors. Jangan menganggap angka itu sebagai hasil DRC varian THT; jalankan ERC/DRC pada file THT sendiri setelah perubahan final.

---

[README adapter (parent)](../README.md) · [README utama repository](../../../README.md)
