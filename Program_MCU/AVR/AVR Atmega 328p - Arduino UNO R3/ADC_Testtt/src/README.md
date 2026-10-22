# Source Code — ADC0 dan BMP280

File <code>main.cpp</code> menggabungkan pembacaan ADC0 tiap 200 ms, output Serial, pembacaan chip ID sensor tiap 1000 ms, serta percobaan membaca nilai raw tekanan/suhu.

## Known issues to review

1. <code>BMP_read_raw()</code> menulis pointer register 0xF4 sebelum membaca, padahal data tekanan BMP280 mulai di 0xF7 dan suhu mulai di 0xFA.
2. Terdapat <code>I2C_START</code> tanpa tanda kurung, sehingga fungsi repeated-start tidak terpanggil sebagaimana dimaksud.
3. Format string <code>snprintf</code> menerima array karakter untuk placeholder numerik (%02X dan %ld), yang menyebabkan output tidak valid/undefined behavior.
4. Data belum dikompensasi dengan koefisien kalibrasi sensor, sehingga raw counts bukan nilai °C/hPa.
5. ADC menggunakan referensi internal nominal 1.1 V. Pastikan rangkaian pembagi tidak memberi tegangan lebih tinggi ke A0.

Build dari root proyek dengan <code>pio run -e uno</code>. Lihat [README parent](../README.md) untuk daftar komponen, fungsi, dan foto referensi.
