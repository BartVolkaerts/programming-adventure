CC=gcc
CFLAGS=-std=c99
OBJECTS=oef1-4

all: $(OBJECTS)

oef1-4: oef1-4.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -rf *.o $(OBJECTS) 
