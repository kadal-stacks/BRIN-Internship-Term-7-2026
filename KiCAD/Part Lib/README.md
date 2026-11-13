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
  <a href="https://www.arm.com/company/policies/trademarks/guidelines-corporate-logo" title="Arm corporate logo guidelines">
    <img src="https://upload.wikimedia.org/wikipedia/commons/7/7a/Arm_logo_2025.svg" alt="Arm logo" height="38">
  </a>
</p>
<p align="center"><sub>STM32: microcontroller family by STMicroelectronics · Arm: CPU architecture and processor IP. The exact core depends on the STM32 part number; STM32F103 devices use an Arm Cortex-M3 core. Logos identify the referenced technologies and do not imply endorsement.</sub></p>


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
