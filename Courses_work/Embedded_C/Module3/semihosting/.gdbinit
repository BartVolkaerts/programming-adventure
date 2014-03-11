 tar ext :3333
 monitor halt
 file out/main.elf
 load out/main.elf
 mon reset halt
 mon arm semihosting enable
 stepi
