.text
.global main
main:
 	sub sp, sp, 16
    str x30, [sp]

    adr x0, format
    adr x1, a
    bl scanf

    adr x0, format
    adr x1, b
    bl scanf

    adr x1, a
    adr x2, b
    ldr w1, [x1]
    ldr w2, [x2]

    add w1, w1, w2
    sxtw x1, w1
    adr x0, format
    bl printf

    ldr x30, [sp]
    add sp, sp, 16 
    ret 

.data
    format: .string "%d"
    a: .word 1
    b: .word 1