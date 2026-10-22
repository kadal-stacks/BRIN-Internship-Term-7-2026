# Howland VCCS with TL072 (THT)

Varian THT dari rangkaian Howland Voltage-Controlled Current Source. Komponen yang tertera: U1 TL072 dengan footprint DIP-8, empat resistor 100 kΩ (R1–R4), R5 150 Ω, RV1 1 kΩ, dua header 1×3 (J1/J2), serta rail VCC/VEE/GND.

<p align="center"><a href="https://www.ti.com/product/TL072"><img src="https://www.dnatechindia.com/image/catalog/TL072.jpg?v=1445492923" alt="Foto asli paket IC TL072 DIP-8" width="330"></a></p><sub>Foto IC TL072 DIP-8 dari pemasok; lihat <a href="https://www.ti.com/product/TL072">datasheet resmi TI</a> untuk package/pinout. Bukan foto board Howland yang dirancang di repository.</sub>

## Fungsi
Jaringan resistor dan umpan balik TL072 dimaksudkan untuk mengendalikan arus beban berdasarkan sinyal kendali. Rasio resistor, setelan RV1, supply, dan tegangan compliance menentukan hasil nyata.

## Verifikasi
Buka file project, periksa pinout serta label konektor Id+/Id-/Out, jalankan ERC/DRC, dan pastikan footprint DIP-8, diameter drill, resistor THT, serta jarak komponen sesuai perakitan. Validasi dengan simulasi dan pengukuran arus pada beberapa beban sebelum menganggapnya final.
