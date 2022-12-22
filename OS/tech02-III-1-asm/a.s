.intel_syntax noprefix
 
#include "sys/syscall.h"
 
.text
 
.global _start
 
_start:
 
    r:
        mov rax, 0
        sub rsp, 1000
        mov rdi, 0
        lea rsi, char
        mov rdx, 1000
        syscall
 
        cmp rax, 0
        jz f
 
        mov rdx, rax
        mov rax, 1
        mov rdi, 1
        lea rsi, char
        syscall  
 
        jmp r
 
    f:
        mov rax, SYS_exit     
        xor rdi, rdi              
        syscall
 
.bss
    char: .zero 1000