CC=gcc
CFLAGS=-std=c99
OBJECTS=oef3-2 oef3-3 oef3-4 oef3-5

all: $(OBJECTS)

oef3-2: oef3-2.o
	$(CC) $(CFLAGS) -o $@ $^
oef3-3: oef3-3.o
	$(CC) $(CFLAGS) -o $@ $^ 
oef3-4: oef3-4.o
	$(CC) $(CFLAGS) -o $@ $^ -lm
oef3-5: oef3-5.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -rf *.o $(OBJECTS) 
