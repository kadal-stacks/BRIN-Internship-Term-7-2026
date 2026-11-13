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

# ADC Test — ADC0 + BMP280 I²C (PlatformIO Nano)

Proyek ini menggunakan target <code>nanoatmega328</code> dengan framework Arduino. Source saat ini menggabungkan pembacaan tegangan melalui ADC0 dengan percobaan membaca chip ID BMP280 via I²C/TWI.

<p align="center">
  <a href="https://wholesale.pimoroni.com/en-eu/products/adafruit-bmp280-i2c-or-spi-barometric-pressure-altitude-sensor"><img src="https://wholesale.pimoroni.com/cdn/shop/products/2651-05.jpg?crop=center&height=1500&v=1597152815&width=1500" alt="Foto modul breakout sensor BMP280" width="310"></a>
  <a href="https://laelectronica.com.gt/arduino-uno-rev3"><img src="https://laelectronica.com.gt/image/cache/catalog/Productos/Arduinos/A000066-1-1200x1200.jpg" alt="Foto board Arduino Uno R3 sebagai referensi keluarga ATmega328P" width="310"></a>
</p>
<sub>Foto modul sensor dari <a href="https://wholesale.pimoroni.com/en-eu/products/adafruit-bmp280-i2c-or-spi-barometric-pressure-altitude-sensor">pemasok modul BMP280</a> dan foto board referensi dari <a href="https://laelectronica.com.gt/arduino-uno-rev3">halaman produk Uno R3</a>. Foto bukan bukti modul tersebut yang dipakai pada sesi tes.</sub>

## Komponen/hardware yang tersirat oleh source

| Bagian | Peran |
| --- | --- |
| ATmega328P / target Nano | Menjalankan firmware; clock pada source diasumsikan 16 MHz |
| ADC0 / A0 | Mengukur nilai analog yang dipakai untuk menghitung V_in dan R_uji |
| Resistor referensi 3.6 kΩ + R_uji | Formula source mengasumsikan rangkaian pembagi tegangan; pastikan nilai dan posisi resistor mengikuti wiring yang sebenarnya |
| BMP280 pada I²C | Percobaan baca register chip ID 0xD0; alamat 7-bit di source 0x76 |
| USART TX 9600 baud | Mengirim nilai hasil ke terminal serial |

## Fungsi dan batas saat ini

- ADC dijadwalkan setiap 200 ms; hitungannya memakai referensi 1.1 V dan model pembagi tegangan.
- BMP280 chip ID dicoba dibaca tiap 1000 ms; nilai produksi yang diharapkan adalah 0x58.
- Versi source ini belum membaca suhu/tekanan yang terkompensasi dari BMP280.

**Peringatan ADC:** di ATmega328P, kombinasi REFS1=1 dan REFS0=1 memilih referensi internal nominal 1.1 V. Komentar lama yang menyebut AVcc tidak konsisten dengan bitmask dan perhitungan V_in. Pastikan tegangan ADC0 tidak melebihi referensi yang dipilih; jangan sambungkan node 5 V langsung ke A0 tanpa divider yang benar.

**Peringatan timing:** file mendefinisikan <code>main()</code> sendiri walau memakai framework Arduino dan <code>millis()</code>. Inisialisasi core/timer Arduino perlu dipastikan berjalan; jika tidak, interval waktu tidak dapat dipercaya. Nilai ADC awal dan nilai ADC periodik di buffer juga perlu ditinjau agar output tidak tercampur antara data awal dan data terbaru.

## Build

- Build: <code>pio run -e nanoatmega328</code>
- Upload: <code>pio run -e nanoatmega328 -t upload</code>

Sumber register BMP280: [datasheet resmi Bosch Sensortec](https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bmp280-ds001.pdf).
