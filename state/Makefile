CC = g++
CFLAGS = -Wall -g -O0 -I.

PROGRAM = demo

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp 
		$(CC) $(CFLAGS) -c $^ -o $@

clean:
		rm -f demo $(OBJS)

format:
		astyle *.cpp *.h
		rm -f *.orig

check: $(PROGRAM)
		valgrind --leak-check=yes ./$(PROGRAM)

.PHONY: clean format check
