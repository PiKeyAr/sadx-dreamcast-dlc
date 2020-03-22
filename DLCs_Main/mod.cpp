#include "stdafx.h"
#include "DLCs.h"

#include <random>

// DLC code
#include "ATT.h"
#include "Christmas98.h"
#include "Christmas99.h"
#include "Famitsu.h"
#include "Halloween.h"
#include "LaunchParty.h"
#include "Quo.h"
#include "Reebok.h"
#include "SambaGP.h"
#include "Y2K.h"
#include "Kadomatsu.h"

// DLC data
extern NJS_MATERIAL matlist_00000004[];		// Data/DLC_ATT.h
extern NJS_MATERIAL matlist_00000004_2[];	// Data/DLC_Christmas99.h

static const wchar_t *const OldModDLLs[] = {
	L"SONICADV_000",
	L"SONICADV_002",
	L"SONICADV_003",
	L"SONICADV_501",
	L"SONICADV_502",
	L"SONICADV_503",
	L"SONICADV_504",
	L"SONICADV_505",
	L"SONICADV_506",
	L"SONICADV_507",
	L"SONICADV_508",
	L"SONICADV_509",
	L"SONICADV_510",
	L"SONICADV_511",
};

_SYSTEMTIME CurrentTime;

std::string DLCMode;
int LaunchPartyDLCMode = 0;
std::string SegaVoiceLanguage = "English";

int MenuVoiceMode;

// Debug timer stuff
bool HDTimer = false;
char DebugCharacterRed = 0;
int DebugTimer_Current = 0;
int DebugTimer_Total = 0;
int DebugTimer_Minutes = 0;
int DebugTimer_Seconds = 0;
int DebugTimer_Miliseconds = 0;

// Twinkle Circuit track IDs
int SonicTrack = 2;
int TailsTrack = 1;
int KnucklesTrack = 3;
int AmyTrack = 4;
int BigTrack = 5;
int GammaTrack = 0;

// Monthly DLCs
static int MonthlyDLCs[12][2];

HMODULE ADV00MODELS = GetModuleHandle(L"ADV00MODELS");
DataPointer(COL, COL_whatever, ((size_t)ADV00MODELS + 0x001D8144));
DataPointer(uint8_t, TextureFilterSettingForPoint_1, 0x0078B7C4);
DataPointer(uint8_t, TextureFilterSettingForPoint_2, 0x0078B7D8);
DataPointer(uint8_t, TextureFilterSettingForPoint_3, 0x0078B7EC);

// Common
bool EverybodySuperSonicRacing = false;
int CurrentDLC = 0;
bool ObjectsLoaded = false;
bool ObjectsLoaded_SS = false;
bool ObjectsLoaded_MR = false;
bool ForceSADXLayout = false;
bool DisableDuringStory = true;
bool TimerLoaded = false;
int PreviousLevel = 0;
int PreviousAct = 0;
int HintTimer = 0;
int ChallengeTimer = 0;
int CollectedAll = 0;
int MusicMode = 0;
SETObjData setdata_dlc = {};
bool ChallengeOver = false;
bool ChallengeAction = false;

// Famitsu and Reebok stuff
bool Collected1 = false;
bool Collected2 = false;
bool Collected3 = false;
bool Collected4 = false;
bool Collected5 = false;

// AT&T stuff
bool HighwayGoal = false;

// QUO stuff
bool CollectedSS1 = false;
bool CollectedSS2 = false;
bool CollectedSS3 = false;
bool CollectedMR1 = false;
bool CollectedMR2 = false;
bool CollectedMR3 = false;

// MR challenge stuff
bool Treasure1 = false;
bool Treasure2 = false;
bool Treasure3 = false;
bool Treasure4 = false;

// Sand hill challenge stuff
bool Gate1 = false;
bool Gate2 = false;
bool Gate3 = false;
bool Gate4 = false;
bool Gate5 = false;
bool Gate6 = false;
bool Gate7 = false;
bool Gate8 = false;
bool Gate9 = false;
bool Gate10 = false;

#define ReplaceBIN(a,b) helperFunctions.ReplaceFile("system\\" a ".BIN", "system\\" b ".BIN");

static const PVMEntry TimerTextures = { "CON_REGULAR_E", (TexList *)0x00912DF4 };

static int CharacterVoice = 0;
static int VoiceLanguage_sel = 1;
static bool AlternateEggman = false;

// SEGA, Sonic Team
static const int voices[8][2] =
{
	{ 1994, 1995 },	// Sonic
	{ 1996, 1997 },	// Tails
	{ 1998, 1999 },	// Knuckles
	{ 2000, 2001 },	// Amy
	{ 2002, 2003 },	// Big
	{ 2004, 2005 },	// Gamma
	{ 2006, 2008 },	// Eggman
	{ 2010, 2011 }	// Tikal
};

static int GetVoiceNumber(int value)
{
	int result = voices[CharacterVoice][value];
	return (CharacterVoice == 6 && AlternateEggman) ? ++result : result;
}

static void PlaySegaSonicTeamVoice()
{
	if (SegaVoiceLanguage != "Off")
	{
		if (SegaLogo_Frames == 1 && SoundManager_ptr == nullptr)
		{
			SoundManager_Load(LoadObject((LoadObj)0, 1, SoundManager_Load));
		}

		if (SegaLogo_Frames != 30)
		{
			return;
		}

		if (SoundManager_ptr != nullptr)
		{
			switch (SegaLogo_Mode)
			{
			case 1:
				VoiceLanguage = VoiceLanguage_sel;
				PlayVoice(GetVoiceNumber(0));
				SoundManager_ptr->MainSub(SoundManager_ptr);
				break;

			case 16:
				PlayVoice(GetVoiceNumber(1));
				SoundManager_ptr->MainSub(SoundManager_ptr);
				VoiceLanguage = 1;
				break;

			default:
				break;
			}
		}
		else
		{
			PrintDebug("Error initializing Sound Manager.\n");
		}
	}
}

void __declspec(naked) PlaySegaSonicTeamVoice_asm()
{
	__asm
	{
		call DisplayLogoScreen
		add esp, 4
		call PlaySegaSonicTeamVoice
		xor eax, eax
		retn
	}
}

void StopVoicesButMaybeNot_Challenge()
{
	//004B793E
	if (!ChallengeAction) StopVoices();
}

void StopVoicesButMaybeNot_Christmas()
{
	//004B793E
	if (MusicMode == 0) StopVoices();
}

void DLCHook_LoadLevelIncrementAct(ObjectMaster *a1)
{
	sub_4570B0();
	if (IsAdventureComplete(GetCharacterSelection()) || !DisableDuringStory)
	{
		if (CurrentDLC == 0)
		{
			if (CurrentLevel == 4 && CurrentAct == 0)
			{
				if (ChallengeAction && !ChallengeOver && CurrentLevel == 4 && CurrentAct == 0 && CurrentCharacter == 0) LoadATT1Stuff();
			}
			if (CurrentLevel == 38 && CurrentCharacter == 2) LoadATT3Stuff(); //Challenge 3
		}
		//Halloween
		if (CurrentDLC == 4)
		{
			if (CurrentLevel == 3 && CurrentAct == 0) LoadHalloweenStuff_Twinkle1();
			if (CurrentLevel == 3 && CurrentAct == 1) LoadHalloweenStuff_Twinkle2();
			if (CurrentLevel == 3 && CurrentAct == 2) LoadHalloweenStuff_Twinkle3();
		}
		//Reebok challenge
		if (CurrentDLC == 7 && GetEventFlag(EventFlags_Sonic_EmeraldCoastClear))
		{
			if (ChallengeAction && !ChallengeOver && CurrentLevel == 1 && CurrentAct == 0 && CurrentCharacter == 0) LoadReebokStuffInEmeraldCoast();
		}
		//Y2K Rings
		if (CurrentDLC == 9)
		{
			if (CurrentLevel != 26 && CurrentLevel != 33 && CurrentLevel != 29 && CurrentLevel != 32 && CurrentLevel != 34) LoadY2KRings();
		}
	}
}

void DLCHook_StationSquare()
{
	if (LANDTABLESS[3]->Col[136].Radius <= 3949 && LANDTABLESS[3]->Col[136].Radius >= 3946)
	{
		ForceSADXLayout = true;
		//PrintDebug("SADX layout\n");
	}
	else
	{
		ForceSADXLayout = false;
		//PrintDebug("SA1 layout\n");
	}
	sub_62E980();
	if (IsAdventureComplete(GetCharacterSelection()) || !DisableDuringStory)
	{
		if (CurrentDLC == 0)
		{
			//Challenge 1 (Sonic)
			if (CurrentLevel == 26 && CurrentCharacter == 0 && (GetEventFlag(EventFlags_Sonic_SpeedHighwayClear) || !GetEventFlag(EventFlags_Sonic_SpeedHighwayOpen))) LoadATT1Stuff_SS();
			//Challenge 2 (Knuckles)
			if ((CurrentLevel == 26 || CurrentLevel == 33) && CurrentCharacter == 3) LoadATT2Stuff_SSorMR();
			//Challenge 3 (Tails)
			if (CurrentLevel == 26 && CurrentCharacter == 2) LoadATT3Stuff_SS(); //Challenge 3
		}
		if (CurrentDLC == 1)
		{
			if (CurrentLevel == 26) Christmas98_LoadStuff();
		}
		//Christmas 99
		if (CurrentDLC == 2)
		{
			if (CurrentLevel == 26) Christmas99_LoadStuff();
		}
		//Famitsu
		if (CurrentDLC == 3)
		{
			if (CurrentLevel == 26) Famitsu_LoadStuff();
		}
		//Halloween
		if (CurrentDLC == 4)
		{
			if (CurrentLevel == 26) LoadHalloweenStuff_StationSquare();
		}
		//Launch Party
		if (CurrentDLC == 5)
		{
			if (CurrentLevel == 26) LoadLaunchPartyStuff_SS();
		}
		//QUO challenge
		if (CurrentDLC == 6)
		{
			if (CurrentLevel == 26 || CurrentLevel == 33) LoadQUOStuff();
		}
		//Reebok challenge
		if (CurrentDLC == 7)
		{
			if (CurrentLevel == 26 && GetEventFlag(EventFlags_Sonic_EmeraldCoastClear)) LoadReebokStuffInStationSquare();
		}
		//Samba GP
		if (CurrentDLC == 8)
		{
			if (CurrentLevel == 26) LoadSambaGateEntry();
		}
		//Y2K
		if (CurrentDLC == 9)
		{
			if (CurrentLevel == 26) LoadY2KRings_StationSquare(); else LoadY2KRings();
		}
		//Kadomatsu
		if (CurrentDLC == 10)
		{
			if (CurrentLevel == 26) Kadomatsu_LoadStuff();
		}
	}
}

void DLCHook_MysticRuins()
{
	sub_52F240();
	if (IsAdventureComplete(GetCharacterSelection()) || !DisableDuringStory)
	{
		//ATT challenges
		if (CurrentDLC == 0)
		{
			//Challenge 2 (Knuckles)
			if ((CurrentLevel == 26 || CurrentLevel == 33) && CurrentCharacter == 3) LoadATT2Stuff_SSorMR();
		}
		//QUO challenge
		if (CurrentDLC == 6)
		{
			if (CurrentLevel == 26 || CurrentLevel == 33) LoadQUOStuff();
		}
	}
}

void DrawDebugText_NoFiltering(NJS_POINT2 *points, float scale)
{
	uint8_t Backup1 = TextureFilterSettingForPoint_1;
	uint8_t Backup2 = TextureFilterSettingForPoint_2;
	uint8_t Backup3 = TextureFilterSettingForPoint_3;
	WriteData((uint8_t*)0x0078B7C4, (uint8_t)0x01);
	WriteData((uint8_t*)0x0078B7D8, (uint8_t)0x01);
	WriteData((uint8_t*)0x0078B7EC, (uint8_t)0x01);
	Direct3D_TextureFilterPoint();
	DrawRectPoints(points, scale);
	WriteData((uint8_t*)0x0078B7C4, Backup1);
	WriteData((uint8_t*)0x0078B7D8, Backup2);
	WriteData((uint8_t*)0x0078B7EC, Backup3);
}

void DrawDebugTimer()
{
	if (MessageShown) return;
	//Character grid is 40x30 for 4:3 resolutions, each character is 16x16 for 640x480 at scale 16
	float HorizontalResolution_float = (float)HorizontalResolution;
	float VerticalResolution_float = (float)VerticalResolution;
	int FontScale = int(HorizontalResolution_float / 640.0f);
	int RightColumn = int(floor(HorizontalResolution_float/(16.0f*FontScale)));
	int BottomLine = int(floor(VerticalResolution_float/(16.0f*FontScale)));
	if (!IsGamePaused() && ((FramerateSetting < 2 && FrameCounter % 4 == 0) || FramerateSetting >= 2 && FrameCounter % 2 == 0)) DebugCharacterRed++;
	if (DebugCharacterRed > 7) DebugCharacterRed = 0;
	SetDebugFontSize(FontScale*16);
	SetDebugFontColor(0xFFF0F049);
	DisplayDebugString(NJM_LOCATION(RightColumn-9, BottomLine-7), "[TARGET]");
	SetDebugFontColor(0xFF5AC3F0);
	PrintDebugNumber(NJM_LOCATION(RightColumn-6, BottomLine-6), DebugTimer_Current, 2); //Current number of targets
	PrintDebugNumber(NJM_LOCATION(RightColumn-3, BottomLine-6), DebugTimer_Total, 2); //Total number of targets
	SetDebugFontColor(0xFF4AEE66);
	DisplayDebugString(NJM_LOCATION(RightColumn-4, BottomLine-6), "/");
	if (DebugCharacterRed == 0) SetDebugFontColor(0xFFE94202); else SetDebugFontColor(0xFFF0C046);
	DisplayDebugString(NJM_LOCATION(RightColumn-9, BottomLine-5), "-");
	if (DebugCharacterRed == 2) SetDebugFontColor(0xFFE94202); else SetDebugFontColor(0xFFF0C046);
	DisplayDebugString(NJM_LOCATION(RightColumn-7, BottomLine-5), "T");
	if (DebugCharacterRed == 3) SetDebugFontColor(0xFFE94202); else SetDebugFontColor(0xFFF0C046);
	DisplayDebugString(NJM_LOCATION(RightColumn-6, BottomLine-5), "I");
	if (DebugCharacterRed == 4) SetDebugFontColor(0xFFE94202); else SetDebugFontColor(0xFFF0C046);
	DisplayDebugString(NJM_LOCATION(RightColumn-5, BottomLine-5), "M");
	if (DebugCharacterRed == 5) SetDebugFontColor(0xFFE94202); else SetDebugFontColor(0xFFF0C046);
	DisplayDebugString(NJM_LOCATION(RightColumn-4, BottomLine-5), "E");
	if (DebugCharacterRed == 7) SetDebugFontColor(0xFFE94202); else SetDebugFontColor(0xFFF0C046);
	DisplayDebugString(NJM_LOCATION(RightColumn-2, BottomLine-5), "-");
	SetDebugFontColor(0xFF87E1EF);
	DisplayDebugString(NJM_LOCATION(RightColumn-7, BottomLine-4), ":");
	DisplayDebugString(NJM_LOCATION(RightColumn-4, BottomLine-4), ":");
	SetDebugFontColor(0xFFB3DFED);
	PrintDebugNumber(NJM_LOCATION(RightColumn-9, BottomLine-4), DebugTimer_Minutes, 2); //Timer minutes
	PrintDebugNumber(NJM_LOCATION(RightColumn-6, BottomLine-4), DebugTimer_Seconds, 2); //Timer seconds
	PrintDebugNumber(NJM_LOCATION(RightColumn-3, BottomLine-4), DebugTimer_Miliseconds, 2); //Timer miliseconds
}

extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions &helperFunctions)
	{
		WriteJump((void*)0x0042CCC7, PlaySegaSonicTeamVoice_asm);
		WriteJump((void*)0x0042CD2F, PlaySegaSonicTeamVoice_asm);
		GetLocalTime(&CurrentTime);
		srand(CurrentTime.wSecond);
		if (helperFunctions.Version < 6)
		{
			MessageBox(WindowHandle,
				L"Mod Loader out of date. Dreamcast DLCs mod requires API version 6 or newer.",
				L"Dreamcast DLCs mod error: Mod Loader out of date", MB_OK | MB_ICONERROR);
			return;
		}

		// Check for old mod DLLs.
		std::wstring OldModsMessage = L"Old/incompatible mods detected!\n\n"
			L"It appears that you are running the Dreamcast DLCs "
			L"mod with older individual DLC mods. The individual "
			L"mods are outdated and will cause problems if you "
			L"leave them enabled. These mods are no longer needed "
			L"because they are built into the Dreamcast DLCs mod, "
			L"which you are also running.\n\n"
			L"Please uninstall the individual DLC mods in the Mod Manager.\n\n";

		bool OldModsFound = false;
		for (unsigned int i = 0; i < LengthOfArray(OldModDLLs); i++)
		{
			if (GetModuleHandle(OldModDLLs[i]) != nullptr)
			{
				// Found a known incompatible mod.
				OldModsMessage += OldModDLLs[i];
				OldModsMessage += '\n';
				OldModsFound = true;
			}
		}

		if (OldModsFound)
		{
			MessageBox(WindowHandle, OldModsMessage.c_str(),
				L"Dreamcast DLCs mod error: incompatible mods detected",
				MB_OK | MB_ICONERROR);
			return;
		}

		//Config stuff
		const IniFile *config = new IniFile(std::string(path) + "\\config.ini");
		MenuVoiceMode = config->getInt("General settings", "MenuVoiceThing", -1);
		HDTimer = config->getBool("General settings", "HDTimer", false);
		if (!HDTimer) WriteCall((void*)0x00793BCC, DrawDebugText_NoFiltering);
		if (MenuVoiceMode == 9) MenuVoiceMode = rand() % 8 + 1;
		DisableDuringStory = config->getBool("General settings", "DisableDuringStory", true);
		DLCMode = config->getString("General settings", "DLCMode", "Random");
		CurrentDLC = config->getInt("General settings", "DLCSingle", 0);
		SegaVoiceLanguage = config->getString("General settings", "SegaVoiceLanguage", "English");
		EverybodySuperSonicRacing = config->getBool("Samba GP settings", "SuperSonicRacing", false);
		SonicTrack = config->getInt("Samba GP settings", "SonicTrack", 2);
		TailsTrack = config->getInt("Samba GP settings", "TailsTrack", 1);
		KnucklesTrack = config->getInt("Samba GP settings", "KnucklesTrack", 3);
		AmyTrack = config->getInt("Samba GP settings", "AmyTrack", 4);
		BigTrack = config->getInt("Samba GP settings", "BigTrack", 5);
		GammaTrack = config->getInt("Samba GP settings", "GammaTrack", 0);

		// Monthly DLCs.
		struct dlcKeyInfo
		{
			const char *dlc1name;
			const char *dlc2name;
			int dlc1id;
			int dlc2id;
		};
		static const dlcKeyInfo dlcKeyNames[12] =
		{
			{"Jan1DLC", "Jan2DLC", 10, 9},
			{"Feb1DLC", "Feb2DLC", 3, 3},
			{"Mar1DLC", "Mar2DLC", 6, 6},
			{"Apr1DLC", "Apr2DLC", 0, 0},
			{"May1DLC", "May2DLC", 0, 0},
			{"Jun1DLC", "Jun2DLC", 8, 8},
			{"Jul1DLC", "Jul2DLC", 7, 7},
			{"Aug1DLC", "Aug2DLC", -1, -1},
			{"Sep1DLC", "Sep2DLC", 5, 5},
			{"Oct1DLC", "Oct2DLC", 4, 4},
			{"Nov1DLC", "Nov2DLC", 8, 8},
			{"Dec1DLC", "Dec2DLC", 2, 1},
		};

		for (unsigned int i = 0; i < 12; i++)
		{
			MonthlyDLCs[i][0] = config->getInt("Seasonal DLC settings",
				dlcKeyNames[i].dlc1name, dlcKeyNames[i].dlc1id);
			MonthlyDLCs[i][1] = config->getInt("Seasonal DLC settings",
				dlcKeyNames[i].dlc2name, dlcKeyNames[i].dlc2id);
		}

		delete config;

		// DLCs.
		if (DLCMode == "Random")
		{
			// Randomly select a DLC.
			CurrentDLC = rand() % 10;
		}
		else if (DLCMode == "Seasonal")
		{
			// Select a DLC based on the current month.
			// NOTE: wMonth is 1-12. Subtract 1 for the array index.
			if (CurrentTime.wDay <= 15)
			{
				// First half of the month.
				CurrentDLC = MonthlyDLCs[CurrentTime.wMonth-1][0];
			}
			else
			{
				// Second half of the month.
				CurrentDLC = MonthlyDLCs[CurrentTime.wMonth-1][1];
			}
		}
		WriteCall((void*)0x00415A6D, DLCHook_LoadLevelIncrementAct); //LoadLevel
		WriteCall((void*)0x004147B6, DLCHook_LoadLevelIncrementAct); //IncrementAct
		WriteCall((void*)0x0062F098, DLCHook_StationSquare); 
		WriteCall((void*)0x0062F102, DLCHook_StationSquare);
		WriteCall((void*)0x0052FB82, DLCHook_MysticRuins);

		// DLC-specific handling.
		//PrintDebug("Current DLC ID: %02X\n", CurrentDLC);
		switch (CurrentDLC)
		{
			case 0:
				// AT&T challenges
				WriteCall((void*)0x004B793E, StopVoicesButMaybeNot_Challenge);
				helperFunctions.RegisterCommonObjectPVM(ATT1Textures);
				helperFunctions.RegisterCommonObjectPVM(ATT2Textures);
				helperFunctions.RegisterCommonObjectPVM(ATT3Textures);
				helperFunctions.RegisterCommonObjectPVM(TimerTextures);
				break;
			case 1:
				// Christmas 98
				MusicList[68].Name = "Xmas98_1";
				MusicList[69].Name = "Xmas98_2";
				MusicList[70].Name = "Xmas98_3";
				helperFunctions.RegisterCommonObjectPVM(Christmas98Textures);
				WriteCall((void*)0x004B793E, StopVoicesButMaybeNot_Christmas);
				break;
			case 2:
				// Christmas 99
				helperFunctions.RegisterCommonObjectPVM(Christmas99Textures);
				WriteCall((void*)0x004B793E, StopVoicesButMaybeNot_Christmas);
				break;
			case 3:
				// Famitsu
				WriteCall((void*)0x004B793E, StopVoicesButMaybeNot_Challenge);
				helperFunctions.RegisterCommonObjectPVM(FamitsuTextures);
				helperFunctions.RegisterCommonObjectPVM(TimerTextures);
				ReplaceBIN("CAMSS00S", "CAMSS00S_F");
				ReplaceBIN("CAMSS01S", "CAMSS01S_F");
				ReplaceBIN("CAMSS02S", "CAMSS02S_F");
				ReplaceBIN("CAMSS03S", "CAMSS03S_F");
				ReplaceBIN("CAMSS04S", "CAMSS04S_F");
				ReplaceBIN("CAMSS05S", "CAMSS05S_F");
				ReplaceBIN("CAMSS00S_DC", "CAMSS00S_F");
				ReplaceBIN("CAMSS01S_DC", "CAMSS01S_F");
				ReplaceBIN("CAMSS02S_DC", "CAMSS02S_F");
				ReplaceBIN("CAMSS03S_DC", "CAMSS03S_F");
				ReplaceBIN("CAMSS04S_DC", "CAMSS04S_F");
				ReplaceBIN("CAMSS05S_DC", "CAMSS05S_F");
				break;
			case 4:
				// Halloween
				helperFunctions.RegisterCommonObjectPVM(HalloweenTextures);
				break;
			case 5:
				// Launch party
				helperFunctions.RegisterCommonObjectPVM(LaunchPartyUSTextures);
				break;
			case 6:
				// QUO challenge
				ReplaceBIN("CAMSS00S", "CAMSS00S_F");
				ReplaceBIN("CAMSS01S", "CAMSS01S_F");
				ReplaceBIN("CAMSS02S", "CAMSS02S_F");
				ReplaceBIN("CAMSS03S", "CAMSS03S_F");
				ReplaceBIN("CAMSS04S", "CAMSS04S_F");
				ReplaceBIN("CAMSS05S", "CAMSS05S_F");
				ReplaceBIN("CAMSS00S_DC", "CAMSS00S_F");
				ReplaceBIN("CAMSS01S_DC", "CAMSS01S_F");
				ReplaceBIN("CAMSS02S_DC", "CAMSS02S_F");
				ReplaceBIN("CAMSS03S_DC", "CAMSS03S_F");
				ReplaceBIN("CAMSS04S_DC", "CAMSS04S_F");
				ReplaceBIN("CAMSS05S_DC", "CAMSS05S_F");
				WriteCall((void*)0x004B793E, StopVoicesButMaybeNot_Challenge);
				helperFunctions.RegisterCommonObjectPVM(QuoTextures);
				helperFunctions.RegisterCommonObjectPVM(TimerTextures);
				break;
			case 7:
				// Reebok challenge
				helperFunctions.RegisterCommonObjectPVM(ReebokTextures);
				helperFunctions.RegisterCommonObjectPVM(TimerTextures);
				break;
			case 8:
				// Samba GP
				helperFunctions.RegisterCommonObjectPVM(SambaGPTextures);
				WriteCall((void*)0x004DB126, QuitTwinkleCircuit);
				WriteCall((void*)0x00640684, CallSambaCircuit);
				break;
			case 9:
				// Y2K Rings
				helperFunctions.RegisterCommonObjectPVM(Y2KTextures);
				break;
			case 10:
				// Kadomatsu
				helperFunctions.RegisterCommonObjectPVM(KadomatsuTextures);
				MusicList[68].Name = "Kado_1";
				MusicList[69].Name = "Kado_2";
				MusicList[70].Name = "Kado_3";
				WriteCall((void*)0x004B793E, StopVoicesButMaybeNot_Christmas);
				break;
			case 51:
				// Launch party JP
				helperFunctions.RegisterCommonObjectPVM(LaunchPartyJPTextures);
				LaunchPartyDLCMode = 2;
				CurrentDLC = 5;
				break;
			case 52:
				// Launch party EU
				helperFunctions.RegisterCommonObjectPVM(LaunchPartyEUTextures);
				LaunchPartyDLCMode = 1;
				CurrentDLC = 5;
				break;
			default:
				break;
		}

		if (SegaVoiceLanguage != "Off")
		{
			std::random_device r;
			std::mt19937 mt(r());
			std::uniform_int_distribution<int> voice(0, 7);
			std::uniform_int_distribution<int> eggman(0, 1);
			if (MenuVoiceMode >= 0 && MenuVoiceMode < 9) CharacterVoice = MenuVoiceMode - 1;
			else CharacterVoice = voice(mt);
			AlternateEggman = eggman(mt) == 1;
			if (SegaVoiceLanguage == "Japanese")
			{
				VoiceLanguage_sel = 0;
				if (CharacterVoice == 5)
				{
					WriteData<1>((char*)0x0042CC9C, 0xFF);
					WriteData<1>((char*)0x0042CD0E, 0xFF);
				}
			}
		}
	}
	__declspec(dllexport) void __cdecl OnFrame()
	{
		if (MenuVoiceMode != -1 && MenuVoiceMode != 9)
		{
			if (MenuVoiceMode == -2) MenuVoice = 0;
			else if (MenuVoiceMode != 10) MenuVoice = MenuVoiceMode;
			else if (FrameCounter % 60 == 0) MenuVoice = rand() % 9;
		}
		if (HintTimer > 0) HintTimer--;
		if (IsAdventureComplete(GetCharacterSelection()) || !DisableDuringStory)
		{
			if (CurrentDLC == 0)
			{
				if (CurrentCharacter == 0)
				{
					if (!IsGamePaused())
					{
						if (GameState == 6 || CurrentLevel != 26 || (GameMode != GameModes_Adventure_Field && GameMode != GameModes_Mission))
						{
							ObjectsLoaded = false;
						}
						if (GameMode != GameModes_Adventure_Field && GameMode != GameModes_Adventure_ActionStg && GameMode != GameModes_Mission)
						{
							HighwayGoal = false;
							ChallengeAction = false;
							ChallengeOver = false;
							ChallengeTimer = 0;
							ObjectsLoaded = false;
						}
						if (CurrentLevel == 4 && GameState == 9 && !HighwayGoal)
						{
							ChallengeAction = false;
							ChallengeOver = false;
							ChallengeTimer = 0;
							ObjectsLoaded = false;
						}
					}
				}
				if (CurrentCharacter == 3)
				{
					if (!IsGamePaused())
					{
						if (GameMode != GameModes_Adventure_Field && GameMode != GameModes_Mission)
						{
							ChallengeAction = false;
							ChallengeOver = false;
							Treasure1 = false;
							Treasure2 = false;
							Treasure3 = false;
							Treasure4 = false;
							ChallengeTimer = 0;
							ObjectsLoaded = false;
						}
						if (PreviousLevel != CurrentLevel)
						{
							ObjectsLoaded = false;
							PreviousLevel = CurrentLevel;
							PreviousAct = CurrentAct;
						}
						if (GameState == 6)
						{
							ObjectsLoaded = false;
						}
					}
				}
				if (CurrentCharacter == 2)
				{
					if (!IsGamePaused())
					{
						if (CurrentLevel != 38 || GameState == 21)
						{
							ChallengeAction = false;
							ChallengeOver = false;
							Gate1 = false;
							Gate2 = false;
							Gate3 = false;
							Gate4 = false;
							Gate5 = false;
							Gate6 = false;
							Gate7 = false;
							Gate8 = false;
							Gate9 = false;
							Gate10 = false;
							ChallengeTimer = 0;
						}
						if (CurrentLevel != 26 || GameState == 6)
						{
							ObjectsLoaded = false;
						}
						if (CurrentLevel == 33 && CollectedAll == 10 && !ChallengeOver && Camera_Data1 != nullptr)
						{
							DisplayHintText(ATT3_Message4, 360);
							Gate1 = false;
							Gate2 = false;
							Gate3 = false;
							Gate4 = false;
							Gate5 = false;
							Gate6 = false;
							Gate7 = false;
							Gate8 = false;
							Gate9 = false;
							Gate10 = false;
							CollectedAll = 0;
							ChallengeTimer = 0;
							ChallengeOver = false;
							ChallengeAction = false;
						}
					}
				}
			}
			if (CurrentDLC == 1)
			{
				if (CurrentLevel != 26 || GameState == 6 || GameState == 21 || (GameMode != GameModes_Adventure_Field && GameMode != GameModes_Mission))
				{
					ObjectsLoaded = false;
					MusicMode = 0;
					WriteData<1>((char*)0x0062EEF9, MusicIDs_StationSquare);
				}
			}
			if (CurrentDLC == 2)
			{
				if (CurrentLevel != 26 || GameState == 6 || GameState == 21 || (GameMode != GameModes_Adventure_Field && GameMode != GameModes_Mission))
				{
					ObjectsLoaded = false;
					MusicMode = 0;
					WriteData<1>((char*)0x0062EEF9, MusicIDs_StationSquare);
				}
			}
			if (CurrentDLC == 3)
			{
				HMODULE ADV00MODELS = GetModuleHandle(L"ADV00MODELS");
				NJS_OBJECT **___ADV00SS01_OBJECTS = (NJS_OBJECT * *)GetProcAddress(ADV00MODELS, "___ADV00SS01_OBJECTS");
				if (!IsGamePaused())
				{
					if (GameState == 6)
					{
						ObjectsLoaded = false;
						Collected1 = false;
						Collected2 = false;
						Collected3 = false;
						Collected4 = false;
						Collected5 = false;
						CollectedAll = 0;
						ChallengeAction = false;
						ChallengeTimer = 0;
					}
					if (ForceSADXLayout && ChallengeAction)
					{
						COL_whatever.Flags = 0x80040000;
						___ADV00SS01_OBJECTS[28]->pos[1] = 20;
					}
					if (CurrentLevel != 26 || (GameMode != GameModes_Adventure_Field && GameMode != GameModes_Mission))
					{
						ObjectsLoaded = false;
						Collected1 = false;
						Collected2 = false;
						Collected3 = false;
						Collected4 = false;
						Collected5 = false;
						CollectedAll = 0;
						ChallengeAction = false;
						ChallengeTimer = 0;
					}
				}
			}
			if (CurrentDLC == 4)
			{
				if (CurrentLevel != 26 || GameState == 6 || GameState == 21)
				{
					ObjectsLoaded = false;
				}
			}
			if (CurrentDLC == 5)
			{
				if (CurrentLevel != 26 || GameState == 6 || GameState == 21)
				{
					ObjectsLoaded = false;
				}
			}
			if (CurrentDLC == 6)
			{
				if (!IsGamePaused())
				{
					if (GameMode != GameModes_Adventure_Field && GameMode != GameModes_Mission)
					{
						CollectedAll = 0;
						CollectedSS1 = false;
						CollectedSS2 = false;
						CollectedSS3 = false;
						CollectedMR1 = false;
						CollectedMR2 = false;
						CollectedMR3 = false;
						ChallengeTimer = 0;
						ChallengeAction = false;
						ObjectsLoaded_SS = false;
						ObjectsLoaded_MR = false;
						TimerLoaded = false;
					}
					if (GameState == 6)
					{
						ObjectsLoaded_SS = false;
						ObjectsLoaded_MR = false;
						TimerLoaded = false;
					}
					if (PreviousLevel != CurrentLevel)
					{
						if (PreviousLevel == 26) ObjectsLoaded_SS = false;
						if (PreviousLevel == 33) ObjectsLoaded_MR = false;
						TimerLoaded = false;
						PreviousLevel = CurrentLevel;
					}
				}
			}
			if (CurrentDLC == 7)
			{
				if (!IsGamePaused())
				{
					if (GameState == 6)
					{
						ObjectsLoaded = false;
					}
					if (CurrentLevel != 26 || (GameMode != GameModes_Adventure_Field && GameMode != GameModes_Mission))
					{
						ObjectsLoaded = false;
					}
					if (ChallengeAction && (CurrentLevel != 1 || CurrentAct != 0))
					{
						ChallengeTimer = 0;
						Collected1 = false;
						Collected2 = false;
						Collected3 = false;
						Collected4 = false;
						Collected5 = false;
						CollectedAll = 0;
					}
				}
			}
			if (CurrentDLC == 8)
			{
				if (CurrentLevel != 26 || GameState == 6 || GameState == 21 || (GameMode != GameModes_Adventure_Field && GameMode != GameModes_Mission))
				{
					ObjectsLoaded = false;
				}
			}
			if (CurrentDLC == 9)
			{
				if (!IsGamePaused())
				{
					if (CurrentLevel != 26)
					{
						ObjectsLoaded = false;
						WriteData<1>((char*)0x0062EEF9, MusicIDs_s_square);
					}
					if (GameState == 6 || GameState == 7 || GameState == 21)
					{
						MusicMode = 0;
						ObjectsLoaded = false;
						WriteData<1>((char*)0x0062EEF9, MusicIDs_s_square);
					}
					if (PreviousLevel != CurrentLevel)
					{
						MusicMode = 0;
						PreviousLevel = CurrentLevel;
						PreviousAct = CurrentAct;
					}
					if (CurrentLevel != 26 && PreviousAct != CurrentAct)
					{
						MusicMode = 0;
						PreviousLevel = CurrentLevel;
						PreviousAct = CurrentAct;
					}
				}
			}
			if (CurrentDLC == 10)
			{
				if (CurrentLevel != 26 || GameState == 6 || GameState == 21 || (GameMode != GameModes_Adventure_Field && GameMode != GameModes_Mission))
				{
					ObjectsLoaded = false;
					MusicMode = 0;
					WriteData<1>((char*)0x0062EEF9, MusicIDs_StationSquare);
				}
			}
		}
	}

	__declspec(dllexport) void __cdecl OnInput()
	{
		if (IsAdventureComplete(GetCharacterSelection()) || !DisableDuringStory)
		{
			if (CurrentDLC == 0)
			{
				if (CurrentCharacter == 3 && GameState == 16)
				{
					if (ChallengeAction && (ControllerPointersShit[0]->PressedButtons & Buttons_Y) == Buttons_Y)
					{
						CollectedAll = 0;
						Treasure1 = false;
						Treasure2 = false;
						Treasure3 = false;
						Treasure4 = false;
						ChallengeTimer = 0;
						ChallengeAction = false;
						ChallengeOver = false;
					}
				}
				if (CurrentCharacter == 2 && GameState == 16)
				{
					if (ChallengeAction && (ControllerPointersShit[0]->PressedButtons & Buttons_Y) == Buttons_Y)
					{
						ChallengeAction = false;
						ChallengeOver = false;
						Gate1 = false;
						Gate2 = false;
						Gate3 = false;
						Gate4 = false;
						Gate5 = false;
						Gate6 = false;
						Gate7 = false;
						Gate8 = false;
						Gate9 = false;
						Gate10 = false;
						ChallengeTimer = 0;
					}
				}
			}
			if (CurrentDLC == 3 && GameState == 16)
			{
				if (ChallengeAction && (ControllerPointersShit[0]->PressedButtons & Buttons_Y) == Buttons_Y)
				{
					CollectedAll = 0;
					Collected1 = false;
					Collected2 = false;
					Collected3 = false;
					Collected4 = false;
					Collected5 = false;
					ChallengeTimer = 0;
					ChallengeAction = false;
				}
			}
			if (CurrentDLC == 6 && GameState == 16)
			{
				if (ChallengeAction && (ControllerPointersShit[0]->PressedButtons & Buttons_Y) == Buttons_Y)
				{
					CollectedAll = 0;
					CollectedSS1 = false;
					CollectedSS2 = false;
					CollectedSS3 = false;
					CollectedMR1 = false;
					CollectedMR2 = false;
					CollectedMR3 = false;
					ChallengeTimer = 0;
					ChallengeAction = false;
				}
			}
		}
	}
}

