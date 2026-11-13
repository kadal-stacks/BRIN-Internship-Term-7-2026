<table align="center">
  <tr>
    <td align="center" valign="middle" width="33%">
      <a href="https://www.kicad.org/" title="KiCad">
        <img src="https://upload.wikimedia.org/wikipedia/commons/5/59/KiCad-Logo.svg" alt="KiCad" width="108">
      </a>
    </td>
    <td align="center" valign="middle" width="33%">
      <a href="https://www.st.com/content/st_com/en/about/st-trademark-list.html" title="STM32 trademark reference">
        <img src="../assets/stm32-logo.svg" alt="STM32 butterfly emblem" width="68" height="68">
      </a>
    </td>
    <td align="center" valign="middle" width="33%">
      <a href="https://www.st.com/en/microcontrollers-microprocessors/stm32f103c8.html" title="Blue Pill STM32F103C8 module reference">
        <img src="Part%20Lib/Kicad-STM32/images/BluePill.JPG" alt="Blue Pill STM32 module 3D reference render" width="102">
      </a>
    </td>
  </tr>
</table>
<p align="center"><sub>STM32 Blue Pill / Black Pill reference · Arm Cortex core depends on the exact MCU variant</sub></p>

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
