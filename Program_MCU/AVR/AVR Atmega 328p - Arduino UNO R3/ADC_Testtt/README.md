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

# ADC_Testtt — ADC0 + BMP280 (PlatformIO Uno)

Proyek PlatformIO dengan environment <code>uno</code>, platform <code>atmelavr</code>, dan framework Arduino. Source dimaksudkan membaca ADC0 untuk menghitung tegangan/resistansi serta mencoba membaca ID dan data raw BMP280 melalui TWI/I²C.

<p align="center">
  <a href="https://wholesale.pimoroni.com/en-eu/products/adafruit-bmp280-i2c-or-spi-barometric-pressure-altitude-sensor"><img src="https://wholesale.pimoroni.com/cdn/shop/products/2651-05.jpg?crop=center&height=1500&v=1597152815&width=1500" alt="Foto modul sensor BMP280" width="310"></a>
  <a href="https://laelectronica.com.gt/arduino-uno-rev3"><img src="https://laelectronica.com.gt/image/cache/catalog/Productos/Arduinos/A000066-1-1200x1200.jpg" alt="Foto board Arduino Uno R3" width="310"></a>
</p>
<sub>Foto komponen referensi dari halaman produk; bukan foto rangkaian yang sudah dirakit.</sub>

## Komponen dan fungsi yang dituju

- **Arduino Uno / ATmega328P**: kontrol firmware, ADC dan bus TWI/I²C.
- **BMP280**: sensor tekanan barometrik dan suhu. Source menargetkan alamat 0x76 dan chip ID 0x58.
- **ADC0 / A0 + pembagi tegangan**: pengukuran node V_in dan estimasi R_uji dengan nilai resistor referensi 3.6 kΩ yang tertulis dalam formula.
- **Serial 9600 baud**: melaporkan sampel ADC dan hasil percobaan sensor.

## Status teknis source

Source ini belum boleh dianggap sebagai driver BMP280 yang selesai. Di dalam <code>BMP_read_raw()</code>, pointer register ditulis ke 0xF4 (control register), sedangkan data tekanan mulai pada 0xF7 dan data suhu mulai pada 0xFA. Ada juga ekspresi <code>I2C_START</code> tanpa pemanggilan fungsi, dan argumen <code>snprintf</code> untuk chip ID/raw values tidak cocok dengan format string. Hasil yang tercetak belum merupakan pembacaan suhu/tekanan terkompensasi karena data kalibrasi dan formula kompensasi belum diterapkan.

**Peringatan ADC:** bit REFS1:0 disetel ke 11, yakni referensi internal nominal 1.1 V. Pastikan tegangan pada A0 tidak melebihi referensi dan rumus pembagi benar terhadap wiring aktual.

## Build

- Build: <code>pio run -e uno</code>
- Upload: <code>pio run -e uno -t upload</code>

Register map: [datasheet resmi Bosch BMP280](https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bmp280-ds001.pdf).
