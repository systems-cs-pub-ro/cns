all: vuln getenv

%.o: %.asm
	nasm -f elf64 $<

%: %.o
	gcc -no-pie -fno-pic -fno-stack-protector -z execstack -o $@ $<

getenv: getenv.c
	gcc  -o $@ $<

clean:
	rm -f vuln.o vuln getenv
