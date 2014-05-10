!!
!!    This program is free software: you can redistribute it and/or modify
!!    it under the terms of the GNU General Public License as published by
!!    the Free Software Foundation, either version 3 of the License, or
!!    (at your option) any later version.
!!
!!    This program is distributed in the hope that it will be useful,
!!    but WITHOUT ANY WARRANTY; without even the implied warranty of
!!    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
!!    GNU General Public License for more details.
!!
!! This is rougly equivalent to "main" but with fewer instructions to step
!! through in the simulator when testing the code.

		.section	Zero,"ax"
!! Reset handler and stack pointer
		.long _ResetHandler
		.long 0xffff2000
!! Manual reset handler and stack pointer
		.long _ResetHandler
		.long 0xffff2000
!! Various exception handlers - this isn't all of them but it should suffice.
		.long IllegalInstructionHandler
		.long Reserved5Handler
		.long SlotIllegalInstructionHandler
		.long Reserved7Handler
		.long Reserved8Handler
		.long CpuAddressErrorHandler
		.long DmacAddressErrorHandler
		.long NmiHandler
		.long BreakHandler
		.long FpuExceptionHandler
		.long HudiHandler

		.section 	RSTHandler,"ax"
_ResetHandler:
				mov.l	Stack,r15
				mov.l	@r15,r15
				mov.l	SetValues,r0
				jsr		@r0
				nop
				
				!!mov.l	DemonstrateAssertionFailure, r0
				!!jsr		@r0
				!!nop
				
				mov.l	GenericTests,r0			
				jsr		@r0			
				nop
.stop:
				bra		.stop
				nop								
		.align 4
		
#include "TargetConfig.h"

Stack:
		.long	_ArchStackPointer
		
!! So you can't just "mov.l _SetValues,r0" (or any other function) since the
!! functions all live in other segments.  You get "pcrel too far" errors.
SetValues:
		.long	_SetValues
			
DemonstrateAssertionFailure:
		.long	_DemonstrateAssertionFailure

GenericTests:
		.long	_GenericTests	

!! Handlers for various exceptions and interrupts.  They do nothing, but 
!! at least you can know which exception or interrupt was triggered.
IllegalInstructionHandler:
		rte
		nop
		
Reserved5Handler:
		rte
		nop
		
SlotIllegalInstructionHandler:
		rte
		nop
		
Reserved7Handler:
		rte
		nop
		
Reserved8Handler:
		rte
		nop
		
CpuAddressErrorHandler:
		rte
		nop
		
DmacAddressErrorHandler:
		rte
		nop
		
NmiHandler:
		rte
		nop
		
BreakHandler:
		rte
		nop
		
FpuExceptionHandler:
		rte
		nop

HudiHandler:
		rte
		nop

		.end
		
		