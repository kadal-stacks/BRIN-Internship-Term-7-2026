# Howland VCCS SMD Variant 2

Folder ini menyimpan salinan desain Howland VCCS dengan beberapa file bernama mirip: <code>Howland-VCCS-TL072_SMD.kicad_sch</code>, <code>Howland-VCCS-TL072_SMD.kicad_pcb</code>, <code>Howland-VCCS-TL072_SMD_2.kicad_pro</code>, dan <code>Howland-VCCS-TL072_SMD_2.kicad_pcb</code>.

## Komponen dari schematic
| Ref. | Nilai/jenis | Footprint yang tercatat |
| --- | --- | --- |
| U1 | TL072 | **DIP-8_W7.62mm** (THT) |
| R1, R3 | 100 kΩ | SMD 0805 |
| R2, R4 | 20 kΩ | SMD 0805 |
| R5 | 100 Ω | SMD 0805 |
| R6, R7 | Belum ditentukan (“R”) | SMD 0805 |
| C1, C2 | Belum ditentukan (“C”) | SMD 0805 |
| JP1, JP2 | Solder jumper terbuka | jumper 2-pad |
| H1, H2 | Mounting hole M2.2 | mounting hole |
| J1, J2 | Header 1×3, 2.54 mm | through-hole |

<p align="center"><a href="https://www.ti.com/product/TL072"><img src="https://www.deltaset.net/Resimler/Urunler/TL072_%2CTL072CP_DIP-8_THT_-_DELTASET_ELEKTRONIK1_3054.jpg" alt="Foto asli paket IC TL072 DIP-8" width="330"></a></p><sub>Foto IC TL072 DIP-8 dari pemasok; lihat <a href="https://www.ti.com/product/TL072">datasheet resmi TI</a> untuk package/pinout. Bukan foto board Howland yang dirancang di repository.</sub>

## Fungsi
Sumber arus terkendali tegangan berbasis topologi Howland. Nilai resistor dan pencocokan rasio merupakan bagian inti feedback; kapasitor/jumper generic yang belum diberi nilai membuat BOM belum lengkap. U1 diberi footprint DIP-8 saat ini, sehingga jangan menganggap board full-SMD.


## Periksa sebelum ekspor
File .kicad_pcb yang mana yang merupakan pasangan schematic/project belum dapat dipastikan hanya dari nama. Buka project, periksa daftar net dan footprint, lakukan ERC/DRC, lalu simpan satu versi kanonis. Jangan mengekspor Gerber sebelum memastikan PCB dan schematic benar-benar sepasang.
