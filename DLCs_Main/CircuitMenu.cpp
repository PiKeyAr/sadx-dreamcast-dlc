#include <stdafx.h>
#include <SADXModLoader.h>
#include <ModelInfo.h>
#include "Metadata.h"
#include "SADXData.h"

//Twinkle Circuit selection screen

unsigned char checker_texturedata[6144];
NJS_TEXINFO checker_texinfo;
NJS_TEXNAME checker_textures[1];
NJS_TEXLIST checker_texlist = {arrayptrandlength(checker_textures)};
NJS_TEXMEMLIST checker_texmemlist;

void BackupDebugFontSettings();
void RestoreDebugFontSettings();
void DrawCenteredDebugRectangle(float leftchar, float topchar, float rightchar, float bottomchar, Uint32 color);
void DisplayCenteredDebugString(std::string str, int hzoffset = 0, int yoffset = -1);
void njDrawSprite2D_DrawNow_Point(NJS_SPRITE* sp, Int n, Float pri, NJD_SPRITE attr);

enum CircuitMenuModes
{
	MODE_DISABLE = 0,
	MODE_ENABLE = 1,
	MODE_CANCEL = 2,
	MODE_WARP = 3,
	MODE_FINISH = 4
};

//Variables
bool stickpress;
int circuitmenu_mode;
int selection;
int offset = 40;
int fadealpha;

//Red glow (selection)
NJS_COLOR redglow_color = {0xFFFFFFFF};
bool redglow;

//Rainbow pattern on selection arrow
NJS_COLOR rainbow[] = {{0xFFFF0000}, {0xFFFF7F00}, {0xFFFFFF00}, {0xFF00FF00}, {0xFF00FFFF}, {0xFF0000FF}, {0xFFFF00FF}};
int rainbow_colormode;

//Checkerboard background
NJS_TEXANIM CheckerboardTexanim = {256, 256, 64, 64, 0, 0, 255, 255, 0, 0};
NJS_SPRITE CheckerboardSprite = {{320, 240, 0.0f }, 60.0f, 60.0f, 0, &checker_texlist, &CheckerboardTexanim};
NJS_COLOR checker_colors[] = {{ 0xFFFF0000 },{ 0xFFFF00FF },{ 0xFF0000FF },{ 0xFF00FFFF },{ 0xFF00FF00 },{ 0xFFFFFF00 }};
NJS_COLOR checker_currentcol = {0xFFFFFF00};
int checker_colindex = 0;
int checker_anglespeed = 2;
int checker_angledir = 1;
float checker_zoomspeed = 0.15f;
int checker_zoomdir = 1;

void CheckerboardCallback(NJS_SPRITE* sprite)
{
	njSetTexture(&checker_texlist);
	njPushMatrix(0);
	njTranslate(0, 0, 0, 0);
	Direct3D_SetZFunc(1u);
	Direct3D_EnableZWrite(0);
	njDrawSprite2D_DrawNow_Point(sprite, 0, -1.0f, NJD_SPRITE_ANGLE | NJD_SPRITE_COLOR | NJD_SPRITE_ALPHA);
	Direct3D_SetZFunc(1u);
	Direct3D_EnableZWrite(1u);
	njPopMatrix(1u);
}

void TwinkleCircuitMenu_Display()
{
	if (CurrentLevel != LevelIDs_StationSquare && CurrentLevel != LevelIDs_TwinkleCircuit)
	{
		circuitmenu_mode = MODE_DISABLE;
		return;
	}
	if (Camera_Data1 == nullptr) return;

	switch (circuitmenu_mode)
	{
	case MODE_DISABLE:
		return;
	case MODE_ENABLE:
		fadealpha = min(255, fadealpha + 8);
		if (offset > 0) offset--;
		ControlEnabled = false;
		if (CharObj2Ptrs[0] != nullptr)
			CharObj2Ptrs[0]->IdleTime = 0;
		break;
	case MODE_CANCEL:
		ControlEnabled = false;
		fadealpha = max(0, fadealpha - 8);
		if (offset < 40) offset++;
		if (offset >= 40)
		{
			offset = 40;
			circuitmenu_mode = MODE_DISABLE;
			ControlEnabled = true;
		}
		break;
	case MODE_WARP:
		fadealpha = 255;
		if (offset < 40) offset++;
		if (CurrentLevel == LevelIDs_TwinkleCircuit) circuitmenu_mode = MODE_FINISH;
		break;
	case MODE_FINISH:
		fadealpha = 0;
		circuitmenu_mode = MODE_DISABLE;
		ControlEnabled = true;
		break;
	}

	//Checkerboard colors
	if (checker_currentcol.argb.r > checker_colors[checker_colindex].argb.r) checker_currentcol.argb.r--;
	if (checker_currentcol.argb.r < checker_colors[checker_colindex].argb.r) checker_currentcol.argb.r++;
	if (checker_currentcol.argb.g > checker_colors[checker_colindex].argb.g) checker_currentcol.argb.g--;
	if (checker_currentcol.argb.g < checker_colors[checker_colindex].argb.g) checker_currentcol.argb.g++;
	if (checker_currentcol.argb.b > checker_colors[checker_colindex].argb.b) checker_currentcol.argb.b--;
	if (checker_currentcol.argb.b < checker_colors[checker_colindex].argb.b) checker_currentcol.argb.b++;
	//PrintDebug("R%03d G%03d B%03d\n", checker_currentcol.argb.r, checker_currentcol.argb.g, checker_currentcol.argb.b);
	if (checker_currentcol.argb.r == checker_colors[checker_colindex].argb.r && checker_currentcol.argb.g == checker_colors[checker_colindex].argb.g && checker_currentcol.argb.b == checker_colors[checker_colindex].argb.b)
		checker_colindex++;
	if (checker_colindex > 5) 
		checker_colindex = 0;

	//Draw checkerboard
	njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
	njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
	CheckerboardSprite.p.x = (float)HorizontalResolution / 2;
	CheckerboardSprite.p.y = (float)VerticalResolution / 2;
	float r = max(0, ((float)checker_currentcol.argb.r - (float)offset * 6.375f) / 255.0f);
	float g = max(0, ((float)checker_currentcol.argb.g - (float)offset * 6.375f) / 255.0f);
	float b = max(0, ((float)checker_currentcol.argb.b - (float)offset * 6.375f) / 255.0f);
	SetMaterialAndSpriteColor_Float((float)fadealpha / 255.0f, r, g, b);
	DrawModelCallback_QueueSprite(CheckerboardCallback, &CheckerboardSprite, 44000.0f, (QueuedModelFlagsB)4);
	
	//Draw background rectangle
	BackupDebugFontSettings();
	//Character grid is 40x30 for 4:3 resolutions, each character is 16x16 for 640x480 at scale 16
	float FontScale = (float)VerticalResolution / 480.0f;
	int RightColumn = int(floor((float)HorizontalResolution / (16.0f * FontScale)));
	int BottomLine = int(floor((float)VerticalResolution / (16.0f * FontScale)));
	DebugFontSize = FontScale * 16.0f;
	DrawCenteredDebugRectangle(4 - offset, 2, 36 - offset, 27, 0x4F808080);
	DrawCenteredDebugRectangle(5 + offset, 3, 35 + offset, 26, 0x3F000000);
	
	//Draw text
	SetDebugFontColor(0xFF00FFFF);
	DisplayCenteredDebugString("WELCOME TO MERCURY GP !!!", 0-offset, 5);
	SetDebugFontColor(0xFFF0F0F0);
	DisplayCenteredDebugString("(UNOFFICIAL)", 0+offset, 6);
	DisplayCenteredDebugString("SELECT A COURSE", 0-offset, 8);
	if (selection == 0)	SetDebugFontColor(redglow_color.color); else	SetDebugFontColor(0xFFF0F0F0);
	DisplayCenteredDebugString("TWINKLE CIRCUIT   ", 0+offset, 11);
	if (selection == 1)	SetDebugFontColor(redglow_color.color); else	SetDebugFontColor(0xFFF0F0F0);
	DisplayCenteredDebugString("EGGMAN`S CHALLENGE", 0-offset, 13);
	if (selection == 2)	SetDebugFontColor(redglow_color.color); else	SetDebugFontColor(0xFFF0F0F0);
	DisplayCenteredDebugString("SAMBA GP          ", 0+offset, 15);
	if (selection == 3)	SetDebugFontColor(redglow_color.color); else	SetDebugFontColor(0xFFF0F0F0);
	DisplayCenteredDebugString("AN UPWARD BATTLE  ", 0-offset, 17);
	if (selection == 4)	SetDebugFontColor(redglow_color.color); else	SetDebugFontColor(0xFFF0F0F0);
	DisplayCenteredDebugString("JUMPS`N`BUMPS     ", 0+offset, 19);
	if (selection == 5)	SetDebugFontColor(redglow_color.color); else	SetDebugFontColor(0xFFF0F0F0);
	DisplayCenteredDebugString("CRAZY CORNERS     ", 0-offset, 21);
	if (selection == 6)	SetDebugFontColor(redglow_color.color); else	SetDebugFontColor(0xFFF0F0F0);
	DisplayCenteredDebugString("EXIT", -7 + offset, 23);

	//Draw rainbow selection thing
	if (offset == 0)
	{
		SetDebugFontColor(rainbow[rainbow_colormode].color);
		DisplayCenteredDebugString(">", -13, 11 + selection * 2);
		SetDebugFontColor(rainbow[rainbow_colormode + 1].color);
		DisplayCenteredDebugString(">", -12, 11 + selection * 2);
		SetDebugFontColor(rainbow[rainbow_colormode + 2].color);
		DisplayCenteredDebugString(">", -11, 11 + selection * 2);
	}

	//Pulsating selection color
	if (FrameCounter % 4 == 0) rainbow_colormode--;
	if (rainbow_colormode < 0) rainbow_colormode = 4;
	if (redglow)
	{
		redglow_color.argb.b = min(255, redglow_color.argb.b + 8);
		if (redglow_color.argb.b >= 255) redglow = 0;
		redglow_color.argb.g = redglow_color.argb.b;
	}
	else
	{
		redglow_color.argb.b = max(0, redglow_color.argb.b - 8);
		if (redglow_color.argb.b <= 0) redglow = 1;
		redglow_color.argb.g = redglow_color.argb.b;
	}

	//Apply checkerboard rotation and zoom effects
	if (checker_zoomspeed > 0)
	{
		CheckerboardSprite.sx += min(1.0f, checker_zoomspeed);
		CheckerboardSprite.sy += min(1.0f, checker_zoomspeed);
	
	}
	else
	{
		CheckerboardSprite.sx += max(-1.0f, checker_zoomspeed);
		CheckerboardSprite.sy += max(-1.0f, checker_zoomspeed);
	}
	checker_zoomspeed += 0.02f * checker_zoomdir;
	if (abs(checker_zoomspeed) > 1.5f)
		checker_zoomdir = -checker_zoomdir;
	checker_anglespeed += checker_angledir;
	if (checker_anglespeed > 160 || checker_anglespeed < -160) checker_angledir = -checker_angledir;
	CheckerboardSprite.ang += checker_anglespeed;
	RestoreDebugFontSettings();
}

void TwinkleCircuitMenu_Init()
{
	circuitmenu_mode = MODE_ENABLE;
	PlayMusic(MusicIDs_ssracing);
	stickpress = true;
	PlaySound(21, 0, 0, 0);

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

	//Load checkerboard texture
	checker_textures[0].texaddr = (Uint32)TexMemList_PixelFormat(&checker_texinfo, 237542221);

}

void TwinkleCircuitMenu_Input()
{
	//Controls
	if (circuitmenu_mode == MODE_ENABLE)
	{
		//Delay
		if (!stickpress)
		{
			if (ControllerPointers[0]->LeftStickY < -100)
			{
				selection--;
				stickpress = true;
				PlaySound(1, 0, 0, 0);
			}
			else if (ControllerPointers[0]->LeftStickY > 100)
			{
				selection++;
				stickpress = true;
				PlaySound(1, 0, 0, 0);
			}
		}
		else if (ControllerPointers[0]->LeftStickY > -100 && ControllerPointers[0]->LeftStickY < 100) stickpress = false;
		if (selection < 0) selection = 6;
		else if (selection > 6) selection = 0;

		//Quit
		if (ControllerPointers[0]->PressedButtons & Buttons_B)
		{
			circuitmenu_mode = MODE_CANCEL;
			PlaySound(22, 0, 0, 0);
		}

		//Select items
		if (ControllerPointers[0]->PressedButtons & Buttons_A || ControllerPointers[0]->PressedButtons & Buttons_Start)
		{
			if (selection == 6)
			{
				circuitmenu_mode = MODE_CANCEL;
				PlaySound(22, 0, 0, 0);
			}
			else
			{
				NextLevel = LevelIDs_TwinkleCircuit;
				NextAct = selection;
				CutsceneMode = 3;
				circuitmenu_mode = MODE_WARP;
				PlaySound(10, 0, 0, 0);
			}
		}
	}
}
