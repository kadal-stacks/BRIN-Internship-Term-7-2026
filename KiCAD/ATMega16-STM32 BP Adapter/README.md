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
