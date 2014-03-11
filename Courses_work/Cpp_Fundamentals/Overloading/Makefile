CXXFLAGS = -Wall -Wextra

all:	2 3

2: 2.o
	$(LINK.cc) $^ -o $@
	
3: 3.o
	$(LINK.cc) $^ -o $@

clean:
	rm 2 3
	rm *.o
