.include "m168def.inc"
.def timeCounter = r17        ;en timer på r17
.def portbVar = r16            ;et sted at gemme værdigen for om den skal være slukket eller tændt
ser portbVar                ;setter all bitsne til 1
ldi timeCounter, 1         ;setter start værdigen
ldi r18, low(timeCounter || portbVar)
 
.ifdef r18

.else

.endif

main:                        ;main label
    out DDRB, portbVar        ;setter all til at være output
    jmp start                ;jmp til start

 

start:
    rjmp loop
    ldi timeCounter, 10     ;setter timmer
    com portbVar            ;inverter all i portbVal
    jmp start                ;går tilbage til starten

 


loop:                        ;loop label
    out PORTB, portbVar        ;tager værdigen fra portbVal (første gang 0b11111111)
    dec timeCounter            ;tæller counteren ned med 1
    brne loop                ;returner når r17 er på 0
    ret
