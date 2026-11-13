# Howland VCCS with TL072 (THT)

Varian through-hole dari rangkaian Howland VCCS. Schematic terbaru menampilkan TL072 DIP-8, resistor THT, trimmer, konektor 1×3, dan empat mounting hole.

## Komponen dan fungsi

| Ref. | Komponen | Nilai / footprint |
| --- | --- | --- |
| U1 | Dual op-amp TL072 | DIP-8 |
| R1–R4 | Resistor THT | 100 kΩ, 4 buah |
| R5 | Resistor THT | 150 Ω |
| RV1 | Potensiometer trimmer | 1 kΩ, Bourns 3296W vertical |
| J1–J2 | Pin header 1×3 | Pitch 2.54 mm |
| H1–H4 | Mounting hole | M2.2 / M2 |
| Power | VCC, VEE, GND | Rail catu sesuai desain |

Net label eksternal pada schematic mencakup `Id+`, `Id-`, dan `Out`. Secara fungsi, rangkaian ditujukan sebagai sumber arus terkendali tegangan; RV1 menjadi elemen penyetelan. Nilai rasio resistor dan batas supply/compliance harus diverifikasi pada simulasi dan pengukuran aktual.

<p align="center">
  <img src="VCS-THT%20PCB%20Area.png" alt="Howland VCCS THT PCB area drawing" width="680">
</p>

## Dimensi dan luas board

| Parameter | Nilai |
| --- | ---: |
| Lebar bounding outline | 81.28 mm |
| Tinggi bounding outline | 43.18 mm |
| Radius sudut | 2.00 mm |
| Luas bounding rectangle | 3,509.67 mm² |
| Koreksi empat sudut membulat | 3.43 mm² |
| **Luas bidang PCB aktual** | **3,506.24 mm²** |
| **Konversi** | **35.0624 cm²** |

Perhitungan berdasarkan outline `Edge.Cuts` pada PCB/Gerber dengan formula `A = W × H − (4 − π)r²`. Ukuran adalah batas luar board; luas aktual dikurangi sudut rounded.

## Paket Gerber dan drill

**Status: Gerber dan drill tersedia.**

[Unduh paket Gerber](Howland-VCCS-TL072-Gerber.zip)

Layer individual:
- Copper: [F_Cu](Howland-VCCS-TL072-F_Cu.gbr), [B_Cu](Howland-VCCS-TL072-B_Cu.gbr)
- Solder mask: [F_Mask](Howland-VCCS-TL072-F_Mask.gbr), [B_Mask](Howland-VCCS-TL072-B_Mask.gbr)
- Paste: [F_Paste](Howland-VCCS-TL072-F_Paste.gbr), [B_Paste](Howland-VCCS-TL072-B_Paste.gbr)
- Silkscreen: [F_Silkscreen](Howland-VCCS-TL072-F_Silkscreen.gbr), [B_Silkscreen](Howland-VCCS-TL072-B_Silkscreen.gbr)
- Board profile: [Edge_Cuts](Howland-VCCS-TL072-Edge_Cuts.gbr)
- Drill: [PTH](Howland-VCCS-TL072-PTH.drl), [NPTH](Howland-VCCS-TL072-NPTH.drl)
- Job metadata: [Gerber job](Howland-VCCS-TL072-job.gbrjob)

Gerber metadata menyatakan output dibuat dengan KiCad 10.0.5 pada 13 November 2026. Gunakan ZIP dan file layer dari revisi yang sama.

## File project

- `Howland-VCCS-TL072.kicad_pro`
- `Howland-VCCS-TL072.kicad_sch`
- `Howland-VCCS-TL072.kicad_pcb`

Sebelum manufaktur, periksa pinout TL072, rasio resistor, koneksi J1/J2, rail VCC/VEE, dan nilai/setelan RV1. ERC/DRC serta hasil simulasi tidak menggantikan uji kestabilan dan pengukuran arus pada beban yang dituju.

---

[README Howland VCCS](../README.md) · [README KiCad](../../README.md)
