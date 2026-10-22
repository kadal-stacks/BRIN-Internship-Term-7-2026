# ATmega16–STM32 Adapter (THT)

Varian through-hole (THT) adapter ATmega16–STM32.

<p align="center">
  <a href="https://www.mikroe.com/atmega16"><img src="https://cdn1-shop.mikroe.com/img/product/atmega16/atmega16-large_default-12x.jpg" alt="ATmega16 DIP-40" width="35%"></a>
  <a href="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG"><img src="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG" alt="STM32 Blue Pill" width="35%"></a>
</p>
<sub>Foto komponen dari sumber produk/asset repository, bukan foto board adapter yang sudah dirakit.</sub>

## Komponen yang tampak pada schematic

| Ref. / jenis | Komponen | Peran |
| --- | --- | --- |
| J1–J2 | Socket 1×20, pitch 2.54 mm | Header socket untuk antarmuka board |
| J3–J4 | Pin header 1×20, pitch 2.54 mm | Header koneksi antar-sisi |
| U2 | Simbol/library footprint Blue Pill | Referensi mekanik dan pin breakout modul STM32 |
| Power symbols | 3V3, 5V/VCC, GND, PWR_FLAG | Penamaan rail dan pemeriksaan ERC |

## Fungsi

Varian ini merapikan koneksi antar header ATmega16 dan modul/board STM32 melalui jalur PCB. Bukan rangkaian konversi level tegangan: schematic yang ada tidak menunjukkan level shifter aktif. Verifikasi net label, pin number, arah pin 1, serta kemampuan tegangan input tiap pin STM32 sebelum dirakit.

Buka file <code>ATMega16-STM32 BP Adapter_THT.kicad_pro</code>, jalankan ERC/DRC, dan cek footprint THT, diameter drill, annular ring, pitch, serta outline board. Belum ada bukti fabrikasi atau uji fungsi hardware yang tercatat di folder ini.
