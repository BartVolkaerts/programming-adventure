CC=gcc
CFLAGS=-std=c99
OBJECTS=oef3-1 oef3-2 oef3-3 oef3-4 

all: $(OBJECTS)

oef3-1: oef3-1.o
	$(CC) $(CFLAGS) -o $@ $^
oef3-2: oef3-2.o
	$(CC) $(CFLAGS) -o $@ $^
oef3-3: oef3-3.o
	$(CC) $(CFLAGS) -o $@ $^ 
oef3-4: oef3-4.o
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	rm -rf *.o $(OBJECTS) 
