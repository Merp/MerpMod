#define MOD_DATE 14.5.10.045

#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A2UG000L
#define ECU_IDENTIFIER 4B12785007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000D2494)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFFAD70)
#define pRamHoleEnd (0xFFFFB4D0)
#define sPull2DFloat (0x000020AC)
#define sPull3DFloat (0x00002160)

/////////////////////
// Switch Hacks
/////////////////////


/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x000156F4)
#define sRevLimStart (0x00038790)
#define sRevLimEnd (0x000387C0)
#define pFlagsRevLim ((unsigned char*)0xFFFF7AE8)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x0000845C)
#define sMafCalc (0x00008400)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C8914)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x00093114)
#define hCelSignal (0x0009322C)
#define pCelSignalOem ((unsigned char*)0xFFFFA01E)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x0009F7A8)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00015088)
#define sWgdc (0x0001701C)
#define tWgdcInitial (0x0009F770)
#define tWgdcMax (0x0009F738)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF78AC)
#define tPolf (0x000A1534)
#define pPolfEnrich (0xFFFF78AC)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF7CE4)
#define tBaseTimingPCruise (0x000A1D64)
#define tBaseTimingPNonCruise (0x000A1D80)
#define tBaseTimingRCruiseAvcs (0x000A1D9C)
#define tBaseTimingRNonCruiseAvcs (0x000A1DB8)
#define pKcaIam (0xFFFF7EFC)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF668F)
#define ResumeBitMask ((unsigned char)0x01)
#define pCoastFlags ((unsigned char*)0xFFFF668E)
#define CoastBitMask ((unsigned char)0x01)
#define pBrakeFlags ((unsigned char*)0xFFFF6690)
#define BrakeBitMask ((unsigned char)0x01)
#define pClutchFlags ((unsigned char*)0xFFFF6C89)
#define ClutchBitMask ((unsigned char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF6EFA)
#define pFbkc4 ((float*)0xFFFF7E98)
#define pIam1 ((unsigned char*)0xFFFF6EFF)
#define pIam4 ((float*)0xFFFF2F5C)
#define pEngineSpeed ((float*)0xFFFF6CD8)
#define pVehicleSpeed ((float*)0xFFFF6CAC)
#define pCoolantTemp ((float*)0xFFFF5CB4)
#define pAtmoPress ((float*)0xFFFF6F14)
#define pManifoldAbsolutePressure ((float*)0xFFFF6908)
#define pIntakeAirTemp ((float*)0xFFFF5CA4)
#define pMassAirFlow ((float*)0xFFFF5CD8)
#define pMafSensorVoltage ((short*)0xFFFF5C02)
#define pEngineLoad ((float*)0xFFFF6AD4)
#define pReqTorque ((float*)0xFFFF81A4)
#define pThrottlePlate ((float*)0xFFFF69A8)
#define pCurrentGear ((unsigned char*)0xFFFF6EAD)
#define pAf1Res ((float*)0xFFFF5F10)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2D34)
#define dLoadSmoothingB (0x000C2D30)
#define dLoadSmoothingAlt (0x000C2D2C)
#define dLoadSmoothingFinal (0x000C2D40)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FA60)
#define hMemoryReset (0x0000DD1C)
#define pMemoryResetLimit (0xFFFFBFBB)
#define hMemoryResetLimit (0x00012484)

