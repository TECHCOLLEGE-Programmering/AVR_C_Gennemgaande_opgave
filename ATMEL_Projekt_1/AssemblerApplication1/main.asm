;
; AssemblerApplication1.asm
;
; Created: 02-04-2020 09:05:43
; Author : lkri
;

.include "m168def.inc" //Altid inkluder dependensis, de kan finde ude i solution explorer.

.def LED, r16 //giver r16 et navn

ser LED //LED = 0b11111111

out DDRB, LED  //DDRB = 0b11111111
out PORTB, LED //PORTB = 0b11111111

clr LED //LED = 0b00000000

loop1:
	inc LED //LED = LED + 1 = 0b00000001
	rjmp delay //kalder label delay
rjmp loop1 //looper forevigt

delay: //forsinker programmet med specifik en mængde af beregninger.
ldi r17, 128
	dec r17 //start værdi 128.
	brne delay //laver en branch fra label delay.
ret //returnere til tidligere program counter.