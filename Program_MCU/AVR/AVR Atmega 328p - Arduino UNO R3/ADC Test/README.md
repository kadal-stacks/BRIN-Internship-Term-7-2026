# BMP280 I2C Experiment (folder: ADC Test)

PlatformIO target nanoatmega328 dengan framework Arduino. Walaupun folder bernama ADC Test, source src/main.cpp saat ini berisi rutinitas TWI/I2C level-register dan mencoba berkomunikasi dengan BMP280 pada alamat 0x76. Jangan menganggap fungsinya sebagai pembacaan ADC tanpa memeriksa implementasi.

Berkas utama: platformio.ini, src/main.cpp, workspace editor pada src/Workspace file, serta direktori include/lib/test.

- Build: pio run -e nanoatmega328
- Upload: pio run -e nanoatmega328 -t upload

Sesuaikan port jika perlu. Validasi wiring SDA/SCL, ground bersama, tegangan sensor, alamat I2C, dan respons chip ID sebelum menganggap komunikasi berhasil.

---

[README utama repositori](../../../../README.md)
