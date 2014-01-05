# MerpMod

MerpMod is a patch designed for Subaru ecu roms. The goal of this project is to bring advanced features to the oem ecu.

You may find more information at the RomRaider 32bit Speed Density forum: http://www.romraider.com/forum/viewforum.php?f=37

These Mods are applied or removed using the SharpTune application from http://github.com/Merp/SharpTune

Mods require custom definition files to edit and log. Please see the definition info below.

After patching, it is normal to receive a checksum error when opening the rom in ECUFlash. Always click yes to correct the checksum.

The default tables included in the mods ARE NOT BASE MAPS, you will need to FIND/CREATE YOUR OWN BASE MAP!!

# How to compile

This code can be compiled using a variety of different methods and toolchains. This will outline the method that I have used.

Download and install latest GNUSH toolchain and Renesas HEW IDE from http://www.kpitgnutools.com/

Clone this repository locally.

MerpMod depends on SharpTune and SubaruDefs to compile patches. 

Clone https://github.com/Merp/SubaruDefs

Clone https://github.com/Merp/SharpTune or download SharpTune.exe. Copy SharpTune.exe to the MerpMod base directory and run it. Select the previously cloned SubaruDefs repository as the definition repo from Menu->Settings->Definition Repo Location. Close SharpTune.

#Target ROM Selection

To select your target ROM, you must set the target rom placeholder (similar to an environment variable) for the ROM's CALID. TO do this, go to Setup->Customize->Placeholders

The following placeholders should be set by default.
Placeholder     Directory
TARGETROM       <YOUR ROM'S CALID>
TESTROMDIR      $(PROJDIR)\TestRom

#EcuMapTools

SharpTune allows users to import .map files, and converts these to .h header files for use in HEW. This conversion is defined by idatohew.xml.

Map files are imported from /SubaruDisassembly/Maps where / is the folder containing your cloned MerpMod repository.

Entries in the header are persistent (as long as they are defined in idatohew.xml) but are always overridden by entries in the map file! As such, Erroneous entries in the header file must be removed directly from the header file unless overridden by an entry in the map file.

#Build Phases

We need to create two phases, one to update and select the target headers before we compile the code (first build phase), and another to update and patch the rom with the code after it is compiled (last build phase)

To create a build phase: In HEW, select Build->Build Phases.. Click add, select Create new custom phase, then click next. Select 'Single Phase' and click next. Enter the appropriate information.

Target Selection phase:
Command: TargetSelection.bat (included in repo)
Initial Directory: $(PROJDIR)\Targets
Default Options: leave this blank
Environment Variables (VARIABLE = VALUE):
	BUILDCONFIG=$(CONFIGNAME)
	TARGETROM=$(TARGETROM)

Update Test Rom phase:
Command: Update.bat (included in repo)
Initial Directory: $(PROJDIR)\TestRom
Default Options: leave thsi blank
Environment Variables (VARIABLE = VALUE):
	BUILDCONFIG=$(CONFIGNAME)
	MMTEMPDIR=$(TEMPDIR)
	TARGETROM=$(TARGETROM)
	WORKSPDIR=$(WORKSPDIR)

#Linker Sections and Script

Linker sections are defined under Build->KPIT GNUSH [ELF] Toolchain..->Link/Library->Category:Sections

Sections should be organized as follows:
0x00000000 Zero
0x00000100 INTHandler
0x00E00000 RSTHandler
0x00F00000 DefinitionData
0x07001000 .text,.init,.fini,.got,.rodata,.eh_frame_hdr,.eh_frame,.jcr,.tors
0x0E005000 Misc
0x70000000 .data,.gcc_exc,.bss
0x73FFFBF0 .stack
0x80001000 MetaData

Linker script is set up under Category:Other. Under User Defined options, enter the following:
-e _ResetHandler -T "$(PROJDIR)\LinkerScript.txt"

##Build Configurations

Build configuration is passed to SharpTune and back, which determines the config header file used (to select features/options) and determine the appropriate output directories/filenames. e.g. Build config "Flash_Testing" will use Flash.h to select the features by preprocessor options, and after building produces patch files named <CALID>.MerpMod.Flash.Testing.<version>.patch that are saved in the Flash_Testing folder. Also, only "*_Testing" or "*_Release" configs produce definition files, so using "*_Debug" allows you to debug the code in HEW without generating a million useless definitions. More details on these later.

Configurations:

Gratis (Deprecated, succeeded by Flash):
Speed Density
Launch Control
Flat Foot Shift

Flash (stable):
Speed Density
Launch Control
Flat Foot Shift
CEL Flashing (2-stage FBKC, ECT, and more)

Switch: (alpha/untested)
Flash + Advanced Launch Control + 3x2 Map Switching/Blending

#Definitions

Definitions are available from https://github.com/Merp/SubaruDefs and are divided into three categories. First decide which you need.

    Stable: Thoroughly tested but limited in scope.
    Beta: Beta tested, contains some new experimental parameters but not everything. Download
    Alpha: Untested, contains the bleeding edge parameters. Recommended for advanced tuners or developers only! Download
    MerpMod: Based on Alpha, includes definitions for SharpTune Mods. Download

Click the appropriate download link above and extract this zip file to your SharpTune settings directory (default is /<username>/.sharptune/). Alternatively, save and extract wherever you like and point SharpTune’s Definition Repo Location to it (under the Settings menu).

ECU and Logger definitions are currently hosted on github.com. More information about git can be found here.
ECUFlash definition setup:

After extracting the ZIP, open ECUFlash settings and point the ‘rom metadata’ setting to the subdirectory ‘ECUFlash/subaru standard’. Currently, the metric definitions are incomplete! Note: RomRaider editor definitions are not included/supported/planned.
RomRaider logger definition setup:

After extracting the ZIP, open RomRaider settings and set the ‘logger definition location’ to the appropriate definition file. For MerpMod branch use ‘RomRaider/logger/MerpMod//<rom id here>.xml’. For all other branches use ‘RomRaider/logger/<select units and language>.xml


# Credits:
-Merp - SharpTune GUI Design, RomModCore upgrades, Subaru mod development

-NSFW - RomModCore (Previously RomPatch), Subaru mod development (Transition to HEW)

-Dschultz - XMLtoIDC and RomRaider

-Freon - Original SD assembly patch and disassembly information

-RomRaider.com forums


# License:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.