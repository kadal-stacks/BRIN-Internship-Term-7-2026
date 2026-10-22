# Howland Voltage-Controlled Current Source (VCCS)

Kumpulan proyek ini berisi rangkaian Howland current pump berbasis op-amp TL072. Fungsi umumnya adalah mengubah sinyal tegangan kendali menjadi arus pada beban, dengan jaringan resistor dan umpan balik op-amp. Akurasi sangat bergantung pada kecocokan rasio resistor, rentang tegangan, beban, serta catu daya.

<p align="center"><a href="https://www.ti.com/product/TL072"><img src="https://www.dnatechindia.com/image/catalog/TL072.jpg?v=1445492923" alt="Foto asli paket IC TL072 DIP-8" width="330"></a></p><sub>Foto IC TL072 DIP-8 dari pemasok; lihat <a href="https://www.ti.com/product/TL072">datasheet resmi TI</a> untuk package/pinout. Bukan foto board Howland yang dirancang di repository.</sub>

## Komponen dari schematic saat ini

### Varian THT / project umum

| Komponen | Nilai/tipe | Jumlah |
| --- | --- | ---: |
| U1 | TL072, footprint DIP-8 | 1 |
| R1–R4 | 100 kΩ | 4 |
| R5 | 150 Ω | 1 |
| RV1 | Potensiometer 1 kΩ | 1 |
| J1–J2 | Header 1×3, pitch 2.54 mm | 2 |
| Power rails | VCC, VEE, GND | label daya |

### Varian SMD

| Komponen | Nilai saat ini pada schematic | Catatan |
| --- | --- | --- |
| U1 | TL072 | Footprint masih <code>Package_DIP:DIP-8_W7.62mm</code>, jadi belum benar-benar full-SMD |
| R1, R3 | 100 kΩ, ukuran 0805 | Nilai tercantum |
| R2, R4 | 20 kΩ, ukuran 0805 | Nilai tercantum |
| R5 | 100 Ω, ukuran 0805 | Nilai tercantum |
| R6, R7 | Nilai masih generic “R”, ukuran 0805 | Lengkapi nilai sebelum BOM/fabrikasi |
| C1, C2 | Nilai masih generic “C”, ukuran 0805 | Tentukan nilai, voltage rating, dan fungsi |
| JP1, JP2 | Solder jumper terbuka | Pastikan konfigurasi jumper terdokumentasi |
| H1, H2 | Mounting hole M2.2 | Cek dimensi mekanik |
| J1, J2 | Header 1×3, pitch 2.54 mm | Konektor eksternal |

## Alur validasi

1. Periksa rasio resistor dan koneksi feedback pada schematic.
2. Cocokkan supply VCC/VEE dan common-mode/output swing TL072 dengan datasheet.
3. Tentukan komponen yang masih generic dan footprint IC final, terutama di varian SMD.
4. Jalankan ERC dan DRC, kemudian simulasi rangkaian dengan beban yang relevan.
5. Uji arus output serta compliance voltage pada hardware dengan pembatasan arus dan alat ukur yang sesuai.

ERC/DRC yang bersih tidak membuktikan kestabilan atau akurasi sumber arus. Jangan menganggap nilai R5 atau setelan RV1 sebagai nilai final tanpa pengujian.
