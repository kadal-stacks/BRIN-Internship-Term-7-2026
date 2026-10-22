# ATmega16–STM32 Adapter (SMD)

Varian SMD untuk adapter breakout ATmega16–STM32.

<p align="center">
  <a href="https://www.mikroe.com/atmega16"><img src="https://cdn1-shop.mikroe.com/img/product/atmega16/atmega16-large_default-12x.jpg" alt="ATmega16 DIP-40 reference photo" width="35%"></a>
  <a href="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG"><img src="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG" alt="STM32 Blue Pill reference photo" width="35%"></a>
</p>
<sub>Foto referensi perangkat; bukan foto PCB proyek. Sumber: <a href="https://www.mikroe.com/atmega16">MikroE</a> dan aset Blue Pill pada repository.</sub>

## Komponen yang tampak pada schematic

- **J1–J4:** empat konektor 1×20 (Conn_01x20).
- **Net labels:** grup sinyal ATM16.PA, ATM16.PB, ATM16.PC, ATM16.PD, RESET, dan sinyal periferal.
- **Power symbols:** GND, 3V3, 5V/VCC, beserta PWR_FLAG untuk pemeriksaan ERC.
- Tidak ada IC level-shifter aktif atau simbol MCU STM32 eksplisit pada schematic SMD saat ini.

## File utama

- <code>ATMega16-STM32 BP Adapter_SMD.kicad_pro</code>: project.
- <code>ATMega16-STM32 BP Adapter_SMD.kicad_sch</code>: koneksi/net mapping.
- <code>ATMega16-STM32 BP Adapter_SMD.kicad_pcb</code>: layout PCB.
- <code>ATMega16-STM32 BP Adapter_SMD.csv</code>: tabel pendamping; periksa kolom dan konsistensinya sebelum dipakai.
- <code>fp-lib-table</code>: konfigurasi footprint library.

## Fungsi dan pengecekan

Board dimaksudkan untuk merutekan breakout sinyal dari satu sisi konektor ke sisi lain, bukan untuk mengubah level logika. Buka project, periksa setiap label/net, jalankan Update PCB from Schematic, lalu ERC dan DRC. Validasi pin 1, penomoran connector, lebar jalur suplai, clearance, dan dimensi mekanik.

**Peringatan:** pastikan kompatibilitas 5 V ATmega16 terhadap pin STM32 yang terhubung. Schematic tidak menampilkan level shifter. Jangan fabrikasi atau sambungkan ke MCU berdasarkan foto referensi saja.
