#define MOD_ECUID 006F3884D5
#define MOD_DATE 14.10.17.17.16
#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Debug
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A2ZJ500I
#define ECU_IDENTIFIER 3112485106
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////


/////////////////////
// Switch Hacks
/////////////////////


/////////////////////
// Rev Limit Hack
/////////////////////


/////////////////////
// Speed Density Hack
/////////////////////


/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x0005CF14)

/////////////////////
// Cel Hacks
/////////////////////


/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////


/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFFAC3C)
#define pPolfEnrich (0xFFFFAC3C)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFFAF40)
#define pKcaIam (0xFFFFB074)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////


/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc4 ((float*)0xFFFFB030)
#define pIam4 ((float*)0xFFFF8550)
#define pManifoldAbsolutePressure ((float*)0xFFFFA528)
#define pEngineLoad ((float*)0xFFFFA6AC)
#define pReqTorque ((float*)0xFFFFB16C)
#define pThrottlePlate ((float*)0xFFFFA5B8)
#define pCurrentGear ((unsigned char*)0xFFFFA8D1)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////


/////////////////////
// Memory Reset
/////////////////////


