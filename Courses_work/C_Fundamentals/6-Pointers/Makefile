CC=gcc
CFLAGS=-std=c99
OBJECTS=oef6-1 oef6-2 oef6-3 oef6-4 oef6-5

all: $(OBJECTS)

oef6-2: oef6-2.o
	$(CC) $(CFLAGS) -o $@ $^
oef6-3: oef6-3.o
	$(CC) $(CFLAGS) -o $@ $^ 
oef6-4: oef6-4.o
	$(CC) $(CFLAGS) -o $@ $^ 
oef6-5: oef6-5.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -rf *.o $(OBJECTS) 
