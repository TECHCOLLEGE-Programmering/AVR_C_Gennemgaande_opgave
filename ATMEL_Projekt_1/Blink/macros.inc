/*
 * macros.inc
 *
 *  Created: 08-10-2019 11:09:00
 *   Author: lkri
 */

.macro LED12
	ldi r16, 0x20
	out DDRB, r16
	out PORTB, r16
	clr r16
.endmacro

.macro LED13
	ldi r16, 0x19
	out DDRB, r16
	out PORTB, r16
	clr r16
.endmacro

.macro LED12off

.endmacro

; ***** END OF FILE ******************************************************