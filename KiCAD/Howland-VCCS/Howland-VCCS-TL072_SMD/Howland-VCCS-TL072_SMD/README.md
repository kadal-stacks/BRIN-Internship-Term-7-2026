<p align="center">
  <a href="https://commons.wikimedia.org/wiki/File:KiCad-Logo.svg" title="KiCad logo, KiCad Developers Team">
    <img src="https://upload.wikimedia.org/wikipedia/commons/5/59/KiCad-Logo.svg" alt="KiCad logo" width="150">
  </a>
</p>

# Howland VCCS with TL072 (SMD / Hybrid)

Project KiCad untuk varian Howland VCCS dengan jaringan resistor SMD 0805. Schematic terbaru berbeda dari revisi lama: kini memakai R1–R4 = 100 kΩ, R5 = 150 Ω, dan RV1 = 1 kΩ.

## Komponen dari schematic

| Ref. | Komponen | Nilai / footprint |
| --- | --- | --- |
| U1 | Dual op-amp TL072 | **DIP-8 THT** |
| R1–R4 | Resistor | 100 kΩ, SMD 0805 |
| R5 | Resistor | 150 Ω, SMD 0805 |
| RV1 | Potensiometer trimmer | 1 kΩ, Bourns 3296W vertical THT |
| J4 | Pin header 1×6 | Pitch 2.54 mm, THT |
| H1–H2 | Mounting hole | M2.2 / M2 |
| Net labels | Id+, Id-, Out | Label antarmuka sinyal |

Desain ini **hybrid**, bukan full-SMD, karena U1, RV1, dan J4 masih memakai footprint through-hole. Schematic yang terbaru tidak lagi menunjukkan R6/R7, C1/C2, atau solder jumper JP1/JP2 yang tercantum di dokumentasi versi sebelumnya.

Secara fungsi, topologi Howland ditujukan untuk menghasilkan arus beban yang dikendalikan sinyal tegangan. Rasio resistor dan toleransinya mempengaruhi akurasi. Verifikasi supply VCC/VEE, swing output TL072, compliance voltage, dan koneksi beban sebelum uji.

![Howland VCCS SMD board-area drawing](VCCS%20PCB%20Area.png)

## Dimensi dan luas board

| Parameter | Nilai |
| --- | ---: |
| Lebar bounding outline | 27.078 mm |
| Tinggi bounding outline | 22.886 mm |
| Radius sudut | 1.00 mm |
| Luas bounding rectangle | 619.71 mm² |
| Koreksi empat sudut membulat | 0.86 mm² |
| **Luas bidang PCB aktual** | **618.85 mm²** |
| **Konversi** | **6.1885 cm²** |

Luas dihitung dari rounded outline pada layer `Edge.Cuts` menggunakan `A = W × H − (4 − π)r²`.

## Paket Gerber dan drill

**Status: Gerber dan drill tersedia.**

[Unduh paket Gerber ZIP](Howland-VCCS-TL072-SMD-Gerber.zip)

Layer individual:
- Copper: [F_Cu](Howland-VCCS-TL072_SMD-F_Cu.gbr), [B_Cu](Howland-VCCS-TL072_SMD-B_Cu.gbr)
- Solder mask: [F_Mask](Howland-VCCS-TL072_SMD-F_Mask.gbr), [B_Mask](Howland-VCCS-TL072_SMD-B_Mask.gbr)
- Paste: [F_Paste](Howland-VCCS-TL072_SMD-F_Paste.gbr), [B_Paste](Howland-VCCS-TL072_SMD-B_Paste.gbr)
- Silkscreen: [F_Silkscreen](Howland-VCCS-TL072_SMD-F_Silkscreen.gbr), [B_Silkscreen](Howland-VCCS-TL072_SMD-B_Silkscreen.gbr)
- Board profile: [Edge_Cuts](Howland-VCCS-TL072_SMD-Edge_Cuts.gbr)
- Drill: [PTH](Howland-VCCS-TL072_SMD-PTH.drl), [NPTH](Howland-VCCS-TL072_SMD-NPTH.drl)
- Job metadata: [Gerber job](Howland-VCCS-TL072_SMD-job.gbrjob)

Gerber dibuat dengan KiCad 10.0.5 pada 13 November 2026.

## File project

- `Howland-VCCS-TL072_SMD.kicad_pro`
- `Howland-VCCS-TL072_SMD.kicad_sch`
- `Howland-VCCS-TL072_SMD.kicad_pcb`

Sebelum fabrikasi, pastikan nilai/footprint sesuai schematic terbaru, khususnya footprint U1 DIP-8 dan trimmer THT. Jalankan ERC/DRC lagi apabila ada perubahan schematic, footprint, atau layout.

---

[README varian parent](../README.md) · [README Howland VCCS](../../README.md)
