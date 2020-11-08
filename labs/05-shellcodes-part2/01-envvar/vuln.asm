extern printf, strncpy, exit

section .data
fmstr: db "Here's your leek: %p",0xa,0
section .text
global main
main:
    push rbp
    mov rbp, rsp
    sub rsp, 0x10
    mov [rbp-8], rdi
    mov [rbp-0x10], rsi

    lea rbx, [rbp - 0x10]         ; buf

    mov rdi,  [rbp-8]
    cmp rdi, 0x2
    jne away

    mov rsi, [rbp-0x10]   ; argv
    mov rcx, [rsi + 8]    ; argv[1] - source
    mov rsi, rcx

    mov rdi, rbx    ; destination
    mov rdx, 0x1e
    call strncpy
    leave
    ret
away:
    mov rdi, 1
    call exit
