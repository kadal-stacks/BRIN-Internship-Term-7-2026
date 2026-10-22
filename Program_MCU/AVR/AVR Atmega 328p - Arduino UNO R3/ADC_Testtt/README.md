# BMP280 I2C Experiment (ADC_Testtt)

PlatformIO project untuk Arduino Uno (environment uno, platform atmelavr, framework arduino). Source memakai register TWI/I2C AVR dan alamat BMP280 0x76. Meskipun nama folder menyebut ADC, implementasi yang terlihat perlu dipahami sebagai eksperimen komunikasi I2C sampai fungsi ADC diverifikasi secara terpisah.

Berkas utama: platformio.ini dan src/main.cpp; subfolder include/lib/test disediakan untuk pengembangan.

- Build: pio run -e uno
- Upload: pio run -e uno -t upload

Pastikan board/port benar, level tegangan aman, serta pembacaan chip ID sesuai datasheet. Dokumentasikan wiring dan hasil hardware.

---

[README utama repositori](../../../../README.md)
