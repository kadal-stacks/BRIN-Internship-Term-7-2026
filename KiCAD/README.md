<p align="center">
  <a href="https://commons.wikimedia.org/wiki/File:KiCad-Logo.svg" title="KiCad logo, KiCad Developers Team">
    <img src="https://upload.wikimedia.org/wikipedia/commons/5/59/KiCad-Logo.svg" alt="KiCad logo" width="150">
  </a>
</p>
<p align="center">
  <a href="https://www.st.com/content/st_com/en/about/st-trademark-list.html" title="STM32 trademark, STMicroelectronics">
    <img src="https://www.st.com/content/dam/aboutus/trademarks/stm32new-logo.png" alt="STM32 logo" height="48">
  </a>
  &nbsp;&nbsp;&nbsp;
  <a href="https://support.arm.com/documentation/dui0552/a/introduction/about-the-cortex-m3-processor-and-core-peripherals" title="Arm Cortex-M3 processor documentation"><strong>Arm® Cortex®-M3</strong></a>
</p>
<p align="center"><sub>STM32 adalah keluarga mikrokontroler dari STMicroelectronics. Arm menyediakan arsitektur dan desain core CPU; core yang digunakan bergantung pada seri/part number STM32. Contohnya, STM32F103 memakai Arm Cortex-M3. STM32 logo adalah identitas keluarga produk, sedangkan Arm Cortex-M3 di atas adalah nama core, bukan logo arsitektur STM32.</sub></p>


# KiCad Projects

Folder ini menampung schematic, PCB layout, library komponen, dan paket manufaktur dari proyek instrumentasi selama magang.

## Proyek

| Proyek | Fungsi | Status file manufaktur | Area outline PCB |
| --- | --- | --- | ---: |
| [ATmega16–STM32 Adapter (SMD)](ATMega16-STM32%20BP%20Adapter/ATMega16-STM32%20BP%20Adapter_SMD/README.md) | Breakout dan routing pin ATmega16 ke header STM32 | Gerber + drill tersedia | **1,450.75 mm² / 14.5075 cm²** |
| [Howland VCCS TL072 (THT)](Howland-VCCS/Howland-VCCS-TL072/README.md) | Voltage-controlled current source berbasis TL072 | Gerber + drill tersedia | **3,506.24 mm² / 35.0624 cm²** |
| [Howland VCCS TL072 (SMD/hybrid)](Howland-VCCS/Howland-VCCS-TL072_SMD/Howland-VCCS-TL072_SMD/README.md) | Varian Howland dengan resistor SMD dan IC/op-amp THT | Gerber + drill tersedia | **618.85 mm² / 6.1885 cm²** |
| [Impedance Meter Main Board](Impedance-meter2D_Main%20Board/README.md) | Workspace main board impedance meter | File manufaktur belum tersedia di folder | Belum dihitung |
| [Part Libraries](Part%20Lib/README.md) | Symbol, footprint, dan model 3D | Library | — |
| [Raspberry Pi Zero Dev Board](RaspiZeroDevBoard/README.md) | Carrier board Raspberry Pi Zero dengan ADC eksternal, RTC, interface serial, RS-485, LCD, dan rail daya | PCB tersedia; Gerber belum ada | **19,581.96 mm² / 195.8196 cm²** |
| [VCCS 2 Buffer](Howland-VCCS/VCCS%202%20Buffer/README.md) | Workspace schematic buffer berbasis AD826ANZ dan TL082 | PCB masih stub; Gerber/area belum tersedia | Belum dihitung |


### Area board yang sudah dihitung

Dimensi diambil dari geometri `Edge.Cuts` pada file PCB dan dicocokkan dengan layer Gerber profile. Ketiga outline berbentuk persegi panjang dengan empat sudut membulat. Area dihitung sebagai:

`A = (W × H) − (4 − π)r²`

dengan `W` dan `H` sebagai ukuran bounding rectangle dan `r` sebagai radius sudut. Nilai ini adalah luas bidang outline PCB, bukan luas komponen atau bounding box tanpa koreksi sudut.

## Workflow manufaktur KiCad

1. Buka file `.kicad_pro` dari folder proyek.
2. Validasi schematic, footprint, nomor pad, konektor, dan net.
3. Jalankan ERC untuk schematic dan DRC untuk PCB.
4. Plot layer Gerber yang diperlukan dan generate file drill PTH/NPTH.
5. Periksa file `Edge_Cuts.gbr`, `*.gbrjob`, dan arsip ZIP sebelum dikirim ke manufaktur.

Paket Gerber yang tersedia ditautkan dari README masing-masing proyek. Jangan menggunakan file dari folder atau revisi berbeda sebagai satu paket produksi.
