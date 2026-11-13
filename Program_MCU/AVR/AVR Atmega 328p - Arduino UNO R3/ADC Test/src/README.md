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

# Source Code — ADC0 dan BMP280 ID

File <code>main.cpp</code> berisi driver register TWI/I²C, fungsi ADC, dan output USART manual. Intended behavior-nya adalah membaca ADC0 periodik untuk menghitung V_in/R_uji dan membaca register chip ID BMP280 (0xD0) dengan alamat 0x76.

Hal yang perlu diverifikasi sebelum dianggap stabil:
- kombinasi bit referensi ADC memilih internal 1.1 V pada ATmega328P; komentar “AVcc 5V” perlu dikoreksi.
- <code>main()</code> dibuat sendiri sementara source memanggil <code>millis()</code>; pastikan timer/core inisialisasi dilakukan.
- pembacaan BMP280 di versi ini hanya dimaksudkan untuk chip ID, bukan suhu/tekanan terkompensasi.
- validasi ADC raw, rumus pembagi, dan data yang dikirim ke USART agar memakai sampel terbaru.

Build dari root proyek dengan <code>pio run -e nanoatmega328</code>. Lihat [README proyek](../README.md) untuk daftar hardware, foto referensi, dan catatan wiring.
