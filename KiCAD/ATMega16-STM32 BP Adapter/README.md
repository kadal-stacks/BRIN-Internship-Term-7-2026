# ATmega16–STM32 Breakout/Adapter

Desain adapter ini bertujuan menyediakan header breakout untuk membawa sinyal ATmega16 ke sisi konektor/board STM32 sehingga pemetaan pin lebih mudah diuji dan dirakit.

<p align="center">
  <a href="https://www.mikroe.com/atmega16"><img src="https://cdn1-shop.mikroe.com/img/product/atmega16/atmega16-large_default-12x.jpg" alt="ATmega16 40-pin AVR microcontroller" width="34%"></a>
  <a href="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG"><img src="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG" alt="STM32 Blue Pill module" width="34%"></a>
</p>
<sub>Foto komponen referensi: <a href="https://www.mikroe.com/atmega16">ATmega16</a> dan <a href="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG">Blue Pill</a>. Bukan foto adapter hasil perakitan.</sub>

## Varian

- [SMD](ATMega16-STM32%20BP%20Adapter_SMD/README.md): empat konektor 1×20, label/net untuk sinyal ATmega16, serta rail daya.
- [THT](ATMega16-STM32%20BP%20Adapter_THT/README.md): header/socket THT, simbol modul Blue Pill, dan label/net ATmega16.

## Komponen dan fungsi

Dari schematic saat ini, inti adapter bukan rangkaian pemroses aktif, melainkan **konektor dan pemetaan net**:

- Konektor 1×20 untuk jalur header yang menghubungkan sinyal antar sisi.
- Net label untuk pin ATmega16: port PA, PB, PC, PD, RESET, dan sinyal periferal seperti ADC, UART, SPI, I²C/TWI, timer/PWM, serta oscillator.
- Rail daya yang ditandai mencakup 3V3, 5V/VCC, dan GND; simbol PWR_FLAG digunakan untuk pemeriksaan ERC.
- Pada schematic THT, simbol/fingerprint modul Blue Pill tercantum. Pada schematic SMD, modul MCU tidak digambar sebagai simbol eksplisit, sehingga pemetaan konektor perlu diperiksa langsung pada file skematik.

## Peringatan elektrik

Schematic yang diperiksa **tidak menunjukkan level shifter aktif**. Jangan berasumsi sinyal keluaran ATmega16 5 V aman langsung masuk ke semua pin STM32 3,3 V. Verifikasi toleransi setiap pin MCU/board, konfigurasi suplai, orientasi konektor, serta kesesuaian nomor pad dengan datasheet sebelum menghubungkan board atau memberi daya.

Belum ada klaim bahwa adapter telah difabrikasi atau lolos uji hardware. Jalankan ERC/DRC dan lakukan continuity check pada PCB hasil fabrikasi.
