#include <stdafx.h>
#include <SADXModLoader.h>
#include <random>
#include "SegaVoice.h"

Sint8 MenuVoiceMode = 0;
bool SEGAVoice = false;
static int CharacterVoice = 0;
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
	//Code by SonicFreak94

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

void __declspec(naked) PlaySegaSonicTeamVoice_asm()
{
	//Code by SonicFreak94
	__asm
	{
		call DisplayLogoScreen
		add esp, 4
		call PlaySegaSonicTeamVoice
		xor eax, eax
		retn
	}
}

void MenuVoice_Init()
{
	if (SEGAVoice)
	{
		WriteJump((void*)0x0042CCC7, PlaySegaSonicTeamVoice_asm);
		WriteJump((void*)0x0042CD2F, PlaySegaSonicTeamVoice_asm);
		std::random_device r;
		std::mt19937 mt(r());
		std::uniform_int_distribution<int> voice(0, 7);
		std::uniform_int_distribution<int> eggman(0, 1);
		if (MenuVoiceMode >= 0 && MenuVoiceMode < 9) CharacterVoice = max(0, MenuVoiceMode - 1);
		else if (MenuVoiceMode == -2) CharacterVoice = 7;
		else CharacterVoice = voice(mt);
		AlternateEggman = eggman(mt) == 1;
		if (!VoiceLanguage)
		{
			if (CharacterVoice == 5)
			{
				WriteData<1>((char*)0x0042CC9C, 0xFF);
				WriteData<1>((char*)0x0042CD0E, 0xFF);
			}
		}
	}
	if (MenuVoiceMode == 9) MenuVoiceMode = rand() % 8 + 1;
}

void MenuVoice_OnFrame()
{
	if (MenuVoiceMode != -1 && MenuVoiceMode != 9)
	{
		if (MenuVoiceMode == -2) MenuVoice = 0;
		else if (MenuVoiceMode != 10) MenuVoice = MenuVoiceMode;
		else if (FrameCounter % 60 == 0) MenuVoice = rand() % 9;
	}
}