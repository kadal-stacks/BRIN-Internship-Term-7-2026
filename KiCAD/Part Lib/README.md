<table align="center">
  <tr>
    <td align="center" valign="middle" width="33%">
      <a href="https://www.kicad.org/" title="KiCad">
        <img src="https://upload.wikimedia.org/wikipedia/commons/5/59/KiCad-Logo.svg" alt="KiCad" width="108">
      </a>
    </td>
    <td align="center" valign="middle" width="33%">
      <a href="https://www.st.com/content/st_com/en/about/st-trademark-list.html" title="STM32 trademark reference">
        <img src="../../assets/stm32-logo.svg" alt="STM32 butterfly emblem" width="68" height="68">
      </a>
    </td>
    <td align="center" valign="middle" width="33%">
      <a href="https://www.st.com/en/microcontrollers-microprocessors/stm32f103c8.html" title="Blue Pill STM32F103C8 module reference">
        <img src="Kicad-STM32/images/BluePill.JPG" alt="Blue Pill STM32 module 3D reference render" width="102">
      </a>
    </td>
  </tr>
</table>
<p align="center"><sub>STM32 Blue Pill / Black Pill reference · Arm Cortex core depends on the exact MCU variant</sub></p>

# KiCad Part Libraries

Folder ini mengelompokkan library komponen agar reusable antar-project.

<p align="center">
  <a href="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG"><img src="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BluePill.JPG" alt="STM32 Blue Pill board" width="35%"></a>
  <a href="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BlackPill.JPG"><img src="https://raw.githubusercontent.com/kadal-stacks/BRIN-Internship-Term-7-2026/main/KiCAD/Part%20Lib/Kicad-STM32/images/BlackPill.JPG" alt="STM32 Black Pill board" width="35%"></a>
</p>
<sub>Foto referensi nyata untuk modul yang direpresentasikan oleh library, bukan foto PCB buatan repository.</sub>

## Isi folder
- [Kicad-STM32](Kicad-STM32/README.md): simbol, footprint, dan model 3D untuk Blue Pill/Black Pill.
- [MCU_Custom.pretty](MCU_Custom.pretty/README.md): footprint MCU custom, termasuk outline/silkscreen Blue Pill.
- <code>MCU.kicad_sym</code>: symbol library kustom.
- <code>MCU.bak</code>: backup; periksa perbedaannya sebelum menjadikan sumber utama.

## Menggunakan
Tambahkan symbol lewat Preferences → Manage Symbol Libraries dan footprint lewat Preferences → Manage Footprint Libraries. Cocokkan nomor pin, pad, pitch, dan dimensi terhadap datasheet/modul fisik. Gunakan konfigurasi project-specific bila library hanya berlaku pada satu project.
