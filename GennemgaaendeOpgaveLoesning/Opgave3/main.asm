/*
 ********************* Opgave 3 ******************************
 * GennegåendeOpgaveLosning
 * Created: 26-04-21 15:07:40
 * Author : lkri
 * Created for Atmega168 Datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-9365-Automotive-Microcontrollers-ATmega88-ATmega168_Datasheet.pdf
 * May be copied and used with source reference.
 */ 

.include "m168def.inc"

.def LED = r16			; Register r16, benævnes “LED” i dette program

.equ LED13 = 0x20		; Værdien 0x20 (0b00100000) kan referers til ved LED13
						; i dette program
.org 0x0000				; Startvektoren i en ATMEGA168 er adresse 0x0000. 
						; Første instruktion placeres på denne adresse.
rjmp main				; Hop til memory adresse 0x0034. 
						; Dette er den første program adresse efter interrupt vektoerne.
.org 0x0034				; Selve programmet starter i denne adresse.
						; Første programinstruktion placeres på denne adresse.
main: ser LED			; Sæt alle bit i register r16 til 1 r16 = ”11111111”

out DDRB, LED			; Kopier data fra r16 til retningsregisteret i PORTB. 
						; DDRB indeholder nu værdien ”11111111”
ldi LED, LED13			; Værdien fra LED13 overføres til general perpose register 16.

loop: out PORTB, LED	; Kopier data fra r16 til PORTB. Herved
						; vil alle LED’s koblet til Port B tændes.
rjmp loop				; Hop tilbage til label “loop” Uendelig loop.