# Non-Blocking LED Sequencer

Program PlatformIO untuk Arduino Uno/ATmega328P yang mengatur pola LED dengan beberapa timestamp berbasis <code>millis()</code>, tanpa menggunakan <code>delay()</code> pada loop utama.

<p align="center"><a href="https://santanaimport.com.br/arduino-uno-rev3-a000066.htm?sku=A000066"><img src="https://santanaimport.com.br/imagens/produtos/zoom/A000066_normal.JPG" alt="Arduino Uno R3 board reference photo" width="360"></a></p>
<sub>Foto Uno adalah referensi board saja; repository belum menyertakan foto rangkaian LED hasil perakitan.</sub>

## Komponen dan fungsi

- Board target: Arduino Uno / ATmega328P, environment PlatformIO <code>uno</code>.
- LED eksternal per output, masing-masing memakai resistor pembatas arus. Contoh pin pada source: D0–D3 dan A0–A3 (pin analog dipakai sebagai digital).
- Timer software pertama mengubah output setiap 500 ms; timer kedua mengubah output kelompok lain setiap 1000 ms dengan <code>time = 1</code>.

## Hal yang perlu diperhatikan

D0 dan D1 dipakai juga sebagai UART RX/TX pada Uno, jadi dapat mengganggu upload/Serial. Bila tidak ada alasan khusus, pindahkan LED dari D0/D1 ke pin digital lain, lalu ubah firmware dan wiring bersamaan. Jangan menghubungkan LED tanpa resistor.

- Build: <code>pio run -e uno</code>
- Upload: <code>pio run -e uno -t upload</code>

