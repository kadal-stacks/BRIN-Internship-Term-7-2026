# Source Code

`main.cpp` memuat:
- Inisialisasi hardware SPI ATmega328P pada Mode 2.
- Penulisan word 16-bit AD9833 melalui FSYNC, dengan byte MSB dikirim lebih dahulu.
- Perhitungan 28-bit frequency tuning word dan penulisan dua bagian 14-bit ke FREQ0.
- Inisialisasi PHASE0 = 0 dan frekuensi awal 1 kHz.
- Parser perintah serial untuk frekuensi 10–10,000 Hz.

Pin yang didefinisikan source: PB2/FSYNC (D10), PB3/MOSI (D11), dan PB5/SCK (D13). Lihat [README project](../README.md) untuk arsitektur, batas fungsi, dan perintah build.
