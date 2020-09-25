#include "stdafx.h"
#include "IniFile.hpp"
#include <random>
#include <SADXModLoader.h>
#include "Metadata.h"
#include "ChallengeTimer.h"
#include "SADXData.h"
#include <ModelInfo.h>

//TODO: Write out save files
//TODO: MLT sound/music conversion to DAT/ADX
//TODO: XMAS98 model
//TODO: Kadomatsu model
//TODO: AT&T1 model
//TODO: AT&T goal thing
//TODO: Trigger for circuit menu
//TODO: DLC selection menu

void TwinkleCircuitMenu_Display();
void SetHudColorAndTextureNum_Italic(int n, NJS_COLOR color);
void njDrawQuadTexture_Italic(NJS_QUAD_TEXTURE* points, float scale);
void BackupDebugFontSettings();
void RestoreDebugFontSettings();
void TwinkleCircuitMenu_Input();

NJS_OBJECT* poster_model;
std::string DownloadNameStrings[16];
const char* path_model;
const char* path_model_flat;
DLCMetadata meta;
const IniFile* ini_download;
char DownloadID = 0;
void LoadDLCObject(DLCObjectData* data);

NJS_TEXNAME maintexnames[32];
NJS_TEXLIST maintexlist = {arrayptrandlength(maintexnames)};

NJS_TEXNAME checker_textures[1];
NJS_TEXLIST checker_texlist = {arrayptrandlength(checker_textures)};

std::string path_dlc_textures;

SoundFileInfo sndinfo = {8, "DOWNLOAD"};
SoundList sndlist = {1, &sndinfo };

bool FileExists(const char* filename)
{
	struct stat buffer;
	return (stat(filename, &buffer) == 0);
}

signed int __cdecl InitDownload()
{
	//Load textures
	LoadPVM(path_dlc_textures.c_str(), &maintexlist);
	LoadPVM("DLC\\checker", &checker_texlist);
	//Load objects
	for (int i = 0; i < 256; i++)
	{
		if (meta.items[i].level == 0 && meta.items[i].act == 0) break;
		if (meta.items[i].level != CurrentLevel || meta.items[i].act != CurrentAct) continue;
		else
		{
			//PrintDebug("Object %d, Level: %d, Act: %d\n", i, meta.items[i].level, meta.items[i].act);
			LoadDLCObject(&meta.items[i]);
		}
	}

	//Load sound
	if (meta.has_mlt && !meta.adx)
	{
		std::string str = "SYSTEM\\DLC\\" + DownloadNameStrings[DownloadID] + "\\" + DownloadNameStrings[DownloadID] + ".DAT";
		PrintDebug("Loading soundbank: %s\n", str.c_str());
		SoundBankMemoryData[8] = LoadSoundBank(str.c_str(), 1);
	}

	return 1;
}

DataPointer(int, LoadingOrWhatever, 0x3B28114);

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

		//Write SADX functions
		WriteJump((void*)0x4570B0, InitDownload);
		WriteCall((void*)0x793D06, SetHudColorAndTextureNum_Italic);
		WriteCall((void*)0x793BCC, njDrawQuadTexture_Italic);

		//Config stuff
		const std::string s_files_ini(helperFunctions.GetReplaceablePath("SYSTEM\\dlc\\files.ini"));
		const IniFile *ini_files = new IniFile(s_files_ini);
		for (int i = 0; i < 16; i++)
		{
			std::string keyname = "File" + std::to_string(i);
			if (ini_files->hasKeyNonEmpty("", keyname))
			{
				//PrintDebug("File: %s\n", ini_files->getString("", keyname, "Ass").c_str());
				DownloadNameStrings[i] = ini_files->getString("", keyname, "Ass");
				PrintDebug("F: %s\n", DownloadNameStrings[i].c_str());
			}
		}

		//Set paths
		std::string path_download = "SYSTEM\\dlc\\" + DownloadNameStrings[DownloadID] + "\\";
		std::string path_dlc_ini = path_download + DownloadNameStrings[DownloadID] + ".ini";
		path_model = helperFunctions.GetReplaceablePath((path_download + DownloadNameStrings[DownloadID] + ".sa1mdl").c_str());
		path_model_flat = helperFunctions.GetReplaceablePath("SYSTEM\\dlc\\poster.sa1mdl");
		std::string path_dlc_sound = "SYSTEM\\SoundData\\SE\\" + DownloadNameStrings[DownloadID] + ".dat";
		path_dlc_textures = "DLC\\" + DownloadNameStrings[DownloadID] + "\\" + DownloadNameStrings[DownloadID];
		const std::string s_download_ini(helperFunctions.GetReplaceablePath(path_dlc_ini.c_str()));
		PrintDebug("Path: %s\n", s_download_ini.c_str());

		ModelInfo* mdl = new ModelInfo(path_model_flat);
		poster_model = mdl->getmodel();
		poster_model->basicdxmodel->mats[0].attr_texId = 2;
		poster_model->basicdxmodel->mats[0].diffuse.color = 0xFF00FFFF;

		//Load metadata and items
		ini_download = new IniFile(s_download_ini);
		meta.Load(ini_download);
		for (int u = 0; u < 256; u++)
			if (ini_download->hasGroup("Item " + std::to_string(u)))
				meta.items[u].Load(ini_download, u);

		//Check for DAT soundbanks and enable ADX music
		if (meta.has_mlt)
		{
			PrintDebug("Checking file %s", path_dlc_sound.c_str());
			if (!FileExists(path_dlc_sound.c_str())) meta.adx = true;
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
	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		//CircuitMenu_Display();
	}

	__declspec(dllexport) void __cdecl OnInput()
	{
		//TwinkleCircuitMenu_Input();
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

