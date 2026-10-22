# ATmega16–STM32 Breakout/Adapter

Folder ini berisi desain adapter untuk memetakan koneksi ATmega16 ke header/board STM32, dengan dua varian perakitan:
- [SMD](ATMega16-STM32%20BP%20Adapter_SMD/README.md): project, schematic, PCB, CSV pendamping, dan konfigurasi footprint.
- [THT](ATMega16-STM32%20BP%20Adapter_THT/README.md): project, schematic, PCB, dan konfigurasi footprint.

Sebelum digunakan, cocokkan pin berdasarkan fungsi listrik dan datasheet, bukan hanya urutan fisik. Periksa fungsi ganda (GPIO, ADC, timer/PWM, UART, SPI, I2C, oscillator, reset), suplai, ground, orientasi header, net, dan pad. Jalankan ERC dan DRC. README ini tidak menyatakan desain telah difabrikasi atau diuji pada hardware.

---

[README utama repositori](../../README.md)
