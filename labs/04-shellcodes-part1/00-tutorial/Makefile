all: vuln test_shellcode shell.bin shellcode

vuln: vuln.asm
	nasm $< -f elf64
	gcc -no-pie -fno-pic  -fno-stack-protector -z execstack vuln.o -o $@

shell.bin: shellcode_exit.S
	nasm  $< -o $@

shellcode: shell.bin
	xxd -i $< > $@

test_shellcode: test_shellcode.c shellcode
	gcc -no-pie -o $@ $<

clean:
	rm -rf vuln vuln.o shell.bin test_shellcode shellcode
