CC=gcc
CFLAGS=-std=c99 -g
OBJECTS=stack 

all: stack

stack:	stack_main.o stack.o llist.o
	$(CC) $(CFLAGS) -o stack stack_main.o stack.o llist.o

stack_main.o:	stack_main.c stack.h
	$(CC) $(CFLAGS) -c stack_main.c

stack.o:	stack.c stack.h llist.h
	$(CC) $(CFLAGS) -c stack.c

llist.o:	llist.c llist.h
	$(CC) $(CFLAGS) -c llist.c


clean:
	rm -rf *.o $(OBJECTS) 
