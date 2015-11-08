CC = g++
CFLAGS = -Wall -g -O0

PROGRAM = demo
HPP_FILES = $(wildcard *.hpp)
OBJS = $(patsubst %.hpp, %.o, $(HPP_FILES))

all: $(PROGRAM)

$(PROGRAM): demo.cpp $(OBJS)
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.hpp 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f demo $(OBJS)

format:
	astyle *.cpp *.hpp
	rm -f *.orig

check: $(PROGRAM)
	valgrind --leak-check=yes ./$(PROGRAM)

.PHONY: clean format check
