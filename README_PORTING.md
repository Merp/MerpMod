SCOPE: MerpMod (Flash build) analysis and mapfile creation.

Generate idc script using XMLtoIDC function of SharpTune
Open file and prepare analysis
Reference idatohew.xml and an existing mod header (use IDAtoHEW to create IDC script from header).


Calid: follow reference at end of rom


Ecuid: navigate to 2nd routine of ssm vector, byte referenced is start of ecuid


Rom Hole: Find the largest contiguous section of rom space filled with 0xFF and mark its start. You may find some XREFS in this area, but they are usually bitmasks which are incorrectly marked as XREFS, you should still check all of these. If there are any true XREFS, overwriting them may cause adverse unintended functionality! Because we check the contents while patching (must == 0xFF), overflow into used space is detected and there is no need to mark the end of the rom hole. Note: this assumes no valid XREFS in the romhole, so it is up to you to ensure none exist to prevent adverse unintended functionality!!


Ram Hole: Find the largest contiguous section of unreferenced RAM space. Take care not to mark a section that uses indirect or vbr referencing and do not use the stack's space! Typically the best area is near the end of the ram area (0xFFFF9000-0xFFFFA000 for SH7058) You may encounter bitmasks which are incorrectly marked as XREFS here as well. Because RAM cannot be checked for consistency while patching, mark the end of the ram hole as well! ALWAYS verify ram variables at ALL stages of testing (Flash test, idle test, drive test, etc)!! Corruption can cause adverse unintended functionality!!


Pull Functions: The ecu makes use of several interpolation subroutines that retrieve a map value given a lookup table (LUT) and axis lookup values. We are interested in Pull 2D float and Pull 3D float. You can find them by tracing references to known 2D and 3D tables. For example: MAF scaling will use Pull2DFloat and Target Boost will use Pull3DFloat.


MAF Hook: Follow references for MAF Scaling to find the MAF calculation routine. The routine is hooked through the XREF to Pull2DFloat. In text mode, click Pull2DFloat and scroll down until you see the offset referenced in sMafCalc highlighted, mark the offset (not the routine) as hMafCalc. Mark pMassAirFlow: Mark final value in sMafCalc, and pMafSensorVoltage: Mark input value in sMafCalc.


Rev Limit Hook: Follow references for Rev_Limit_Fuel_Cut to the rev limit routine and mark the start. Analyze the routine and mark the bitmask, appending _0xACTUALBITMASK to the end. Mark the flags set by the routine for fuel cut. Mark the last branch of this code as sRevLimEnd and make sure the name is marked non-local and included in names list (should appear as blue, not gray!). Mark the reference to sRevLimStart as hRevLimDelete.


CEL Hook: Start by searching for 009b1 and start from the end of the list. You are looking for the following pattern: 

sts.l 	pr, @-r15
bsr		sub1
nop
bsr		sub2
nop
bsr		sub3
nop
mov.l 	#unk_FFFF1234, r4
mov.w 	@r4, r2
extu.w 	r2, r2

sub3 in this pattern is sCelTrigger.

Another vector to find this is to search for the port address, which requires your ram segment to be the full range (0xFFFF0000 - 0xFFFFFFFF for SH7058). Try searching for F746.

The Ram address immediately after the port address is pCelSignalOEM. hCelSignal is the ref to this.


WGDC Hook: The WGDC hook is used by other parts of MerpMod as the 'main' routine that runs on a fixed timer. You must at least mark hWGDC and sWGDC! You will have to trace XREFS to the tables, then trace back until you find the routine called from from a large subroutine vector 'jump table'. This is sWGDC and the entry in the jump table vector is hWGDC.


Flags/Signals: Navigate to SsmGet_Switches_63... The ram references correspond to the switch numbers in the subroutine name. These will vary by ecu!
Switch number: Switch
63: Clutch Switch
64: Stoplight Switch
65: Cruise Set/Coast Switch
66: Cruise Accel/Resume Switch
67: Brake Switch

Mark these switches appropriately and mark their bitmasks. Older roms will use a single ram address with varying bitmasks for cruise switches, in this case mark it pCruiseFlags and mark the bitmasks appropriately. 


Engine Parameters: Some parameters will automatically be named by the XMLtoIDC script. Some will require manual marking. See XMLtoIDC. Unless otherwise noted below, mark the ram address referenced by the appropriate SSM routine.
MAF parameters are already marked in sMafCalc.


Engine Load Smoothing: Follow references for MAF Compensation (IAT) to find the Engine Load Calculation subroutine. You may need to mark as a subroutine (click first line of sub and press p). In graph view, look for the last set of branches on the bottom right before the routine consolidates. Engine load smoothing values are typically loaded into fr6 before a jsr @r12 opcode. Follow the naming convention in an existing mod definition. 


Memory Reset: Follow VBR Reset vector at end of rom (immediately before the CALID address) Typically the memory reset routine is the second routine called from the last routine in this routine. Look for a subroutine that references 0xFFFF4000 and 0xFFFFBFBB (SH7058). These are typically the reset limits. Mark the routine as sMemoryReset. Mark the reference to the high limit hMemoryResetLimit, and mark the actual limit address pMemoryResetLimit. Mark the data.l reference to sMemoryReset as hMemoryReset.


Generate a map file to use in your HEW environment!