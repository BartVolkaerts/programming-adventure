CC=gcc
CFLAGS=-std=c99
LDFLAGS+=-lcheck
OBJECTS=llist 

all: $(OBJECTS)

llist: llist.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o $(OBJECTS) 
