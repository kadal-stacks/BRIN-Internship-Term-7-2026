<p align="center">
  <a href="https://platformio.org/" title="PlatformIO">
    <img src="https://upload.wikimedia.org/wikipedia/commons/c/cd/PlatformIO_logo.svg" alt="PlatformIO logo" height="58">
  </a>
  &nbsp;&nbsp;
  <a href="https://commons.wikimedia.org/wiki/File:Avr_logo.svg" title="Atmel AVR logo">
    <img src="https://upload.wikimedia.org/wikipedia/commons/9/96/Avr_logo.svg" alt="AVR logo" height="38">
  </a>
  &nbsp;&nbsp;
  <a href="https://www.microchip.com/en-us/product/ATmega328P" title="Microchip ATmega328P">
    <img src="https://makerbazar.in/cdn/shop/products/ATMEGA328makerbazar1.jpg?v=1642945417" alt="ATmega328P-PU DIP-28 microcontroller photograph" height="68">
  </a>
  &nbsp;&nbsp;
  <a href="https://content.arduino.cc/brand/" title="Arduino official brand assets">
    <img src="https://content.arduino.cc/brand/arduino-color.svg" alt="Arduino logo" height="48">
  </a>
</p>
<p align="center"><sub>PlatformIO · AVR / ATmega328P · Arduino. Foto chip ATmega328P merupakan foto produk non-AI dari pemasok; logo ditampilkan sebagai identitas platform dan komponen, bukan klaim endorsement. Toolchain aktual mengikuti konfigurasi tiap proyek.</sub></p>

# Source Code — ADC0 dan BMP280

File <code>main.cpp</code> menggabungkan pembacaan ADC0 tiap 200 ms, output Serial, pembacaan chip ID sensor tiap 1000 ms, serta percobaan membaca nilai raw tekanan/suhu.

## Known issues to review

1. <code>BMP_read_raw()</code> menulis pointer register 0xF4 sebelum membaca, padahal data tekanan BMP280 mulai di 0xF7 dan suhu mulai di 0xFA.
2. Terdapat <code>I2C_START</code> tanpa tanda kurung, sehingga fungsi repeated-start tidak terpanggil sebagaimana dimaksud.
3. Format string <code>snprintf</code> menerima array karakter untuk placeholder numerik (%02X dan %ld), yang menyebabkan output tidak valid/undefined behavior.
4. Data belum dikompensasi dengan koefisien kalibrasi sensor, sehingga raw counts bukan nilai °C/hPa.
5. ADC menggunakan referensi internal nominal 1.1 V. Pastikan rangkaian pembagi tidak memberi tegangan lebih tinggi ke A0.

Build dari root proyek dengan <code>pio run -e uno</code>. Lihat [README parent](../README.md) untuk daftar komponen, fungsi, dan foto referensi.
