.text

.global sum 

sum:
    mov x3, #0

    s:
        cmp x3, x1
        beq e
        add x3, x3, #1
        ldr w4, [x2]
        add w0, w0, w4
        add w2, w2, #4
        b s 
    e:
ret 