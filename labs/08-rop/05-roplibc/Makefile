CFLAGS = -fno-PIC -Wall -Wextra -Wno-unused-function -Wno-unused-variable -g -O0 -fno-stack-protector
LDFLAGS = -no-pie

all: roplibc

.PHONY: clean

roplibc: roplibc.c

clean:
	rm -f roplibc
	rm -f *.o
