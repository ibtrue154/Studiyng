.text
.global calculate
.global R
    calculate:
        adr x1, A
        adr x2, B
        adr x3, C
        adr x4, D
        adr x5, R
        ldr x1, [x1]
        ldr x2, [x2]
        ldr x3, [x3]
        ldr x4, [x4]
        mul x0, x1, x2
        mul x1, x3, x4
        add x0, x0, x1
        str x0, [x5]
        ret
.data
R: .quad