/*
	Copyright (C) 2012-2013 Merrill A. Myers III merrillamyersiii@gmail.com
	
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/

#include "EcuHacks.h"

//Define structures for definition output
typedef struct
{
	long op;
	long address;
	char name[];
} TableDef;

typedef struct
{
	long op;
	long coladdress;
	long dataaddress;
	char name[];
} Table2dDef;

typedef struct
{
	long op;
	long dataaddress;
	char name[];
} Table1dDef;

typedef struct
{
	long op;
	long address;
	char id[8];
	long buf;
	char storagetype[8];
	long buf2;
	char name[];
} ParamDef;

typedef struct
{
	long op;
	long address;
	char id[8];
	long buf;
	long bit;
	char name[];
} ParamBitDef;

typedef struct
{
	long op;
	long address;
	char name[];
} AxisDef;


enum DefOps
{
	OpIdent = 0x43210000,
	OpIdentAddr = 0x43210001,
	OpTable1d = 0x43210002,
	OpTable2d = 0x43210003,
	OpTable3d = 0x43210004,
	OpX = 0x43210005,
	OpY = 0x43210006,
	OpStaticY = 0x43210007,
	OpRAM = 0x43210008,
	OpRAMBit = 0x43210010,
	OpRAMAllBits = 0x43210011,
	OpEnd = 0x00090009,
};

typedef struct {
	long IdentOp;
	long IdentOffset;
	char Ident[ECU_IDENTIFIER_CHARS];
	long Identend;
	long InhOffset;
	char InhIdent[ECU_CALIBRATION_CHARS];
	long IdentIhnEnd;
	long InhEcuIdOffset;
	char InhEcuId[ECU_IDENTIFIER_CHARS];
	long EcuIdInhEnd; 
} DefMetaHeader;

/*const DefMetaHeader defmetaheader __attribute__ ((section ("DefinitionDataHeader"),aligned(4))) = 
{
	IdentOp:	OpIdent,
	IdentOffset:	DERP(dRomHoleStart),
	Ident:	STR(MOD_ECU_IDENTIFIER),
	Identend:	OpEnd,
	InhOffset:	0x0,
	InhIdent:	STR(ECU_CALIBRATION_ID),
	IdentIhnEnd:	OpEnd,
	InhEcuIdOffset:	0x0,
	InhEcuId:	STR(ECU_IDENTIFIER),
	EcuIdInhEnd:	OpEnd
);*/

#define DEFNEW1D(NAME,ADDR)	const TableDef ADDR##_1DDef DEFDATA =	{op: OpTable1d , address: (int)&ADDR , name: NAME }
#define DEFNEW2D(NAME,ADDR)	const TableDef ADDR##_2DDef DEFDATA =	{op: OpTable2d , address: (int)&ADDR , name: NAME }
#define DEFNEW3D(NAME,ADDR)	const TableDef ADDR##_3DDef DEFDATA =	{op: OpTable3d , address: (int)&ADDR , name: NAME }

#define DEFIDA1D(NAME,ADDR)	const TableDef ADDR##_1DDef DEFDATA =	{op: OpTable1d , address: (int)ADDR , name: NAME }
#define DEFIDA2D(NAME,ADDR)	const TableDef ADDR##_2DDef DEFDATA =	{op: OpTable2d , address: (int)ADDR , name: NAME }
#define DEFIDA3D(NAME,ADDR)	const TableDef ADDR##_3DDef DEFDATA =	{op: OpTable3d , address: (int)ADDR , name: NAME }

#define DEFINERAM(NAME,ADDR,TYPE,EID)	const ParamDef ADDR##_ParamDef DEFDATA =	{op: OpRAM , address: (int)ADDR , id: EID , buf: OpEnd , storagetype: TYPE , buf2: OpEnd, name: NAME }
#define DEFINERAMBIT(NAME,ADDR,BIT,EID)	const ParamBitDef ADDR##_ParamBitDef DEFDATA =	{op: OpRAMBit , address: (int)ADDR , id: EID , buf: OpEnd , bit: BIT , name: NAME }
#define DEFINERAMVAR(NAME,ADDR,TYPE,EID)	const ParamDef ADDR##_ParamDef DEFDATA =	{op: OpRAM , address: (int)&pRamVariables->ADDR , id: EID , buf: OpEnd , storagetype: TYPE , buf2: OpEnd, name: NAME }//TRY TO FIX THIS??
#define DEFINERAMVARARRAY(NAME,ADDR,INDEX,TYPE,EID)	const ParamDef ADDR##INDEX##_ParamDef DEFDATA =	{op: OpRAM , address: (int)&pRamVariables->ADDR[INDEX] , id: EID , buf: OpEnd , storagetype: TYPE , buf2: OpEnd name: NAME }//TRY TO FIX THIS??
#define DEFINERAMVARARRAYALLBITS(NAME,ADDR,INDEX,TYPE,EID)	const ParamDef ADDR##INDEX##_ParamDef DEFDATA =	{op: OpRAMAllBits , address: (int)&pRamVariables->ADDR[INDEX] , id: EID , buf: OpEnd , storagetype: TYPE , buf2: OpEnd, name: NAME }//TRY TO FIX THIS??
//TODO: in sharptune, if no match is found, create a new one to read out RAWDATA!

#if PORT_LOGGER
DEFINERAMVARARRAYALLBITS("MerpMod Port Logger A",PortParameters,0,"uint16","E");
DEFINERAMVARARRAYALLBITS("MerpMod Port Logger B",PortParameters,1,"uint16","E");
DEFINERAMVARARRAYALLBITS("MerpMod Port Logger C",PortParameters,2,"uint16","E");
DEFINERAMVARARRAYALLBITS("MerpMod Port Logger D",PortParameters,3,"uint16","E");
DEFINERAMVARARRAYALLBITS("MerpMod Port Logger E",PortParameters,4,"uint16","E");
DEFINERAMVARARRAYALLBITS("MerpMod Port Logger F",PortParameters,5,"uint16","E");
DEFINERAMVARARRAYALLBITS("MerpMod Port Logger G",PortParameters,6,"uint16","E");
DEFINERAMVARARRAYALLBITS("MerpMod Port Logger H",PortParameters,7,"uint16","E");
DEFINERAMVARARRAYALLBITS("MerpMod Port Logger J",PortParameters,8,"uint16","E");
DEFINERAMVARARRAYALLBITS("MerpMod Port Logger K",PortParameters,9,"uint16","E");
DEFINERAMVARARRAYALLBITS("MerpMod Port Logger L",PortParameters,10,"uint16","E");

#endif

#if RAM_HOLE_SCANNER
DEFINERAMVAR("MerpMod Ram Hole Scanner Address",ScannedAddress,"uint16","E");
DEFINERAMVAR("MerpMod Ram Hole Scanner Value",ScannedValue,"uint16","E");
//DEFINERAMVAR("MerpMod Ram Hole Scanner Composite",ScannedAddress,"uint32","E");
DEFINERAMVAR("MerpMod Ram Hole Scanner Stack Pointer",ScannedStackPointer,"uint32","E");
#endif

#if PROG_MODE
DEFINERAMVAR("MerpMod Prog Mode Entry",ProgModeEntry,"uint8","E");
DEFINERAMVAR("MerpMod Prog Mode Wait",ProgModeWait,"uint8","E");
DEFINERAMVAR("MerpMod Prog Mode Timer",ProgModeTimer,"uint8","E");
DEFINERAMVAR("MerpMod Prog Mode Enable",ProgModeEnable,"uint8","E");
DEFINERAMVAR("MerpMod Prog Mode Current Mode",ProgModeCurrentMode,"uint8","E");
DEFINERAMVAR("MerpMod Prog Mode Selected Value Flash",ProgModeValueFlashes,"uint8","E");
DEFINERAMVAR("MerpMod Prog Mode Value",ProgModeValue,"float","E");
#endif
	
DEFIDA1D("ECU Identifier",dEcuId);

//Engine load smoothing factors
DEFIDA1D("Engine Load Smoothing Factor A",dLoadSmoothingA);
DEFIDA1D("Engine Load Smoothing Factor B",dLoadSmoothingB);
#ifdef dLoadSmoothingAlt
	DEFIDA1D("Engine Load Smoothing Factor Alternate",dLoadSmoothingAlt);
#endif
#ifdef dLoadSmoothingAlt2
	DEFIDA1D("Engine Load Smoothing Factor Alternate B",dLoadSmoothingAlt2);
#endif
DEFIDA1D("Engine Load Smoothing Factor Final",dLoadSmoothingFinal);

//Switches/flags
// TODO UNCOMMENT THIS ONCE BITS ARE WORKING IN SHARPTUNE!!!
#ifdef pClutchFlags
DEFINERAMBIT("MerpMod Clutch Switch",pClutchFlags, ClutchBitMask,"E");
#endif

#ifdef pBrakeFlags
DEFINERAMBIT("MerpMod Brake Switch",pBrakeFlags, BrakeBitMask,"E");
#endif

#ifdef pResumeFlags
	DEFINERAMBIT("MerpMod Cruise Resume Switch",pResumeFlags, ResumeBitMask,"E");
#endif
#ifdef pCoastFlags
	DEFINERAMBIT("MerpMod Cruise Coast Switch",pCoastFlags, CoastBitMask,"E");
#endif
#ifdef pFlagsRevLim
	DEFINERAMBIT("MerpMod Rev Limit Fuel Cut Switch",pFlagsRevLim, RevLimBitMask,"E");
#endif

//VIN stuff	
#if VIN_HACKS && VIN_TEST_LOG
DEFINERAMVAR("MerpMod Vehicle Identifier",VehicleIdent,"uint28","E");
DEFINERAMVAR("MerpMod Auth Pass/Fail",VinAuth,"uint8","E");
#endif

#if SPARK_CUT
DEFINERAM("Default LC Spark Events Cut From",DefaultLCSparkEventsCutFrom,"uint8","E");
DEFINERAMVAR("LC Spark Events Cut From",SparkEventsX,"uint8","E");
#endif

#if SD_HACKS
DEFINERAMVAR("MerpMod SD Mode Switch",MafMode,"uint8","E");
DEFINERAMVAR("MerpMod SD Volumetric Efficiency",VolumetricEfficiency,"float","E");
DEFINERAMVAR("MerpMod SD Airflow Final Output",MafFromSpeedDensity,"float","E");
DEFINERAMVAR("MerpMod SD Airflow Maf Sensor",MafFromSensor,"float","E");
DEFINERAMVAR("MerpMod SD Atmospheric Compensation",AtmosphericCompensation,"float","E");
DEFINERAMVAR("MerpMod SD Blending Ratio",SDMafBlendRatio,"float","E");
DEFINERAMVAR("MerpMod SD Airflow Blending",SDMafFromBlend,"float","E");
DEFNEW3D("Volumetric Efficiency Table 1",VolumetricEfficiencyTable1);

#if SWITCH_HACKS
DEFNEW3D("Volumetric Efficiency Table 2",VolumetricEfficiencyTable2);
#endif

#if SD_DMAP
DEFINE3D("Delta MAP Compensation",SDDeltaMapTable);
DEFINERAM("MerpMod Delta MAP",pDeltaMap,"float","E");
DEFINERAMVAR("MerpMod Delta MAP Compensation Direct",DeltaMapCompensation,"float","E");
#endif

DEFNEW3D("Atmospheric Pressure Compensation",AtmosphericCompensationTable);
DEFNEW3D("SD Blending Table",SDBlendingTable);
DEFNEW1D("Engine Displacement",Displacement);
DEFNEW1D("Speed Density Mode",DefaultMafMode);
DEFNEW1D("Speed Density Constant",SpeedDensityConstant);

#if VE_RAMTUNING
DEFINERAMVAR3D("Volumetric Efficiencty Ram Table",VERamCols); //TODO this won't work yet!
DEFINERAMVAR("VERamFlag",VERamFlag,"uint8","E");
#endif	

#endif

#if REVLIM_HACKS
DEFNEW1D("Rev Limit (Redline)",DefaultRedLineCut);
#ifdef pCurrentGear
DEFNEW1D("Flat Foot Shift Mode",DefaultFlatFootShiftMode);
DEFNEW1D("Flat Foot Shift Delta (Automatic Limit)",DefaultFlatFootShiftAutoDelta);
#endif
DEFNEW1D("Flat Foot Shift Delta (Static Limit)",DefaultFlatFootShiftStaticDelta);	
DEFNEW1D("Flat Foot Shift Minimum Speed Threshold",DefaultFlatFootShiftSpeedThreshold);
DEFNEW1D("Flat Foot Shift Minimum RPM Threshold",DefaultFlatFootShiftRpmThreshold);
DEFNEW1D("LC Maximum Speed Threshold",DefaultLaunchControlSpeedMax);
DEFNEW1D("LC Minimum Throttle Threshold",LCMinimumThrottle);
DEFNEW1D("FFS Minimum Throttle Threshold",FFSMinimumThrottle);
#ifdef pCurrentGear
DEFNEW1D("FFS Gear Ratios",GearRatios);
#endif
DEFNEW1D("Rev Limit (Launch Control)",DefaultLaunchControlCut);	
	
	//PARAMS
DEFINERAMVAR("MerpMod FFS Mode",FlatFootShiftMode,"uint8","E");//TODO add to def base
DEFINERAMVAR("MerpMod LC Engaged Signal",LCEngaged,"uint8","E");
DEFINERAMVAR("MerpMod FFS Engaged Signal",FFSEngaged,"uint8","E");
DEFINERAMVAR("MerpMod FFS Gear Monitor",FFSGear,"uint8","E");
DEFINERAMVAR("MerpMod RevLimit Active Cut RPM",RevLimCut,"float","E");
DEFINERAMVAR("MerpMod RevLimit Active Resume RPM",RevLimResume,"float","E");
DEFINERAMVAR("MerpMod RedLine Cut RPM",RedLineCut,"float","E");
DEFINERAMVAR("MerpMod RedLine Hysteresis",RedLineHyst,"float","E");
DEFINERAMVAR("MerpMod Launch Control RPM",LaunchControlCut,"float","E");
DEFINERAMVAR("MerpMod Launch Control Hysteresis",LaunchControlHyst,"float","E");
DEFINERAMVAR("MerpMod FFS Delta (Auto)",FlatFootShiftAutoDelta,"float","E");
DEFINERAMVAR("MerpMod FFS Delta (Static)",FlatFootShiftStaticDelta,"float","E");
DEFINERAMVAR("MerpMod FFS Engagement RPM",FFSRPM,"float","E");
DEFINERAMVAR("MerpMod FFS Speed Threshold",FlatFootShiftSpeedThreshold,"float","E");
DEFINERAMVAR("MerpMod LC Speed Threshold",LaunchControlSpeedMax,"float","E");
#endif

#if LC_ADJUST
DEFNEW1D("Launch Control Adjustment Step",LCAdjustStep);
#endif

#if SWITCH_HACKS
DEFINERAMVAR("MerpMod Master Init Flag",MasterInitFlag,"uint8","E");
	
DEFINERAMVAR("MerpMod TGV Volts Left",TGVLeftVolts,"float","E");
DEFINERAMVAR("MerpMod TGV Volts Right",TGVRightVolts,"float","E");

DEFNEW2D("TGV Left Input Scaling",TGVLeftScaling);
DEFNEW2D("TGV Right Input Scaling",TGVRightScaling);

DEFNEW1D("Map Switch Input Threshold Low",MapSwitchThresholdLo);
DEFNEW1D("Map Switch Input Threshold High",MapSwitchThresholdHi);
DEFNEW1D("Map Switch Input Mode",MapSwitchInput);
DEFNEW1D("Map Blending Input Mode",BlendRatioInput);
DEFINERAMVAR("MerpMod Map Switch",MapSwitch,"uint8","E");
DEFINERAMVAR("MerpMod Map Blending Ratio",MapBlendRatio,"float","E");
DEFINERAMVAR("MerpMod TGV Left Scaled",TGVLeftScaled,"float","E");	
DEFINERAMVAR("MerpMod TGV Right Scaled",TGVRightScaled,"float","E");

DEFNEW1D("Default Map Blending Ratio",DefaultMapBlendRatio);
DEFNEW1D("Default Map Switch",DefaultMapSwitch);

#if INJECTOR_HACKS
DEFNEW2D("Map Blending Injector Scaling",InjectorScalingTable);
DEFINERAMVAR("MerpMod Injector Scaling",InjectorScaling,"float","E");
#endif

#endif

#if POLF_HACKS
DEFINERAMVAR("MerpMod LC Fueling Lock Enrichment",LCFuelLock,"float","E");
DEFINERAMVAR("MerpMod LC Fueling Mode",LCFuelMode,"float","E");
DEFINERAMVAR("MerpMod LC Fueling Enrichment",LCFuelEnrich,"float","E");
DEFINERAMVAR("MerpMod LC Fueling Enrichment Multiplier",LCFuelEnrichMultiplier,"float","E");	
DEFINERAMVAR("MerpMod Primary Open Loop Fueling Output",PolfOutput,"float","E");	
	
	//TODO add ENABLE SWITCHES
#if SWITCH_HACKS
DEFNEW1D("Primary Open Loop Fuel Hack Enable",DefaultPolfHackEnabled);
DEFNEW3D("Primary Open Loop Fueling Table 1 Intelligent",FuelTable1i);
DEFNEW3D("Primary Open Loop Fueling Table 2 Intelligent",FuelTable2i);
DEFNEW3D("Primary Open Loop Fueling Table 1 Sport",FuelTable1s);
DEFNEW3D("Primary Open Loop Fueling Table 2 Sport",FuelTable2s);
DEFNEW3D("Primary Open Loop Fueling Table 1 Sport Sharp",FuelTable1ss);
DEFNEW3D("Primary Open Loop Fueling Table 2 Sport Sharp",FuelTable2ss);
#else
DEFNEW3D("Primary Open Loop Fueling Table 1",FuelTable1i);	
DEFNEW3D("Primary Open Loop Fueling Table 2",FuelTable2i);	
#endif
DEFNEW3D("Launch Control Fuel Enrichment",LCFuelEnrichTable);	
DEFNEW1D("Launch Control Fueling Mode",DefaultLCFuelMode);	
DEFNEW1D("Launch Control Enrichment (Lock Mode)",DefaultLCFuelLock);	

#endif

#if PROG_MODE
#endif

#if SPARK_HACKS
#endif

#if CEL_HACKS
DEFNEW1D("FBKC Threshold",FBKCLoThreshold);	
DEFNEW1D("FBKC Flash Speed",FBKCLoFlashSpeed);	
DEFNEW1D("FBKC Flash Count",FBKCLoFlashes);	
DEFNEW1D("FBKC Severe Knock Threshold",FBKCHiThreshold);	
DEFNEW1D("FBKC Severe Knock Flash Speed",FBKCHiFlashSpeed);	
DEFNEW1D("FBKC Severe Knock Flash Count",FBKCHiFlashes);
DEFNEW1D("FBKC Load Threshold",FBKCLoadThreshold);
DEFNEW1D("IAM Flash Threshold",IAMFlashThreshold);
DEFNEW1D("IAM Flash Count",IAMFlashes);
DEFNEW1D("IAM Flash Speed",IAMFlashSpeed);

	
#ifdef pAf1Res
DEFNEW1D("EGT AF1 Resistance Threshold",EGTResistanceThreshold);
DEFNEW1D("EGT Flash Speed",EGTFlashSpeed);
DEFNEW1D("EGT Flash Count",EGTFlashes);

DEFNEW1D("EGT Load Threshold",EGTCelLoadThreshold);
#endif

DEFNEW1D("ECT Flash Speed",ECTFlashSpeed);
DEFNEW1D("ECT Flash Count",ECTFlashes);
DEFNEW1D("ECT Flash Temperature Threshold",ECTFlashThreshold);
	
#if defined(CRUISE_FLAGS) || defined (CRUISE_RESUME_FLAGS)
DEFNEW1D("IAM Recall Flash Speed",IAMFlashSpeed);
#endif

DEFINERAMVAR("MerpMod CEL Signal",CelSignal,"uint8","E");
DEFINERAM("MerpMod CEL Signal OEM",pCelSignalOem,"uint8","E");
DEFINERAMVAR("MerpMod CEL Flash Counter",CelFlashCounter,"uint8","E");
DEFINERAMVAR("MerpMod CEL Speed Counter",CelFlashSpeedCounter,"uint8","E");
	
#endif


#if BOOST_HACKS
DEFNEW1D("Boost Hack Enable",DefaultBoostHackEnabled);
DEFINERAMVAR("MerpMod PGWG Compensation",PGWGComp,"float","E");
#if SWITCH_HACKS
DEFNEW3D("Per Gear Wastegate Table 1 Intelligent",PGWGTable1i);
DEFNEW3D("Per Gear Wastegate Table 2 Intelligent",PGWGTable2i);
DEFNEW3D("Per Gear Wastegate Table 1 Sport",PGWGTable1s);
DEFNEW3D("Per Gear Wastegate Table 2 Sport",PGWGTable2s);
DEFNEW3D("Per Gear Wastegate Table 1 Sport Sharp",PGWGTable1ss);
DEFNEW3D("Per Gear Wastegate Table 2 Sport Sharp",PGWGTable2ss);
#else
DEFNEW3D("Per Gear Wastegate Table 1",PGWGTable1i);
DEFNEW3D("Per Gear Wastegate Table 2",PGWGTable2i);
#endif
DEFINERAMVAR("MerpMod PGTB Compensation",PGTBComp,"float","E");
#if SWITCH_HACKS
DEFNEW3D("Per Gear Target Boost Table 1 Intelligent",PGTBTable1i);
DEFNEW3D("Per Gear Target Boost Table 2 Intelligent",PGTBTable2i);
DEFNEW3D("Per Gear Target Boost Table 1 Sport",PGTBTable1s);
DEFNEW3D("Per Gear Target Boost Table 2 Sport",PGTBTable2s);
DEFNEW3D("Per Gear Target Boost Table 1 Sport Sharp",PGTBTable1ss);
DEFNEW3D("Per Gear Target Boost Table 2 Sport Sharp",PGTBTable2ss);
#else
DEFNEW3D("Per Gear Target Boost Table 1",PGTBTable1i);
DEFNEW3D("Per Gear Target Boost Table 2",PGTBTable2i);
#endif

DEFINERAMVAR("MerpMod Max WGDC Per Gear",WGDCMax,4,"E");
#if SWITCH_HACKS
DEFNEW3D("Max Wastegate Duty Compensation Table 1 Intelligent",WGDCMaxTable1i);
DEFNEW3D("Max Wastegate Duty Compensation Table 2 Intelligent",WGDCMaxTable2i);
DEFNEW3D("Max Wastegate Duty Compensation Table 1 Sport",WGDCMaxTable1s);
DEFNEW3D("Max Wastegate Duty Compensation Table 2 Sport",WGDCMaxTable2s);
DEFNEW3D("Max Wastegate Duty Compensation Table 1 Sport Sharp",WGDCMaxTable1ss);
DEFNEW3D("Max Wastegate Duty Compensation Table 2 Sport Sharp",WGDCMaxTable2ss);
#else
DEFNEW3D("Max Wastegate Duty Compensation Table 1",WGDCMaxTable1i);
DEFNEW3D("Max Wastegate Duty Compensation Table 2",WGDCMaxTable2i);
#endif

DEFINERAMVAR("MerpMod Initial WGDC Per Gear",WGDCInitial,"float","E");
#if SWITCH_HACKS
DEFNEW3D("Initial Wastegate Duty Compensation Table 1 Intelligent",WGDCInitialTable1i);
DEFNEW3D("Initial Wastegate Duty Compensation Table 2 Intelligent",WGDCInitialTable2i);
DEFNEW3D("Initial Wastegate Duty Compensation Table 1 Sport",WGDCInitialTable1s);
DEFNEW3D("Initial Wastegate Duty Compensation Table 2 Sport",WGDCInitialTable2s);
DEFNEW3D("Initial Wastegate Duty Compensation Table 1 Sport Sharp",WGDCInitialTable1ss);
DEFNEW3D("Initial Wastegate Duty Compensation Table 2 Sport Sharp",WGDCInitialTable2ss);
#else
DEFNEW3D("Initial Wastegate Duty Compensation Table 1",WGDCInitialTable1i);
DEFNEW3D("Initial Wastegate Duty Compensation Table 2",WGDCInitialTable2i);
#endif

DEFINERAMVAR("MerpMod Target Boost Output",TargetBoost,"float","E");
#if SWITCH_HACKS
DEFNEW3D("Target Boost Compensation Table 1 Intelligent",TargetBoostTable1i);
DEFNEW3D("Target Boost Compensation Table 2 Intelligent",TargetBoostTable2i);
DEFNEW3D("Target Boost Compensation Table 1 Sport",TargetBoostTable1s);
DEFNEW3D("Target Boost Compensation Table 2 Sport",TargetBoostTable2s);
DEFNEW3D("Target Boost Compensation Table 1 Sport Sharp",TargetBoostTable1ss);
DEFNEW3D("Target Boost Compensation Table 2 Sport Sharp",TargetBoostTable2ss);
#else
DEFNEW3D("Target Boost Compensation Table 1",TargetBoostTable1);
DEFNEW3D("Target Boost Compensation Table 2",TargetBoostTable2);
#endif
	
	#if WGDC_LOCK
DEFNEW1D("WGDC Lock Maximum RPM",RPMWGDCLock);
DEFNEW1D("WGDC Lock Minimum Throttle",ThrottleLockWGDC);
	#endif
#endif

#if TIMING_HACKS
DEFINERAMVAR("MerpMod LC Timing Mode",LCTimingMode,"uint8","E");
DEFINERAMVAR("MerpMod LC Timing Lock Value",LCTimingLock,"float","E");
DEFINERAMVAR("MerpMod LC Timing Retard",LCTimingRetard,"float","E");
DEFINERAMVAR("MerpMod LC Timing Retard Multiplier",LCTimingRetardMultiplier,"float","E");
DEFINERAMVAR("MerpMod Base Timing Final Output",TimingHackOutput,"float","E");
	
DEFNEW1D("Launch Control Timing Mode",DefaultLCTimingMode);
DEFNEW1D("Launch Control Timing Lock",DefaultLCTimingLock);	
DEFNEW1D("Default Launch Control Timing Retard Multiplier",DefaultLCTimingRetardMultiplier);
DEFNEW3D("Launch Control Timing Retard Table",LCTimingRetardTable);
	
#if SWITCH_HACKS
DEFNEW1D("Timing Hack Enable",DefaultTimingHackEnabled);
DEFNEW3D("Base Timing Table 1 Intelligent",TimingTable1i);
DEFNEW3D("Base Timing Table 2 Intelligent",TimingTable2i);
DEFNEW3D("Base Timing Table 1 Sport",TimingTable1s);
DEFNEW3D("Base Timing Table 2 Sport",TimingTable2s);
DEFNEW3D("Base Timing Table 1 Sport Sharp",TimingTable1ss);
DEFNEW3D("Base Timing Table 2 Sport Sharp",TimingTable2ss);
DEFNEW3D("Knock Correction Retard Table 1 Intelligent",KnockCorrectionRetardTable1i);
DEFNEW3D("Knock Correction Retard Table 2 Intelligent",KnockCorrectionRetardTable2i);
DEFNEW3D("Knock Correction Retard Table 1 Sport",KnockCorrectionRetardTable1s);
DEFNEW3D("Knock Correction Retard Table 2 Sport",KnockCorrectionRetardTable2s);
DEFNEW3D("Knock Correction Retard Table 1 Sport Sharp",KnockCorrectionRetardTable1ss);
DEFNEW3D("Knock Correction Retard Table 2 Sport Sharp",KnockCorrectionRetardTable2ss);
#else
DEFNEW3D("Base Timing Table 1",TimingTable1i);
DEFNEW3D("Base Timing Table 2",TimingTable2i);
DEFNEW3D("Knock Correction Retard Table 1",KnockCorrectionRetardTable1i);
DEFNEW3D("Knock Correction Retard Table 2",KnockCorrectionRetardTable2i);
#endif

#endif

#if SUB_KCA_HACKS
#endif

#if POLF_HACKS
#endif

#if INJECTOR_HACKS
#endif

#if MEMORY_HACKS
#endif

#if VE_RAMTUNING
#endif

#if POLF_RAMTUNING
#endif

#if TIMING_RAMTUNING
#endif

#if PGWG_RAMTUNING
#endif

#if WGDC_RAMTUNING
#endif


const long endofdeffile __attribute__ ((section ("DefinitionDataEnd"),aligned(4))) = 0x00090009;
const long endofdeffile1 __attribute__ ((section ("DefinitionDataEnd"),aligned(4))) = 0x00090009;
const long endofdeffile2 __attribute__ ((section ("DefinitionDataEnd"),aligned(4))) = 0x00090009;
const long endofdeffile3 __attribute__ ((section ("DefinitionDataEnd"),aligned(4))) = 0x00090009;
