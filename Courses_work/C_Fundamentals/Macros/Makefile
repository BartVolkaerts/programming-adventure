CC=gcc
CFLAGS=-std=c99 -DLOG_LEVEL=3
OBJECTS=oef1-1 oef1-2 oef1-3 oef1-4 oef1-5 oef1-6 oef1-7

all: $(OBJECTS)

oef1-1: oef1-1.o
	$(CC) $(CFLAGS) -o $@ $^
oef1-2: oef1-2.o
	$(CC) $(CFLAGS) -o $@ $^
oef1-3: oef1-3.o
	$(CC) $(CFLAGS) -o $@ $^
oef1-4: oef1-4.o
	$(CC) $(CFLAGS) -o $@ $^
oef1-5: oef1-5.o
	$(CC) $(CFLAGS) -o $@ $^
oef1-6: oef1-6.o
	$(CC) $(CFLAGS) -o $@ $^
oef1-7: oef1-7.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o $(OBJECTS) 
