# Source Code — ADC0 dan BMP280 ID

File <code>main.cpp</code> berisi driver register TWI/I²C, fungsi ADC, dan output USART manual. Intended behavior-nya adalah membaca ADC0 periodik untuk menghitung V_in/R_uji dan membaca register chip ID BMP280 (0xD0) dengan alamat 0x76.

Hal yang perlu diverifikasi sebelum dianggap stabil:
- kombinasi bit referensi ADC memilih internal 1.1 V pada ATmega328P; komentar “AVcc 5V” perlu dikoreksi.
- <code>main()</code> dibuat sendiri sementara source memanggil <code>millis()</code>; pastikan timer/core inisialisasi dilakukan.
- pembacaan BMP280 di versi ini hanya dimaksudkan untuk chip ID, bukan suhu/tekanan terkompensasi.
- validasi ADC raw, rumus pembagi, dan data yang dikirim ke USART agar memakai sampel terbaru.

Build dari root proyek dengan <code>pio run -e nanoatmega328</code>. Lihat [README proyek](../README.md) untuk daftar hardware, foto referensi, dan catatan wiring.
