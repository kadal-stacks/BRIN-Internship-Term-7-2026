# Source Code

main.cpp berisi rutinitas TWI/I2C level-register untuk ATmega328P dan komunikasi sensor BMP280 menggunakan alamat 0x76.

Build dari root project dengan pio run -e uno. Validasi SDA/SCL, pull-up bus, level tegangan, alamat sensor, ACK/NACK, dan pembacaan chip ID sebelum mengandalkan hasil. Nama folder ADC_Testtt tidak menjamin ADC menjadi fungsi utama.

---

[README utama repositori](../../../../../README.md)
