CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-function -g -O0 -fno-stack-protector -no-pie
LDFLAGS = -no-pie

.PHONY: all clean

all: off_by_one

off_by_one: off_by_one.o

off_by_one.o: off_by_one.c

clean:
	-rm -f off_by_one.o off_by_one
	-rm -f *~
