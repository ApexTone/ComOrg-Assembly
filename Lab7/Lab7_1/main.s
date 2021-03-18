    .data
    .balign 4
fifteen:    .word 15
    .balign
thirty:     .word 30

    .text
    .global main
main:
    LDR R1, =fifteen
    LDR R1, [R1]
    LDR R2, =thirty
    LDR R2, [R2]
    ADD R0,R1,R2
end:
    BX LR
