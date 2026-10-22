# Source Code

LED-Berjalan.cpp adalah implementasi utama pola LED.

- Menggunakan millis() dan timestamp untuk mengatur interval tanpa blocking.
- Mengubah status output pada D0–D3 serta A0–A3.
- Variabel time menentukan interval pembaruan pada implementasi saat ini.

D0/D1 juga merupakan pin UART RX/TX pada Uno. Hindari pemakaian bersamaan dengan komunikasi serial bila tidak diperlukan; gunakan resistor pembatas arus setiap LED.

---

[README utama repositori](../../../../../README.md)
