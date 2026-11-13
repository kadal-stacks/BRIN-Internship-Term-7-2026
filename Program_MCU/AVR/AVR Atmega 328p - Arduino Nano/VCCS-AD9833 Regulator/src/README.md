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

# Source Code

`main.cpp` memuat:
- Inisialisasi hardware SPI ATmega328P pada Mode 2.
- Penulisan word 16-bit AD9833 melalui FSYNC, dengan byte MSB dikirim lebih dahulu.
- Perhitungan 28-bit frequency tuning word dan penulisan dua bagian 14-bit ke FREQ0.
- Inisialisasi PHASE0 = 0 dan frekuensi awal 1 kHz.
- Parser perintah serial untuk frekuensi 10–10,000 Hz.

Pin yang didefinisikan source: PB2/FSYNC (D10), PB3/MOSI (D11), dan PB5/SCK (D13). Lihat [README project](../README.md) untuk arsitektur, batas fungsi, dan perintah build.
