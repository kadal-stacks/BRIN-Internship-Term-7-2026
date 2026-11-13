# Howland Voltage-Controlled Current Source (VCCS)

Folder ini berisi dua varian manufaktur aktif dari Howland current pump berbasis op-amp TL072, serta workspace buffer yang masih terpisah.

Topologi Howland menggunakan op-amp dan jaringan resistor umpan balik untuk mengubah tegangan kendali menjadi arus pada beban. Kinerja bergantung pada rasio/matching resistor, supply op-amp, rentang output, beban, serta compliance voltage.

## Varian dengan paket Gerber

| Varian | Folder proyek | Area board | Paket |
| --- | --- | ---: | --- |
| THT | [Howland-VCCS-TL072](Howland-VCCS-TL072/README.md) | **3,506.24 mm² / 35.0624 cm²** | [Gerber ZIP](Howland-VCCS-TL072/Howland-VCCS-TL072-Gerber.zip) |
| SMD/hybrid | [Howland-VCCS-TL072_SMD](Howland-VCCS-TL072_SMD/Howland-VCCS-TL072_SMD/README.md) | **618.85 mm² / 6.1885 cm²** | [Gerber ZIP](Howland-VCCS-TL072_SMD/Howland-VCCS-TL072_SMD/Howland-VCCS-TL072-SMD-Gerber.zip) |

## Ringkasan komponen schematic terbaru

### THT

| Komponen | Jumlah / nilai |
| --- | ---: |
| U1 TL072, DIP-8 | 1 |
| R1–R4 | 100 kΩ, 4 buah |
| R5 | 150 Ω |
| RV1 | 1 kΩ, trimmer THT |
| J1–J2 | Header 1×3 |
| H1–H4 | Mounting hole M2.2 |

### SMD/hybrid

| Komponen | Jumlah / nilai |
| --- | ---: |
| U1 TL072, DIP-8 (THT) | 1 |
| R1–R4, SMD 0805 | 100 kΩ, 4 buah |
| R5, SMD 0805 | 150 Ω |
| RV1 | 1 kΩ, trimmer THT |
| J4 | Header 1×6 |
| H1–H2 | Mounting hole M2.2 |

Varian SMD adalah hybrid, bukan full-SMD: schematic terbaru masih menetapkan TL072 footprint DIP-8 dan trimmer THT. Rujuk README proyek untuk rincian layer Gerber, area, dan gambar board.

## Workspace lain

Folder [VCCS 2 Buffer](VCCS%202%20Buffer/README.md) merupakan workspace terpisah. Paket Gerber/board area belum tersedia untuk proyek tersebut pada tree repository saat ini.
