# Howland VCCS 2 Buffer

Workspace schematic untuk tahap pengembangan buffer pada rangkaian VCCS.

## Komponen yang terlihat pada schematic

| Ref. | Komponen | Nilai/jenis yang tercantum |
| --- | --- | --- |
| U1 | AD826ANZ | Dual high-speed op-amp, footprint DIP-8 kustom |
| U2, U3 | TL082 | Dual JFET-input op-amp |
| R1–R14 | Resistor | Value masih generik `R_Small`; nilai dan footprint perlu ditentukan |

Topologi ini memuat tiga IC op-amp dan jaringan resistor, tetapi nilai resistor belum diisi. Karena itu, fungsi tiap tahap buffer, gain, impedansi input/output, kebutuhan supply, dan stabilitas belum bisa disimpulkan dari BOM saja. Ikuti koneksi pada schematic dan tambahkan penjelasan fungsi blok setelah desain dikunci.

## Status PCB dan manufaktur

- File schematic `Howland-VCCS-2-Buffer.kicad_sch` tersedia.
- File `Howland-VCCS-2-Buffer.kicad_pcb` saat ini hanya berisi header PCB KiCad tanpa footprint, track, atau outline board.
- Belum ada Gerber, drill file, maupun board-area image.
- Luas board belum dapat dihitung karena tidak ada geometri `Edge.Cuts`.

## Langkah berikutnya

1. Tetapkan nilai/toleransi resistor dan footprint komponen.
2. Verifikasi fungsi tiap tahap AD826ANZ/TL082 melalui analisis dan simulasi.
3. Lengkapi PCB dari schematic dan jalankan ERC/DRC.
4. Setelah outline board ditentukan, hitung area dan plot Gerber/drill.

---

[README VCCS 2 Buffer](../README.md) · [README Howland VCCS](../../README.md)
