<table align="center">
  <tr>
    <td align="center" valign="middle" width="33%">
      <a href="https://www.kicad.org/" title="KiCad">
        <img src="https://upload.wikimedia.org/wikipedia/commons/5/59/KiCad-Logo.svg" alt="KiCad" width="112">
      </a>
    </td>
    <td align="center" valign="middle" width="33%">
      <a href="https://www.st.com/stm32" title="STM32 by STMicroelectronics">
        <img src="../../assets/stm32-wordmark.svg" alt="STM32 wordmark" width="108">
      </a>
    </td>
    <td align="center" valign="middle" width="33%">
      <a href="https://support.arm.com/documentation/dui0552/a/introduction/about-the-cortex-m3-processor-and-core-peripherals" title="Arm Cortex-M3 processor documentation">
        <strong>Arm® Cortex®-M3</strong>
      </a>
    </td>
  </tr>
</table>
<p align="center"><sub>STM32 adalah keluarga MCU dari STMicroelectronics. STM32F103 menggunakan core Arm Cortex-M3.</sub></p>

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
