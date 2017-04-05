;
; cs150hw6.asm
;
; Created: 11/1/2015 9:06:46 PM
; Author : Jonathan
;

init:
    ldi r16, 0x00 ; Zero Reg
    ldi r17, 0x20 ; LED Port Mask
    ldi r18, 0x00 ; Timer Flag Reg Holder
    ldi r19, 0x02 ; Timer Flag Reset Mask
    ldi r20, 0x3d ; Hi time comp val (for 1s) 1s->0x3d  test~>0x25
    ldi r21, 0x09 ; Lo time comp val (for 1s) 1s->0x09  test~>0x00
    ldi r22, 0x05 ; tccr1b val (prescaler to 1024)
    ldi r30, 0x00 ; GP Counter
    sts 0x0024, r17 ; store port mask at ddr
    sts 0x0089, r20 ; store hi time comp val
    sts 0x0088, r21 ; store lo time comp val
    sts 0x0080, r16 ; tccr1a
    sts 0x0081, r22 ; tccr1b set prescalar
    sts 0x0082, r16 ; tccr1c
    sts 0x0025, r16 ; PORTB all off (turns off LED)
    call wait1

main:
    call outH
    call outA
    call outN
    call outS
    call out3
    call out7
    call endPhrase
    rjmp main

outH:
    call dit
    call dit
    call dit
    call dit
    call endChar
    ret

outA:
    call dit
    call doo
    call endChar
    ret

outN:
    call doo
    call dit
    call endChar
    ret

outS:
    call dit
    call dit
    call dit
    call endChar
    ret

out3:
    call dit
    call dit
    call dit
    call doo
    call doo
    call endChar
    ret

out7:
    call doo
    call doo
    call dit
    call dit
    call dit
    call endChar
    ret

endPhrase: ; Wait 4 more units (endDit/Doo+endchar+4=7)
    eor r30, r30
    lendPhrase:
        call wait1
        inc r30
        cpi r30, 0x04
        brbc 1, lendPhrase
    ret

endChar: ; wait two more units (for letter gap)
    eor r30, r30
    lendChar:
        call wait1
        inc r30
        cpi r30, 0x02
        brbc 1, lendChar
    ret

dit: ; on one unit, off one unit
    sts 0x0025, r17 ; PORTB bit 5 ON
    call wait1 
    sts 0x0025, r16 ; PORTB all OFF
    call wait1
    ret

doo: ; on three units, off one unit
    sts 0x0025, r17 ; PORTB bit 5 ON
    eor r30, r30 ; zero the counter
    ldoo:
        call wait1 ; wait 1s
        inc r30 ; count that second
        cpi r30, 0x03 ; see if we've counted 3 seconds
        brbc 1, ldoo ; loop if SREG Z is 0 (compare did not return 0)
    sts 0x0025, r10 ; PORTB bit 5 OFF
    call wait1
    ret

wait1:
    sts 0x0036, r19 ; Reset Timer Flag
    sts 0x0085, r16 ; Timer16H Zero
    sts 0x0084, r16 ; Timer16L Zero
    lwait1:
        lds r18, 0x0036 ; Load Timer Flag to r18
        andi r18, 0x02 ; Mask r18 to just Timer16's flag bit
        cpi r18, 0x02 ; Compare with Timer16's flag bit
        brbc 1, lwait1  ; Loop if cpi didn't match
    ret



