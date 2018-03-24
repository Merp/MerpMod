/*
	Copyright (C) 2012-2013 Merrill A. Myers III merrillamyersiii@gmail.com
	
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/

#include "EcuHacks.h"// !Start Hook at 0x

#if SPARK_HACKS

asm("nop");
asm("nop");
asm(".long 0xFFFFFFFF");
asm("nop");
asm("nop");
asm("nop");
//long LCSECF  __attribute__ ((section ("SparkHacksData"),aligned(4))) = &(pRamVariables.SparkEventsX);
 
  
//void main () __attribute__ ((section ("SparkHacks"),aligned(4)));

 //void main()
//{ 
//long LCSECF = &(pRamVariables.SparkEventsX);
 //asm(".long 0xFFFFFFFF");
//asm("nop");
//asm("mov.l @(LCSECF), r0");
//asm("nop");
//}
/*asm("mov.l @%0, r0"
 :  no outputs 
 : "r" (LCSECF)
 :  no clobbered regs 
 );
 asm("nop");
}
asm("
.section SparkCutHookOCR,"ax"
nop
nop
nop
nop
nop
mov.l	(SparkCutASMOCR),r3
jsr		@r3
nop
bra		SparkCutHookOCREnd
nop
nop
nop
SparkCutASMOCR:
		.long	_SparkCutASMOCR
		nop
SparkCutHookOCREnd:!This shoudl land at ");


.section SparkCutHookGR,"ax"
!Start Hook at 
mov.l	(SparkCutASMGR),r3
jsr		@r3
nop
bra		SparkCutHookGREnd
nop
nop
SparkCutASMGR:
		.long	_SparkCutASMGR 	
nop
nop
SparkCutHookGREnd:	!MUST LAND on the branch
.short 0xA022		!REPLACE OLD BRANCH!!
nop




	

.section RomHole_SparkCutCode,"ax"

.global _SparkCutASMOCR,

_SparkCutASMOCR:

!OK TO USE:
!Registers:   r0, r1, r2, r3, r7, r13,
!DO NOT USE R4, R5, R6, R11, R12, R14
!Incoming:
!R12=cylinder

	!!!!!!!!!!!!!!!!!!!
	!!EXECUTE EXISTING CODE!!
	!!!!!!!!!!!!!!!!!!!!!
	bf/s	SkipOCR		! in existing code, branch if TCNT has reached OCR
	mov		r13, r3		!calculated ocr
	sub		r4, r3		!calculated ocr - tcnt
	exts.w	r3, r3	
	cmp/pz	r3	
	bt/s	NotReached		!branch if TCNT has not reached CALCulated OCR
	mov		r5, r3			
	mov		r4, r13			!Use TCNT if past calc ocr
NotReached:
	add		r6, r3
	mov.l	@(0x4,r3),r2	!pull ocr addr
	mov.w	r13, @r2		!Store value to OCR
	!!!!!!!!!!!!!
	!!END OF OEM CODE
	!!!!!!!!!!!!!!!!!	
	mov		r2, r13			!OCR address to r13
	mov.l	(GRCounter),r2				!running event counter for GR setting only STARTS @ 1
	mov.b	@r2, r1
	mov.l	(_LCSparkEventsToCut), r0 	!for RAM adjustment
!	mova	(LCSparkEventsToCut), r0	!Static # events to cut, STARTS @ 0
	mov.b	@r0, r2
	cmp/hi	r2, r1				!unsigned greater than
	bt/s	SkipOCR				!branch (SKIP CUT) if counter > # events to be cut
	nop	
CutSparkO:
	!Spark Cut code here
	mov.l	(_LCSparkCutFlag), r1
	mov.b	@r1, r0
	mov		#1, r2
	cmp/eq	r0,r2
	bf/s	SkipOCR			! Check cut flag, branchif notcutting
	nop
	mov		#3, r0			!use table to adjust this value!
	mov		r14, r2			!get current calc for GR *verified this is correct*
	mov.l	@(0x8,r3),r1	!pull GR addr, verified r3 is untouched
	add		r2, r0			!Add 3 to GR calc
	mov.w	r0, @r1
	mov.w	r2, @r13		!Store OCR
SkipOCR:
	!!! TCNT HAS EXCEEDED OCR IF YOU BRANCHED HERE INITIALLY
	!extu.b	r12, r3		!grab current cylinder
	!mov.l	(OCRCounter),r3				!running event counter for ENTIRE BRANCH, this always runs!	
	!mov.b	@r3, r1
	!add		#1, r1
	rts
	!mov.b	r1, @r3						!increment OCR counter
	nop
	
.align 4
	
.global _SparkCutASMGR,

_SparkCutASMGR:

!!HOOK A67C BRANCH - Setting of GR2.
!INCOMING:
	! incoming r4 is TCNT2 + 3, r14 is selected pulse offset+dwell termination counts
	! R12 is Current cylinder	

	!!This code sets flag for post-GR-set
	mov     #1, r0
	mov.b	r0, @(6,r7)	
	!!Examine the GR Counter		
	mov.l	(GRCounter),r11
	mov.b	@r11, r1		
	mov.l	(_LCSparkEventsToCut),r0	!RAM Variable	
	!mova	(LCSparkEventsToCut), r0	!Static # events to cut, STARTS @ 0
	mov.b	@r0, r2
	cmp/hi	r2, r1				!unsigned greater than
	bf/s	Skip				!branch to CUT if counter < total #events to be cut
	nop
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	!!NOT cuTTIng spark, finish OEM ROUTINE
	!!IF Cutting spark, skip this and leave
	!!GR set by OCR routine
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	mov     r14, r2
	sub     r4, r2
	exts.w  r2, r2
	cmp/pz  r2
	bt/s    loc_A68A
	nop
	mov     r4, r14
loc_A68A:
	add     r6, r5
	mov.l   @(8,r5), r3
	mov.w   r14, @r3	
	!!!!!!!!!!!!!!!!!!!!!!!!!!!
	!!UPDATE THE GR COUNTER
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Skip:
	add		#1, r1		!add to grcounter
	mov.l	(_LCSparkEventsCutFrom), r0 !RAM VARIABLE
	!mova	(LCSparkEventsCutFrom), r0	!Static # events to cut, STARTS @ 0
	mov.b	@r0, r2
	cmp/hi	r2, r1				!unsigned greater than 
	bt/s	GRCReset			!Reset counter if it hits limit
	nop
	rts
	mov.b	r1, @r11	!increment counter	
GRCReset:
	mov		#1, r0		!Counter is 1-based
	rts
	mov.b	r0, @r11 

.align 4

.global _LCSparkCutFlag, _LCSparkEventsToCut, _LCSparkEventsCutFrom
.global _DefaultLCSparkEventsToCut, _DefaultLCSparkEventsCutFrom

_LCSparkCutFlag:
	.long 0xFFFF9750
	
_LCSparkEventsToCut:        
	.long 0xFFFF9754 !Free Memory Location to store Current cylinder
	
_LCSparkEventsCutFrom:
	.long 0xFFFF9758 !Free Memory Location to store Current cylinder
	
GRCounter:
	.long 0xFFFF975C !Free Memory Location to store Current cylinder
	
_DefaultLCSparkEventsToCut:
	.byte	3;
	
_DefaultLCSparkEventsCutFrom:
	.byte	5;

.align 4

.end
*/

#endif
