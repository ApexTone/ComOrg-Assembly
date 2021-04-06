	.data
intro: .asciz "Blinking LED with wiringPi\n"
errMsg: .asciz "Setting up problem... Abort!\n"
pin:	.int 7
i:	.int 0
duration:	.int 500
OUTPUT =1 @constant

	.text
	.global main
	.extern pinMode
	.extern delay
	.extern digitalWrite
	.extern printf
	.extern wiringPiSetup
main:
	PUSH {ip,lr}
	LDR R0, =intro
	BL printf
	BL wiringPiSetup
	MOV R1, #-1
	CMP R0, R1
	BNE init
	LDR R0, =errMsg
	BL printf
	B done
init:	LDR R0, =pin
	LDR R0, [R0]
	MOV R1, #OUTPUT
	BL pinMode
	LDR R4, =i
	LDR R4,[R4]
	MOV R5,#10
forLoop:
	CMP R4,R5
	BGE done
	LDR R0, =pin
	LDR R0, [R0]
	MOV R1, #1
	BL digitalWrite
	LDR R0, =duration
	LDR R0, [R0]
	BL delay
	LDR R0, =pin
	LDR R0, [R0]
	MOV R1, #0
	BL digitalWrite
	LDR R0, =duration
	LDR R0, [R0]
	BL delay
	ADD R4, #1
	B forLoop
done:
	POP {ip,pc}
	
