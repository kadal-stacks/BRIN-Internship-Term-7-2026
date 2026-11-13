# KiCad Projects

Folder ini menampung schematic, PCB layout, library komponen, dan paket manufaktur dari proyek instrumentasi selama magang.

## Proyek

| Proyek | Fungsi | Status file manufaktur | Area outline PCB |
| --- | --- | --- | ---: |
| [ATmega16–STM32 Adapter (SMD)](ATMega16-STM32%20BP%20Adapter/ATMega16-STM32%20BP%20Adapter_SMD/README.md) | Breakout dan routing pin ATmega16 ke header STM32 | Gerber + drill tersedia | **1,450.75 mm² / 14.5075 cm²** |
| [Howland VCCS TL072 (THT)](Howland-VCCS/Howland-VCCS-TL072/README.md) | Voltage-controlled current source berbasis TL072 | Gerber + drill tersedia | **3,506.24 mm² / 35.0624 cm²** |
| [Howland VCCS TL072 (SMD/hybrid)](Howland-VCCS/Howland-VCCS-TL072_SMD/Howland-VCCS-TL072_SMD/README.md) | Varian Howland dengan resistor SMD dan IC/op-amp THT | Gerber + drill tersedia | **618.85 mm² / 6.1885 cm²** |
| [Impedance Meter Main Board](Impedance-meter2D_Main%20Board/README.md) | Workspace main board impedance meter | File manufaktur belum tersedia di folder | Belum dihitung |
| [Part Libraries](Part%20Lib/README.md) | Symbol, footprint, dan model 3D | Library | — |

### Area board yang sudah dihitung

Dimensi diambil dari geometri `Edge.Cuts` pada file PCB dan dicocokkan dengan layer Gerber profile. Ketiga outline berbentuk persegi panjang dengan empat sudut membulat. Area dihitung sebagai:

`A = (W × H) − (4 − π)r²`

dengan `W` dan `H` sebagai ukuran bounding rectangle dan `r` sebagai radius sudut. Nilai ini adalah luas bidang outline PCB, bukan luas komponen atau bounding box tanpa koreksi sudut.

## Workflow manufaktur KiCad

1. Buka file `.kicad_pro` dari folder proyek.
2. Validasi schematic, footprint, nomor pad, konektor, dan net.
3. Jalankan ERC untuk schematic dan DRC untuk PCB.
4. Plot layer Gerber yang diperlukan dan generate file drill PTH/NPTH.
5. Periksa file `Edge_Cuts.gbr`, `*.gbrjob`, dan arsip ZIP sebelum dikirim ke manufaktur.

Paket Gerber yang tersedia ditautkan dari README masing-masing proyek. Jangan menggunakan file dari folder atau revisi berbeda sebagai satu paket produksi.
