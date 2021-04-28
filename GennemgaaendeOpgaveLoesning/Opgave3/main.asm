/*
 ********************* Opgave 3 ******************************
 * Genneg�endeOpgaveLosning
 * Created: 26-04-21 15:07:40
 * Author : lkri
 * Created for Atmega168 Datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-9365-Automotive-Microcontrollers-ATmega88-ATmega168_Datasheet.pdf
 * May be copied and used with source reference.
 */ 

.include "m168def.inc"

.def LED = r16			; Register r16, ben�vnes �LED� i dette program

.equ LED13 = 0x20		; V�rdien 0x20 (0b00100000) kan referers til ved LED13
						; i dette program
.org 0x0000				; Startvektoren i en ATMEGA168 er adresse 0x0000. 
						; F�rste instruktion placeres p� denne adresse.
rjmp main				; Hop til memory adresse 0x0034. 
						; Dette er den f�rste program adresse efter interrupt vektoerne.
.org 0x0034				; Selve programmet starter i denne adresse.
						; F�rste programinstruktion placeres p� denne adresse.
main: ser LED			; S�t alle bit i register r16 til 1 r16 = �11111111�

out DDRB, LED			; Kopier data fra r16 til retningsregisteret i PORTB. 
						; DDRB indeholder nu v�rdien �11111111�
ldi LED, LED13			; V�rdien fra LED13 overf�res til general perpose register 16.

loop: out PORTB, LED	; Kopier data fra r16 til PORTB. Herved
						; vil alle LED�s koblet til Port B t�ndes.
rjmp loop				; Hop tilbage til label �loop� Uendelig loop.