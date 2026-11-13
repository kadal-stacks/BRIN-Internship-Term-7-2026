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
        <img src="../Part%20Lib/Kicad-STM32/images/BluePill.JPG" alt="Blue Pill STM32 module 3D reference render" width="102">
      </a>
    </td>
  </tr>
</table>
<p align="center"><sub>STM32 Blue Pill reference · STM32F103C8T6 · Arm® Cortex®-M3 core</sub></p>

# ATmega16–STM32 Breakout/Adapter

Desain adapter ini menyediakan breakout konektor untuk merutekan sinyal ATmega16 ke sisi header/board STM32. Fungsi utamanya adalah pemetaan dan routing sinyal, bukan konversi level tegangan.

## Varian

| Varian | Dokumentasi | Gerber | Area board |
| --- | --- | --- | ---: |
| SMD | [README SMD](ATMega16-STM32%20BP%20Adapter_SMD/README.md) | [ZIP manufaktur](ATMega16-STM32%20BP%20Adapter_SMD/ATMega16-STM32%20BP%20Adapter_SMD_Geber.zip) | **1,450.75 mm² / 14.5075 cm²** |
| THT | [README THT](ATMega16-STM32%20BP%20Adapter_THT/README.md) | Belum ada paket Gerber pada folder THT saat ini | Belum dihitung |

### Preview area PCB SMD

![Adapter SMD board-area drawing](ATMega16-STM32%20BP%20Adapter_SMD/Adapter%20PCB%20Area.png)

## Fungsi dan komponen utama

Pada varian SMD, schematic menggunakan empat konektor 1×20: dua socket dan dua pin header, beserta net-label port ATmega16, RESET, dan rail daya. Tidak terlihat IC level-shifter aktif pada schematic. Karena itu, board hanya merutekan koneksi; kompatibilitas logika 5 V dan 3.3 V harus diperiksa terpisah.

Mapping detail serta catatan pin khusus, AVCC, GND, dan alternate function dijelaskan dalam README varian SMD.
