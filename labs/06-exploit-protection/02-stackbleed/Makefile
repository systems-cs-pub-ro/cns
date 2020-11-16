CFLAGS = -Wall -Wextra -Wno-unused-function -Wno-unused-variable -g -O0
LDFLAGS = -z execstack

all: stackbleed

.PHONY: clean

stackbleed: stackbleed.o

stackbleed.o: stackbleed.c
	$(CC) -c $(CFLAGS) -fno-stack-protector -o $@ $<

clean:
	rm -f stackbleed
	rm -f *.o
