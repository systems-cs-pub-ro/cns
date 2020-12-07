CFLAGS = -fno-PIC -Wall -Wextra -Wno-unused-function -Wno-unused-variable -fno-stack-protector -g -O0
LDFLAGS = -no-pie

all: ropchain

.PHONY: clean

ropchain: ropchain.c

clean:
	rm -f ropchain
	rm -f *.o
