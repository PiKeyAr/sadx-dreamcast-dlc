#include "stdafx.h"
#include "IniFile.hpp"
#include <random>
#include <SADXModLoader.h>
#include "Metadata.h"
#include "ChallengeTimer.h"
#include "SADXData.h"
#include <Trampoline.h>
#include "SegaVoice.h"
#include "lanternapi.h"

//TODO: Rendering settings for flat model
//TODO: Write out save files
//TODO: DLC selection menu

unsigned char checker_texturedata[6144];
NJS_TEXINFO checker_texinfo;

_SYSTEMTIME CurrentTime;
static int MonthlyDLCs[12][2];
std::string DLCMode;

void TwinkleCircuitMenu_Display();
void SetHudColorAndTextureNum_Italic(int n, NJS_COLOR color);
void njDrawQuadTexture_Italic(NJS_QUAD_TEXTURE* points, float scale);
void BackupDebugFontSettings();
void RestoreDebugFontSettings();
void TwinkleCircuitMenu_Input();
void MenuVoice_Init();
void MenuVoice_OnFrame();
bool CheckLevelAct(int level, int act);

struct dlcKeyInfo
{
	const char* dlc1name;
	const char* dlc2name;
	int dlc1id;
	int dlc2id;
};

static const dlcKeyInfo dlcKeyNames[12] =
{
	{"Jan1DLC", "Jan2DLC", 2, 13},
	{"Feb1DLC", "Feb2DLC", 4, 4},
	{"Mar1DLC", "Mar2DLC", 3, 3},
	{"Apr1DLC", "Apr2DLC", 14, 14},
	{"May1DLC", "May2DLC", 7, 7},
	{"Jun1DLC", "Jun2DLC", 8, 8},
	{"Jul1DLC", "Jul2DLC", 9, 9},
	{"Aug1DLC", "Aug2DLC", 15, 11},
	{"Sep1DLC", "Sep2DLC", 5, 5},
	{"Oct1DLC", "Oct2DLC", 6, 10},
	{"Nov1DLC", "Nov2DLC", 10, 0},
	{"Dec1DLC", "Dec2DLC", 1, 12},
};

std::string DownloadNameStrings[16];
const char* path_model;
const char* path_model_flat;
DLCMetadata meta;
const IniFile* ini_download;
Uint8 DownloadID = 0;
bool EnableCircuitMenu = false;
bool SuperSonicRacing = true;
bool DisableDuringStory = true;

void LoadDLCObject(DLCObjectData* data);

NJS_TEXNAME maintexnames[32];
NJS_TEXLIST maintexlist = {arrayptrandlength(maintexnames)};

NJS_TEXNAME checker_textures[1];
NJS_TEXLIST checker_texlist = {arrayptrandlength(checker_textures)};
NJS_TEXMEMLIST checker_texmemlist;

std::string path_dlc_textures;

SoundFileInfo sndinfo = { 8, "DOWNLOAD" };
SoundList sndlist = { 1, &sndinfo };

bool FileExists(const char* filename)
{
	struct stat buffer;
	return (stat(filename, &buffer) == 0);
}

signed int __cdecl InitDownload()
{
	//Exit if story in not completed
	if (DisableDuringStory && !IsAdventureComplete(GetCharacterSelection())) return 1;

	//Exit if not the right character
	switch (CurrentCharacter)
	{
	case Characters_Sonic:
		if (!meta.chars_sonic) return 1;
		break;
	case Characters_Tails:
		if (!meta.chars_tails) return 1;
		break;
	case Characters_Knuckles:
		if (!meta.chars_knuckles) return 1;
		break;
	case Characters_Amy:
		if (!meta.chars_amy) return 1;
		break;
	case Characters_Gamma:
		if (!meta.chars_e102) return 1;
		break;
	case Characters_Big:
		if (!meta.chars_big) return 1;
		break;
	}

	//Load checkerboard texture
	checker_textures[0].texaddr = (Uint32)TexMemList_PixelFormat(&checker_texinfo, 237542221);

	//Load timer
	if (!timer.loaded)
	{
		//PrintDebug("Reloading timer\n");
		timer.Initialize();
	}

	//Load textures
	LoadPVM(path_dlc_textures.c_str(), &maintexlist);

	//Load objects
	for (int i = 0; i < 256; i++)
	{
		if (meta.items[i].level == 0 && meta.items[i].act == 0) break;
		if (!CheckLevelAct(meta.items[i].level, meta.items[i].act)) continue;
		{
			//PrintDebug("Object %d, Level: %d, Act: %d\n", i, meta.items[i].level, meta.items[i].act);
			LoadDLCObject(&meta.items[i]);
		}
	}

	//Load sound
	if (meta.has_mlt && !meta.adx)
	{
		std::string str = "SYSTEM\\DLC\\" + DownloadNameStrings[DownloadID] + "\\" + DownloadNameStrings[DownloadID] + ".DAT";
		//PrintDebug("Loading soundbank: %s\n", str.c_str());
		SoundBankMemoryData[8] = LoadSoundBank(str.c_str(), 1);
	}

	return 1;
}

static void PlayLevelMusic_r(int a1);
static Trampoline PlayLevelMusic_t(0x425800, 0x42580A, PlayLevelMusic_r);
static void __cdecl PlayLevelMusic_r(int a1)
{
	auto original = reinterpret_cast<decltype(PlayLevelMusic_r)*>(PlayLevelMusic_t.Target());
	if (CurrentSong != 68 && CurrentSong != 69 && CurrentSong != 70) original(a1);
}

extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions &helperFunctions)
	{
		if (helperFunctions.Version < 6)
		{
			MessageBox(WindowHandle,
				L"Mod Loader out of date. Dreamcast DLCs mod requires API version 6 or newer.",
				L"Dreamcast DLCs mod error: Mod Loader out of date", MB_OK | MB_ICONERROR);
			return;
		}

		//Lighting
		HMODULE LanternDLL = GetModuleHandle(L"sadx-dc-lighting");
		if (LanternDLL != nullptr) DLLLoaded_Lantern = true;
		material_register_ptr = (void(*)(const NJS_MATERIAL* const* materials, size_t length, lantern_material_cb callback))GetProcAddress(LanternDLL, "material_register");
		set_diffuse_ptr = (void(*)(int32_t, bool))GetProcAddress(LanternDLL, "set_diffuse");

		//Initialize checkerboard texture for circuit menu
		checker_texturedata[0] = 0xAA;
		checker_texturedata[1] = 0x52;
		checker_texturedata[2] = 0xC3;
		checker_texturedata[3] = 0x18;
		checker_texturedata[4] = 0xC3;
		checker_texturedata[5] = 0x18;
		checker_texturedata[6] = 0xAA;
		checker_texturedata[7] = 0x52;
		njSetTextureInfo(&checker_texinfo, (Uint16*)&checker_texturedata, NJD_TEXFMT_VQ | NJD_TEXFMT_RGB_565, 128, 128);
		njSetTextureNameEx(checker_textures, &checker_texinfo, (void*)0xFFFFFFFE, NJD_TEXATTR_GLOBALINDEX | NJD_TEXATTR_TYPE_MEMORY);

		//Write SADX functions
		WriteJump((void*)0x4570B0, InitDownload);
		WriteCall((void*)0x793D06, SetHudColorAndTextureNum_Italic);
		WriteCall((void*)0x793BCC, njDrawQuadTexture_Italic);

		//Mod config stuff
		const std::string s_path(path);
		const std::string s_config_ini(s_path + "\\config.ini");
		const IniFile* const config = new IniFile(s_config_ini);
		MenuVoiceMode = config->getInt("General settings", "MenuVoiceThing", -1);
		SEGAVoice = config->getBool("General settings", "SegaVoice", false);
		MenuVoice_Init();
		GetLocalTime(&CurrentTime);
		srand(CurrentTime.wSecond);
		EnableCircuitMenu = config->getBool("General settings", "CircuitMenu", true);
		SuperSonicRacing = config->getBool("General settings", "SuperSonicRacing", true);
		DisableDuringStory = config->getBool("General settings", "DisableDuringStory", true);

		//Seasonal stuff
		DLCMode = config->getString("General settings", "DLCMode", "Random");

		for (unsigned int i = 0; i < 12; i++)
		{
			MonthlyDLCs[i][0] = config->getInt("Seasonal DLC settings",
				dlcKeyNames[i].dlc1name, dlcKeyNames[i].dlc1id);
			MonthlyDLCs[i][1] = config->getInt("Seasonal DLC settings",
				dlcKeyNames[i].dlc2name, dlcKeyNames[i].dlc2id);
		}

		//DLC modes
		if (DLCMode == "Single")
		{
			DownloadID = config->getInt("General settings", "DLCSingle", 0);
		}
		else if (DLCMode == "Random")
		{
			DownloadID = rand() % 10;
		}
		else if (DLCMode == "Seasonal")
		{
			//NOTE: wMonth is 1-12. Subtract 1 for the array index.
			if (CurrentTime.wDay <= 15)
			{
				//First half of the month
				DownloadID = MonthlyDLCs[CurrentTime.wMonth - 1][0];
			}
			else
			{
				//Second half of the month
				DownloadID = MonthlyDLCs[CurrentTime.wMonth - 1][1];
			}
		}
		delete config;

		//DLC config stuff
		const std::string s_files_ini(helperFunctions.GetReplaceablePath("SYSTEM\\dlc\\files.ini"));
		const IniFile *ini_files = new IniFile(s_files_ini);
		for (int i = 0; i < 16; i++)
		{
			std::string keyname = "File" + std::to_string(i);
			if (ini_files->hasKeyNonEmpty("", keyname))
			{
				//PrintDebug("File: %s\n", ini_files->getString("", keyname, "Ass").c_str());
				DownloadNameStrings[i] = ini_files->getString("", keyname, "Ass");
				//PrintDebug("F: %s\n", DownloadNameStrings[i].c_str());
			}
		}
		delete ini_files;

		//Set paths
		std::string path_download = "SYSTEM\\dlc\\" + DownloadNameStrings[DownloadID] + "\\";
		std::string path_dlc_ini = path_download + DownloadNameStrings[DownloadID] + ".ini";
		path_model = helperFunctions.GetReplaceablePath((path_download + DownloadNameStrings[DownloadID] + ".sa1mdl").c_str());
		path_model_flat = helperFunctions.GetReplaceablePath("SYSTEM\\dlc\\poster.sa1mdl");
		std::string path_dlc_sound = "SYSTEM\\DLC\\" + DownloadNameStrings[DownloadID] + "\\" + DownloadNameStrings[DownloadID] + ".DAT";
		path_dlc_textures = "DLC\\" + DownloadNameStrings[DownloadID] + "\\" + DownloadNameStrings[DownloadID];
		const std::string s_download_ini(helperFunctions.GetReplaceablePath(path_dlc_ini.c_str()));
		//PrintDebug("Path: %s\n", s_download_ini.c_str());

		//Tell which function to use when rendering models
		std::string renderinfo_file = path_download +"renderinfo.ini";
		//PrintDebug("Where: %s\n", renderinfo_file.c_str());
		const IniFile* renderinfo = new IniFile(helperFunctions.GetReplaceablePath(renderinfo_file.c_str()));
		meta.rendermode_model = renderinfo->getInt("", "ModelFunction", 0);
		//PrintDebug("%d\n", renderinfo->getInt("", "ModelFunction", 0));
		meta.rendermode_flat = renderinfo->getInt("", "FlatFunction", 0);
		meta.depth_model = renderinfo->getFloat("", "ModelDepth", 0);
		meta.depth_flat = renderinfo->getFloat("", "FlatDepth", 0);
		delete renderinfo;

		//Load metadata and items
		ini_download = new IniFile(s_download_ini);
		meta.Load(ini_download);
		for (int u = 0; u < 256; u++)
			if (ini_download->hasGroup("Item " + std::to_string(u)))
				meta.items[u].Load(ini_download, u);
		delete ini_download;

		//Check for DAT soundbanks and enable ADX music
		if (meta.has_mlt)
		{
			//PrintDebug("Checking file %s\n", helperFunctions.GetReplaceablePath(path_dlc_sound.c_str()));
			if (!FileExists(helperFunctions.GetReplaceablePath(path_dlc_sound.c_str())))
			{
				std::string file1 = "SYSTEM\\DLC\\" + DownloadNameStrings[DownloadID] + "\\01.ADX";
				std::string file2 = "SYSTEM\\DLC\\" + DownloadNameStrings[DownloadID] + "\\02.ADX";
				std::string file3 = "SYSTEM\\DLC\\" + DownloadNameStrings[DownloadID] + "\\03.ADX";
				meta.adx = true;
				helperFunctions.ReplaceFile("SYSTEM\\SoundData\\BGM\\WMA\\NIGHTS_A.WMA", file1.c_str());
				helperFunctions.ReplaceFile("SYSTEM\\SoundData\\BGM\\WMA\\NIGHTS_K.WMA", file2.c_str());
				helperFunctions.ReplaceFile("SYSTEM\\SoundData\\BGM\\WMA\\NIGHTS_S.WMA", file3.c_str());
				MusicList[68].Loop = true;
				MusicList[69].Loop = true;
				MusicList[70].Loop = true;
			}
			else sndinfo.Filename = DownloadNameStrings[DownloadID].c_str();
		}

		//Fix vanilla SADX levels to be compatible with DLC challenges
		if (LANDTABLESS[3]->Col[136].Radius <= 3949 && LANDTABLESS[3]->Col[136].Radius >= 3946)
		{
			meta.dxmode = true;
			LANDTABLESS[3]->Col[273].Flags = 0x80040000; //Window transparency (Famitsu challenge)
			ADV00SS01_OBJECTS[28]->pos[1] = 20; //Invisible collision in station area (Famitsu challenge)
			//PrintDebug("SADX layout detected\n");
		}
		MusicList[87].Loop = true; //Make Super Sonic Racing loop
	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		if (MenuVoiceMode != -1) MenuVoice_OnFrame();
		if (EnableCircuitMenu) TwinkleCircuitMenu_Display();
	}

	__declspec(dllexport) void __cdecl OnInput()
	{
		//if (ControllerPointers[0]->PressedButtons & Buttons_A) PlaySound(0x567, 0, 0, 0); //SE_DL_DOWNLOAD
		if (EnableCircuitMenu) TwinkleCircuitMenu_Input();
		if (IsGamePaused() && ControllerPointers[0]->PressedButtons & Buttons_Y)
		{
			//PrintDebug("Challenge reset\n");
			for (int i = 0; i < 256; i++)
			{
				timer.enable = false;
				timer.visible = false;
				timer.target_current = 0;
				timer.time_current = 0;
				meta.items[i].collected = false;
			}
		}
	}
}

