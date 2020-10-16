/*
* seriel.asm
*
* Created: 04-11-2019 08:11:55
* Author : lkri
*/

.include "m168def.inc"

/*
* definere variabler
*/
.def	tmp=r16
.def	count1=r17
.def 	count2=r18
.def 	count3=r19

.org	0x0000
	
rjmp	start

.org	0x0034

/*
* Opsætning af USART Baud Rate Registers, se side 193
*/

start:
	clr	tmp
	sts	UBRR0H,tmp		; 4 bit UBRRnH, se side 193. Skal sættes til 0x00 først.
	ldi	tmp,0x67		; 9600 Baud = 0x67/D103 , se side 196
	sts	UBRR0L, tmp
	clr	tmp

	sts	UCSR0A,tmp		; Nulstilles. Se side 189
	ldi	tmp,0x08
	sts	UCSR0B,tmp		; TXENn: Transmitter Enable. Se side 190
	ldi	tmp,0x06		; 0x06 insættes i tmp
	sts	UCSR0C,tmp		; UCSZn1:0: Character Size. Se side 191-192

	ldi	tmp, 'A'

loop:
	sts	UDR0,tmp		; The USART Transmit Data Buffer Register. Se side 189.
						; Send bogstavet/ASCII værdien “A” til SRAM.
	inc tmp
	ldi  count1, 41
    ldi  count2, 150
    ldi  count3, 128

D1: dec  count3
    brne D1
    dec  count2
    brne D1
    dec  count1
    brne D1

rjmp loop