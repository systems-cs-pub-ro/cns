all: 640k

%: %.o
	$(CC) -no-pie -fno-pic  -fno-stack-protector -z execstack -o $@ $<

%.o: %.asm
	nasm -f elf64 $<

clean:
	rm -f 640k
