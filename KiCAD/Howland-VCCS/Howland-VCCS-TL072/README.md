# Howland VCCS with TL072

Varian project KiCad dengan resistor through-hole dan TL072 DIP-8.

## BOM / komponen yang tertera
| Ref. | Komponen | Nilai/tipe |
| --- | --- | --- |
| U1 | Dual op-amp TL072 | DIP-8 |
| R1–R4 | Resistor | 100 kΩ, 4 buah |
| R5 | Resistor | 150 Ω |
| RV1 | Potensiometer trimmer | 1 kΩ |
| J1–J2 | Header 1×3 | pitch 2.54 mm |
| Power | VCC, VEE, GND | sesuaikan supply dengan datasheet |

<p align="center"><a href="https://www.ti.com/product/TL072"><img src="https://www.deltaset.net/Resimler/Urunler/TL072_%2CTL072CP_DIP-8_THT_-_DELTASET_ELEKTRONIK1_3054.jpg" alt="Foto asli paket IC TL072 DIP-8" width="330"></a></p><sub>Foto IC TL072 DIP-8 dari pemasok; lihat <a href="https://www.ti.com/product/TL072">datasheet resmi TI</a> untuk package/pinout. Bukan foto board Howland yang dirancang di repository.</sub>

## Fungsi rangkaian
Topologi Howland VCCS memakai op-amp dan rasio resistor untuk menghasilkan arus keluaran yang dikendalikan sinyal masukan, selama batas compliance voltage dan rentang kerja op-amp terpenuhi. RV1 menyediakan penyetelan. Pastikan resistor yang membentuk rasio memiliki toleransi/matching yang sesuai; catu daya TL072 dan beban harus divalidasi.

## File project
- <code>Howland-VCCS-TL072.kicad_pro</code>: project KiCad.
- <code>Howland-VCCS-TL072.kicad_sch</code>: schematic.
- <code>Howland-VCCS-TL072.kicad_pcb</code>: PCB layout.

## Checklist sebelum dibuat
Jalankan ERC/DRC, periksa pin TL072, nilai resistor, pin konektor dengan label <code>Id+</code>, <code>Id-</code> dan <code>Out</code>, serta rail VCC/VEE/GND. Jangan memakai schematic saja sebagai bukti rangkaian sudah stabil atau akurat. Cocokkan kemampuan tegangan output/input op-amp dengan beban aktual.
