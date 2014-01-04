# MerpMod

MerpMod is a patch designed for Subaru ecu roms. The goal of this project is to bring advanced features to the oem ecu.

You may find more information at the RomRaider 32bit Speed Density forum: http://www.romraider.com/forum/viewforum.php?f=37

# How to compile

This code can be compiled using a variety of different methods and toolchains. This will outline the method that I have used.
--

Download and install latest GNUSH toolchain and Renesas HEW IDE from http://www.kpitgnutools.com/

Clone this repository locally.

Open HEW and create a new workspace. Set the workspace to your local repo's PARENT folder and name the project/workspace the name of your repo's folder. Select the appropriate CPU (SuperH RISC engine) and toolchain (KPIT GNUSH [ELF]) and click OK. 

Select the appropriate CPU series (Subaru: SH2e) and CPU Type (512kb rom = SH7055f, 1024kb rom = SH7058F). Click Finish.

Right click the bold project name in the upper left tree-view, select 'Add Files' and add all files in the 'Source' directory.

TODO: list other files to add (target configs, linker script, idatohew, etc.)

TODO: Detail the placeholders

TODO: Set up the Linker sections and other toolchain options.

TODO: Build SharpTune and copy executables.

##Build Configurations
TODO: detail how the build configurations are set up and interact with SharpTune to determine the appropriate mod config header to include.

Gratis (stable):
Speed Density

Flash (stable):
Gratis + CEL Flashing

Switch: (alpha/untested)
Flash + Advanced Launch Control + 3x2 Map Switching/Blending

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