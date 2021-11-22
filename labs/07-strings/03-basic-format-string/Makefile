CFLAGS = -Wall -fno-stack-protector -no-pie -zexecstack -g
LDFLAGS =  -no-pie -zexecstack

.PHONY: all clean

all: basic_format_string

basic_format_string: basic_format_string.o

basic_format_string.o: basic_format_string.c

clean:
	-rm -f *~
	-rm -f *.o
	-rm -f basic_format_string
	-rm -f .gdb_history
	-rm -f core
	-rm -f peda-session*.txt
