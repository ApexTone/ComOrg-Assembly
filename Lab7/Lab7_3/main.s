    .data
primes:
    .word 2
    .word 3
    .word 5
    .word 7

    .text
    .global main
main:
    LDR R3, =primes
    LDR R0, [R3, #4]  @R0 = Mem[R3+4] (primes[1])
end:
    BX LR
