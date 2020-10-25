CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-function -g -O0 -fno-stack-protector -no-pie
LDFLAGS = -no-pie
.PHONY: all clean

all: overflow_ptr

overflow_ptr: overflow_ptr.o

overflow_ptr.o: overflow_ptr.c

clean:
	-rm -f overflow_ptr.o overflow_ptr
	-rm -f *~
