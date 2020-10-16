/*
 * macro.inc
 *
 *  Created: 16-10-2019 14:54:26
 *   Author: lkri
 */ 

 .macro delay
	ldi r29, 150			;load delay_0 with values for 1s cycle 0 --> 255
    ldi r30, 150
    ldi r31, 41

	dec r29
    brne delay
 
    dec r30
    brne delay
 
    dec r31
    brne delay
	clr r29
	clr r30
	clr r31
 .endmacro