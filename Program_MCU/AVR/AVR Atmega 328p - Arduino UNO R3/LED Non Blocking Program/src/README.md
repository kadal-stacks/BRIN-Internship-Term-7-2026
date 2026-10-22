# Source Code — LED Sequencer

File <code>LED-Berjalan.cpp</code> mengatur dua kelompok output dengan <code>millis()</code>:
- D0–D3 berganti status ketika interval mencapai <code>time × 500 ms</code>.
- A0–A3 berganti status ketika interval mencapai <code>time × 1000 ms</code>.
- Dengan <code>time = 1</code>, interval nominal adalah 500 ms dan 1000 ms, tanpa delay blocking.

Tidak ada schematic/wiring photo untuk project ini pada tree repository, sehingga wiring fisik tidak diklaim sebagai hasil final. Gunakan satu resistor pembatas arus per LED, periksa polaritas dan arus output, dan hindari D0/D1 jika serial upload/debug diperlukan.

Lihat [README proyek](../README.md) untuk foto board referensi, komponen, dan perintah build.
