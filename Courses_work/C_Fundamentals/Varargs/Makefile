CC=gcc
CFLAGS=-std=c99
OBJECTS=oef2-1 oef2-2 oef2-3 oef2-4 oef2-5 oef2-6

all: $(OBJECTS)

oef2-1: oef2-1.o
	$(CC) $(CFLAGS) -o $@ $^
oef2-2: oef2-2.o
	$(CC) $(CFLAGS) -o $@ $^
oef2-3: oef2-3.o
	$(CC) $(CFLAGS) -o $@ $^
oef2-4: oef2-4.o
	$(CC) $(CFLAGS) -o $@ $^
oef2-5: oef2-5.o
	$(CC) $(CFLAGS) -o $@ $^
oef2-6: oef2-6.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -rf *.o $(OBJECTS) 
