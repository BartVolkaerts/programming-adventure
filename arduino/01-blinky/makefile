CC=avr-gcc

all: main

main: main.o uart.o
	$(CC) -mmcu=atmega328p main.o uart.o -o main

main.o: main.c uart.o
	$(CC) -Os -DF_CPU=16000000UL -mmcu=atmega328p -o main.o -c main.c

uart.o: uart.c
	$(CC) -Os -DF_CPU=16000000UL -mmcu=atmega328p -o uart.o -c uart.c


program:
	avr-objcopy -O ihex -R .eeprom main main.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 57600 -U flash:w:main.hex

clean:
	rm main main.o main.hex uart.o

