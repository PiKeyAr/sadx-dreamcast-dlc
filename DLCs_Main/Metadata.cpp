#include <stdafx.h>
#include "Metadata.h"
#include <SADXModLoader.h>
#include <IniFile.hpp>
#include <ModelInfo.h>
#include "SADXData.h"
#include <WTypes.h>
#include <oleauto.h>

//DLC Metadata
std::string DLCMetadata::title;
std::string DLCMetadata::description;
std::string DLCMetadata::appname;
Uint32 DLCMetadata::dlc_id;
Uint8 DLCMetadata::rendermode_model;
Uint8 DLCMetadata::rendermode_flat;
float DLCMetadata::depth_flat;
float DLCMetadata::depth_model;
bool DLCMetadata::has_mlt;
bool DLCMetadata::chars_sonic;
bool DLCMetadata::chars_tails;
bool DLCMetadata::chars_knuckles;
bool DLCMetadata::chars_e102;
bool DLCMetadata::chars_amy;
bool DLCMetadata::chars_big;
bool DLCMetadata::adx;
bool DLCMetadata::dxmode;
//char DLCMetadata::whatever;
//DLCRegionLocks DLCMetadata::region;
DLCObjectData DLCMetadata::items[256];
std::string DLCMetadata::JapaneseStrings[16];
std::string DLCMetadata::EnglishStrings[16];
std::string DLCMetadata::FrenchStrings[16];
std::string DLCMetadata::SpanishStrings[16];
std::string DLCMetadata::GermanStrings[16];

void AddWhiteDiffuseMaterial(NJS_MATERIAL* material);

std::string UTF8ToANSI(std::string s, UINT codepage)
{
	//https://stackoverflow.com/questions/8298081/convert-utf-8-to-ansi-in-c/35272822#35272822
	BSTR    bstrWide;
	char* pszAnsi;
	int     nLength;
	const char* pszCode = s.c_str();

	nLength = MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, NULL, NULL);
	bstrWide = SysAllocStringLen(NULL, nLength);

	MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, bstrWide, nLength);

	nLength = WideCharToMultiByte(codepage, 0, bstrWide, -1, NULL, 0, NULL, NULL);
	pszAnsi = new char[nLength];

	WideCharToMultiByte(codepage, 0, bstrWide, -1, pszAnsi, nLength, NULL, NULL);
	SysFreeString(bstrWide);

	std::string r(pszAnsi);
	delete[] pszAnsi;
	return r;
}

DLCObjectFlags ParseObjectFlags(std::string flags)
{
	unsigned __int16 result = 0;
	std::string temp;
	for (int i = 0; i < flags.length() + 1; i++)
	{
		if (flags[i] == ',' || i == flags.length())
		{
			//PrintDebug("String: '%s'\n", temp.c_str());
			if (temp == "FLAG_CHALLENGE") result |= FLAG_CHALLENGE;
			else if (temp == "FLAG_SOUND") result |= FLAG_SOUND;
			else if (temp == "UNKNOWN_0") result |= UNKNOWN_0;
			else if (temp == "FLAG_SOLID") result |= FLAG_SOLID;
			else if (temp == "FLAG_MESSAGE") result |= FLAG_MESSAGE;
			else if (temp == "FLAG_COLLISION_ONLY") result |= FLAG_COLLISION_ONLY;
			else if (temp == "FLAG_WARP") result |= FLAG_WARP;
			else if (temp == "FLAG_COLLECTIBLE") result |= FLAG_COLLECTIBLE;
			else if (temp == "FLAG_TIMER") result |= FLAG_TIMER;
			temp = "";
		}
		if (flags[i] != ' ' && flags[i] != ',' && i < flags.length()) temp += flags[i];
		//PrintDebug("F: %d", flags[i]);
	}
	//PrintDebug("Flags: %X\n", result);
	return (DLCObjectFlags)result;
}

DLCObjectTypes ParseObjectType(std::string type)
{
	int result = 0;
	if (type[type.length() - 1] == ' ') type = type.substr(0, type.length() - 1);
	if (type == "TYPE_MODEL") result |= TYPE_MODEL;
	else if (type == "TYPE_SPRITE") result |= TYPE_SPRITE;
	else if (type == "TYPE_INVISIBLE") result |= TYPE_INVISIBLE;
	//PrintDebug("Type: %d\n", result);
	return (DLCObjectTypes)result;
}

void DLCObjectData::Load(const IniFile* ini, Uint8 id)
{
	std::string item = "Item " + std::to_string(id);
	level = ini->getInt(item, "Level", 0);
	act = ini->getInt(item, "Act", 0);
	scale_x = (float)(ini->getInt(item, "ScaleX", 10) / 10.0f);
	scale_y = (float)(ini->getInt(item, "ScaleY", 10) / 10.0f);
	scale_z = (float)(ini->getInt(item, "ScaleZ", 10) / 10.0f);
	rotspeed_x = ini->getInt(item, "RotSpeedX", 0);
	rotspeed_y = ini->getInt(item, "RotSpeedY", 0);
	rotspeed_z = ini->getInt(item, "RotSpeedZ", 0);
	objecttype = ParseObjectType(ini->getString(item, "ObjectType", "TYPE_INVISIBLE"));
	textureid = ini->getInt(item, "TextureID", 0);
	flags = ParseObjectFlags(ini->getString(item, "Flags", ""));
	//PrintDebug("Object %d flags %X\n", id, flags);
	objectid = ini->getInt(item, "CollectibleID", 0);
	message = ini->getInt(item, "MessageID", 0);
	radius = (float)ini->getInt(item, "TriggerRadius", 0);
	warplevel = ini->getInt(item, "WarpLevelOrSoundbank", 0);
	sound = ini->getInt(item, "WarpActOrSoundID", 0);
	rot_x = ini->getInt(item, "RotationX", 0);
	rot_y = ini->getInt(item, "RotationY", 0);
	rot_z = ini->getInt(item, "RotationZ", 0);
	collected = false;
	x = (float)ini->getInt(item, "X", 0);
	y = (float)ini->getInt(item, "Y", 0);
	z = (float)ini->getInt(item, "Z", 0);
	//PrintDebug("Item: %s, Level: %d\n", item.c_str(), level);
	ModelInfo* modelfile = new ModelInfo(path_model);
	ModelInfo* modelfile_flat = new ModelInfo(path_model_flat);
	//Load models
	switch (objecttype)
	{
	case TYPE_MODEL:
	{
		//PrintDebug("Loading model: %s\n", path_model);
		NJS_OBJECT* model_full = modelfile->getmodel();
		model = model_full;
		if (textureid != 0) model->basicdxmodel->mats[0].attr_texId = textureid;
		if (model->basicdxmodel->mats[0].attrflags & NJD_FLAG_IGNORE_LIGHT && model->basicdxmodel->mats[1].attrflags & NJD_FLAG_IGNORE_LIGHT) //stupid hack but idk
		{
			for (int u = 1; u < model->basicdxmodel->nbMat; u++)
				AddWhiteDiffuseMaterial(&model->basicdxmodel->mats[u]);
		}
		//if (model_full == nullptr) PrintDebug("NULL");
		break;
	}
	case TYPE_SPRITE:
	{
		//PrintDebug("Loading model: %s\n", path_model);
		NJS_OBJECT* model_flat = modelfile_flat->getmodel();
		model = model_flat;
		//model->basicdxmodel->mats[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
		if (textureid != 0) model->basicdxmodel->mats[0].attr_texId = textureid;
		break;
	}
	case TYPE_INVISIBLE:
		model = NULL;
		break;
	}
	if (flags & FLAG_COLLISION_ONLY)
		model = NULL;
}

void DLCObjectData::Info(Uint8 id)
{
	return;
}

void DLCMetadata::Load(const IniFile* ini)
{
	title = ini->getString("", "Title", "None");
	description = ini->getString("", "Description", "None");
	appname= ini->getString("", "Author", "None");
	dlc_id = ini->getInt("", "Identifier", 0);
	has_mlt = ini->getBool("", "ContainsSound", false);
	chars_sonic = ini->getBool("", "EnableSonic", false);
	chars_tails = ini->getBool("", "EnableTails", false);
	chars_knuckles = ini->getBool("", "EnableKnuckles", false);
	chars_e102 = ini->getBool("", "EnableGamma", false);
	chars_amy = ini->getBool("", "EnableAmy", false);
	chars_big = ini->getBool("", "EnableBig", false);
	//char whatever;
	//DLCRegionLocks region;
	for (int s = 0; s < 16; s++)
	{
		JapaneseStrings[s] = UTF8ToANSI(ini->getString("", "JapaneseMessage" + std::to_string(s), ""), 932);
		EnglishStrings[s] = UTF8ToANSI(ini->getString("", "EnglishMessage" + std::to_string(s), ""), 932);
		FrenchStrings[s] = UTF8ToANSI(ini->getString("", "FrenchMessage" + std::to_string(s), ""), Codepage);
		SpanishStrings[s] = UTF8ToANSI(ini->getString("", "SpanishMessage" + std::to_string(s), ""), Codepage);
		GermanStrings[s] = UTF8ToANSI(ini->getString("", "GermanMessage" + std::to_string(s), ""), Codepage);
	}
}

void DLCMetadata::Info()
{
	PrintDebug("Title: %s\n", title.c_str());
	PrintDebug("Description: %s\n", description.c_str());
	PrintDebug("Author: %s\n", appname.c_str());
	PrintDebug("ID: %d\n", dlc_id);
	PrintDebug("Has MLT: %d\n", has_mlt);
	PrintDebug("Characters: ");
	if (chars_sonic) PrintDebug("Sonic ");
	if (chars_tails) PrintDebug("Tails ");
	if (chars_knuckles) PrintDebug("Knuckles ");
	if (chars_e102) PrintDebug("Gamma ");
	if (chars_amy) PrintDebug("Amy ");
	if (chars_big) PrintDebug("Big ");
	PrintDebug("\n");
	for (int s = 0; s < 16; s++)
	{
		PrintDebug("E.String %d: %s\n", s, EnglishStrings[s].c_str());
	}
}
