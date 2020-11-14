CFLAGS = -Wall -Wextra -Wno-unused-function -Wno-unused-variable -g -O0
LDFLAGS = -z execstack

all: vulnerable vulnerable-ssp

.PHONY: clean

vulnerable: vulnerable.o
vulnerable-ssp: vulnerable-ssp.o

vulnerable.o: vulnerable.c
	$(CC) -c $(CFLAGS) -fno-stack-protector -o $@ $<

vulnerable-ssp.o: vulnerable.c
	$(CC) -c $(CFLAGS) -fstack-protector-all -o $@ $<

clean:
	rm -f vulnerable vulnerable-ssp
	rm -f *.o
