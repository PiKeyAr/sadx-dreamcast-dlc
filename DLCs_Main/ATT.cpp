// AT&T DLC functions.
#include <stdafx.h>
#include "ATT.h"
#include "Data/DLC_ATT.h"

const PVMEntry ATT1Textures = { "SONICADV_504", (TexList *)&texlist_att1 };
const PVMEntry ATT2Textures = { "SONICADV_506", (TexList *)&texlist_att2 };
const PVMEntry ATT3Textures = { "SONICADV_508", (TexList *)&texlist_att3 };

static void ATTTimer_Display(ObjectMaster *a1)
{
	//List stuff for results
	TimerTenMinutesTexanim.texid = (((ChallengeTimer / 3600) % 60) / 10) % 10;
	TimerMinutesTexanim.texid = ((ChallengeTimer / 3600) % 60) % 10;
	TimerTenSecondsTexanim.texid = (((ChallengeTimer / 60) % 60) / 10) % 10;
	TimerSecondsTexanim.texid = ((ChallengeTimer / 60) % 60) % 10;
	TimerMTenSecondsTexanim.texid = (((ChallengeTimer * 5 / 3) % 1000) / 10) % 10;
	TimerMSecondsTexanim.texid = ((ChallengeTimer * 5 / 3) % 1000) % 10;
	//Debug timer version
	if (!HDTimer)
	{
		DebugTimer_Miliseconds = ((ChallengeTimer * 5 / 3) % 1000) % 100;
		DebugTimer_Seconds = (ChallengeTimer / 60) % 60;
		DebugTimer_Minutes = (ChallengeTimer / 3600) % 60;
		DebugTimer_Current = CollectedAll;
		if (CurrentCharacter == 2) DebugTimer_Total = 10;
		else if (CurrentCharacter == 3) DebugTimer_Total = 4;
		DrawDebugTimer();
	}
	else
	{
		if (CurrentCharacter == 0)
		{
			TimerTenMinutesTexanim.sx = 16 * HorizontalStretch;
			TimerTenMinutesTexanim.sy = 16 * HorizontalStretch;
			TimerMinutesTexanim.sx = 16 * HorizontalStretch;
			TimerMinutesTexanim.sy = 16 * HorizontalStretch;
			TimerColon1Texanim.sx = 16 * HorizontalStretch;
			TimerColon1Texanim.sy = 16 * HorizontalStretch;
			TimerTenSecondsTexanim.sx = 16 * HorizontalStretch;
			TimerTenSecondsTexanim.sy = 16 * HorizontalStretch;
			TimerSecondsTexanim.sx = 16 * HorizontalStretch;
			TimerSecondsTexanim.sy = 16 * HorizontalStretch;
			TimerColon2Texanim.sx = 16 * HorizontalStretch;
			TimerColon2Texanim.sy = 16 * HorizontalStretch;
			TimerMTenSecondsTexanim.sx = 16 * HorizontalStretch;
			TimerMTenSecondsTexanim.sy = 16 * HorizontalStretch;
			TimerMSecondsTexanim.sx = 16 * HorizontalStretch;
			TimerMSecondsTexanim.sy = 16 * HorizontalStretch;
			njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
			njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
			njSetTexture((NJS_TEXLIST*)0x00912DF4);
			SetMaterialAndSpriteColor_Float(1.0f, 1.0f, 1.0f, 1.0f);
			//Draw timer tenminutes
			TimerTenMinutesTexanim.texid = (((ChallengeTimer / 3600) % 60) / 10) % 10;
			njDrawSprite2D_ForcePriority(&TimerTenMinutes, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer minutes
			TimerMinutesTexanim.texid = ((ChallengeTimer / 3600) % 60) % 10;
			njDrawSprite2D_ForcePriority(&TimerMinutes, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw minute colon
			TimerColon1Texanim.texid = 10;
			njDrawSprite2D_ForcePriority(&TimerColon1, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer tenseconds
			TimerTenSecondsTexanim.texid = (((ChallengeTimer / 60) % 60) / 10) % 10;
			njDrawSprite2D_ForcePriority(&TimerTenSeconds, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer seconds
			TimerSecondsTexanim.texid = ((ChallengeTimer / 60) % 60) % 10;
			njDrawSprite2D_ForcePriority(&TimerSeconds, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw minute colon
			TimerColon2Texanim.texid = 10;
			njDrawSprite2D_ForcePriority(&TimerColon2, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer militenseconds
			TimerMTenSecondsTexanim.texid = (((ChallengeTimer * 5 / 3) % 1000) / 10) % 10;
			njDrawSprite2D_ForcePriority(&TimerMTenSeconds, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer miliseconds
			TimerMSecondsTexanim.texid = ((ChallengeTimer * 5 / 3) % 1000) % 10;
			njDrawSprite2D_ForcePriority(&TimerMSeconds, 0, 22046.498f, NJD_SPRITE_ALPHA);
			ClampGlobalColorThing_Thing();
		}
		if (CurrentCharacter == 3)
		{
			CardCountTexanim.sx = 16 * HorizontalStretch;
			CardCountTexanim.sy = 16 * HorizontalStretch;
			CardCountSlashTexanim.sx = 16 * HorizontalStretch;
			CardCountSlashTexanim.sy = 16 * HorizontalStretch;
			CardCountTotalTexanim.sx = 16 * HorizontalStretch;
			CardCountTotalTexanim.sy = 16 * HorizontalStretch;
			TimerTenMinutesTexanim.sx = 16 * HorizontalStretch;
			TimerTenMinutesTexanim.sy = 16 * HorizontalStretch;
			TimerMinutesTexanim.sx = 16 * HorizontalStretch;
			TimerMinutesTexanim.sy = 16 * HorizontalStretch;
			TimerColon1Texanim.sx = 16 * HorizontalStretch;
			TimerColon1Texanim.sy = 16 * HorizontalStretch;
			TimerTenSecondsTexanim.sx = 16 * HorizontalStretch;
			TimerTenSecondsTexanim.sy = 16 * HorizontalStretch;
			TimerSecondsTexanim.sx = 16 * HorizontalStretch;
			TimerSecondsTexanim.sy = 16 * HorizontalStretch;
			TimerColon2Texanim.sx = 16 * HorizontalStretch;
			TimerColon2Texanim.sy = 16 * HorizontalStretch;
			TimerMTenSecondsTexanim.sx = 16 * HorizontalStretch;
			TimerMTenSecondsTexanim.sy = 16 * HorizontalStretch;
			TimerMSecondsTexanim.sx = 16 * HorizontalStretch;
			TimerMSecondsTexanim.sy = 16 * HorizontalStretch;
			njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
			njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
			njSetTexture((NJS_TEXLIST*)0x00912DF4);
			SetMaterialAndSpriteColor_Float(1.0f, 1.0f, 1.0f, 1.0f);
			//Draw count
			CardCountTexanim.texid = CollectedAll;
			njDrawSprite2D_ForcePriority(&CardCount, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw slash
			CardCountSlashTexanim.texid = 73;
			njDrawSprite2D_ForcePriority(&CardCountSlash, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw total
			CardCountTotalTexanim.texid = 4;
			njDrawSprite2D_ForcePriority(&CardCountTotal, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer tenminutes
			TimerTenMinutesTexanim.texid = (((ChallengeTimer / 3600) % 60) / 10) % 10;
			njDrawSprite2D_ForcePriority(&TimerTenMinutes, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer minutes
			TimerMinutesTexanim.texid = ((ChallengeTimer / 3600) % 60) % 10;
			njDrawSprite2D_ForcePriority(&TimerMinutes, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw minute colon
			TimerColon1Texanim.texid = 10;
			njDrawSprite2D_ForcePriority(&TimerColon1, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer tenseconds
			TimerTenSecondsTexanim.texid = (((ChallengeTimer / 60) % 60) / 10) % 10;
			njDrawSprite2D_ForcePriority(&TimerTenSeconds, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer seconds
			TimerSecondsTexanim.texid = ((ChallengeTimer / 60) % 60) % 10;
			njDrawSprite2D_ForcePriority(&TimerSeconds, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw minute colon
			TimerColon2Texanim.texid = 10;
			njDrawSprite2D_ForcePriority(&TimerColon2, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer militenseconds
			TimerMTenSecondsTexanim.texid = (((ChallengeTimer * 5 / 3) % 1000) / 10) % 10;
			njDrawSprite2D_ForcePriority(&TimerMTenSeconds, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer miliseconds
			TimerMSecondsTexanim.texid = ((ChallengeTimer * 5 / 3) % 1000) % 10;
			njDrawSprite2D_ForcePriority(&TimerMSeconds, 0, 22046.498f, NJD_SPRITE_ALPHA);
			ClampGlobalColorThing_Thing();
		}
		if (CurrentCharacter == 2)
		{
			CardTenCountTexanim.sx = 16 * HorizontalStretch;
			CardTenCountTexanim.sy = 16 * HorizontalStretch;
			CardCountTexanim.sx = 16 * HorizontalStretch;
			CardCountTexanim.sy = 16 * HorizontalStretch;
			CardCountSlashTexanim.sx = 16 * HorizontalStretch;
			CardCountSlashTexanim.sy = 16 * HorizontalStretch;
			CardCountTotalTexanim.sx = 16 * HorizontalStretch;
			CardCountTotalTexanim.sy = 16 * HorizontalStretch;
			CardCountTotal2Texanim.sx = 16 * HorizontalStretch;
			CardCountTotal2Texanim.sy = 16 * HorizontalStretch;
			TimerTenMinutesTexanim.sx = 16 * HorizontalStretch;
			TimerTenMinutesTexanim.sy = 16 * HorizontalStretch;
			TimerMinutesTexanim.sx = 16 * HorizontalStretch;
			TimerMinutesTexanim.sy = 16 * HorizontalStretch;
			TimerColon1Texanim.sx = 16 * HorizontalStretch;
			TimerColon1Texanim.sy = 16 * HorizontalStretch;
			TimerTenSecondsTexanim.sx = 16 * HorizontalStretch;
			TimerTenSecondsTexanim.sy = 16 * HorizontalStretch;
			TimerSecondsTexanim.sx = 16 * HorizontalStretch;
			TimerSecondsTexanim.sy = 16 * HorizontalStretch;
			TimerColon2Texanim.sx = 16 * HorizontalStretch;
			TimerColon2Texanim.sy = 16 * HorizontalStretch;
			TimerMTenSecondsTexanim.sx = 16 * HorizontalStretch;
			TimerMTenSecondsTexanim.sy = 16 * HorizontalStretch;
			TimerMSecondsTexanim.sx = 16 * HorizontalStretch;
			TimerMSecondsTexanim.sy = 16 * HorizontalStretch;
			njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
			njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
			njSetTexture((NJS_TEXLIST*)0x00912DF4);
			SetMaterialAndSpriteColor_Float(1.0f, 1.0f, 1.0f, 1.0f);
			//Draw count 10
			if (CollectedAll < 10) CardTenCountTexanim.texid = 0; else CardTenCountTexanim.texid = 1;
			njDrawSprite2D_ForcePriority(&CardTenCount, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw count
			if (CollectedAll < 10) CardCountTexanim.texid = CollectedAll; else CardCountTexanim.texid = 0;
			njDrawSprite2D_ForcePriority(&CardCount, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw slash
			CardCountSlashTexanim.texid = 73;
			njDrawSprite2D_ForcePriority(&CardCountSlash, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw total
			CardCountTotalTexanim.texid = 1;
			njDrawSprite2D_ForcePriority(&CardCountTotal, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw total 2
			CardCountTotal2Texanim.texid = 0;
			njDrawSprite2D_ForcePriority(&CardCountTotal2, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer tenminutes
			njDrawSprite2D_ForcePriority(&TimerTenMinutes, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer minutes
			njDrawSprite2D_ForcePriority(&TimerMinutes, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw minute colon
			TimerColon1Texanim.texid = 10;
			njDrawSprite2D_ForcePriority(&TimerColon1, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer tenseconds
			njDrawSprite2D_ForcePriority(&TimerTenSeconds, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer seconds
			njDrawSprite2D_ForcePriority(&TimerSeconds, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw minute colon
			TimerColon2Texanim.texid = 10;
			njDrawSprite2D_ForcePriority(&TimerColon2, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer militenseconds
			njDrawSprite2D_ForcePriority(&TimerMTenSeconds, 0, 22046.498f, NJD_SPRITE_ALPHA);
			//Draw timer miliseconds
			njDrawSprite2D_ForcePriority(&TimerMSeconds, 0, 22046.498f, NJD_SPRITE_ALPHA);
			ClampGlobalColorThing_Thing();
		}
	}
}

static void ATTTimer_Main(ObjectMaster *a1)
{
	if (CurrentCharacter == 0)
	{
		if (ChallengeAction)
		{
			ChallengeTimer++;
			ATTTimer_Display(a1);
		}
		if (((((ChallengeTimer / 3600) % 60) / 10) % 10) >= 1)
		{
			ChallengeOver = true;
		}
	}
	if (CurrentCharacter == 3)
	{
		CollectedAll = Treasure1 + Treasure2 + Treasure3 + Treasure4;
		if (ChallengeAction)
		{
			ChallengeTimer++;
			ATTTimer_Display(a1);
		}
		if ((((ChallengeTimer / 3600) % 60) % 10) >= 5)
		{
			ChallengeOver = true;
		}
		if (ChallengeAction && ChallengeTimer % 3600 == 0)
		{
			PlaySound(4, 0, 0, 0);
		}
	}
	if (CurrentCharacter == 2)
	{
		CollectedAll = Gate1 + Gate2 + Gate3 + Gate4 + Gate5 + Gate6 + Gate7 + Gate8 + Gate9 + Gate10;
		if (ChallengeAction)
		{
			ChallengeTimer++;
			ATTTimer_Display(a1);
		}
		if ((((ChallengeTimer / 3600) % 60) % 10) >= 3 && !ChallengeOver)
		{
			ChallengeOver = true;
			DisplayHintText(ATT3_Message2, 120);
		}
		if (ChallengeAction && ChallengeTimer % 3600 == 0)
		{
			PlaySound(4, 0, 0, 0);
		}
	}
}

void ATTTimer_Load(ObjectMaster *a1)
{
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))ATTTimer_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))ATTTimer_Display;
	a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
}

static void ATTObject_Display(ObjectMaster *a1)
{
	EntityData1 *v1;
	Angle v2;
	Angle v3;
	Angle v4;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		if (CurrentCharacter == 0)
		{
			njSetTexture(&texlist_att1);
			njPushMatrix(0);
			njTranslateV(0, &v1->Position);
			v2 = v1->Rotation.x;
			v3 = v1->Rotation.y;
			v4 = v1->Rotation.z;
			njRotateXYZ(0, v2, v3, v4);
			njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
			if (v1->CharID == 10) ProcessModelNode_AB_Wrapper(&poster_att1_big, v1->Scale.x);
			if (v1->CharID == 12) ProcessModelNode_AB_Wrapper(&object_00000CE4, v1->Scale.x);
			if (v1->CharID == 13)
			{
				if (v1->Action == 1)
				{
					matlist_att1Z[0].attrflags |= NJD_FLAG_USE_ALPHA;
					if (matlist_att1Z[0].diffuse.argb.a > 8) matlist_att1Z[0].diffuse.argb.a = matlist_att1Z[0].diffuse.argb.a - 8;
				}
				else
				{
					matlist_att1Z[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
					if (matlist_att1Z[0].diffuse.argb.a < 255) matlist_att1Z[0].diffuse.argb.a = matlist_att1Z[0].diffuse.argb.a + 8;
				}
				if (matlist_att1Z[0].diffuse.argb.a > 255) matlist_att1Z[0].diffuse.argb.a = 255;
				ProcessModelNode_AB_Wrapper(&poster_att1_start, v1->Scale.x);
			}
			if (v1->CharID == 14 && HighwayGoal)
			{
				if (v1->Action == 1)
				{
					matlist_att1W[0].attrflags |= NJD_FLAG_USE_ALPHA;
					if (matlist_att1W[0].diffuse.argb.a > 8) matlist_att1W[0].diffuse.argb.a = matlist_att1W[0].diffuse.argb.a - 8;
				}
				else
				{
					matlist_att1W[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
					if (matlist_att1W[0].diffuse.argb.a < 255) matlist_att1W[0].diffuse.argb.a = matlist_att1W[0].diffuse.argb.a + 8;
				}
				if (matlist_att1W[0].diffuse.argb.a > 255) matlist_att1W[0].diffuse.argb.a = 255;
				ProcessModelNode_AB_Wrapper(&poster_att1_goal, v1->Scale.x);
			}
			njPopMatrix(1u);
		}
		if (CurrentCharacter == 3)
		{
			njSetTexture(&texlist_att2);
			njPushMatrix(0);
			njTranslateV(0, &v1->Position);
			v2 = v1->Rotation.x;
			v3 = v1->Rotation.y;
			v4 = v1->Rotation.z;
			njRotateXYZ(0, v2, v3, v4);
			njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
			if (v1->CharID == 21) ProcessModelNode_AB_Wrapper(&object_000006D0, v1->Scale.x);
			if (v1->CharID == 22)
			{
				if (v1->Action == 1)
				{
					matlist_att2W[0].attrflags |= NJD_FLAG_USE_ALPHA;
					if (matlist_att2W[0].diffuse.argb.a > 8) matlist_att2W[0].diffuse.argb.a = matlist_att2W[0].diffuse.argb.a - 8;
				}
				else
				{
					matlist_att2W[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
					if (matlist_att2W[0].diffuse.argb.a < 255) matlist_att2W[0].diffuse.argb.a = matlist_att2W[0].diffuse.argb.a + 8;
				}
				if (matlist_att2W[0].diffuse.argb.a > 255) matlist_att2W[0].diffuse.argb.a = 255;
				ProcessModelNode_AB_Wrapper(&poster_att2_goal, v1->Scale.x);
			}
			if (v1->CharID == 23)
			{
				if (v1->Action == 1)
				{
					matlist_att2Z[0].attrflags |= NJD_FLAG_USE_ALPHA;
					if (matlist_att2Z[0].diffuse.argb.a > 8) matlist_att2Z[0].diffuse.argb.a = matlist_att2Z[0].diffuse.argb.a - 8;
				}
				else
				{
					matlist_att2Z[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
					if (matlist_att2Z[0].diffuse.argb.a < 255) matlist_att2Z[0].diffuse.argb.a = matlist_att2Z[0].diffuse.argb.a + 8;
				}
				if (matlist_att2Z[0].diffuse.argb.a > 255) matlist_att2Z[0].diffuse.argb.a = 255;
				ProcessModelNode_AB_Wrapper(&poster_att2_start, v1->Scale.x);
			}
			njPopMatrix(1u);
		}
		if (CurrentCharacter == 2)
		{
			njSetTexture(&texlist_att3);
			njPushMatrix(0);
			njTranslateV(0, &v1->Position);
			v2 = v1->Rotation.x;
			v3 = v1->Rotation.y;
			v4 = v1->Rotation.z;
			njRotateXYZ(0, v2, v3, v4);
			njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
			if (v1->CharID == 31) ProcessModelNode_AB_Wrapper(&poster_att3, v1->Scale.x);
			if (v1->CharID == 32) ProcessModelNode_AB_Wrapper(&poster_att3_att, v1->Scale.x);
			if (v1->CharID == 33)
			{
				if (v1->Action == 1)
				{
					matlist_att3Z[0].attrflags |= NJD_FLAG_USE_ALPHA;
					if (matlist_att3Z[0].diffuse.argb.a > 8) matlist_att3Z[0].diffuse.argb.a = matlist_att3Z[0].diffuse.argb.a - 8;
				}
				else
				{
					matlist_att3Z[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
					if (matlist_att3Z[0].diffuse.argb.a < 255) matlist_att3Z[0].diffuse.argb.a = matlist_att3Z[0].diffuse.argb.a + 8;
				}
				if (matlist_att3Z[0].diffuse.argb.a > 255) matlist_att3Z[0].diffuse.argb.a = 255;
				ProcessModelNode_AB_Wrapper(&poster_att3_start, v1->Scale.x);
			}
			if (v1->CharID == 34) ProcessModelNode_AB_Wrapper(&object_00001210, v1->Scale.x);
			if (v1->CharID == 35)
			{
				if (v1->Action == 1)
				{
					matlist_att3W[0].attrflags |= NJD_FLAG_USE_ALPHA;
					if (matlist_att3W[0].diffuse.argb.a > 8) matlist_att3W[0].diffuse.argb.a = matlist_att3W[0].diffuse.argb.a - 8;
				}
				else
				{
					matlist_att3W[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
					if (matlist_att3W[0].diffuse.argb.a < 255) matlist_att3W[0].diffuse.argb.a = matlist_att3W[0].diffuse.argb.a + 8;
				}
				if (matlist_att3W[0].diffuse.argb.a > 255) matlist_att3W[0].diffuse.argb.a = 255;
				ProcessModelNode_AB_Wrapper(&poster_att3_goal, v1->Scale.x);
			}
			njPopMatrix(1u);
		}
	}
}

static void ATTObject_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
	v1 = a1->Data1;
	Angle v2;
	int v3;
	v3 = (v1->Index) * 16;
	v2 = (v1->Rotation.y + v3) % 65535;
	v1->Rotation.y = v2;
	if (CurrentCharacter == 0)
	{
		if (v1->CharIndex == 3 && !ChallengeAction) v1->Action = 0;
		if (v1->CharIndex == 3 && ChallengeAction) v1->Action = 1;
		if (v1->CharIndex == 4 && ChallengeAction) v1->Action = 0;
		if (v1->CharIndex == 4 && !ChallengeAction) v1->Action = 1;
		if (v1->Action == 1 && v1->Scale.x > 0.05f)
		{
			v1->Scale.x = v1->Scale.x*0.95f;
			v1->Scale.y = v1->Scale.y*0.95f;
			v1->Scale.z = v1->Scale.z*0.95f;
		}
		if (v1->Action != 1 && v1->Scale.x < 1.0f)
		{
			v1->Scale.x = v1->Scale.x*1.05f;
			v1->Scale.y = v1->Scale.y*1.05f;
			v1->Scale.z = v1->Scale.z*1.05f;
			if (v1->Scale.y >= 1.0f)
			{
				v1->Scale.x = 1.0f;
				v1->Scale.y = 1.0f;
				v1->Scale.z = 1.0f;
			}
		}
		if (v1->Action != 1 && IsPlayerInsideSphere(&v1->Position, 15))
		{
			if (HintTimer <= 0)
			{
				//Go back to Station Square
				if (v1->CharIndex == 7 && ChallengeAction)
				{
					PlaySound(12, 0, 0, 0);
					DisplayHintText(ATT1_Message4, 180);
					HighwayGoal = true;
					v1->Action = 1;
					sub_412D80(LevelIDs_StationSquare, 3);
					HintTimer = 120;
				}
				//Start plate
				if (v1->CharIndex == 3 && !ChallengeAction)
				{
					PlaySound(12, 0, 0, 0);
					DisplayHintText(ATT1_Message5, 180);
					HighwayGoal = false;
					ChallengeTimer = 0;
					ChallengeAction = true;
					DebugTimer_MaxMins = 5;
					ChallengeOver = false;
					v1->Action = 1;
					sub_412D80(LevelIDs_SpeedHighway, 0);
					HintTimer = 60;
				}
				//Goal plate
				if (v1->CharIndex == 4 && HighwayGoal && !ChallengeOver)
				{
					v1->Action = 1;
					PlaySound(12, 0, 0, 0);
					snprintf(ResultText, LengthOfArray(ResultText),
						"Your result is: %d%d:%d%d:%d%d.",
						TimerTenMinutesTexanim.texid, TimerMinutesTexanim.texid,
						TimerTenSecondsTexanim.texid, TimerSecondsTexanim.texid,
						TimerMTenSecondsTexanim.texid, TimerMSecondsTexanim.texid);
					DisplayHintText(ATT1_Message7, 180);
					ChallengeAction = false;
					ChallengeOver = false;
					ChallengeTimer = 0;
					HintTimer = 500;
				}
				//Goal plate (time over)
				if (v1->CharIndex == 4 && ChallengeOver)
				{
					v1->Action = 1;
					PlaySound(12, 0, 0, 0);
					DisplayHintText(ATT1_Message3, 180);
					ChallengeAction = false;
					ChallengeOver = false;
					ChallengeTimer = 0;
					HintTimer = 300;
				}
				//Poster 1
				if (v1->CharIndex == 6 && CurrentLevel == 26)
				{
					PlaySound(23, 0, 0, 0);
					DisplayHintText(ATT1_Message2, 180);
					HintTimer = 60;
				}
				//Poster 2
				if (v1->CharIndex == 5 && CurrentLevel == 26)
				{
					PlaySound(23, 0, 0, 0);
					DisplayHintText(ATT1_Message1, 180);
					HintTimer = 60;
				}
				//You can't continue from here
				if (v1->CharIndex == 10)
				{
					PlaySound(23, 0, 0, 0);
					DisplayHintText(ATT1_Message6, 180);
					HintTimer = 60;
				}
			}
		}
		if (v1->Scale.x > 0.1f) ATTObject_Display(a1);
	}
	if (CurrentCharacter == 3)
	{
		if ((CurrentLevel == 26 && CurrentAct == 3) || (CurrentLevel == 33 && CurrentAct == 0))
		{
			if (v1->CharIndex == 3 && !ChallengeAction) v1->Action = 0;
			if (v1->CharIndex == 3 && ChallengeAction) v1->Action = 1;
			if (v1->CharIndex == 4 && ChallengeAction) v1->Action = 0;
			if (v1->CharIndex == 4 && !ChallengeAction) v1->Action = 1;
			if (v1->Action == 1 && v1->Scale.x > 0.05f)
			{
				v1->Scale.x = v1->Scale.x*0.95f;
				v1->Scale.y = v1->Scale.y*0.95f;
				v1->Scale.z = v1->Scale.z*0.95f;
			}
			if (v1->Action != 1 && v1->Scale.x < 1.0f)
			{
				v1->Scale.x = v1->Scale.x*1.05f;
				v1->Scale.y = v1->Scale.y*1.05f;
				v1->Scale.z = v1->Scale.z*1.05f;
				if (v1->Scale.y >= 1.0f)
				{
					v1->Scale.x = 1.0f;
					v1->Scale.y = 1.0f;
					v1->Scale.z = 1.0f;
				}
			}
			if (v1->Action != 1 && IsPlayerInsideSphere(&v1->Position, 18))
			{
				if (HintTimer <= 0)
				{
					//Treasures
					if (v1->CharID == 24 && ChallengeAction)
					{
						if (v1->CharIndex == 5 && !Treasure1)
						{
							PlaySound(11, 0, 0, 0);
							if (Treasure2 && Treasure3 && Treasure4) DisplayHintText(ATT2_Message0, 120); else DisplayHintText(ATT2_Message5, 120);
							Treasure1 = true;
						}
						if (v1->CharIndex == 6 && !Treasure2)
						{
							PlaySound(11, 0, 0, 0);
							if (Treasure1 && Treasure3 && Treasure4) DisplayHintText(ATT2_Message0, 120); else DisplayHintText(ATT2_Message6, 120);
							Treasure2 = true;
						}
						if (v1->CharIndex == 7 && !Treasure3)
						{
							PlaySound(11, 0, 0, 0);
							if (Treasure1 && Treasure2 && Treasure4) DisplayHintText(ATT2_Message0, 120); else DisplayHintText(ATT2_Message7, 120);
							Treasure3 = true;
						}
						if (v1->CharIndex == 8 && !Treasure4)
						{
							PlaySound(11, 0, 0, 0);
							if (Treasure1 && Treasure2 && Treasure3) DisplayHintText(ATT2_Message0, 120); else DisplayHintText(ATT2_Message8, 120);
							Treasure4 = true;
						}
						HintTimer = 120;
					}
					//Wooden thing
					if (v1->CharID == 21)
					{
						switch (v1->CharIndex)
						{
						case 0:
							DisplayHintText(ATT2_Message0, 120);
							break;
						case 1:
							DisplayHintText(ATT2_Message1, 120);
							break;
						case 2:
							DisplayHintText(ATT2_Message2, 120);
							break;
						case 3:
							DisplayHintText(ATT2_Message3, 120);
							break;
						case 4:
							DisplayHintText(ATT2_Message4, 120);
							break;
						case 9:
							DisplayHintText(ATT2_Message9, 120);
							break;
						case 10:
							DisplayHintText(ATT2_Message10, 120);
							break;
						case 11:
							DisplayHintText(ATT2_Message11, 120);
							break;
						case 12:
							DisplayHintText(ATT2_Message12, 120);
							break;
						case 13:
							DisplayHintText(ATT2_Message13, 120);
							break;
						case 14:
							DisplayHintText(ATT2_Message14, 120);
							break;
						case 15:
							DisplayHintText(ATT2_Message15, 120);
							break;
						default:
							break;
						}
						HintTimer = 120;
					}
					//Start plate
					if (v1->CharID == 23 && !ChallengeAction)
					{
						PlaySound(5, 0, 0, 0);
						ChallengeAction = true;
						DebugTimer_MaxMins = 5;
						DisplayHintText(ATT2_Message3, 120);
						HintTimer = 120;
					}
					//Goal plate (not all treasures collected)
					if (v1->CharID == 22 && CollectedAll < 4 && !ChallengeOver)
					{
						v1->Action = 1;
						PlaySound(23, 0, 0, 0);
						DisplayHintText(ATT2_Message16, 180);
						HintTimer = 360;
					}
					//Goal plate (all treasures collected)
					if (v1->CharID == 22 && CollectedAll >= 4 && !ChallengeOver)
					{
						v1->Action = 1;
						PlaySound(5, 0, 0, 0);
						snprintf(ResultText, LengthOfArray(ResultText),
							"Your result is: %d%d:%d%d:%d%d.",
							TimerTenMinutesTexanim.texid, TimerMinutesTexanim.texid,
							TimerTenSecondsTexanim.texid, TimerSecondsTexanim.texid,
							TimerMTenSecondsTexanim.texid, TimerMSecondsTexanim.texid);
						DisplayHintText(ATT2_Message4, 180);
						Treasure1 = false;
						Treasure2 = false;
						Treasure3 = false;
						Treasure4 = false;
						CollectedAll = 0;
						ChallengeAction = false;
						ChallengeOver = false;
						ChallengeTimer = 0;
						HintTimer = 500;
					}
					//Goal plate (time over)
					if (v1->CharID == 22 && ChallengeOver)
					{
						v1->Action = 1;
						PlaySound(5, 0, 0, 0);
						DisplayHintText(ATT2_Message2, 180);
						Treasure1 = false;
						Treasure2 = false;
						Treasure3 = false;
						Treasure4 = false;
						CollectedAll = 0;
						ChallengeAction = false;
						ChallengeOver = false;
						ChallengeTimer = 0;
						HintTimer = 300;
					}
				}
			}
			if (v1->Scale.x > 0.1f) ATTObject_Display(a1);
		}
	}
	if (CurrentCharacter == 2)
	{
		if ((CurrentLevel == 26 && CurrentAct == 3) || (CurrentLevel == 38))
		{
			if (v1->Action == 1 && v1->Scale.x > 0.05f)
			{
				v1->Scale.x = v1->Scale.x*0.95f;
				v1->Scale.y = v1->Scale.y*0.95f;
				v1->Scale.z = v1->Scale.z*0.95f;
			}
			if (v1->Action != 1 && IsPlayerInsideSphere(&v1->Position, 100))
			{
				if (HintTimer <= 0)
				{
					//Gates
					if (v1->CharID == 34 && ChallengeAction && IsPlayerInsideSphere(&v1->Position, 35))
					{
						if (v1->CharIndex == 6 && !Gate1)
						{
							PlaySound(11, 0, 0, 0);
							if (CollectedAll >= 9) DisplayHintText(ATT3_Message0, 120); else DisplayHintText(ATT3_Message6, 120);
							Gate1 = true;
							v1->Action = 1;
						}
						if (v1->CharIndex == 7 && !Gate2)
						{
							PlaySound(11, 0, 0, 0);
							if (CollectedAll >= 9) DisplayHintText(ATT3_Message0, 120); else DisplayHintText(ATT3_Message7, 120);
							Gate2 = true;
							v1->Action = 1;
						}
						if (v1->CharIndex == 8 && !Gate3)
						{
							PlaySound(11, 0, 0, 0);
							if (CollectedAll >= 9) DisplayHintText(ATT3_Message0, 120); else DisplayHintText(ATT3_Message8, 120);
							Gate3 = true;
							v1->Action = 1;
						}
						if (v1->CharIndex == 9 && !Gate4)
						{
							PlaySound(11, 0, 0, 0);
							if (CollectedAll >= 9) DisplayHintText(ATT3_Message0, 120); else DisplayHintText(ATT3_Message9, 120);
							Gate4 = true;
							v1->Action = 1;
						}
						if (v1->CharIndex == 10 && !Gate5)
						{
							PlaySound(11, 0, 0, 0);
							if (CollectedAll >= 9) DisplayHintText(ATT3_Message0, 120); else DisplayHintText(ATT3_Message10, 120);
							Gate5 = true;
							v1->Action = 1;
						}
						if (v1->CharIndex == 11 && !Gate6)
						{
							PlaySound(11, 0, 0, 0);
							if (CollectedAll >= 9) DisplayHintText(ATT3_Message0, 120); else DisplayHintText(ATT3_Message11, 120);
							Gate6 = true;
							v1->Action = 1;
						}
						if (v1->CharIndex == 12 && !Gate7)
						{
							PlaySound(11, 0, 0, 0);
							if (CollectedAll >= 9) DisplayHintText(ATT3_Message0, 120); else DisplayHintText(ATT3_Message12, 120);
							Gate7 = true;
							v1->Action = 1;
						}
						if (v1->CharIndex == 13 && !Gate8)
						{
							PlaySound(11, 0, 0, 0);
							if (CollectedAll >= 9) DisplayHintText(ATT3_Message0, 120); else DisplayHintText(ATT3_Message13, 120);
							Gate8 = true;
							v1->Action = 1;
						}
						if (v1->CharIndex == 14 && !Gate9)
						{
							PlaySound(11, 0, 0, 0);
							if (CollectedAll >= 9) DisplayHintText(ATT3_Message0, 120); else DisplayHintText(ATT3_Message14, 120);
							Gate9 = true;
							v1->Action = 1;
						}
						if (v1->CharIndex == 15 && !Gate10)
						{
							PlaySound(11, 0, 0, 0);
							if (CollectedAll >= 9) DisplayHintText(ATT3_Message0, 120); else DisplayHintText(ATT3_Message15, 120);
							Gate10 = true;
							v1->Action = 1;
						}
						HintTimer = 120;
					}
					//Poster
					if (v1->CharID == 31 && CurrentLevel == 26 && IsPlayerInsideSphere(&v1->Position, 15))
					{
						DisplayHintText(ATT3_Message5, 180);
						HintTimer = 180;
					}
					//Start plate
					if (v1->CharID == 33 && !ChallengeAction)
					{
						v1->Action = 1;
						PlaySound(5, 0, 0, 0);
						ChallengeAction = true;
						DebugTimer_MaxMins = 3;
						DisplayHintText(ATT3_Message3, 120);
						HintTimer = 60;
					}
					//Goal plate (not all Gates passed)
					if (v1->CharID == 35 && CollectedAll < 10 && !ChallengeOver)
					{
						v1->Action = 1;
						PlaySound(5, 0, 0, 0);
						DisplayHintText(ATT3_Message16, 180);
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
						ChallengeAction = false;
						ChallengeOver = false;
						ChallengeTimer = 0;
						HintTimer = 120;
					}
					//Goal plate (all Gates passed)
					if (v1->CharID == 35 && CollectedAll >= 10 && !ChallengeOver)
					{
						v1->Action = 1;
						PlaySound(5, 0, 0, 0);
						snprintf(ResultText, LengthOfArray(ResultText),
							"Goal! Your result is: %d%d:%d%d:%d%d.",
							TimerTenMinutesTexanim.texid, TimerMinutesTexanim.texid,
							TimerTenSecondsTexanim.texid, TimerSecondsTexanim.texid,
							TimerMTenSecondsTexanim.texid, TimerMSecondsTexanim.texid);
						DisplayHintText(ATT3_Message4, 600);
						ChallengeAction = false;
						ChallengeOver = false;
						HintTimer = 300;
					}
					//Goal plate (time over)
					if (v1->CharID == 35 && ChallengeOver)
					{
						v1->Action = 1;
						PlaySound(5, 0, 0, 0);
						DisplayHintText(ATT3_Message2, 180);
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
						ChallengeAction = false;
						ChallengeOver = false;
						ChallengeTimer = 0;
						HintTimer = 300;
					}
				}
			}
			if (v1->Scale.x > 0.1f) ATTObject_Display(a1);
		}
	}
}

void ATTObject_Load(ObjectMaster *a1)
{
	Angle Wha;
	NJS_OBJECT *v5;
	EntityData1 *v1;
	v1 = a1->Data1;
	v5 = nullptr;
	if (CurrentCharacter == 0)
	{
		//Rotating platform
		if (v1->CharID == 12)
		{
			v5 = DynamicCOL_AddFromEntity(&object_00000CE4, a1, (ColFlags)0x10001001);
			v5->scl[0] = 1.0f;
			v5->scl[1] = 1.0f;
			v5->scl[2] = 1.0f;
		}
		//Billboard
		if (v1->CharID == 10 && v1->CharIndex != 7)
		{
			v5 = DynamicCOL_AddFromEntity(&poster_att1_big, a1, (ColFlags)0x20001001);
			v5->scl[0] = v1->Scale.x;
			v5->scl[1] = v1->Scale.y;
			v5->scl[2] = v1->Scale.z;
			v5->ang[0] = v1->Rotation.x;
			v5->ang[1] = v1->Rotation.y;
			v5->ang[2] = v1->Rotation.z;
		}
		a1->MainSub = (void(__cdecl *)(ObjectMaster *))ATTObject_Main;
		a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))ATTObject_Display;
	}
	if (CurrentCharacter == 3)
	{
		a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
		a1->MainSub = (void(__cdecl *)(ObjectMaster *))ATTObject_Main;
		a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))ATTObject_Display;
	}
	if (CurrentCharacter == 2)
	{
		a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
		a1->MainSub = (void(__cdecl *)(ObjectMaster *))ATTObject_Main;
		a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))ATTObject_Display;
	}
}

void LoadATT1Stuff(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF1, ATTObject_Load);
	ObjectFunc(OF2, ATTTimer_Load);
	setdata_dlc.Distance = 612800.0f;
	//Timer
	obj = LoadObject((LoadObj)2, 3, OF2);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 64;
		ent->Position.y = 64;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
	}
	//Big billboard
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -292;
		ent->Position.y = 50;
		ent->Position.z = 4;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 3.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1848;
		ent->Position.y = -1332;
		ent->Position.z = 385;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x982D;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 2382;
		ent->Position.y = -1261;
		ent->Position.z = 902;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x8000;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 3069;
		ent->Position.y = -1122;
		ent->Position.z = 679;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 3883;
		ent->Position.y = -786;
		ent->Position.z = -283;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4405;
		ent->Position.y = -1077;
		ent->Position.z = 773;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x4FA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4167;
		ent->Position.y = -1285;
		ent->Position.z = 261;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 5.0f;
		ent->Scale.y = 5.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 3813;
		ent->Position.y = -1626;
		ent->Position.z = 1710;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x4000;
		ent->Rotation.z = 0;
		ent->Scale.x = 5.0f;
		ent->Scale.y = 5.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 3773;
		ent->Position.y = -1431;
		ent->Position.z = 1710;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x4000;
		ent->Rotation.z = 0;
		ent->Scale.x = 5.0f;
		ent->Scale.y = 5.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1413;
		ent->Position.y = -1203;
		ent->Position.z = 2246;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x4000;
		ent->Rotation.z = 0;
		ent->Scale.x = 11.0f;
		ent->Scale.y = 11.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 2950;
		ent->Position.y = -1176;
		ent->Position.z = 3669;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 5.0f;
		ent->Scale.y = 5.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 767;
		ent->Position.y = -376;
		ent->Position.z = 118;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 9.0f;
		ent->Scale.y = 9.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4083;
		ent->Position.y = -1458;
		ent->Position.z = 4617;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x69F4;
		ent->Rotation.z = 0;
		ent->Scale.x = 5.0f;
		ent->Scale.y = 5.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4085;
		ent->Position.y = -1478;
		ent->Position.z = 4621;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x69F4;
		ent->Rotation.z = 0;
		ent->Scale.x = 5.0f;
		ent->Scale.y = 5.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 10;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4040;
		ent->Position.y = -1478;
		ent->Position.z = 4595;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x69F4;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 3.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 10;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4125;
		ent->Position.y = -1478;
		ent->Position.z = 4646;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x69F4;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 3.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 10;
		ent->CharID = 10;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4114;
		ent->Position.y = -1500;
		ent->Position.z = 4574;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x69F4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 7;
		ent->CharID = 10;
	}
	//Platform
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4622;
		ent->Position.y = -1340;
		ent->Position.z = -216;
		ent->Index = 2;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 6;
		ent->CharID = 12;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4486;
		ent->Position.y = -1460;
		ent->Position.z = 1668;
		ent->Index = 2;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 6;
		ent->CharID = 12;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 3844;
		ent->Position.y = -1423;
		ent->Position.z = 1696;
		ent->Index = 2;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 6;
		ent->CharID = 12;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 3840;
		ent->Position.y = -1380;
		ent->Position.z = 1640;
		ent->Index = 2;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 6;
		ent->CharID = 12;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4350;
		ent->Position.y = -1907;
		ent->Position.z = 3987;
		ent->Index = 2;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 6;
		ent->CharID = 12;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 717;
		ent->Position.y = 535;
		ent->Position.z = 18;
		ent->Index = 2;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 6;
		ent->CharID = 12;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 2955;
		ent->Position.y = -1190;
		ent->Position.z = 696;
		ent->Index = 2;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 6;
		ent->CharID = 12;
	}
}

void LoadATT1Stuff_SS(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF1, ATTObject_Load);
	ObjectFunc(OF2, ATTTimer_Load);
	setdata_dlc.Distance = 612800.0f;
	if ((GameMode == GameModes_Adventure_Field || GameMode == GameModes_Mission) && CurrentCharacter == 0)
	{
		if (!ObjectsLoaded)
		{
			//Timer
			obj = LoadObject((LoadObj)2, 3, OF2);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 64;
				ent->Position.y = 64;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
			}
			//Poster 1
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 366;
				ent->Position.y = 26;
				ent->Position.z = 1303;
				ent->Index = 0;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0xC000;
				ent->Rotation.z = 0;
				ent->Scale.x = 1.3f;
				ent->Scale.y = 1.3f;
				ent->Scale.z = 1.0f;
				ent->CharIndex = 6;
				ent->CharID = 10;
			}
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 366;
				ent->Position.y = 26;
				ent->Position.z = 1435;
				ent->Index = 0;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0xC000;
				ent->Rotation.z = 0;
				ent->Scale.x = 1.3f;
				ent->Scale.y = 1.3f;
				ent->Scale.z = 1.0f;
				ent->CharIndex = 5;
				ent->CharID = 10;
			}
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 347;
				ent->Position.y = 38;
				ent->Position.z = 1370;
				ent->Index = 0;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0xC000;
				ent->Rotation.z = 0;
				ent->Scale.x = 1.3f;
				ent->Scale.y = 1.3f;
				ent->Scale.z = 1.0f;
				ent->CharIndex = 3;
				ent->CharID = 13;
			}
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 327;
				ent->Position.y = 38;
				ent->Position.z = 1370;
				ent->Index = 0;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0xC000;
				ent->Rotation.z = 0;
				ent->Scale.x = 1.3f;
				ent->Scale.y = 1.3f;
				ent->Scale.z = 1.0f;
				ent->CharIndex = 4;
				ent->CharID = 14;
			}
			ObjectsLoaded = true;
		}
	}
}

void LoadATT2Stuff_SSorMR(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF1, ATTObject_Load);
	ObjectFunc(OF2, ATTTimer_Load);
	setdata_dlc.Distance = 612800.0f;
	if ((GameMode == GameModes_Adventure_Field || GameMode == GameModes_Mission) && CurrentCharacter == 3)
	{
		if (CurrentLevel == 26)
		{
			if (!ObjectsLoaded)
			{
				//Wooden billboard
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 125;
					ent->Position.y = 15;
					ent->Position.z = 1445;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x13E9;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 9;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 356;
					ent->Position.y = 14;
					ent->Position.z = 1223;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x4000;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 9;
					ent->CharID = 21;
				}
				ObjectsLoaded = true;
			}
		}
		if (CurrentLevel == 33)
		{
			if (!ObjectsLoaded)
			{
				//Timer
				obj = LoadObject((LoadObj)2, 3, OF2);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 64;
					ent->Position.y = 64;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
				}
				//Wooden billboard
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = -145;
					ent->Position.y = 70;
					ent->Position.z = 1055;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x2AAA;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 15;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = -218;
					ent->Position.y = 72;
					ent->Position.z = 1140;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 15;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = -330;
					ent->Position.y = 71;
					ent->Position.z = 728;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0xC000;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 15;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = -93;
					ent->Position.y = 105;
					ent->Position.z = 324;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x071C;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 10;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = -169;
					ent->Position.y = 74;
					ent->Position.z = 36;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 22209;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 14;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = -22;
					ent->Position.y = -27;
					ent->Position.z = -150;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x8EEE;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 14;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 40;
					ent->Position.y = -15;
					ent->Position.z = -253;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x8EEE;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 10;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 166;
					ent->Position.y = -27;
					ent->Position.z = -216;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x8EEE;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 14;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 335;
					ent->Position.y = -16;
					ent->Position.z = -68;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0xA5B0;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 11;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 458;
					ent->Position.y = 77;
					ent->Position.z = 143;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x42D8;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 15;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = -60;
					ent->Position.y = 75;
					ent->Position.z = 200;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x4000;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 13;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 7;
					ent->Position.y = 80;
					ent->Position.z = 137;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x8000;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 13;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 140;
					ent->Position.y = 75;
					ent->Position.z = 200;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x4000;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 13;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 7;
					ent->Position.y = 77;
					ent->Position.z = 376;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x8000;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 13;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 184;
					ent->Position.y = 200;
					ent->Position.z = 925;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0xA666;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 15;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 275;
					ent->Position.y = 200;
					ent->Position.z = 792;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0xA666;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 15;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 386;
					ent->Position.y = 200;
					ent->Position.z = 709;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0xA666;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 15;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 489;
					ent->Position.y = 200;
					ent->Position.z = 559;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0xA666;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 12;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1345;
					ent->Position.y = 220;
					ent->Position.z = 405;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x0D82;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 14;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 999;
					ent->Position.y = 140;
					ent->Position.z = 888;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x89F4;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 14;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1417;
					ent->Position.y = 190;
					ent->Position.z = 648;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x9B05;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 12;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1477;
					ent->Position.y = 205;
					ent->Position.z = 784;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x1B05;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 14;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1499;
					ent->Position.y = 200;
					ent->Position.z = 849;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x4B60;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 14;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1623;
					ent->Position.y = 195;
					ent->Position.z = 944;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x4B60;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 10;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1800;
					ent->Position.y = 193;
					ent->Position.z = 1160;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x4666;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 12;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1948;
					ent->Position.y = 191;
					ent->Position.z = 1342;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x4666;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 11;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 2061;
					ent->Position.y = 191;
					ent->Position.z = 1543;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x18E3;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 14;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1247;
					ent->Position.y = 16;
					ent->Position.z = 599;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0xA71C;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 15;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1386;
					ent->Position.y = 19;
					ent->Position.z = 400;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x6000;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 15;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1360;
					ent->Position.y = 10;
					ent->Position.z = 17;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x49F4;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 13;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1308;
					ent->Position.y = 10;
					ent->Position.z = -309;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x216C;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 14;
					ent->CharID = 21;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1452;
					ent->Position.y = 10;
					ent->Position.z = -431;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x561C;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 14;
					ent->CharID = 21;
				}
				//Treasure 1
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = -16;
					ent->Position.y = 55;
					ent->Position.z = 300;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x561C;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 5;
					ent->CharID = 24;
				}
				//Treasure 2
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 617;
					ent->Position.y = 40;
					ent->Position.z = -160;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x561C;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 6;
					ent->CharID = 24;
				}
				//Treasure 3
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 7;
					ent->Position.y = 45;
					ent->Position.z = 200;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x561C;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 7;
					ent->CharID = 24;
				}
				//Treasure 4
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 1613;
					ent->Position.y = -17;
					ent->Position.z = -59;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x561C;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 8;
					ent->CharID = 24;
				}
				//Start plate
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = -87;
					ent->Position.y = 235;
					ent->Position.z = 1145;
					ent->Index = 10;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0xA666;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.5f;
					ent->Scale.y = 1.5f;
					ent->Scale.z = 1.5f;
					ent->CharIndex = 3;
					ent->CharID = 23;
				}
				//Goal plate
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = -62;
					ent->Position.y = 235;
					ent->Position.z = 1107;
					ent->Index = 10;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0xA666;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.5f;
					ent->Scale.y = 1.5f;
					ent->Scale.z = 1.5f;
					ent->CharIndex = 4;
					ent->CharID = 22;
				}
				ObjectsLoaded = true;
			}
		}
	}
}

void LoadATT3Stuff_SS(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF1, ATTObject_Load);
	ObjectFunc(OF2, ATTTimer_Load);
	setdata_dlc.Distance = 612800.0f;
	if ((GameMode == GameModes_Adventure_Field || GameMode == GameModes_Mission) && CurrentCharacter == 2)
	{
		if (CurrentLevel == 26)
		{
			if (!ObjectsLoaded)
			{
				//Poster
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 44;
					ent->Position.y = 27;
					ent->Position.z = 1417;
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x127D;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 5;
					ent->CharID = 31;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					if (ForceSADXLayout)
					{
						ent->Position.x = -2.75;
						ent->Position.y = 41;
						ent->Position.z = 1403.375f;
					}
					else
					{
						ent->Position.x = -5;
						ent->Position.y = 41;
						ent->Position.z = 1400;
					}
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x127D;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 5;
					ent->CharID = 31;
				}
				obj = LoadObject((LoadObj)2, 3, OF1);
				obj->SETData.SETData = &setdata_dlc;
				if (obj)
				{
					ent = obj->Data1;
					if (ForceSADXLayout)
					{
						ent->Position.x = 59.25f;
						ent->Position.y = 41;
						ent->Position.z = 1372.375f;
					}
					else
					{
						ent->Position.x = 57;
						ent->Position.y = 41;
						ent->Position.z = 1369;
					}
					ent->Index = 0;
					ent->Rotation.x = 0;
					ent->Rotation.y = 0x127D;
					ent->Rotation.z = 0;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
					ent->CharIndex = 5;
					ent->CharID = 31;
				}
				ObjectsLoaded = true;
			}
		}
	}
}

void LoadATT3Stuff(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF1, ATTObject_Load);
	ObjectFunc(OF2, ATTTimer_Load);
	setdata_dlc.Distance = 612800.0f;
	//Timer
	obj = LoadObject((LoadObj)2, 3, OF2);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 64;
		ent->Position.y = 64;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
	}
	//Gates
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 72;
		ent->Position.y = -767;
		ent->Position.z = -1196;
		ent->Index = 0;
		ent->Rotation.x = 0xE000;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 6;
		ent->CharID = 34;
		if (Gate1) ent->Action = 1; else ent->Action = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 112;
		ent->Position.y = -1522;
		ent->Position.z = -2472;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 7;
		ent->CharID = 34;
		if (Gate2) ent->Action = 1; else ent->Action = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1000;
		ent->Position.y = -1791;
		ent->Position.z = -3182;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 8;
		ent->CharID = 34;
		if (Gate3) ent->Action = 1; else ent->Action = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1109;
		ent->Position.y = -2694;
		ent->Position.z = -5156;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 9;
		ent->CharID = 34;
		if (Gate4) ent->Action = 1; else ent->Action = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 163;
		ent->Position.y = -3177;
		ent->Position.z = -6562;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 10;
		ent->CharID = 34;
		if (Gate5) ent->Action = 1; else ent->Action = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 57;
		ent->Position.y = -4515;
		ent->Position.z = -8892;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 11;
		ent->CharID = 34;
		if (Gate6) ent->Action = 1; else ent->Action = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 950;
		ent->Position.y = -4726;
		ent->Position.z = -9462;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 12;
		ent->CharID = 34;
		if (Gate7) ent->Action = 1; else ent->Action = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1052;
		ent->Position.y = -5329;
		ent->Position.z = -10761;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 13;
		ent->CharID = 34;
		if (Gate8) ent->Action = 1; else ent->Action = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1595;
		ent->Position.y = -5981;
		ent->Position.z = -12377;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 14;
		ent->CharID = 34;
		if (Gate9) ent->Action = 1; else ent->Action = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 994;
		ent->Position.y = -6507;
		ent->Position.z = -13333;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 15;
		ent->CharID = 34;
		if (Gate10) ent->Action = 1; else ent->Action = 0;
	}
	//Start plate
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 86;
		ent->Position.y = -215;
		ent->Position.z = -354;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 10.0f;
		ent->Scale.y = 6.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 3;
		ent->CharID = 33;
		if (ChallengeAction) ent->Action = 1; else ent->Action = 0;
	}
	//Goal plate
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1302;
		ent->Position.y = -7339;
		ent->Position.z = -15126;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 10.0f;
		ent->Scale.y = 6.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 35;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 23;
		ent->Position.y = -308;
		ent->Position.z = -547;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 5;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 28;
		ent->Position.y = -371;
		ent->Position.z = -659;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 11;
		ent->Position.y = -454;
		ent->Position.z = -812;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 99;
		ent->Position.y = -766;
		ent->Position.z = -1369;
		ent->Index = 0;
		ent->Rotation.y = 0xEFA4;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 109;
		ent->Position.y = -1236;
		ent->Position.z = -2097;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 128;
		ent->Position.y = -996;
		ent->Position.z = -1686;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 227;
		ent->Position.y = -1606;
		ent->Position.z = -290;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 960;
		ent->Position.y = -1691;
		ent->Position.z = -3207;
		ent->Index = 0;
		ent->Rotation.y = 0xEFA4;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1104;
		ent->Position.y = -2376;
		ent->Position.z = -4668;
		ent->Index = 0;
		ent->Rotation.y = 0x0FA4;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 232;
		ent->Position.y = -2991;
		ent->Position.z = -6135;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -27;
		ent->Position.y = -2991;
		ent->Position.z = -6166;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 132;
		ent->Position.y = -4091;
		ent->Position.z = -8184;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 79;
		ent->Position.y = -4336;
		ent->Position.z = -8702;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 630;
		ent->Position.y = -4656;
		ent->Position.z = -9534;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 844;
		ent->Position.y = -4656;
		ent->Position.z = -9520;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1060;
		ent->Position.y = -4656;
		ent->Position.z = -9538;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1098;
		ent->Position.y = -5566;
		ent->Position.z = -11577;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1431;
		ent->Position.y = -6151;
		ent->Position.z = -12905;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 862;
		ent->Position.y = -6636;
		ent->Position.z = -13721;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1243;
		ent->Position.y = -7091;
		ent->Position.z = -15799;
		ent->Index = 0;
		ent->Rotation.y = 0;
		ent->Rotation.x = 0xEFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 10.0f;
		ent->Scale.y = 10.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 4;
		ent->CharID = 32;
	}
}
