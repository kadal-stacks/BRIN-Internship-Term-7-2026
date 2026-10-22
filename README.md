<!-- Official BRIN logo sourced from Wikimedia Commons; no AI-generated imagery is used. -->
<p align="center">
  <a href="https://brin.go.id/" title="Situs resmi BRIN">
    <img src="https://upload.wikimedia.org/wikipedia/commons/5/5a/LOGO_BRIN_NEW.jpg" alt="Logo Badan Riset dan Inovasi Nasional (BRIN)" width="118">
  </a>
</p>

<h1 align="center">BRIN Internship | Term 7 · 2026</h1>

<p align="center">
  Catatan kerja dan hasil praktik di bidang embedded systems, firmware mikrokontroler, serta desain rangkaian dan PCB.
</p>

<p align="center">
  <a href="https://github.com/kadal-stacks/BRIN-Internship-Term-7-2026/commits/main">
    <img alt="Last commit" src="https://img.shields.io/github/last-commit/kadal-stacks/BRIN-Internship-Term-7-2026?style=flat-square&label=last%20commit">
  </a>
  <a href="https://github.com/kadal-stacks/BRIN-Internship-Term-7-2026">
    <img alt="Repository size" src="https://img.shields.io/github/repo-size/kadal-stacks/BRIN-Internship-Term-7-2026?style=flat-square">
  </a>
  <a href="https://github.com/kadal-stacks/BRIN-Internship-Term-7-2026">
    <img alt="Top language" src="https://img.shields.io/github/languages/top/kadal-stacks/BRIN-Internship-Term-7-2026?style=flat-square">
  </a>
  <a href="https://www.kicad.org/">
    <img alt="EDA" src="https://img.shields.io/badge/EDA-KiCad-314CB0?style=flat-square&logo=kicad&logoColor=white">
  </a>
  <a href="https://www.platformio.org/">
    <img alt="Embedded firmware" src="https://img.shields.io/badge/Firmware-Embedded%20C%2FC%2B%2B-00599C?style=flat-square&logo=cplusplus&logoColor=white">
  </a>
</p>

---

## Tentang repositori

Repositori ini mengumpulkan pekerjaan teknis selama **Magang BRIN Term 7 (2026)**. Isinya berkembang melalui proyek KiCad untuk perancangan elektronik dan PCB, eksperimen program mikrokontroler, serta contoh firmware untuk latihan dan pengujian.

Struktur dibuat mengikuti kelompok pekerjaan agar file desain, source code, dan library pendukung tetap berada dekat dengan proyek masing-masing. Status setiap desain perlu dinilai dari file dan hasil verifikasi yang tersedia; keberadaan file proyek tidak otomatis berarti desain sudah tervalidasi atau siap fabrikasi.

## Ruang lingkup

### 1. Desain elektronik dan PCB dengan KiCad

| Folder | Isi |
| --- | --- |
| [`KiCAD/ATMega16-STM32 BP Adapter`](KiCAD/ATMega16-STM32%20BP%20Adapter) | Proyek adapter/pemetaan koneksi ATmega16 ke board STM32, dengan varian **SMD** dan **THT**. Berisi project, schematic, layout PCB, dan file pendukung yang tersedia. |
| [`KiCAD/Howland-VCCS`](KiCAD/Howland-VCCS) | Proyek rangkaian Howland Voltage-Controlled Current Source menggunakan TL072, dengan beberapa varian footprint/perakitan. |
| [`KiCAD/Impedance-meter2D_Main Board`](KiCAD/Impedance-meter2D_Main%20Board) | Folder proyek untuk main board impedance meter. Kelengkapan desain dapat berbeda dari proyek lainnya. |
| [`KiCAD/Part Lib/Kicad-STM32`](KiCAD/Part%20Lib/Kicad-STM32) | Library simbol, footprint, dan model 3D untuk modul STM32 **Blue Pill** dan **Black Pill**. Lihat README di dalam folder untuk rincian library. |
| [`KiCAD/Folder Tugas`](KiCAD/Folder%20Tugas) | Folder untuk materi/tugas KiCad. |

Format yang umum dijumpai antara lain `.kicad_pro` (project), `.kicad_sch` (schematic), `.kicad_pcb` (PCB layout), `.kicad_sym` (symbol library), dan `.kicad_mod` (footprint).

### 2. Firmware dan eksperimen mikrokontroler

| Lokasi | Isi |
| --- | --- |
| [`Program_MCU/AVR/AVR Atmega 328p - Arduino UNO R3`](Program_MCU/AVR/AVR%20Atmega%20328p%20-%20Arduino%20UNO%20R3) | Eksperimen pada ATmega328P/Arduino Uno R3, termasuk proyek ADC dan program LED non-blocking. |
| [`LED-Berjalan.cpp`](LED-Berjalan.cpp) | Contoh program LED berjalan. |
| [`Non-blocking using Multi LED.cpp`](Non-blocking%20using%20Multi%20LED.cpp) | Contoh pengaturan beberapa pola LED tanpa bergantung pada jeda blocking di loop utama. |

Sebagian proyek firmware memiliki `platformio.ini` dan dapat dibuka sebagai proyek PlatformIO. Untuk source code yang berdiri sendiri, pilih board, framework, pin, serta konfigurasi build yang sesuai sebelum mengompilasi.

## Alur kerja

Alur berikut merangkum cara menavigasi dan melanjutkan pekerjaan di repositori ini. Langkah verifikasi tetap perlu disesuaikan dengan proyek dan hardware yang digunakan.

1. **Pilih proyek yang relevan.** Buka folder di `KiCAD/` untuk pekerjaan desain atau `Program_MCU/` untuk eksperimen firmware.
2. **Buka file proyek utama.** Untuk KiCad, buka file `.kicad_pro` di folder proyek agar hubungan schematic, PCB, dan library lokal lebih mudah dipertahankan.
3. **Periksa keterkaitan desain.** Pastikan nomor pin, nama net, simbol, footprint, orientasi konektor, ukuran mekanik, dan tegangan logika sesuai datasheet serta modul fisik. Hal ini sangat penting untuk adapter ATmega16–STM32.
4. **Verifikasi sebelum menganggap selesai.** Tinjau Electrical Rules Checker (ERC) untuk schematic dan Design Rules Checker (DRC) untuk PCB. Periksa hasil simulasi atau pengujian firmware jika tersedia. ERC/DRC yang bersih sendiri tidak menjamin rangkaian bekerja pada hardware.
5. **Simpan perubahan secara terstruktur.** Pertahankan file yang dibutuhkan proyek, hindari memasukkan file lock atau file sementara editor, lalu commit perubahan dengan pesan yang menjelaskan lingkup pekerjaan.

## Referensi visual

Gambar di bawah merupakan tangkapan layar asli dari dokumentasi KiCad, digunakan sebagai referensi antarmuka schematic dan PCB editor, bukan sebagai klaim bahwa gambar tersebut adalah hasil desain proyek ini.

<p align="center">
  <a href="https://www.kicad.org/blog/2024/02/Version-8.0.0-Released/">
    <img src="https://www.kicad.org/img/blog/2024/release-8.0.0/schematic-ui.png" alt="Antarmuka Schematic Editor KiCad" width="48%">
  </a>
  <a href="https://docs.kicad.org/9.0/it/pcbnew/pcbnew.html">
    <img src="https://docs.kicad.org/9.0/it/pcbnew/images/pcbnew_user_interface.png" alt="Antarmuka PCB Editor KiCad" width="48%">
  </a>
</p>

## Memulai

- **KiCad:** instal KiCad, lalu buka file `.kicad_pro` dari folder proyek yang akan dikerjakan.
- **Firmware:** untuk proyek yang memiliki `platformio.ini`, gunakan VS Code dengan ekstensi PlatformIO atau PlatformIO CLI. Pastikan board/framework cocok dengan konfigurasi proyek.
- **Hardware:** sebelum upload firmware atau memberi daya, cocokkan wiring dan level tegangan dengan datasheet serta lakukan pemeriksaan dasar untuk menghindari kerusakan komponen.

## Catatan status dan akurasi

Repositori ini merupakan arsip kerja yang berkembang. Skema, mapping pin, footprint, routing, pengaturan panel, dan source code perlu diverifikasi terhadap versi tool, datasheet komponen, hardware aktual, serta persyaratan manufaktur. Jangan menganggap desain siap produksi hanya berdasarkan visual layout atau status file yang sudah di-commit.

## Sumber gambar dan aset

- **Logo BRIN:** karya resmi Badan Riset dan Inovasi Nasional; ditautkan dari [Wikimedia Commons](https://commons.wikimedia.org/wiki/File:LOGO_BRIN_NEW.jpg), yang mencatat sumber dan status domain publik di Indonesia.
- **Tangkapan layar KiCad:** [KiCad 8 release article](https://www.kicad.org/blog/2024/02/Version-8.0.0-Released/) dan [dokumentasi PCB Editor KiCad](https://docs.kicad.org/9.0/it/pcbnew/pcbnew.html).
- **Library STM32:** lihat [README library lokal](KiCAD/Part%20Lib/Kicad-STM32/README.md) untuk detail simbol, footprint, model 3D, dan konteks sumbernya.

<p align="center">
  <sub>Logo BRIN digunakan untuk menunjukkan konteks kegiatan magang. Repositori ini tidak menyatakan dirinya sebagai repositori resmi BRIN.</sub>
</p>
