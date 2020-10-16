;
; ReadPin.asm
;
; Created: 10-10-2019 15:20:20
; Author : lkri
;
start:
	.include "m168def.inc"	;includes device dependensies 
	.equ BUT1 = 4			;pin 12
	.equ LED1 = 5			;pin 13
	.org 0x34				;sets orgin of code in program memory

init:
	ldi r16, 0b11101111		; 5th bit input
	out DDRB, r16			;loads r16 to Data Directive Register
	out PORTB, r16			;loads r16 to PORTB register
	clr r16					;clears register

;________Loop________
loop:
	sbic PINB, BUT1			;skips if register in I/O is clear
	sbi	PORTB, LED1			;sets bit of PORTB PIN5 in I/O register
	sbis PINB, BUT1			;skibs if register in I/O is set
	cbi PORTB, LED1			;clears bit Of PORTB PIN5 in I/O register
	rjmp loop				;jumps back to loop id