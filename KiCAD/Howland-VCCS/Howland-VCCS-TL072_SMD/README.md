# Howland VCCS with TL072 (SMD)

Folder parent untuk varian Howland VCCS dengan komponen pasif SMD. File project sebenarnya berada di [subfolder project](Howland-VCCS-TL072_SMD/README.md).

<p align="center"><a href="https://www.ti.com/product/TL072"><img src="https://www.deltaset.net/Resimler/Urunler/TL072_%2CTL072CP_DIP-8_THT_-_DELTASET_ELEKTRONIK1_3054.jpg" alt="Foto asli paket IC TL072 DIP-8" width="330"></a></p><sub>Foto IC TL072 DIP-8 dari pemasok; lihat <a href="https://www.ti.com/product/TL072">datasheet resmi TI</a> untuk package/pinout. Bukan foto board Howland yang dirancang di repository.</sub>

## Fungsi dan status komponen
Tujuan rangkaian adalah sumber arus terkendali tegangan berbasis TL072, namun schematic di subfolder masih memiliki beberapa nilai komponen yang belum ditentukan. R1/R3 = 100 kΩ, R2/R4 = 20 kΩ, R5 = 100 Ω; R6/R7 masih generic “R”, C1/C2 masih generic “C”.

**Gap penting:** footprint U1 TL072 masih DIP-8 walaupun folder dinamai SMD. Konfirmasi apakah desain memang hybrid (IC THT + pasif SMD) atau ganti footprint ke paket SMD yang benar sebelum fabrikasi.
