CXXFLAGS = -Wall -Wextra

all: 1 2

1: 1.o Class1.o 
	$(LINK.cc) $^ -o $@

2: 2.o TassString.o 
	$(LINK.cc) $^ -o $@

clean:
	rm *.o
	rm 1 2
