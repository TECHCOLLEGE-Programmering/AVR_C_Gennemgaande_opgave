.include "m168def.inc"
.def timeCounter = r17        ;en timer p� r17
.def portbVar = r16            ;et sted at gemme v�rdigen for om den skal v�re slukket eller t�ndt
ser portbVar                ;setter all bitsne til 1
ldi timeCounter, 1         ;setter start v�rdigen
ldi r18, low(timeCounter || portbVar)
 
.ifdef r18

.else

.endif

main:                        ;main label
    out DDRB, portbVar        ;setter all til at v�re output
    jmp start                ;jmp til start

 

start:
    rjmp loop
    ldi timeCounter, 10     ;setter timmer
    com portbVar            ;inverter all i portbVal
    jmp start                ;g�r tilbage til starten

 


loop:                        ;loop label
    out PORTB, portbVar        ;tager v�rdigen fra portbVal (f�rste gang 0b11111111)
    dec timeCounter            ;t�ller counteren ned med 1
    brne loop                ;returner n�r r17 er p� 0
    ret
