# Source Code

`main.cpp` berisi driver SPI hardware dan antarmuka serial untuk AD9833:
- PB2/D10 digunakan sebagai FSYNC.
- PB3/D11 digunakan sebagai MOSI/SDATA.
- PB5/D13 digunakan sebagai SCK/SCLK.
- Register FREQ0 diset dengan 28-bit frequency tuning word.
- PHASE0 diset nol; startup mengatur frekuensi 1 kHz.
- Parser serial menerima frekuensi integer 10–10,000 Hz.

Source tidak membaca feedback arus VCCS atau mengatur amplitudo. Lihat [README project](../README.md) untuk penjelasan fungsi, batas implementasi, dan mismatch konfigurasi target Nano/Uno.
