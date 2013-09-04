#define MOD_DATE 13.3.20.1128

/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CD7A0)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFF7400)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002150)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x000127E8)
#define sRevLimStart (0x000317D8)
#define sRevLimEnd (0x0003180E)
#define pFlagsRevLimit ((char*)0xFFFF5A30)
#define RevLimitBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00007A04)
#define sMafCalc (0x000079A8)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C6E3C)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007AEC4)
#define hCelSignal (0x0007AFDC)
#define pCelSignalOem ((char*)0xFFFF6FF2)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x000122B4)
#define sWgdc (0x00014B20)
#define dWgdcMax (0x00082C50)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF5874)
#define tPolf (0x000842DC)
#define pPolfEnrich (0xFFFF5874)

/////////////////////
// Timing Hacks
/////////////////////

#define dBaseTiming (0x0008493C)
#define pBaseTiming (0xFFFF5BE4)
#define pKcaIam (0xFFFF5D58)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF4D54)
#define ResumeBitMask ((char)0x04)
#define pCoastFlags ((char*)0xFFFF4D54)
#define CoastBitMask ((char)0x02)
#define pBrakeFlags ((char*)0xFFFF4D54)
#define BrakeBitMask ((char)0x08)
#define pClutchFlags ((char*)0xFFFF51B9)
#define ClutchBitMask ((char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF5334)
#define pFbkc4 ((float*)0xFFFF5D14)
#define pIam1 ((char*)0xFFFF5339)
#define pIam4 ((float*)0xFFFF267C)
#define pEngineSpeed ((float*)0xFFFF51E8)
#define pVehicleSpeed ((float*)0xFFFF51D8)
#define pCoolantTemp ((float*)0xFFFF2DC8)
#define pAtmoPress ((float*)0xFFFF2E34)
#define pManifoldAbsolutePressure ((float*)0xFFFF4F30)
#define pIntakeAirTemp ((float*)0xFFFF2DB8)
#define pMassAirFlow ((float*)0xFFFF2DF4)
#define pMafSensorVoltage ((short*)0xFFFF2D22)
#define pEngineLoad ((float*)0xFFFF50B0)
#define pReqTorque ((float*)0xFFFF5EF8)
#define pThrottlePlate ((float*)0xFFFF4FC0)
#define pCurrentGear ((char*)0xFFFF52E9)
#define pAf1Res ((float*)0xFFFF4A54)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2398)
#define dLoadSmoothingB (0x000C239C)
#define dLoadSmoothingFinal (0x000C23A0)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000F928)
#define hMemoryReset (0x0000D324)
#define pMemoryResetLimit (0xFFFFBFFB)
#define hMemoryResetLimit (0x0000FFF8)

