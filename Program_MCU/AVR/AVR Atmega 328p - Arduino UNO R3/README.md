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

# ATmega328P / Arduino Uno R3

Kumpulan eksperimen firmware untuk keluarga ATmega328P. Setiap proyek memiliki konfigurasi build sendiri.

<p align="center"><a href="https://laelectronica.com.gt/arduino-uno-rev3"><img src="https://laelectronica.com.gt/image/cache/catalog/Productos/Arduinos/A000066-1-1200x1200.jpg" alt="Arduino Uno R3 reference photo" width="340"></a></p>
<sub>Foto referensi board Arduino Uno R3; bukan foto hasil pengujian firmware di repository.</sub>

## Subproyek

- [ADC Test](ADC%20Test/README.md): target PlatformIO Nano ATmega328; membaca ADC0 dan mencoba akses BMP280.
- [ADC (CMake)](ADC/README.md): proyek bare-metal CMake.
- [ADC_Testtt](ADC_Testtt/README.md): PlatformIO dengan pembacaan ADC0 dan eksperimen BMP280.
- [LED Non Blocking Program](LED%20Non%20Blocking%20Program/README.md): pola LED memakai `millis()`.
- [VCCS–AD9833 Regulator](VCCS%20-%20AD9833%20Regulator/README.md): salinan firmware kontrol frekuensi DDS AD9833.

**Catatan target:** meskipun proyek AD9833 ini berada di folder Arduino UNO R3, `platformio.ini` saat ini menyatakan `board = nanoatmega328`, bukan `uno`. README proyek menjelaskan perintah yang sesuai dengan konfigurasi aktual dan hal yang perlu diselaraskan jika target fisiknya memang Uno R3.
