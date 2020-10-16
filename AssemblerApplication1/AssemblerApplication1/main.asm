;
; AssemblerApplication1.asm
;
; Created: 17-03-2020 09:27:09
; Author : lkri
;

.include "m168def.inc"

.def LED=r16			; Register r16, benævnes “LED”
						; i dette program
.org 0x0000				; Startvektoren i en ATMEGA168 er adresse
						; 0x0000. Første instruktion placeres på
						; denne adresse.
rjmp main				; Hop til memory adresse 0x0034. Dette er
						; den første program adresse efter
						; interrupt vektoerne.
.org 0x0034				; Selve programmet starter i
						; denne adresse
						; Første programinstruktion placeres på
						; denne adresse.
main: ser LED			; Sæt alle bit i register r16 til 1
						; r16 = ”11111111”13
out DDRB, LED			; Kopier data fra r16 til retningsregisteret i
						; PORTB. DDRB indeholder
						; nu værdien ”11111111”
loop: out PORTB, LED	; Kopier data fra r16 til PORTB. Herved
						; vil alle LED’s koblet til Port B tændes.
rjmp loop				; Hop tilbage til label “loop”
						; Uendelig loop.