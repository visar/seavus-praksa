reset halt
flash probe 0
stm32f1x mass_erase 0
flash write_bank 0 main.bin 0
reset halt
