## MerpMod TODO


Short Term:
1. Add flex fuel tables for: Tip-in, CL ECT Comp, and Post-Start Enrichments.
2. Add switch to force open loop for tuning
3. Make map blending smarter. Should be able to handle open/short circuits.
4. Check functionality of re-enabling TGV CEL codes when using TGV input.

Mid Term:
1. FBKC disable for LC??
2. Document programming mode & ram tuning API, and idatohew instructions
3. Document sharptune API
4. Write new unit tests for: RamTuning, BoostHacks, FuelHacks, TimingHacks
5. Write a fuel-cut startup interlocker based on user defined input sequence
	-Will require some tricky memory management (reset clear, etc)
6. Figure out make-file building, use ENV vars to set TARGET ROM
7. Use a batch file to run multi-make-builds, set build config in ENV vars
	-This will require a new 'update-rom' batch file logic path to direct binary output (use ENV var in batch file!)

