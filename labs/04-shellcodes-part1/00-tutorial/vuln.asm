extern gets
extern printf

section .data
formatstr: db "Enjoy your leak: %p",0xa,0

section .text
global main
main:
	push rbp
	mov rbp, rsp
	sub rsp, 64
	lea rbx, [rbp - 64]
	mov rsi, rbx
	mov rdi, formatstr
	call printf
	mov rdi, rbx
	call gets
	leave
	ret
