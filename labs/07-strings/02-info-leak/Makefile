CFLAGS =  -Wall -Wextra -std=gnu99 -fno-stack-protector -mpreferred-stack-boundary=3 -Wno-unused-function -no-pie -fno-PIC -g
LDFLAGS = -no-pie -fno-PIC

.PHONY: all clean

all: info_leak

info_leak: info_leak.o

info_leak.o: info_leak.c

clean:
	-rm -f *~
	-rm -f *.o
	-rm -f info_leak
	-rm -f .gdb_history
	-rm -f core
	-rm -f peda-session*.txt
