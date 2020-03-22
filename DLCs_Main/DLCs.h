#pragma once
#include <SADXModLoader.h>
#include <string>

extern std::string DLCMode;
extern int LaunchPartyDLCMode;
extern std::string SegaVoiceLanguage;

// Twinkle Circuit track IDs.
extern int SonicTrack;
extern int TailsTrack;
extern int KnucklesTrack;
extern int AmyTrack;
extern int BigTrack;
extern int GammaTrack;

// Common
extern bool EverybodySuperSonicRacing;
extern int CurrentDLC;
extern bool ObjectsLoaded;
extern bool ObjectsLoaded_SS;
extern bool ObjectsLoaded_MR;
extern bool ForceSADXLayout;
extern bool DisableDuringStory;
extern bool TimerLoaded;
extern int PreviousLevel;
extern int PreviousAct;
extern int HintTimer;
extern int ChallengeTimer;
extern int CollectedAll;
extern int MusicMode;
extern SETObjData setdata_dlc;

extern bool ChallengeOver;
extern bool ChallengeAction;

// Famitsu and Reebok stuff
extern bool Collected1;
extern bool Collected2;
extern bool Collected3;
extern bool Collected4;
extern bool Collected5;

// AT&T stuff
extern bool HighwayGoal;

// QUO stuff
extern bool CollectedSS1;
extern bool CollectedSS2;
extern bool CollectedSS3;
extern bool CollectedMR1;
extern bool CollectedMR2;
extern bool CollectedMR3;

// MR challenge stuff
extern bool Treasure1;
extern bool Treasure2;
extern bool Treasure3;
extern bool Treasure4;

// Sand Hill challenge stuff
extern bool Gate1;
extern bool Gate2;
extern bool Gate3;
extern bool Gate4;
extern bool Gate5;
extern bool Gate6;
extern bool Gate7;
extern bool Gate8;
extern bool Gate9;
extern bool Gate10;

// Common function pointers.
FunctionPointer(void, sub_412D80, (int a1, int a2), 0x412D80);
FunctionPointer(void, sub_62E980, (), 0x62E980);
FunctionPointer(void, sub_52F240, (), 0x52F240);
FunctionPointer(signed int, sub_4570B0, (), 0x4570B0);
FunctionPointer(signed int, sub_49E170, (ObjectMaster *a1), 0x49E170);
FunctionPointer(signed int, sub_49CD60, (ObjectMaster *a1), 0x49CD60);
FunctionPointer(void, sub_425800, (int a1), 0x425800);

// Common data pointers.
// NOTE: These were previously defined as DataPointer() here,
// but SADXVariables.h defines them as well but with a different name,
// so we're just using a macro to rename them.
DataPointer(int, MessageShown, 0x3C58258);
#define DroppedFrames MissedFrames
#define FramerateSetting DeltaTimeMultiplier
#define ControllerPointersShit ControllerPointers
