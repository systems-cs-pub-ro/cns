CFLAGS = -fno-pic -Wall -Wextra -Wno-unused-function -Wno-unused-variable -g -O0  -fno-stack-protector
LDFLAGS = -no-pie

all: ropbuf
	cp ropbuf ropbuf_dbg
	execstack -s --set-execstack ropbuf
.PHONY: clean

ropbuf: ropbuf.c

clean:
	rm -f ropbuf ropbuf_dbg
	rm -f *.o

