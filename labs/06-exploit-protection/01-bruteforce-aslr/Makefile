CFLAGS = -m32 -Wall -Wextra -Wno-unused-function -Wno-unused-variable -g -O0
LDFLAGS = -m32 -z execstack

all: bruteforce buf

.PHONY: clean

bruteforce: bruteforce.o

bruteforce.o: bruteforce.c
	$(CC) -c $(CFLAGS) -fno-stack-protector -o $@ $<

buf: buf.c

clean:
	rm -f bruteforce buf
	rm -f *.o
