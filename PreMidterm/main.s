    .data
    .balign 4
n: .word 10
    .balign 4
sum: .word 0

    .text
    .global main
main:
        LDR R0, =n
        LDR R0, [R0]
        LDR R1, =sum
        LDR R1, [R1]
for:    cmp R0, #0
        BLE endloop
        ADD R1, R1, R0
        SUB R0, R0, #1
        BL for
endloop:
    BX LR
