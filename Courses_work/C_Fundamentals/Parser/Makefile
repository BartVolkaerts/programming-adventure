CC=gcc
CFLAGS=-std=c99 -g
OBJECTS=parser

all: parser

parser:	srecparser.o
	$(CC) $(CFLAGS) -o parser srecparser.o

srecparser.o:	srecparser.c srecparser.h
	$(CC) $(CFLAGS) -c srecparser.c

clean:
	rm -rf *.o $(OBJECTS) 
