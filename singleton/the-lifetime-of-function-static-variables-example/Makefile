CC = g++
CFLAGS = -Wall -g -O0

PROGRAM = example 

all: $(PROGRAM)

$(PROGRAM): the-lifetime-of-function-static-variables-example.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAM) 

format:
	astyle *.cpp
	rm -f *.orig

check: $(PROGRAM)
	valgrind --leak-check=yes ./$(PROGRAM)

.PHONY: clean format check
