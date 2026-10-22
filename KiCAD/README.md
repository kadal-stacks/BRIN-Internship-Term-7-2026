# KiCad Projects

Folder ini mengelompokkan desain rangkaian, schematic, PCB layout, dan library komponen yang dipakai selama magang.

<p align="center">
  <a href="https://www.mikroe.com/atmega16"><img src="https://cdn1-shop.mikroe.com/img/product/atmega16/atmega16-large_default-12x.jpg" alt="ATmega16 DIP-40" width="28%"></a>
  <a href="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG"><img src="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG" alt="STM32 Blue Pill" width="28%"></a>
  <a href="https://www.ti.com/product/TL072"><img src="https://www.deltaset.net/Resimler/Urunler/TL072_%2CTL072CP_DIP-8_THT_-_DELTASET_ELEKTRONIK1_3054.jpg" alt="TL072 DIP-8" width="28%"></a>
</p>
<sub>Foto komponen referensi dari vendor dan aset foto lokal repository, bukan foto hasil fabrikasi proyek.</sub>

## Proyek

| Proyek | Fungsi / isi |
| --- | --- |
| [ATMega16-STM32 BP Adapter](ATMega16-STM32%20BP%20Adapter/README.md) | Adapter breakout yang merapikan pemetaan sinyal ATmega16 ke header/board STM32; ada varian SMD dan THT. |
| [Howland-VCCS](Howland-VCCS/README.md) | Sumber arus terkendali tegangan menggunakan op-amp TL072 dan jaringan resistor. |
| [Impedance-meter2D_Main Board](Impedance-meter2D_Main%20Board/README.md) | Workspace main board impedance meter; dokumentasi fungsi/BOM menunggu schematic/PCB tersimpan. |
| [Part Lib](Part%20Lib/README.md) | Library simbol, footprint, dan model 3D, termasuk STM32 Blue Pill/Black Pill. |

## Workflow KiCad

1. Buka project dengan file .kicad_pro.
2. Cocokkan simbol, nomor pin, footprint, dan datasheet komponen.
3. Jalankan ERC pada schematic dan DRC pada PCB.
4. Periksa outline mekanik, konektor, clearance, drill, dan hasil ekspor Gerber sebelum fabrikasi.

Foto eksternal dalam README proyek adalah referensi bentuk komponen. Gunakan file .kicad_sch/.kicad_pcb sebagai sumber desain sebenarnya. 
