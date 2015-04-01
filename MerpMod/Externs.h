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

#include "enums.h"

//////////////////////////
//Function Prototypes
//////////////////////////

void ADCLogger() ROMCODE;
unsigned char TestBrakeSwitch()	ROMCODE;
//unsigned char BitTest(float* input, unsigned char bit) ROMCODE;
unsigned char TestClutchSwitch() ROMCODE;
unsigned char TestCruiseResumeSwitch() ROMCODE;
unsigned char TestCruiseMasterSwitch() ROMCODE;
unsigned char TestCruiseCoastSwitch() ROMCODE;
unsigned char TestDefoggerSwitch() ROMCODE;
unsigned char TestIdleSwitch() ROMCODE;
unsigned char TestNeutralSwitch() ROMCODE;
unsigned char DriveModeSwitch() ROMCODE;
unsigned char DriveModeSwitchAlt() ROMCODE;
void TestCruiseControlToggles() ROMCODE;

void Initializer()	ROMCODE;
void ClearRamVariables()	ROMCODE;
void PopulateRamVariables()	ROMCODE;
void ResetRamVariables() ROMCODE;
void InitRamVariables() ROMCODE;

void EcuHacksMain() ROMCODE;
void RevLimHook() ROMCODE;

float ComputeMassAirFlow(TwoDTable* MafScalingTable, float MafVoltage)  ROMCODE;
float CallSpeedDensityHook()  ROMCODE;
void CelDoubleRepeat(unsigned char * CelFlashes1, unsigned char Speed1, unsigned char * CelFlashes2, unsigned char Speed2, unsigned char Delay1, unsigned char Delay2)  ROMCODE;
void CelFlashStart(unsigned char CelFlashes, unsigned char Speed, unsigned char Delay, unsigned char Interrupt)  ROMCODE;
void CelFlash()	ROMCODE;
void WGDCHack(void) ROMCODE;
void TargetBoostHack(void) ROMCODE;
void POLFHack()  ROMCODE;
void InjectorHack() ROMCODE;
void DriveModeHack()  ROMCODE;
void LoadFuelLevels() ROMCODE;
void CheckFuelLevels() ROMCODE;
void FuelUp() ROMCODE;
void ALSRamTuning() ROMCODE;
void Mileage() ROMCODE;
void SSMHack1() ROMCODE;
void SSMHack2() ROMCODE;
void WGDCalt() ROMCODE;
void ThrottleKick() ROMCODE;
void AntiLag() ROMCODE;
void RollingAntiLag() ROMCODE;
void IdleTimingHack()  ROMCODE;
void FlexLearn() ROMCODE;
void FlexRatioUser() ROMCODE;
void FlexLearnStop() ROMCODE;
void FlexRoughCorrect() ROMCODE;
void FlexFineCorrect() ROMCODE;
void MemoryHardReset() ROMCODE;
void RotationalFuelCut() ROMCODE;
void DisplacementOnDemand() ROMCODE;
void ADHack() ROMCODE;
void Timer(float Minutes, float Seconds) ROMCODE;
void Timers(float Minutes, float Seconds, unsigned char Number) ROMCODE;
void Timer1(float Minutes, float Seconds) ROMCODE;
void Timer2(float Minutes, float Seconds) ROMCODE;
void Timer3(float Minutes, float Seconds) ROMCODE;
float TimingHack()  ROMCODE;
void RotationalSparkCut() ROMCODE;
float Pull2DRamHook(float* table, float xLookup) ROMCODE;
float Pull2DRamHookTipIn(float* table, float xLookup) ROMCODE;
float Pull2DRamHookCrankingFuel(float* table, float xLookup) ROMCODE;
float Pull2DRamHookStartupEnrich2(float* table, float xLookup) ROMCODE;
float Pull2DRamHookStartupEnrich3(float* table, float xLookup) ROMCODE;
float Pull3DRamHook(float* table, float xLookup, float yLookup) ROMCODE;
void VinCheck() ROMCODE;

void ProgModeListener()  ROMCODE;
void ProgModeMain()  ROMCODE;
void EnterProgMode()  ROMCODE;
void ExitProgMode()  ROMCODE;
void ProgModeCruiseToggled(unsigned char) ROMCODE;

void ProgModeMapSwitch()  ROMCODE;
void ProgModeBlendAdjust()  ROMCODE;
void ProgModeLCAdjust()  ROMCODE;
void ProgModeIAMAdjust() ROMCODE;
void ProgModeValetMode() ROMCODE;

void LCAdjustCruiseToggled(unsigned char) ROMCODE;

#if !AUTO_TRANS
void SetClutch(int value) __attribute__ ((section ("Misc")));
#endif
void SetBrake(int value) __attribute__ ((section ("Misc")));

float Abs(float input) ROMCODE;
float LowPass(float input, float limit) ROMCODE;
float HighPass(float input, float limit) ROMCODE;
unsigned short HighPassShort(unsigned short input, unsigned short limit) ROMCODE;
float BandPass(float input, float lowlim, float highlim) ROMCODE;
int BandPassInt(int input, int lowlim, int highlim) ROMCODE;
unsigned short BandPassShort(unsigned short input, unsigned short lowlim, unsigned short highlim) ROMCODE;
float Smooth(float smoothingFactor, float input, float previous) ROMCODE;

void RevLimCode(void) ROMCODE;
void RevLimReset(void) ROMCODE;

float BlendAndSwitch(TableGroup tg, float xLookup, float yLookup) ROMCODE;
float SwitchSelect(TableSubSet tss, float xLookup, float yLookup) ROMCODE;
void InputUpdate() ROMCODE;
void MapSwitchThresholdCheck(float input) ROMCODE;

//////////////////////////
//Extern Function Pointers
//////////////////////////
extern float (*Pull3DHooked)(ThreeDTable* table, float xLookup, float yLookup);
extern float (*Pull2DHooked)(TwoDTable* table, float xLookup);
extern float (*ShortToFloatHooked)(unsigned short input, float grad, float offs);
extern float (*FloatToShortHooked)(float input, float grad, float offs);

#define MafVoltageToInternalUnits 13107.20005368709

// Test utility functions.
void TestFailed(unsigned char *message) __attribute__ ((section ("Misc")));
void Assert(int condition, unsigned char *message) __attribute__ ((section ("Misc")));
int AreCloseEnough(float actual, float expected) __attribute__ ((section ("Misc")));


////////////////////
//TABLES
////////////////////

extern TableGroup VETableGroup;
extern ThreeDTable VolumetricEfficiencyTable1;
extern ThreeDTable VolumetricEfficiencyTable2;
extern ThreeDTable VolumetricEfficiencyRamTable;
extern ThreeDTable TemperatureCompensationTable;
extern ThreeDTable AtmosphericCompensationTable;
extern ThreeDTable SDBlendingTable;

extern TwoDTable InjectorScalingMultiplierTable;

extern unsigned char DefaultPolfHackEnabled;
extern TableGroup FuelTableGroup;
extern ThreeDTable FuelTable1i;
extern ThreeDTable FuelTable2i;
extern ThreeDTable FuelTable1s;
extern ThreeDTable FuelTable2s;
extern ThreeDTable FuelTable1ss;
extern ThreeDTable FuelTable2ss;
extern ThreeDTable LCFuelEnrichTable;
extern unsigned char DefaultLCFuelMode;
extern float DefaultLCFuelLock;
extern float PGFuelComp;
extern float DefaultLCFuelEnrichMultiplier;

extern TableGroup ReqTorqTableGroup;
extern ThreeDTable ReqTorqTable1v;
extern ThreeDTable ReqTorqTable1i;
extern ThreeDTable ReqTorqTable1s;
extern ThreeDTable ReqTorqTable1ss;

extern TableGroup AVCSTableGroup;
extern ThreeDTable AVCSTable1i;
extern ThreeDTable AVCSTable1s;
extern ThreeDTable AVCSTable1ss;
extern ThreeDTable AVCSTable2i;
extern ThreeDTable AVCSTable2s;
extern ThreeDTable AVCSTable2ss;
//extern TableGroup AVCSGear5TableGroup;
//extern ThreeDTable AVCSTable1Gear5;
//extern ThreeDTable AVCSTable2Gear5;

extern TableGroup PGWGTableGroup;
extern ThreeDTable PGWGTable1i;
extern ThreeDTable PGWGTable2i;
extern ThreeDTable PGWGTable1s;
extern ThreeDTable PGWGTable2s;
extern ThreeDTable PGWGTable1ss;
extern ThreeDTable PGWGTable2ss;

extern TableGroup PGTBTableGroup;
extern ThreeDTable PGTBTable1i;
extern ThreeDTable PGTBTable2i;
extern ThreeDTable PGTBTable1s;
extern ThreeDTable PGTBTable2s;
extern ThreeDTable PGTBTable1ss;
extern ThreeDTable PGTBTable2ss;

extern TableGroup TargetBoostTableGroup;
extern ThreeDTable TargetBoostTable1i;
extern ThreeDTable TargetBoostTable2i;
extern ThreeDTable TargetBoostTable1s;
extern ThreeDTable TargetBoostTable2s;
extern ThreeDTable TargetBoostTable1ss;
extern ThreeDTable TargetBoostTable2ss;

extern TableGroup WGDCInitialTableGroup;
extern ThreeDTable WGDCInitialTable1i;
extern ThreeDTable WGDCInitialTable2i;
extern ThreeDTable WGDCInitialTable1s;
extern ThreeDTable WGDCInitialTable2s;
extern ThreeDTable WGDCInitialTable1ss;
extern ThreeDTable WGDCInitialTable2ss;

extern TableGroup WGDCMaxTableGroup;
extern ThreeDTable WGDCMaxTable1i;
extern ThreeDTable WGDCMaxTable2i;
extern ThreeDTable WGDCMaxTable1s;
extern ThreeDTable WGDCMaxTable2s;
extern ThreeDTable WGDCMaxTable1ss;
extern ThreeDTable WGDCMaxTable2ss;

extern ThreeDTable PGWGRamTable;
extern ThreeDTable WGDCInitialRamTable;
extern ThreeDTable WGDCMaxRamTable;


extern unsigned char DefaultTimingHackEnabled;
extern float PGHighGearsTimingComp;
extern TableGroup TimingTableGroup;
extern ThreeDTable TimingTable1i;
extern ThreeDTable TimingTable2i;
extern ThreeDTable TimingTable1s;
extern ThreeDTable TimingTable2s;
extern ThreeDTable TimingTable1ss;
extern ThreeDTable TimingTable2ss;

extern TableGroup KnockCorrectionRetardTableGroup;
extern ThreeDTable KnockCorrectionRetardTable1i;
extern ThreeDTable KnockCorrectionRetardTable2i;
extern ThreeDTable KnockCorrectionRetardTable1s;
extern ThreeDTable KnockCorrectionRetardTable2s;
extern ThreeDTable KnockCorrectionRetardTable1ss;
extern ThreeDTable KnockCorrectionRetardTable2ss;

extern ThreeDTable FirstGearTimingAdditiveTable;
extern ThreeDTable SecondGearTimingAdditiveTable;

extern ThreeDTable LCTimingRetardTable;


extern float RPMLockWGDC;
extern float ThrottleLockWGDC;

extern float GearRatios[];

extern float FFSMinimumThrottle;
extern float LCMinimumThrottle;

#if SD_DMAP
extern ThreeDTable SDDeltaMapTable;
#endif

extern float CelsiusToKelvin;
extern float Displacement;
extern float SpeedDensityConstant;
extern unsigned char DefaultMafMode;

extern unsigned char DefaultLCTimingMode;
extern float DefaultLCTimingLock;
extern float DefaultLCTimingRetardMultiplier;
extern float DefaultMaxSubtractiveKCA;

extern float DefaultInjectorScaling;

extern float RPMLockWGDC;
extern float ThrottleLockWGDC;

extern float DefaultBlend;
extern int IAMFailSafe;

//Spark Cut defaults
extern char* LCSparkCutFlag;
extern char* LCSparkEventsToCut;
extern char* LCSparkEventsCutFrom;
extern unsigned char DefaultLCSparkEventsToCut;
extern unsigned char DefaultLCSparkEventsCutFrom;

//CEL flash defaults
extern unsigned char FBKCLoFlashes;
extern unsigned char FBKCLoFlashSpeed;
extern unsigned char FBKCHiFlashes;
extern unsigned char FBKCHiFlashSpeed;
extern unsigned char EGTFlashes;
extern unsigned char EGTFlashSpeed;
extern unsigned char IAMFlashSpeed;
extern unsigned char IAMFlashes;
extern float IAMFlashThreshold;
extern unsigned char ECTFlashes;
extern unsigned char ECTFlashSpeed;
extern float ECTFlashThreshold;
extern float FBKCLoThreshold;
extern float FBKCHiThreshold;
extern float FBKCLoadThreshold;
extern float EGTCelLoadThreshold;
extern float EGTResistanceThreshold;

extern unsigned char ShiftLightFlashes;
extern float DefaultShiftLightRPM;
extern unsigned char ShiftLightFlashSpeed;
extern unsigned char KillModeFlashes;
extern unsigned char KillModeFlashSpeed;
extern unsigned char FlexLearnFlashes;
extern unsigned char FlexLearnFlashSpeed;
extern unsigned char ShiftLightEnabled;
extern ThreeDTable ShiftLightRPMs;


#if ALS_HACKS
extern float DefaultALSBoostLimit;
extern float DefaultALSFuelLock;
extern float DefaultRIMFuelLock;
extern float DefaultALSTimingLock;
extern float DefaultRIMTimingLock;
extern float DefaultALSTargetIdleSpeed;
extern float DefaultALSTargetIdleSpeedFCRI;
extern float FuelRatio1;
extern float FuelRatio2;
extern unsigned char NewDriveMode;
extern unsigned char DefaultDriveMode;
extern unsigned char ShiftMode;
extern unsigned char ModeWait;
extern unsigned char KillWait;
extern unsigned char ALSModeFlashes;
extern unsigned char ALSModeFlashSpeed;
extern float CyclesPerSec;
extern unsigned char FlexFuelEnabled;
extern float FlexRoughFTs;
extern float FlexFineFTs;
extern float FlexRoughRatio;
extern float FlexFineRatio;
extern float FuelCheckWaitTime;
extern float FlexRatioUserJump;
extern float TargetCLAFR;
extern float LeanCruiseLoadThreshold;
extern TwoDTable O2SensorScalingMPGTable;
extern float ALSWGDC;
extern float ALSAVCS;
extern float DefaultALSPOLFRamTuning;
extern float DefaultALSTimingRamTuning;
extern float DefaultALSAVCSRamTuning;
extern float ALSTimingRamTuningAdder;
extern float ALSPOLFRamTuningAdder;
extern float ALSAVCSRamTuningAdder;
extern float OpenLoopAFRmin;
extern float ALSAcceleratorTrigger;
extern float ALSRPMLimit;
extern float ALSVehicleSpeedEnable;
extern float ALSVehicleSpeedDisable;
extern float RIMVehicleSpeedDisable;
extern float ALSRequestedTorque;
//extern float ALSTPS;
//extern float ALSTPS4;
extern unsigned char RIMCutMode;
extern unsigned char ALSCutMode;
extern unsigned char RollingAntiLagEnabled;
extern unsigned char DODMode;
extern float FCRIPedalThresh;
extern float ALSPedalThresh;
extern float DefaultRimRPMDiff;
extern float ECTALSThreshold;
extern float ALSRPMDeltaLimit;
extern short PedalKick;

#endif

//Rev Limiter Defaults
extern unsigned char DefaultRevLimMode;
extern unsigned char DefaultFlatFootShiftMode;
extern float DefaultRedLineCut;
extern float DefaultRedLineHyst;
extern float DefaultLaunchControlSpeedMax;
extern float DefaultLaunchControlCut;
extern float DefaultLaunchControlHyst;
extern float DefaultFlatFootShiftAutoDelta;
extern float DefaultFlatFootShiftStaticDelta;
extern float DefaultFlatFootShiftHyst;
extern float DefaultFlatFootShiftSpeedThreshold;
extern float DefaultFlatFootShiftRpmThreshold;
extern float LCAdjustStep;

extern float ValetModeRevLim;

#if VIN_HACKS
extern const VinBlockStruct VinBlock;
extern unsigned char Licensee[];
#endif

#if SWITCH_HACKS
extern unsigned char DefaultMapSwitch;
extern float DefaultMapBlendRatio;
extern float LeftTGVInputSmoothingFactor;
extern float RightTGVInputSmoothingFactor;
extern float LeftTGVInputMultiplier;
extern float RightTGVInputMultiplier;
extern float LeftTGVInputOffset;
extern float RightTGVInputOffset;
extern TwoDTable TGVLeftScaling;
extern TwoDTable TGVRightScaling;
extern float MapSwitchThresholdLo;
extern float MapSwitchThresholdHi;
extern unsigned char BlendRatioInput;
extern unsigned char MapSwitchInput;

extern TwoDTable TipInEnrichMultiplier;
extern TwoDTable CrankingFuelMultiplier;
extern TwoDTable StartupEnrichMultiplier;
#endif

extern long RomHoleEndMarker;
extern unsigned char ModIdentifier[];