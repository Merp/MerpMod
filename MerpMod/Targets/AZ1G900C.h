#define MOD_ECUID F3E0129A96
#define MOD_DATE 14.10.17.17.40
#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Debug
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AZ1G900C
#define ECU_IDENTIFIER 7452584007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D47A0)
#define dRomHoleStart (0x000E2000)
#define pRamHoleStart (0xFFFFA6C0)
#define pRamHoleEnd (0xFFFFBF70)
#define sPull2DFloat (0x000BE844)
#define sPull3DFloat (0x000BE8F8)

/////////////////////
// Switch Hacks
/////////////////////

#define pSiDrive (0xFFFF617E)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00042B28)
#define sRevLimStart (0x00034FCC)
#define sRevLimEnd (0x0003500C)
#define pFlagsRevLim ((unsigned char*)0xFFFF77A0)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000049E8)
#define sMafCalc (0x0000498C)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C7688)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007AA04)
#define hCelSignal (0x0007AADC)
#define pCelSignalOem ((unsigned char*)0xFFFF9996)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00042654)
#define sWgdc (0x00013D70)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////


/////////////////////
// Timing Hacks
/////////////////////


/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF620B)
#define ResumeBitMask ((unsigned char)0x01)
#define pCoastFlags ((unsigned char*)0xFFFF620A)
#define CoastBitMask ((unsigned char)0x01)
#define pBrakeFlags ((unsigned char*)0xFFFF620C)
#define BrakeBitMask ((unsigned char)0x01)
#define pClutchFlags ((unsigned char*)0xFFFF67F3)
#define ClutchBitMask ((unsigned char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc4 ((float*)0xFFFF7C78)
#define pIam4 ((float*)0xFFFF2D28)
#define pEngineSpeed ((float*)0xFFFF6844)
#define pVehicleSpeed ((float*)0xFFFF6820)
#define pCoolantTemp ((float*)0xFFFF4140)
#define pAtmoPress ((float*)0xFFFF6AA0)
#define pManifoldAbsolutePressure ((float*)0xFFFF6450)
#define pIntakeAirTemp ((float*)0xFFFF4128)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4042)
#define pReqTorque ((float*)0xFFFF7FDC)
#define pThrottlePlate ((float*)0xFFFF6518)
#define pCurrentGear ((unsigned char*)0xFFFF6A31)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((unsigned char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2C34)
#define dLoadSmoothingB (0x000C2C30)
#define dLoadSmoothingAlt (0x000C2C2C)
#define dLoadSmoothingFinal (0x000C2C40)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x000100C0)
#define hMemoryReset (0x0000FB18)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011A64)

