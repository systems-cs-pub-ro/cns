CFLAGS = -m32 -Wall -Wextra -Wno-unused-function -Wno-unused-variable -g -O0
LDFLAGS = -m32 -z execstack

all: canary

.PHONY: clean

vulnerable3: canary.o

vulnerable3.o: canary.c
	$(CC) -c $(CFLAGS) -fstack-protector-strong -o $@ $<

clean:
	rm -f canary
	rm -f *.o

