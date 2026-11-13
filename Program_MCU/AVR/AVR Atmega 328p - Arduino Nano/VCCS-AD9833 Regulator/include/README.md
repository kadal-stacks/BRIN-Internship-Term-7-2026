# Header Files

Direktori untuk header project (.h/.hpp). Source AD9833 saat ini masih berada di satu file `src/main.cpp` dan belum memerlukan header kustom.

Jika driver AD9833 dipisah ke modul, tempatkan deklarasi fungsi/register di header dan implementasinya di file source tersendiri. Sertakan include guard atau `#pragma once`.
