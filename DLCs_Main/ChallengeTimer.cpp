#include <stdafx.h>
#include <SADXModLoader.h>
#include "ChallengeTimer.h"
#include "Metadata.h"

void BackupDebugFontSettings();
void RestoreDebugFontSettings();

bool ChallengeTimer::enable;
bool ChallengeTimer::loaded;
bool ChallengeTimer::visible;
Uint32 ChallengeTimer::time_current;
Uint32 ChallengeTimer::time_target;
char ChallengeTimer::target_total;
char ChallengeTimer::target_current;
OBJ_CONDITION ChallengeTimer::setdata_timer;
char ChallengeTimer::highlightchar;
bool ChallengeTimer::timer_flip;
bool ChallengeTimer::pause_flip;
const char** ChallengeTimer::message_foundall;
const char** ChallengeTimer::message_timeup;
const char** ChallengeTimer::message_clear;

std::string ReplaceZeroes(int value)
{
	std::string result;
	if (value >= 10)
		result += std::to_string(value / 10);
	else
		result += "O";
	if (value % 10 != 0)
		result += std::to_string(value % 10);
	else
		result += "O";
	return result;
}

void ChallengeTimer::DisplaySub(task* a1)
{
	if (!visible) return;
	BackupDebugFontSettings();
	//Character grid is 40x30 for 4:3 resolutions, each character is 16x16 for 640x480 at scale 16
	int FontScale = int((float)VerticalResolution / 480.0f);
	int RightColumn = int(floor((float)HorizontalResolution / (16.0f * FontScale)));
	int BottomLine = int(floor((float)VerticalResolution / (16.0f * FontScale)));
	SetDebugFontSize(FontScale * 16);
	//Show prompt if game is paused
	if (IsGamePaused())
	{
		SetDebugFontColor(0x039FEA9E);
		DisplayDebugString(NJM_LOCATION(RightColumn - 10, BottomLine - 7), "- RETRY -");
		if (FrameCounter % 30 == 0) pause_flip = !pause_flip;
		if (pause_flip)
		{
			SetDebugFontColor(0x0381EA80);
			DisplayDebugString(NJM_LOCATION(RightColumn - 9, BottomLine - 6), "PRESS Y");
		}
	}
	else
	{
		if (time_current % 4 == 0) highlightchar++;
		if (highlightchar > 7) highlightchar = 0;
		else if (!enable) highlightchar = 1;
		SetDebugFontColor(0x03F0F049);
		DisplayDebugString(NJM_LOCATION(RightColumn - 9, BottomLine - 7), "[TARGET]");
		//Count display
		if (timer_flip && enable)
		{
			SetDebugFontColor(0x034AEE66);
			DisplayDebugString(NJM_LOCATION(RightColumn - 4, BottomLine - 6), "/");
			SetDebugFontColor(0x035AC3F0);
			DisplayDebugString(NJM_LOCATION(RightColumn - 6, BottomLine - 6), ReplaceZeroes(target_current).c_str()); //Current number of targets
			DisplayDebugString(NJM_LOCATION(RightColumn - 3, BottomLine - 6), ReplaceZeroes(target_total).c_str()); //Total number of targets
		}
		//Target time display
		else
		{
			SetDebugFontColor(0x034AEE66);
			DisplayDebugStringFormatted(NJM_LOCATION(RightColumn - 9, BottomLine - 6), "%s:OO:OO", ReplaceZeroes(time_target).c_str());
		}
		if (highlightchar == 0) SetDebugFontColor(0x03E94202); else SetDebugFontColor(0x03F0C046);
		DisplayDebugString(NJM_LOCATION(RightColumn - 9, BottomLine - 5), "-");
		if (highlightchar == 2) SetDebugFontColor(0x03E94202); else SetDebugFontColor(0x03F0C046);
		DisplayDebugString(NJM_LOCATION(RightColumn - 7, BottomLine - 5), "T");
		if (highlightchar == 3) SetDebugFontColor(0x03E94202); else SetDebugFontColor(0x03F0C046);
		DisplayDebugString(NJM_LOCATION(RightColumn - 6, BottomLine - 5), "I");
		if (highlightchar == 4) SetDebugFontColor(0x03E94202); else SetDebugFontColor(0x03F0C046);
		DisplayDebugString(NJM_LOCATION(RightColumn - 5, BottomLine - 5), "M");
		if (highlightchar == 5) SetDebugFontColor(0x03E94202); else SetDebugFontColor(0x03F0C046);
		DisplayDebugString(NJM_LOCATION(RightColumn - 4, BottomLine - 5), "E");
		if (highlightchar == 7) SetDebugFontColor(0x03E94202); else SetDebugFontColor(0x03F0C046);
		DisplayDebugString(NJM_LOCATION(RightColumn - 2, BottomLine - 5), "-");
		if (highlightchar == 0) SetDebugFontColor(0x03E94202); else SetDebugFontColor(0x0387E1EF);
		DisplayDebugString(NJM_LOCATION(RightColumn - 7, BottomLine - 4), ":");
		DisplayDebugString(NJM_LOCATION(RightColumn - 4, BottomLine - 4), ":");
		SetDebugFontColor(0x03B3DFED);
		DisplayDebugString(NJM_LOCATION(RightColumn - 9, BottomLine - 4), ReplaceZeroes(((time_current / 3600) % 60) % 10).c_str()); //Timer minutes
		DisplayDebugString(NJM_LOCATION(RightColumn - 6, BottomLine - 4), ReplaceZeroes((time_current / 60) % 60).c_str()); //Timer seconds
		DisplayDebugString(NJM_LOCATION(RightColumn - 3, BottomLine - 4), ReplaceZeroes(((time_current * 5 / 3) % 1000) % 100).c_str()); //Timer miliseconds
		if (time_current % 255 == 0)
		{
			timer_flip = !timer_flip;
		}
	}
	RestoreDebugFontSettings();
}

void ChallengeTimer::MainSub(task* a1)
{
	if (enable) time_current++;
	if (visible) DisplaySub(a1);
}

void ChallengeTimer::DeleteSub(task* a1)
{
	loaded = false;
}

void ChallengeTimer::LoadSub(task* a1)
{
	a1->exec = (void(__cdecl*)(task*))MainSub;
	a1->disp = (void(__cdecl*)(task*))DisplaySub;
	a1->dest = (void(__cdecl*)(task*))DeleteSub;
}

void ChallengeTimer::Initialize()
{
	task* obj;
	taskwk* ent;
	if (!loaded)
	{
		obj = CreateElementalTask((LoadObj)2, 3, LoadSub);
		setdata_timer.unionStatus.fRangeOut = 612800.0f;
		obj->ocp = &setdata_timer;
		if (obj)
		{
			ent = obj->twp;
			ent->pos.x = 64;
			ent->pos.y = 64;
			ent->scl.x = 1.0f;
			ent->scl.y = 1.0f;
			ent->scl.z = 1.0f;
		}
	}
	//Load "found all", "clear" and "time up" strings. They're always number 0, 1 and 2 respectively.
	const char** arr_foundall = new const char* [2];
	const char** arr_timeup = new const char* [2];
	const char** arr_clear = new const char* [2];
	switch (TextLanguage)
	{
	case 0:
		arr_foundall[0] = meta.JapaneseStrings[0].c_str();
		arr_clear[0] = meta.JapaneseStrings[1].c_str();
		arr_timeup[0] = meta.JapaneseStrings[2].c_str();
		break;
	case 2:
		arr_foundall[0] = meta.FrenchStrings[0].c_str();
		arr_clear[0] = meta.FrenchStrings[1].c_str();
		arr_timeup[0] = meta.FrenchStrings[2].c_str();
		break;
	case 3:
		arr_foundall[0] = meta.SpanishStrings[0].c_str();
		arr_clear[0] = meta.SpanishStrings[1].c_str();
		arr_timeup[0] = meta.SpanishStrings[2].c_str();
		break;
	case 4:
		arr_foundall[0] = meta.GermanStrings[0].c_str();
		arr_clear[0] = meta.GermanStrings[1].c_str();
		arr_timeup[0] = meta.GermanStrings[2].c_str();
		break;
	case 1:
	default:
		arr_foundall[0] = meta.EnglishStrings[0].c_str();
		arr_clear[0] = meta.EnglishStrings[1].c_str();
		arr_timeup[0] = meta.EnglishStrings[2].c_str();
		break;
	}
	arr_foundall[1] = NULL;
	arr_timeup[1] = NULL;
	arr_clear[1] = NULL;
	message_timeup = arr_timeup;
	message_foundall = arr_foundall;
	message_clear = arr_clear;
	loaded = true;
}