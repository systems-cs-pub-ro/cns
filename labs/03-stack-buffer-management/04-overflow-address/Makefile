CC = gcc
CFLAGS = -no-pie -Wall -Wextra -Wno-unused-function -Wno-unused-variable -g -O0 -fno-stack-protector
LDFLAGS = -no-pie

.PHONY: all clean

all: overflow_address

overflow_address: overflow_address.o

overflow_address.o: overflow_address.c

clean:
	-rm -f overflow_address.o overflow_address
	-rm -f *~
