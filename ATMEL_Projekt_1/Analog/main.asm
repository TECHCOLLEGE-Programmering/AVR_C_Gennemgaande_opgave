;
; Analog.asm
;
; Created: 16-10-2019 11:29:48
; Author : lkri
;

.macro delay
	ldi r20, 150			; load register with values for 1s cycle 0 --> 255
    ldi r21, 150
    ldi r22, 41

	dec r20
    brne delay
 
    dec r21
    brne delay
 
    dec r22
    brne delay

	clr r20
	clr r21
	clr r22
.endmacro

start:
	.include "m168def.inc"
	;.include "macro.inc"

	.equ LED1 = 5

	.def AnalogInput = r17

main:
	ldi r16, 0x00
	out DDRC, r16			; Data directive set to input
	ldi r16, 0xFF
	out DDRB, r16			; Data directive set to output

loop:
	in AnalogInput, PINC

	.if 4 <= 5
		sbi PINB, 5			; pin13
		delay
	.else
		sbi PINB, 3			; pin11
		;delay
	.endif
	rjmp loop