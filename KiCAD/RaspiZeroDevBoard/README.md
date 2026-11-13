# Raspberry Pi Zero Dev Board

Carrier/development board untuk Raspberry Pi Zero dengan interface tambahan untuk akuisisi analog, komunikasi, RTC, display, dan distribusi daya.

## Preview area board

![Raspberry Pi Zero Dev Board measured outline](RaspiZeroDevBoard%20PCB%20Area.svg)

| Parameter | Nilai |
| --- | ---: |
| Lebar outline | 120.65 mm |
| Tinggi outline | 162.56 mm |
| Radius sudut | 6 mm |
| Luas bounding rectangle | 19,612.86 mm² |
| Koreksi empat sudut rounded | 30.90 mm² |
| **Luas bidang PCB aktual** | **19,581.96 mm²** |
| **Konversi** | **195.8196 cm²** |

Luas dihitung dari rounded-rectangle pada layer `Edge.Cuts` file `RaspiZeroDevBoard.kicad_pcb`:

`A = W × H − (4 − π)r²`

SVG adalah gambar ukur/preview vektor yang dibuat dari geometri CAD. Ini bukan foto produk, bukan render AI, dan bukan plot Gerber.

## Fungsi board

Schematic menunjukkan carrier board Raspberry Pi Zero dengan sejumlah interface eksternal:

| Blok | Komponen/label pada schematic | Fungsi yang dituju |
| --- | --- | --- |
| Host | J1, footprint Raspberry Pi Zero socketed | Koneksi modul Raspberry Pi Zero |
| ADC | U2 ADS1115, input ADC_Input0–ADC_Input3, R/C bertanda ADC_R/ADC_C | Empat kanal input analog melalui ADC eksternal |
| RTC | A2, Module_ZS-042 | Modul RTC DS3231 |
| RS-485 | U1, TLL_TO_RS-485 / module MAX485 | Interface komunikasi RS-485 |
| Display | A1, I2C-LCD1602 | Display karakter 16×2 melalui I²C |
| DC-DC | PS1, LM2596_Module | Modul regulator DC-DC |
| Serial/peripheral | Header UART, SPI, I²C | Akses interface peripheral |
| Power | Power_In, 5V Out, 3V3 Out | Input dan distribusi rail daya |
| User I/O | Tombol SW1/SW2, LED D1/D2, solder jumper | Kontrol lokal, indikator, dan konfigurasi board |

Schematic juga menunjukkan solder-jumper untuk pemilihan alamat ADS1115 (0x49, 0x4A, 0x4B), enable LED, enable button, RTC interrupt/SQW, dan arah RS-485. Nilai komponen bertanda generik seperti `ADC_R`, `ADC_C`, `I2C_R`, dan `R_LED` perlu diselesaikan pada BOM sebelum produksi.

## Catatan desain yang perlu diverifikasi

- Symbol J1 bernilai `Raspberry_Pi_4`, sedangkan footprint-nya bernama Raspberry Pi Zero. Pastikan symbol/value hanya label yang belum diperbarui atau memang perlu dikoreksi.
- Cek kebutuhan catu daya Raspberry Pi, distribusi 5V/3V3, rating modul LM2596, dan koneksi ground.
- Periksa mapping pin GPIO/peripheral Pi Zero terhadap header UART, SPI, I²C, ADC, dan RS-485.
- Pastikan resistansi pembagi/filter pada input ADS1115 dan rentang tegangan analog aman untuk input ADC.
- Pastikan konfigurasi jumper alamat ADS1115 tidak bertabrakan dan pull-up I²C sesuai bus.

## Status manufaktur

File project, schematic, dan PCB tersedia. Namun folder ini **belum berisi paket Gerber, file drill, atau screenshot area board asli**. SVG di atas hanya preview geometri dan perhitungan luas. Sebelum fabrikasi, jalankan ERC/DRC pada revisi terkini, plot seluruh layer Gerber, generate PTH/NPTH drill, lalu periksa hasilnya.

## File utama

- `RaspiZeroDevBoard.kicad_pro`
- `RaspiZeroDevBoard.kicad_sch`
- `RaspiZeroDevBoard.kicad_pcb`
- `RaspiZeroDevBoard PCB Area.svg`

---

[README KiCad](../README.md)
