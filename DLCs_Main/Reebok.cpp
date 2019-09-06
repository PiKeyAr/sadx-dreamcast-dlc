// Reebok DLC functions.
#include <stdafx.h>
#include "Reebok.h"
#include "Data/DLC_Reebok.h"
extern NJS_MATERIAL matlist_00000004[];		// Data/DLC_ATT.h
extern NJS_MATERIAL matlist_00000004_2[];	// Data/DLC_Christmas99.h

const PVMEntry ReebokTextures = { "SONICADV_507", (TexList *)&texlist_reebok };

static void ReebokPoster_Display(ObjectMaster *a1)
{
	EntityData1 *v1;
	Angle v2;
	Angle v3;
	Angle v4;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		njSetTexture(&texlist_reebok);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		v2 = v1->Rotation.x;
		v3 = v1->Rotation.y + 0xC000;
		v4 = v1->Rotation.z;
		njRotateXYZ(0, v2, v3, v4);
		njScale(0, v1->Scale.z, v1->Scale.y, v1->Scale.x);
		if (v1->CharID == 3)
		{
			if (v1->Action == 1)
			{
				matlist_reebokposterZ[0].attrflags |= NJD_FLAG_USE_ALPHA;
				if (matlist_reebokposterZ[0].diffuse.argb.a > 8) matlist_reebokposterZ[0].diffuse.argb.a = matlist_reebokposterZ[0].diffuse.argb.a - 8;
			}
			else
			{
				matlist_reebokposterZ[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
				if (matlist_reebokposterZ[0].diffuse.argb.a < 255) matlist_reebokposterZ[0].diffuse.argb.a = matlist_reebokposterZ[0].diffuse.argb.a + 8;
			}
			if (matlist_reebokposterZ[0].diffuse.argb.a > 255) matlist_reebokposterZ[0].diffuse.argb.a = 255;
			ProcessModelNode_AB_Wrapper(&reebokposter_start, v1->Scale.x);
		}
		if (v1->CharID == 4)
		{
			if (v1->Action == 1)
			{
				matlist_reebokposterW[0].attrflags |= NJD_FLAG_USE_ALPHA;
				if (matlist_reebokposterW[0].diffuse.argb.a > 8) matlist_reebokposterW[0].diffuse.argb.a = matlist_reebokposterW[0].diffuse.argb.a - 8;
			}
			else
			{
				matlist_reebokposterW[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
				if (matlist_reebokposterW[0].diffuse.argb.a < 255) matlist_reebokposterW[0].diffuse.argb.a = matlist_reebokposterW[0].diffuse.argb.a + 8;
			}
			if (matlist_reebokposterW[0].diffuse.argb.a > 255) matlist_reebokposterW[0].diffuse.argb.a = 255;
			ProcessModelNode_AB_Wrapper(&reebokposter_goal, v1->Scale.x);
		}
		if (v1->CharID == 8) ProcessModelNode_AB_Wrapper(&reebokposter, v1->Scale.x);
		if (v1->CharID == 7) ProcessModelNode_AB_Wrapper(&reebokposter_small, v1->Scale.x);
		njPopMatrix(1u);
	}
}

static void ReebokPoster_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
	v1 = a1->Data1;
	Angle v2;
	int v3;
	if (v1->NextAction == CurrentAct)
	{
		v3 = (v1->Index) * 16;
		v2 = (v1->Rotation.y + v3) % 65535;
		v1->Rotation.y = v2;
		if (v1->Action == 1)
		{
			if (v1->Scale.x > 0.05f)
			{
				v1->Scale.x = v1->Scale.x*0.95f;
				v1->Scale.y = v1->Scale.y*0.95f;
				v1->Scale.z = v1->Scale.z*0.95f;
			}
		}
		if (v1->Action != 1)
		{
			if (v1->Scale.x < 1.0f)
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
		}
		if (IsPlayerInsideSphere(&v1->Position, 15))
		{
			if (HintTimer <= 0)
			{
				if (v1->CharIndex == 9)
				{
					PlaySound(23, 0, 0, 0);
					DisplayHintText(ReebokMessage1, 180);
					HintTimer = 180;
				}
				if (v1->CharIndex == 8)
				{
					PlaySound(23, 0, 0, 0);
					DisplayHintText(ReebokMessage6, 180);
					HintTimer = 180;
				}
				if (v1->CharIndex == 7)
				{
					PlaySound(23, 0, 0, 0);
					DisplayHintText(ReebokMessage8, 180);
					HintTimer = 180;
				}
				if (v1->CharIndex == 3)
				{
					PlaySound(12, 0, 0, 0);
					DisplayHintText(ReebokMessage7, 180);
					Collected1 = false;
					Collected2 = false;
					Collected3 = false;
					Collected4 = false;
					Collected5 = false;
					ChallengeTimer = 0;
					ChallengeAction = true;
					ChallengeOver = false;
					v1->Action = 1;
					sub_412D80(LevelIDs_EmeraldCoast, 0);
					HintTimer = 60;
				}
				if (ChallengeAction && v1->CharIndex == 4)
				{
					if (CollectedAll >= 5)
					{
						v1->Action = 1;
						PlaySound(12, 0, 0, 0);
						sub_425800(MusicIDs_EmeraldCoastAzureBlueWorld);
						snprintf(ResultText, LengthOfArray(ResultText),
							"Your result is: %d%d:%d%d:%d%d.",
							TimerTenMinutesTexanim.texid, TimerMinutesTexanim.texid,
							TimerTenSecondsTexanim.texid, TimerSecondsTexanim.texid,
							TimerMTenSecondsTexanim.texid, TimerMSecondsTexanim.texid);
						DisplayHintText(ReebokMessage9, 180);
						ChallengeAction = false;
						ChallengeOver = true;
						ChallengeTimer = 0;
						HintTimer = 700;
					}
					else
					{
						PlaySound(23, 0, 0, 0);
						DisplayHintText(ReebokMessage2, 180);
						HintTimer = 180;
					}
				}
			}
		}
		if (v1->Scale.x > 0.05f) ReebokPoster_Display(a1);
	}
}

static void ReebokPoster_Load(ObjectMaster *a1)
{
	Angle Wha;
	NJS_OBJECT *v5;
	EntityData1 *v1;
	v1 = a1->Data1;
	if (v1->CharID == 8)
	{
		Wha = v1->Rotation.y + 0xC000;
		v5 = DynamicCOL_AddFromEntity(&reebokposter, a1, (ColFlags)0x20001001);
		v5->ang[1] = Wha;
		v5->scl[0] = 1.0f;
		v5->scl[1] = 1.5f;
		v5->scl[2] = 2.5f;
		a1->DeleteSub = DynamicCOL_DeleteObject;
	}
	else
	{
		v5 = nullptr;
		a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
	}
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))ReebokPoster_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))ReebokPoster_Display;
}

static void Shoes_Display(ObjectMaster *a1)
{
	EntityData1 *v1;
	Angle v2;
	Angle v3;
	Angle v4;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		njSetTexture(&texlist_reebok);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
		v2 = v1->Rotation.x;
		v3 = v1->Rotation.y;
		v4 = v1->Rotation.z;
		njRotateXYZ(0, v2, v3, v4);
		if (v1->Action == 1)
		{
			matlist_00000004[0].attrflags |= NJD_FLAG_USE_ALPHA;
			matlist_00000004[1].attrflags |= NJD_FLAG_USE_ALPHA;
			matlist_00000004[2].attrflags |= NJD_FLAG_USE_ALPHA;
			matlist_00000004[0].diffuse.argb.a = 255 - v1->InvulnerableTime;
			matlist_00000004[1].diffuse.argb.a = 255 - v1->InvulnerableTime;
			matlist_00000004[2].diffuse.argb.a = 255 - v1->InvulnerableTime;
			matlist_00000004_2[0].diffuse.argb.a = 38 - (v1->InvulnerableTime / 7.0f);
		}
		else
		{
			matlist_00000004[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
			matlist_00000004[1].attrflags &= ~NJD_FLAG_USE_ALPHA;
			matlist_00000004[2].attrflags &= ~NJD_FLAG_USE_ALPHA;
			matlist_00000004[0].diffuse.argb.a = 255;
			matlist_00000004[1].diffuse.argb.a = 255;
			matlist_00000004[2].diffuse.argb.a = 255;
			matlist_00000004_2[0].diffuse.argb.a = 38;
		}
		ProcessModelNode_AB_Wrapper(&object_000010AC, v1->Scale.x);
		ProcessModelNode(&object_000010AC_2, QueuedModelFlagsB_3, v1->Scale.x);
		njPopMatrix(1u);
	}
}

static void Shoes_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
	int SpeedY;
	Angle v2;
	Angle v3;
	Angle v4;
	NJS_OBJECT *v5; // eax@2
	v1 = a1->Data1;
	if (v1->NextAction == CurrentAct && !ChallengeOver && ChallengeAction)
	{
		if (v1->Action != 1) v1->InvulnerableTime = 0;
		if (v1->Action == 1)
		{
			if (v1->InvulnerableTime < 255) v1->InvulnerableTime = v1->InvulnerableTime + 8;
			if (v1->InvulnerableTime > 255) v1->InvulnerableTime = 255;
		}
		SpeedY = 246;
		v2 = v1->Rotation.x;
		v3 = v1->Rotation.y;
		v4 = v1->Rotation.z;
		v3 = (v3 + int(SpeedY)) % 65535;
		v1->Rotation.y = v3;
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
		if (IsPlayerInsideSphere(&v1->Position, 15))
		{
			if ((v1->CharID == 0 && !Collected1) || (v1->CharID == 1 && !Collected2) || (v1->CharID == 2 && !Collected3) || (v1->CharID == 3 && !Collected4) || (v1->CharID == 4 && !Collected5))
			{
				if (v1->CharID == 0) Collected1 = true;
				if (v1->CharID == 1) Collected2 = true;
				if (v1->CharID == 2) Collected3 = true;
				if (v1->CharID == 3) Collected4 = true;
				if (v1->CharID == 4) Collected5 = true;
				if (CollectedAll != 0) PlaySound(1229, 0, 0, 0);
				v1->Action = 1;
				if (HintTimer <= 0)
				{
					sub_425800(MusicIDs_bossevnt);
					if (Collected1 && Collected2 && Collected3 && Collected4 && Collected5) DisplayHintText(ReebokMessage5, 180);
					else DisplayHintText(ReebokMessage4, 180);
					HintTimer = 60;
				}
			}
		}
		if (v1->Scale.x > 0.05f) Shoes_Display(a1);
	}
}

static void ReebokTimer_Display(ObjectMaster *a1)
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
		DebugTimer_Total = 5;
		DrawDebugTimer();
	}
	else
	{
		HedgehogCountTexanim.sx = 16 * HorizontalStretch;
		HedgehogCountTexanim.sy = 16 * HorizontalStretch;
		HedgehogCountSlashTexanim.sx = 16 * HorizontalStretch;
		HedgehogCountSlashTexanim.sy = 16 * HorizontalStretch;
		HedgehogCountTotalTexanim.sx = 16 * HorizontalStretch;
		HedgehogCountTotalTexanim.sy = 16 * HorizontalStretch;
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
		HedgehogCountTexanim.texid = CollectedAll;
		njDrawSprite2D_ForcePriority(&HedgehogCount, 0, 22046.498f, NJD_SPRITE_ALPHA);
		//Draw slash
		HedgehogCountSlashTexanim.texid = 73;
		njDrawSprite2D_ForcePriority(&HedgehogCountSlash, 0, 22046.498f, NJD_SPRITE_ALPHA);
		//Draw total
		HedgehogCountTotalTexanim.texid = 5;
		njDrawSprite2D_ForcePriority(&HedgehogCountTotal, 0, 22046.498f, NJD_SPRITE_ALPHA);
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

static void ReebokTimer_Main(ObjectMaster *a1)
{
	if (((ChallengeTimer / 3600) % 60) / 10 < 1)
	{
		if (ChallengeAction)
		{
			CollectedAll = Collected1 + Collected2 + Collected3 + Collected4 + Collected5;
			ChallengeTimer++;
			ReebokTimer_Display(a1);
		}
	}
	if (((ChallengeTimer / 3600) % 60) / 10 >= 1)
	{
		ChallengeAction = false;
		ChallengeOver = true;
		ChallengeTimer = 0;
		sub_425800(MusicIDs_EmeraldCoastAzureBlueWorld);
		DisplayHintText(ReebokMessage3, 180);
	}
}

static void ReebokTimer_Load(ObjectMaster *a1)
{
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))ReebokTimer_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))ReebokTimer_Display;
	a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
}

static void Shoes_Load(ObjectMaster *a1)
{
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))Shoes_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))Shoes_Display;
	a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
}

void LoadReebokStuffInEmeraldCoast(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF0, Shoes_Load);
	ObjectFunc(OF1, ReebokPoster_Load);
	ObjectFunc(OF2, ReebokTimer_Load);
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
	//Shoes
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -642;
		ent->Position.y = 19;
		ent->Position.z = 1547;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 5;
		ent->CharID = 0;
		if (!Collected1)
		{
			ent->Action = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
		}
		else
		{
			ent->Action = 1;
			ent->Scale.x = 0.05f;
			ent->Scale.y = 0.05f;
			ent->Scale.z = 0.05f;
		}
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -46;
		ent->Position.y = 22;
		ent->Position.z = 25;
		ent->CharID = 1;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 5;
		if (!Collected2)
		{
			ent->Action = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
		}
		else
		{
			ent->Action = 1;
			ent->Scale.x = 0.05f;
			ent->Scale.y = 0.05f;
			ent->Scale.z = 0.05f;
		}
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 2588;
		ent->Position.y = 50;
		ent->Position.z = 310;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 5;
		ent->CharID = 2;
		if (!Collected3)
		{
			ent->Action = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
		}
		else
		{
			ent->Action = 1;
			ent->Scale.x = 0.05f;
			ent->Scale.y = 0.05f;
			ent->Scale.z = 0.05f;
		}
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1872;
		ent->Position.y = 245;
		ent->Position.z = 805;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharID = 3;
		ent->CharIndex = 5;
		if (!Collected4)
		{
			ent->Action = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
		}
		else
		{
			ent->Action = 1;
			ent->Scale.x = 0.05f;
			ent->Scale.y = 0.05f;
			ent->Scale.z = 0.05f;
		}
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 6063;
		ent->Position.y = 401;
		ent->Position.z = 883;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 5;
		ent->CharID = 4;
		if (!Collected5)
		{
			ent->Action = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
		}
		else
		{
			ent->Action = 1;
			ent->Scale.x = 0.05f;
			ent->Scale.y = 0.05f;
			ent->Scale.z = 0.05f;
		}
		ent->NextAction = 0;
	}
	//ReebokPosters type 1
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 6356;
		ent->Position.y = 423;
		ent->Position.z = 1144;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC2D8;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 6122;
		ent->Position.y = 184;
		ent->Position.z = 1242;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x927D;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 5733;
		ent->Position.y = 20;
		ent->Position.z = 1074;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xE000;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -134;
		ent->Position.y = 21;
		ent->Position.z = 179;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x6FA4;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -550;
		ent->Position.y = 21;
		ent->Position.z = 481;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xA000;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -634;
		ent->Position.y = 89;
		ent->Position.z = 1171;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x8000;
		ent->Rotation.z = 0;
		ent->CharID = 8;
		ent->CharIndex = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -641;
		ent->Position.y = 68;
		ent->Position.z = 1588;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x8000;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -997;
		ent->Position.y = 68;
		ent->Position.z = 1548;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x4000;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -425;
		ent->Position.y = 127;
		ent->Position.z = 1209;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 281;
		ent->Position.y = 19;
		ent->Position.z = 907;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xCFA4;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 765;
		ent->Position.y = 98;
		ent->Position.z = 589;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xD777;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 972;
		ent->Position.y = 83;
		ent->Position.z = 968;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x9A4F;
		ent->CharID = 8;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1780;
		ent->Position.y = 125;
		ent->Position.z = 837;
		ent->Rotation.x = 0;
		ent->CharID = 8;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 2183;
		ent->Position.y = 69;
		ent->Position.z = 867;
		ent->Rotation.x = 0;
		ent->CharID = 8;
		ent->Rotation.y = 0x9777;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1874;
		ent->Position.y = 203;
		ent->Position.z = 559;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 2358;
		ent->Position.y = 81;
		ent->Position.z = 340;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 3360;
		ent->Position.y = 25;
		ent->Position.z = 289;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xCFA4;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 3360;
		ent->Position.y = 25;
		ent->Position.z = 443;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xAFA4;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4300;
		ent->Position.y = 47;
		ent->Position.z = 1582;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4587;
		ent->Position.y = 47;
		ent->Position.z = 1767;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4666;
		ent->Position.y = 40;
		ent->Position.z = 1546;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x6000;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 4767;
		ent->Position.y = 29;
		ent->Position.z = 1121;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x8000;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 5171;
		ent->Position.y = 70;
		ent->Position.z = 1118;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x8000;
		ent->Rotation.z = 0;
		ent->CharIndex = 8;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 5792;
		ent->Position.y = 415;
		ent->Position.z = 693;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 7;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 5783;
		ent->Position.y = 411;
		ent->Position.z = 685;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 7;
		ent->CharID = 8;
		ent->Scale.x = 2.5f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	//ReebokPosters type 2
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -53;
		ent->Position.y = 30;
		ent->Position.z = -15;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->Index = 10;
		ent->CharIndex = 0;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -29;
		ent->Position.y = 42;
		ent->Position.z = 70;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->Index = 246;
		ent->CharIndex = 0;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -317;
		ent->Position.y = 29;
		ent->Position.z = 108;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->Index = 10;
		ent->CharIndex = 0;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -491;
		ent->Position.y = 43;
		ent->Position.z = 261;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 246;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -573;
		ent->Position.y = 37;
		ent->Position.z = 611;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 10;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -699;
		ent->Position.y = 37;
		ent->Position.z = 643;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 246;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -397;
		ent->Position.y = 107;
		ent->Position.z = 1253;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 10;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 129;
		ent->Position.y = 28;
		ent->Position.z = 1024;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 246;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 328;
		ent->Position.y = 36;
		ent->Position.z = 718;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 10;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 460;
		ent->Position.y = 31;
		ent->Position.z = 548;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 246;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 569;
		ent->Position.y = 31;
		ent->Position.z = 617;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 10;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1643;
		ent->Position.y = 141;
		ent->Position.z = 790;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 246;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1860;
		ent->Position.y = 217;
		ent->Position.z = 947;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 10;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1921;
		ent->Position.y = 63;
		ent->Position.z = 366;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 10;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 1987;
		ent->Position.y = 41;
		ent->Position.z = 243;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 10;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 5712;
		ent->Position.y = 22;
		ent->Position.z = 1162;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 246;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 5966;
		ent->Position.y = 43;
		ent->Position.z = 1119;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 10;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 5952;
		ent->Position.y = 44;
		ent->Position.z = 1216;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 246;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 6061;
		ent->Position.y = 187;
		ent->Position.z = 1231;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 10;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 6347;
		ent->Position.y = 433;
		ent->Position.z = 1087;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 0;
		ent->Index = 246;
		ent->CharID = 7;
		ent->Scale.x = 1.9f;
		ent->Scale.y = 0.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
	//Goal tab
	obj = LoadObject((LoadObj)2, 3, OF1);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 5842;
		ent->Position.y = 422;
		ent->Position.z = 726;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x27D2;
		ent->Rotation.z = 0;
		ent->CharIndex = 4;
		ent->Index = 0;
		ent->CharID = 4;
		ent->Scale.x = 1.3f;
		ent->Scale.y = 1.3f;
		ent->Scale.z = 1.0f;
		ent->NextAction = 0;
	}
}

void LoadReebokStuffInStationSquare(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF0, Shoes_Load);
	ObjectFunc(OF1, ReebokPoster_Load);
	ObjectFunc(OF2, ReebokTimer_Load);
	setdata_dlc.Distance = 612800.0f;
	if ((GameMode == GameModes_Adventure_Field || GameMode == GameModes_Mission) && CurrentCharacter == 0)
	{
		if (!ObjectsLoaded)
		{
			//ReebokPoster 1
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = -167;
				ent->Position.y = 15;
				ent->Position.z = 1741;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0x4000;
				ent->Rotation.z = 0;
				ent->CharIndex = 9;
				ent->CharID = 8;
				ent->Scale.x = 1.8f;
				ent->Scale.y = 1.5f;
				ent->Scale.z = 1.0f;
				ent->NextAction = 3;
			}
			//ReebokPoster 2
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = -167;
				ent->Position.y = 15;
				ent->Position.z = 1626;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0x4000;
				ent->Rotation.z = 0;
				ent->CharIndex = 9;
				ent->CharID = 8;
				ent->Scale.x = 2.5f;
				ent->Scale.y = 1.5f;
				ent->Scale.z = 1.0f;
				ent->NextAction = 3;
			}
			//ReebokPoster 3
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = -387;
				ent->Position.y = 29;
				ent->Position.z = 2011;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0x8000;
				ent->Rotation.z = 0;
				ent->CharIndex = 9;
				ent->CharID = 8;
				ent->Scale.x = 2.5f;
				ent->Scale.y = 1.5f;
				ent->Scale.z = 1.0f;
				ent->NextAction = 4;
			}
			//ReebokPoster 4 (start)
			ChallengeAction = false;
			ChallengeTimer = 0;
			Collected1 = false;
			Collected2 = false;
			Collected3 = false;
			Collected4 = false;
			Collected5 = false;
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = -496;
				ent->Position.y = 26;
				ent->Position.z = 2068;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0x6000;
				ent->Rotation.z = 0;
				ent->CharIndex = 3;
				ent->CharID = 3;
				ent->Scale.x = 1.3f;
				ent->Scale.y = 1.3f;
				ent->Scale.z = 1.0f;
				ent->NextAction = 4;
			}
			ObjectsLoaded = true;
		}
	}
}
