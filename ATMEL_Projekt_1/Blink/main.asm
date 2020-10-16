;
; Blink.asm
;
; Created: 04-10-2019 11:33:27
; Author : lkri
;
	.include "m168def.inc"
	.include "macros.inc"
	.device ATmega168

start:
	.org 0x34
	rjmp main

main:
;  http://www.bretmulvey.com/avrdelay.html
 
.equ LED1 = 5

.def delay_0 = R17
.def delay_1 = R18
.def delay_2 = R19
   
init:
    LDI R16, 0xFF				;Load 0b 0b11111111 in R16
    OUT DDRB, R16				;1 --> Output    0 --> Input / Whole PortD is now configured as an Output port
 
loop:
    ldi delay_0, 128			;load delay_0 with values for 1s cycle
    ldi delay_1, 150
    ldi delay_2, 41
 
    sbi PINB, LED1				;toggle LED1
    rcall delay					;wait 1s
 
rjmp loop						;loop forever

delay:
    dec delay_0					;0 --> 255
    brne delay
 
    dec delay_1
    brne delay
 
    dec delay_2
    brne delay
ret