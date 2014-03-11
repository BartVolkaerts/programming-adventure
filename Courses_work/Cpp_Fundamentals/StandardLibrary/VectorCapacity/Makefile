CXXFLAGS = -Wall -Wextra
CXX = clang++

all: 1 2 3

1: 1.o
	$(LINK.cc) $^ -o $@

2: 2.o
	$(LINK.cc) $^ -o $@

3: 3.o
	$(LINK.cc) $^ -o $@

clean:
	rm *.o
	rm 1 2 3
