CC=gcc
CFLAGS=-std=c99
OBJECTS=hello_tass

all: $(OBJECTS)

hello_tass: hello_tass.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o $(OBJECTS) 
