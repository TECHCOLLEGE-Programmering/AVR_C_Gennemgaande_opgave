;
; Blink.asm
;
; Created: 04-10-2019 11:33:27
; Author : lkri
;
;  http://www.bretmulvey.com/avrdelay.html delay tool

start:
	.include "m168def.inc"		;includes device dependensies
	.equ LED1 = 5
	.def Delay1 = r18
	.def Delay2 = r19
	.def Delay3 = r20
	.def Delay4 = r21
	.org 0x34

.macro delay20MHz10Sec ;10sec on 20 MHz
    ldi  Delay1, 4
    ldi  Delay2, 247
    ldi  Delay3, 154
    ldi  Delay4, 155
L1: dec  Delay4
    brne L1
    dec  Delay3
    brne L1
    dec  Delay2
    brne L1
    dec  Delay1
    brne L1
    rjmp PC+1
.endmacro

.macro delay8MHz10Sec ;10sec on 8MHz 
    ldi  Delay1, 2
    ldi  Delay2, 150
    ldi  Delay3, 216
    ldi  Delay4, 9
L1: dec  Delay4
    brne L1
    dec  Delay3
    brne L1
    dec  Delay2
    brne L1
    dec  Delay1
    brne L1
    rjmp PC+1
.endmacro

.macro delay16MHz1Sec ;1sec on 16MHz
    ldi  Delay1, 82
    ldi  Delay2, 43
    ldi  Delay3, 0
L1: dec  Delay3
    brne L1
    dec  Delay2
    brne L1
    dec  Delay1
    brne L1
    lpm
    nop
.endmacro

init:
    ldi R16, 0xFF				;Load 0b 0b11111111 in R16
    out DDRB, R16				;1 --> Output    0 --> Input / Whole PortB is now configured as an Output port

;________Loop________
loop:
    sbi PINB, 5					;sets bit of PORTB PIN5 in I/O register
	delay16MHz1Sec				;Macro delay
rjmp loop						;loop forever
