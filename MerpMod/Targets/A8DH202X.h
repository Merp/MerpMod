#define MOD_IDENTIFIER STRI(A8DH202X.MeRpMoD.Switch.Testing.v00.60.d14.12.9.2112)
#define MOD_ECUID 5AED006023
#define MOD_DATE 14.12.9.2112
#include "Switch.h"
#define MOD_CONFIG Switch
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A8DH202X
#define ECU_IDENTIFIER 4312584206
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CFB8C)
#define dRomHoleStart (0x000E1400)
#define pRamHoleStart (0xFFFF96C0)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002150)

/////////////////////
// Switch Hacks
/////////////////////

#define pTGVLeftVoltage ((unsigned short*)0xFFFF5C0A)
#define pTGVRightVoltage ((unsigned short*)0xFFFF5C0C)
#define sShortToFloat (0x00002594)
#define tTipInEnrich (0x0009508C)
#define tCrankingFuelA (0x00094CD0)
#define tCrankingFuelB (0x00094CE4)
#define tCrankingFuelC (0x00094CF8)
#define tCrankingFuelD (0x00094D0C)
#define tCrankingFuelE (0x00094D20)
#define tCrankingFuelF (0x00094D34)
#define tStartupEnrich2_1A (0x00094D98)
#define tStartupEnrich2_1B (0x00094DC0)
#define tStartupEnrich2_2A (0x00094DAC)
#define tStartupEnrich2_2B (0x00094DD4)
#define tStartupEnrich3_1A (0x00094D48)
#define tStartupEnrich3_1B (0x00094D5C)
#define tStartupEnrich3_2A (0x00094D70)
#define tStartupEnrich3_2B (0x00094D84)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00014EB4)
#define sRevLimStart (0x00033D68)
#define sRevLimEnd (0x00033D9E)
#define pFlagsRevLim ((unsigned char*)0xFFFF74EC)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00008314)
#define sMafCalc (0x000082B8)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C82E8)
#define hInjectorScaling (0x0002B738)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0008C1FC)
#define hCelSignal (0x0008C314)
#define pCelSignalOem ((unsigned char*)0xFFFF930E)

/////////////////////
// Boost Hacks
/////////////////////

#define hPullTargetBoost (0x00017750)
#define hTableTargetBoost (0x00017764)
#define tTargetBoost (0x000939C4)
#define hTableTargetBoostAlt (0x00017758)
#define tTargetBoostAlt (0x000939A8)

/////////////////////
// WGDC Hacks
/////////////////////

#define hPullWgdc (0x00017BCC)
#define hWgdc (0x00014964)
#define sWgdc (0x00017260)
#define sJsrWgdcInitial (0x00017AC2)
#define hTableWgdcInitial (0x00017BD4)
#define tWgdcInitial (0x0009391C)
#define tTableWgdcInitialAlt (0x00017BDC)
#define hJsrWgdcMax (0x00017B24)
#define hTableWgdcMax (0x00017C10)
#define tWgdcMax (0x00093954)
#define tWgdcMaxAlt (0x00093938)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF7324)
#define hPull3DPolf (0x000306A0)
#define tPolf (0x00095420)
#define hTablePolf (0x000306AC)
#define hJsrPolf (0x00030518)
#define hPolf (0x00014EE0)
#define sPolf (0x0003046C)
#define pPolfEnrich (0xFFFF7324)

/////////////////////
// Timing Hacks
/////////////////////

#define hBaseTiming (0x00014F9C)
#define hTableBaseTiming (0x00037DE0)
#define tBaseTiming (0x00095B28)
#define pBaseTiming (0xFFFF76A4)
#define sBaseTiming (0x00037C72)
#define hPull3DTiming (0x00037DDC)
#define hSubKca (0x00037654)
#define pKcaIam (0xFFFF7840)

/////////////////////
// Spark Cut
/////////////////////

#define sSparkCutOcrStart (0x0000A756)
#define sSparkCutOcrEnd (0x0000A76C)
#define sSparkCutGrStart (0x0000A7C6)
#define sSparkCutGrEnd (0x0000A7CE)

/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF64B0)
#define ResumeBitMask ((unsigned char)0x04)
#define pCoastFlags ((unsigned char*)0xFFFF64B0)
#define CoastBitMask ((unsigned char)0x02)
#define pBrakeFlags ((unsigned char*)0xFFFF64B0)
#define BrakeBitMask ((unsigned char)0x80)
#define pClutchFlags ((unsigned char*)0xFFFF69F1)
#define ClutchBitMask ((unsigned char)0x80)
#define pTestModeFlags ((unsigned char*)0xFFFF69EC)
#define TestModeBitMask ((unsigned char)0x20)
#define pDefogFlags ((unsigned char*)0xFFFF69EF)
#define DefogBitMask ((unsigned char)0x20)
#define pSSMResetByte ((unsigned char*)0xFFFF2D8E)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF6B6C)
#define pFbkc4 ((float*)0xFFFF77FC)
#define pIam1 ((unsigned char*)0xFFFF6B71)
#define pIam4 ((float*)0xFFFF2B3C)
#define pEngineSpeed ((float*)0xFFFF6A18)
#define pVehicleSpeed ((float*)0xFFFF6A10)
#define pCoolantTemp ((float*)0xFFFF67C4)
#define pAtmoPress ((float*)0xFFFF5CD4)
#define pManifoldAbsolutePressure ((float*)0xFFFF6698)
#define pIntakeAirTemp ((float*)0xFFFF5C9C)
#define pMassAirFlow ((float*)0xFFFF5CD0)
#define pMafSensorVoltage ((short*)0xFFFF5BFE)
#define pEngineLoad ((float*)0xFFFF6848)
#define pReqTorque ((float*)0xFFFF7AF0)
#define pThrottlePlate ((float*)0xFFFF673C)
#define pWgdc4 ((float*)0xFFFF63A0)
#define pCurrentGear ((unsigned char*)0xFFFF6B21)
#define pAf1Res ((float*)0xFFFF5F08)
#define pDeltaMap ((float*)0xFFFF668C)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((unsigned char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C23B8)
#define dLoadSmoothingB (0x000C23BC)
#define dLoadSmoothingFinal (0x000C23C8)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FCAC)
#define hMemoryReset (0x0000DBC8)
#define pMemoryResetLimit (0xFFFFBFBB)
#define hMemoryResetLimit (0x00012038)

