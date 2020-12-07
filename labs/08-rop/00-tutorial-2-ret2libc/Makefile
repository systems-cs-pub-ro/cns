CFLAGS = -Wall -Wextra -Wno-unused-function -Wno-unused-variable -g -O0 -fno-PIC -fno-stack-protector
LDFLAGS = -no-pie

all: ret2libc

.PHONY: clean

ret2libc: ret2libc.c

clean:
	rm -f ret2libc
	rm -f *.o
