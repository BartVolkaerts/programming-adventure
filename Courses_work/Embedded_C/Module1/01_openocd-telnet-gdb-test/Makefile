TCPREFIX = arm-none-eabi-
CC      = $(TCPREFIX)gcc
LD      = $(TCPREFIX)ld -v
CP      = $(TCPREFIX)objcopy
OD      = $(TCPREFIX)objdump
GDBTUI  = $(TCPREFIX)gdbtui

STM32FLASH = ./stm32_flash.pl

# -mfix-cortex-m3-ldrd should be enabled by default for Cortex M3.
CFLAGS  =  -I. -c -fno-common -fno-unwind-tables -O0 -g -mcpu=cortex-m3 -mthumb
LFLAGS  = -Tstm32.ld -nostartfiles
CPFLAGS = -Obinary
ODFLAGS = -S

all: main.bin 
#run

clean:
	-rm -f main.lst *.o main.elf main.lst main.bin 

run: main.bin
	$(STM32FLASH) main.bin

main.bin: main.elf
	@echo ">>> COPYING"
	$(CP) $(CPFLAGS) main.elf main.bin
	$(OD) $(ODFLAGS) main.elf> main.lst

main.elf: main.o stm32.ld
	@echo ">>> LINKING"
	$(LD) $(LFLAGS) -o main.elf main.o

main.o: main.c
	@echo ">>> COMPILING"
	$(CC) $(CFLAGS) main.c

debug:
	$(GDBTUI) -ex "target remote localhost:3333" \ 
	-ex "set remote hardware-breakpoint-limit 6" \ 
	-ex "set remote hardware-watchpoint-limit 4" main.elf

