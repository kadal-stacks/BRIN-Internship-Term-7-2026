# ATmega328P / Arduino Uno R3

Kumpulan eksperimen firmware untuk ATmega328P, dengan proyek PlatformIO dan CMake yang tidak selalu menggunakan entry point atau toolchain yang sama.

<p align="center"><a href="https://laelectronica.com.gt/arduino-uno-rev3"><img src="https://laelectronica.com.gt/image/cache/catalog/Productos/Arduinos/A000066-1-1200x1200.jpg" alt="Arduino Uno R3 board reference photo" width="360"></a></p>
<sub>Foto referensi board <a href="https://laelectronica.com.gt/arduino-uno-rev3">Arduino Uno R3</a>, bukan foto hasil pengujian firmware di repository ini.</sub>

## Subproyek
- [ADC Test](ADC%20Test/README.md): target PlatformIO Nano ATmega328; program membaca ADC0 dan mencoba mengakses chip ID BMP280.
- [ADC (CMake)](ADC/README.md): saat ini source hanya men-toggle LED onboard (D13/PB5), meskipun nama foldernya ADC.
- [ADC_Testtt](ADC_Testtt/README.md): PlatformIO Uno, pembacaan ADC0 dan percobaan data BMP280.
- [LED Non Blocking Program](LED%20Non%20Blocking%20Program/README.md): pola LED memakai millis() tanpa delay blocking.

Baca konfigurasi build pada tiap folder sebelum kompilasi. Nama project tidak selalu mencerminkan perilaku source terbaru.
