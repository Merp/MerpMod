#define MOD_DATE 13.5.22.2216

#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A2ZJB11J
#define ECU_IDENTIFIER 3D12594106
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CC6E4)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFF6F70)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002110)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x000121C8)
#define sRevLimStart (0x0002BA40)
#define sRevLimEnd (0x0002BA76)
#define pFlagsRevLim ((char*)0xFFFF5650)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000078AC)
#define sMafCalc (0x00007850)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C5BD0)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x00070B34)
#define hCelSignal (0x00070C4C)
#define pCelSignalOem ((char*)0xFFFF6BD2)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00011D34)
#define sWgdc (0x00013A8C)
#define tWgdcMax (0x000788C0)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF54E4)
#define pPolfEnrich (0xFFFF54E4)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF57E0)
#define pKcaIam (0xFFFF5910)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF4C0C)
#define ResumeBitMask ((char)0x04)
#define pCoastFlags ((char*)0xFFFF4C0C)
#define CoastBitMask ((char)0x02)
#define pBrakeFlags ((char*)0xFFFF4C0C)
#define BrakeBitMask ((char)0x08)
#define pClutchFlags ((char*)0xFFFF5039)
#define ClutchBitMask ((char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc4 ((float*)0xFFFF58BC)
#define pIam4 ((float*)0xFFFF2588)
#define pEngineSpeed ((float*)0xFFFF5068)
#define pVehicleSpeed ((float*)0xFFFF5058)
#define pCoolantTemp ((float*)0xFFFF2DC8)
#define pAtmoPress ((float*)0xFFFF2E34)
#define pManifoldAbsolutePressure ((float*)0xFFFF4DC0)
#define pIntakeAirTemp ((float*)0xFFFF2DB8)
#define pMassAirFlow ((float*)0xFFFF2DF4)
#define pMafSensorVoltage ((short*)0xFFFF2D22)
#define pEngineLoad ((float*)0xFFFF4F48)
#define pReqTorque ((float*)0xFFFF5AB4)
#define pThrottlePlate ((float*)0xFFFF4E50)
#define pCurrentGear ((char*)0xFFFF515D)
#define pAf1Res ((float*)0xFFFF4A48)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C1BE0)
#define dLoadSmoothingB (0x000C1BE4)
#define dLoadSmoothingFinal (0x000C1BE8)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000F7C4)
#define hMemoryReset (0x0000D1C0)
#define pMemoryResetLimit (0xFFFFBFFB)
#define hMemoryResetLimit (0x0000FE94)

