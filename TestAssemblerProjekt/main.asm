;
; TestAssemblerProjekt.asm
;
; Created: 03-05-2021 11:25:10
; Author : ltpe
;

.include "m168def.inc"

.org	RWW_START_ADDR		; Startvektoren i en ATMEGA168/ATMEGA2560 er adresse 
									; $0000. Første instruktion placeres på 
									; denne adresse.
		jmp	start

.org	URXCaddr			; UART Receive Interrupt
		
;		jmp		USART_RXC_INTERRUPT
		

.org	INT_VECTORS_SIZE

; Replace with your application code
start:
	ldi	r16, 0Xff
	out	DDRB, r16
	out PORTB, r16

	out		SPL, r16            ; Stakken gror nedad i hukomelsen.
	out		SPH, r16

	in		r17, SPL
	in		r18, SPH

loop:
    inc r16
    rjmp loop
