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

# Non-Blocking LED Sequencer

Program PlatformIO untuk Arduino Uno/ATmega328P yang mengatur pola LED dengan beberapa timestamp berbasis <code>millis()</code>, tanpa menggunakan <code>delay()</code> pada loop utama.

<p align="center"><a href="https://laelectronica.com.gt/arduino-uno-rev3"><img src="https://laelectronica.com.gt/image/cache/catalog/Productos/Arduinos/A000066-1-1200x1200.jpg" alt="Arduino Uno R3 board reference photo" width="360"></a></p>
<sub>Foto Uno adalah referensi board saja; repository belum menyertakan foto rangkaian LED hasil perakitan.</sub>

## Komponen dan fungsi

- Board target: Arduino Uno / ATmega328P, environment PlatformIO <code>uno</code>.
- LED eksternal per output, masing-masing memakai resistor pembatas arus. Contoh pin pada source: D0–D3 dan A0–A3 (pin analog dipakai sebagai digital).
- Timer software pertama mengubah output setiap 500 ms; timer kedua mengubah output kelompok lain setiap 1000 ms dengan <code>time = 1</code>.

## Hal yang perlu diperhatikan

D0 dan D1 dipakai juga sebagai UART RX/TX pada Uno, jadi dapat mengganggu upload/Serial. Bila tidak ada alasan khusus, pindahkan LED dari D0/D1 ke pin digital lain, lalu ubah firmware dan wiring bersamaan. Jangan menghubungkan LED tanpa resistor.

- Build: <code>pio run -e uno</code>
- Upload: <code>pio run -e uno -t upload</code>

