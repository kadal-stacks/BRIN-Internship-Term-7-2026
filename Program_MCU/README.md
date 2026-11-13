# Microcontroller Firmware

Folder ini mengelompokkan source code dan eksperimen firmware mikrokontroler, terutama keluarga AVR ATmega328P/Arduino.

## Navigasi
- [AVR Projects](AVR/README.md): proyek berbasis keluarga mikrokontroler AVR.
- [VCCS–AD9833 Regulator](AVR/AVR%20Atmega%20328p%20-%20Arduino%20Nano/VCCS-AD9833%20Regulator/README.md): kontrol frekuensi DDS AD9833 menggunakan SPI hardware dan perintah serial.

Sebelum build, periksa `platformio.ini` atau `CMakeLists.txt` pada folder proyek. Cocokkan board target, clock, baud rate, pin peripheral, dan port upload dengan hardware aktual.
