extern printf


SECTION .data

; message format for printf() call
message:	db	"Sum(%d) is %d", 10, 0

; number to get the sum to
num:		dd	100


SECTION .text
extern printf
global main

main:
	push rbp
	mov rbp, rsp

	; Use eax to compute sum. Sum is initially 0.
	xor rax, rax	; sum is initially 0

	; Use ecx as loop counter. Start from num and decrement to 0.
	mov rcx, [num]
compute_sum_loop:
	; For each step add current counter (ecx) to sum (eax).
	add rax, rcx
	loop compute_sum_loop

    ; Move arguments to registers (rdi = format, rsi = num, rdx = sum)
	; and call printf.
	mov rdx, rax
	mov rdi, message
	mov rsi, [num]
	call printf

	leave
	ret
