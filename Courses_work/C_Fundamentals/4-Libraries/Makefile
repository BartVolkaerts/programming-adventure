CC=gcc
CFLAGS=-std=c99
OBJECTS=oef4-1 oef4-2 oef4-3 oef4-4 oef4-5

all: $(OBJECTS)

oef4-2: oef4-2.o
	$(CC) $(CFLAGS) -o $@ $^
oef4-3: oef4-3.o
	$(CC) $(CFLAGS) -o $@ $^ 
oef4-4: oef4-4.o
	$(CC) $(CFLAGS) -o $@ $^ 
oef4-5: oef4-5.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -rf *.o $(OBJECTS) 
