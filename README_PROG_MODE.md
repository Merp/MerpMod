MerpMod Programming Mode
========================

Entering and Exiting
--------------------

Programming mode is entered and exited using the test mode connector. It is recommended to wire a switch to the connectors. Connecting the leads enters programming mode and puts the car into test mode limp. Disconnecting the leads exits. This does not interfere with the OEM test mode. If the ECU is started with test mode connectors connected, it WILL NOT enter programming mode.

Readout, Selection, and Adjustment
----------------------------------

Programming mode uses the CEL light to read out the current menu item and the current value of the selected menu item.

With the defog switch OFF, programming mode is in 'menu selection mode'. Current menu item is displayed by the count of SLOW flashes.

With the defog switch ON, programming mode is in 'value adjust mode'. Current selected menu item's VALUE is indicated by the count of FAST flashes.

To select the next menu item or increment (+) the value, press the cruise control resume button.

To select the previous menu item or decrement (-) the value, press the cruise control coast button.

Menu Items
----------

1. Map Switch (Intelligent / Sport / Sport Sharp)
2. Map Blending Input Mode (Undefined, TGV Left, TGV Right)
3. Map Blending (Map 1 / Map 2)
4. Launch Control Adjust
5. IAM Adjust
6. Valet Mode 
7. Hard Reset

1. Map Switch
----------

The currently selected map is displayed using the following values:
Intelligent: 1 flash
Sport: 2 flashes
Sport Sharp: 3 flashes

2. Map Blending Mode
--------------------

The current map blending mode is displayed using the current input mode value where:
1 flash = undefined
2 flashes = TGV Left
3 flashes = TGV Right

3. Map Blending
------------

The current map blending ratio is displayed using a value of 1-11 where:
1 flash = 1.0 (Map 1)
2 flashes = 1.1 (Blending)
3 flashes = 1.2 (Blending)
...	(Blending)
11 flashes = 2.0 (Map 2)

4. Launch Control Adjust
---------------------

The current launch control RPM is displayed in ranges of 1000 RPM where:
1 flash = 1000-2000 RPM
2 flashes = 2000-3000 RPM
3 flashes = 3000-4000 RPM
...

5. iAM Adjust
----------

The current IAM value is displayed in increments of 0.1 where:
1 flash = 0.0 IAM
2 flashes = 0.1 IAM
...
11 flashes = 1.0 IAM

6. Valet Mode
----------

The current valet mode is displayed as:

0 flashes = OFF
1 flash = ON

7. ECU Reset
----------

The current hard reset flag is displayed as:

0 flashes = OFF
1 flash = ON (Ram Variable reset occurs when key is cycled. Also performs SSM soft ecu reset. Resets MerpMod persistent ram variables [switch build with RAM_PERSIST=1])
