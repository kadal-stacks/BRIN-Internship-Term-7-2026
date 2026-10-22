# Non-Blocking LED Sequencer

Proyek PlatformIO untuk Arduino Uno/ATmega328P. Source src/LED-Berjalan.cpp memperbarui output berkala memakai millis(), bukan delay() blocking.

- Environment: uno.
- Build: pio run -e uno
- Upload: pio run -e uno -t upload
- Pin output pada implementasi saat ini: D0–D3 dan A0–A3 sebagai digital.

Perhatian: D0/D1 juga digunakan UART RX/TX pada Uno, sehingga bisa mengganggu upload atau komunikasi serial. Jika serial diperlukan, pindahkan LED ke pin yang tidak berbenturan dan perbarui firmware serta wiring. Gunakan resistor pembatas arus untuk setiap LED.

---

[README utama repositori](../../../../README.md)
