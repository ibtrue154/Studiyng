.text
.global _main
.global main

.extern getchar_unlocked
.extern putchar_unlocked

main:
_main:
	sub sp, sp, 16
    str x30, [sp]
loop:
	bl getchar_unlocked
	cmp x0, #255
	bhi exit

    cmp x0, 48
    blt loop

    cmp x0, 57
    bgt loop

    bl putchar_unlocked

    b loop
	
exit:
	ldr x30, [sp]
    add sp, sp, 16 
    mov x0, 0
    ret