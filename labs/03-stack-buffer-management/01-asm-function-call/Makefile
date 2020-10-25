NASM = nasm
CC = gcc -no-pie

.PHONY: all clean

all: function_call

function_call: function_call.o

function_call.o: function_call.asm
	$(NASM) -f elf64 -o $@ $<

clean:
	-rm -f function_call.o function_call
	-rm -f *~
