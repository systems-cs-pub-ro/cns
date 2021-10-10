extern puts, read, printf, scanf, stdout, setvbuf
section .data
	quote: db "640k is enough for anyone!", 0
	give_option: db "Give option: ", 0
	give_index: db "Give index: ", 0
	read_digit: db "1. Read digit.", 0
	write_message: db "2. Write a message.", 0
	exit_message: db "3. Exit.", 0
	digit_scanf: db "%u", 0
	printf_fmt: db "index: %d addr: %p value: %c", 0xa, 0
	unk_opt: db "Unknown option!", 0
	opt: dd 0
	idx: dd 0
section .text
global main
print_menu:
	push rbp
	mov rbp, rsp
	mov rdi, give_option
	call puts
	mov rdi, read_digit
	call puts
	mov rdi, write_message
	call puts
	mov rdi, exit_message
	call puts
	leave
	ret
main:
	push rbp
	mov rbp, rsp
	sub rsp, 32
	mov ecx, 0x0
	mov edx, 0x2
	mov esi, 0x0
	mov rdi, [stdout]
	call setvbuf
	lea rdx, [rbp - 16] ; buf
	lea r14, [rbp - 24] ; digits
	mov byte [r14], '0'
	mov byte [r14 + 1], '1'
	mov byte [r14 + 2], '2'
	mov byte [r14 + 3], '3'
	mov byte [r14 + 4], '4'
	mov byte [r14 + 5], '5'
	mov byte [r14 + 6], '6'
	mov byte [r14 + 7], '7'
	mov rdi, quote
	call puts
forever:                    ; while (1)
	call print_menu
	mov rsi, opt
	mov rdi, digit_scanf
	call scanf
	mov eax, [opt]
	cmp eax, 1
	je opt_read_digit
	cmp eax, 2
	je opt_write_msg
	cmp eax, 3
	je away
	jmp opt_unk
	mov eax, 0
away:
	leave
	ret
opt_read_digit:
	mov rdi, give_index
	call puts
	mov rsi, idx
	mov rdi, digit_scanf
	call scanf
	xor rsi, rsi
	mov rsi, [idx]
	mov rcx, 0
	mov cl, byte[r14 + rsi]   ; digits[index]
	movzx ecx, cl
	lea rdx, [r14 + rsi]      ; &digits[index]
	mov rdi, printf_fmt
	call printf
	mov rax, 0
	jmp forever
opt_write_msg:
	mov rdx, 32
	lea rsi, [rbp - 16]
	mov rdi, 0
	call read
	jmp forever
opt_unk:
	mov rdi, unk_opt
	call puts
	jmp forever
