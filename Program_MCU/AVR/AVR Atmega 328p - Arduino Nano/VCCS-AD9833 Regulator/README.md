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
<p align="center"><sub>PlatformIO · AVR / ATmega328P · Arduino. Foto chip ATmega328P merupakan foto produk non-AI dari pemasok; logo ditampilkan sebagai identitas platform dan komponen, bukan klaim endorsement.</sub></p>

# VCCS–AD9833 Frequency Controller (Arduino Nano)

Firmware untuk ATmega328P/Arduino Nano yang mengirim perintah SPI 16-bit ke AD9833 guna mengatur frequency tuning word pada register FREQ0.


## Fungsi program

Firmware ini menggunakan ATmega328P sebagai SPI master untuk menulis register AD9833. Tujuannya adalah mengatur frekuensi DDS yang menjadi sumber sinyal untuk pengembangan VCCS.

**Batas fungsi yang perlu dipahami:** source saat ini hanya mengatur frekuensi keluaran AD9833 dan melaporkan status melalui serial. Belum terlihat pembacaan arus keluaran, pengukuran feedback, pengaturan amplitudo, atau algoritma closed-loop current regulation. Jadi, kata “Regulator” pada nama folder belum berarti firmware sudah mengatur arus VCCS secara tertutup.

### Spesifikasi yang ditetapkan source

| Parameter | Nilai |
| --- | --- |
| IC DDS | AD9833 |
| Master clock asumsi | 25 MHz (`AD9833_MCLK_HZ`) |
| Register frekuensi | FREQ0 |
| Register fase | PHASE0 = 0 |
| Frekuensi awal | 1,000 Hz |
| Rentang input yang diterima | 10–10,000 Hz |
| Antarmuka konfigurasi | UART/Serial, 115200 baud |
| Antarmuka DDS | Hardware SPI, Mode 2, MSB first |
| SPI clock | F_CPU/4; 4 MHz bila clock ATmega328P = 16 MHz |

Nilai master clock 25 MHz adalah konstanta yang ditetapkan firmware. Pastikan oscillator/MCLK pada modul AD9833 benar-benar 25 MHz. Jika berbeda, frekuensi aktual juga akan bergeser sesuai rasio antara clock aktual dan clock yang dipakai dalam perhitungan firmware.

### Pemetaan pin ATmega328P

| Pin MCU | Pin Arduino Nano/Uno | Ke AD9833 | Fungsi |
| --- | --- | --- | --- |
| PB2 | D10 | FSYNC | Chip select / frame sync, aktif LOW |
| PB3 | D11 | SDATA | SPI MOSI / serial data |
| PB5 | D13 | SCLK | SPI clock |
| GND | GND | GND | Referensi ground bersama |
| MCLK eksternal modul | — | MCLK | Clock referensi DDS, diasumsikan 25 MHz oleh firmware |

MISO tidak digunakan dalam source. Pin catu daya dan keluaran analog AD9833 tidak didefinisikan oleh program; ikuti skematik/modul hardware dan datasheet sebelum wiring. Jangan menganggap mapping pin ini sebagai pengganti pemeriksaan level tegangan.

### Urutan inisialisasi

1. Konfigurasi PB2, PB3, dan PB5 sebagai output.
2. Aktifkan SPI master dengan CPOL=1 dan CPHA=0 (Mode 2), MSB-first.
3. Tulis control word B28 + RESET untuk menahan output DDS selama konfigurasi.
4. Set PHASE0 = 0.
5. Tulis frequency tuning word 28-bit ke FREQ0 dalam dua bagian 14-bit.
6. Set B28 tanpa RESET untuk melepas reset dan mengaktifkan keluaran sinus (MODE dan OPBITEN tetap 0).

Formula frequency tuning word yang digunakan source:

`FTW = round(f_out × 2^28 / f_MCLK)`

### Kontrol melalui Serial Monitor

Kirim angka frekuensi dalam satuan Hz dan akhiri dengan newline/Enter. Contoh:

```text
1000
2500
10000
```

Program menerima integer 10 sampai 10000 Hz. Input di luar rentang, karakter non-digit, atau buffer terlalu panjang akan menghasilkan pesan error. Saat boot, firmware menginisialisasi keluaran pada 1 kHz dan menampilkan prompt pada Serial Monitor.

## Catatan validasi hardware

- Pastikan MCLK modul sesuai 25 MHz atau ubah konstanta `AD9833_MCLK_HZ` sesuai sumber clock yang terukur.
- Verifikasi CPOL/CPHA, urutan bit, dan timing FSYNC dengan datasheet/logic analyzer bila komunikasi SPI belum stabil.
- Pastikan FSYNC, SDATA, SCLK, GND, dan catu daya terhubung sesuai board yang dipakai.
- Ukur frekuensi output AD9833 dengan osiloskop/frequency counter pada beberapa titik rentang.
- Firmware tidak melakukan pengukuran arus atau closed-loop VCCS; fungsi tersebut memerlukan blok sensor/feedback dan algoritma tambahan.

## Struktur project

- `platformio.ini`: target board, framework, dan pengaturan monitor.
- `src/main.cpp`: driver SPI, konfigurasi AD9833, dan parser perintah serial.
- `include/`: header project (belum diperlukan oleh source saat ini).
- `lib/`: pustaka lokal project (belum ada dependency lokal yang dipakai source).
- `test/`: direktori pengujian; belum berisi test otomatis yang teridentifikasi.


## Build dan upload

Target pada `platformio.ini`:
- Environment: `nanoatmega328new`
- Platform: `atmelavr`
- Board: `nanoatmega328new`
- Framework: `arduino`
- Serial Monitor: 115200 baud

Jalankan dari folder proyek:

```bash
pio run -e nanoatmega328new
pio run -e nanoatmega328new -t upload
pio device monitor -b 115200
```

Pilih port serial Nano yang benar saat upload/monitor. Jika memakai board Nano dengan bootloader berbeda, pastikan pilihan board/environment sesuai dengan hardware.

---

[README Arduino Nano](../README.md) · [README AVR](../../README.md)
