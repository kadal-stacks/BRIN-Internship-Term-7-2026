# ATmega16–STM32 Adapter (SMD)

Varian surface-mount device (SMD) untuk adapter ATmega16–STM32.

## File utama
- **ATMega16-STM32 BP Adapter_SMD.kicad_pro**: project KiCad.
- **ATMega16-STM32 BP Adapter_SMD.kicad_sch**: schematic.
- **ATMega16-STM32 BP Adapter_SMD.kicad_pcb**: PCB layout.
- **ATMega16-STM32 BP Adapter_SMD.csv**: data CSV pendamping, perlu dicek tujuan/kolomnya.
- **fp-lib-table**: konfigurasi footprint library proyek.

Buka file project, periksa mapping pin dan konektor, gunakan Update PCB from Schematic setelah perubahan, lalu jalankan ERC/DRC. Verifikasi footprint, solder mask, drill, clearance, dan dimensi sebelum fabrikasi. File .kicad_prl adalah setelan sesi lokal; file ~*.lck merupakan lock file KiCad saat file terbuka.

---

[README utama repositori](../../../README.md)
