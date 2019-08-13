// Famitsu DLC functions.
#include <stdafx.h>
#include "Famitsu.h"

const PVMEntry FamitsuTextures = { "SONICADV_003", (TexList *)&texlist_famitsu };

static void FamitsuPoster_Display(ObjectMaster *a1)
{
	EntityData1 *v1;
	Angle v2;
	Angle v3;
	Angle v4;
	v1 = a1->Data1;
	if (!DroppedFrames && !IsGamePaused())
	{
		njSetTexture(&texlist_famitsu);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		v2 = v1->Rotation.x;
		v3 = v1->Rotation.y;
		v4 = v1->Rotation.z;
		njRotateXYZ(0, v2, v3, v4);
		njScale(0, v1->Scale.z, v1->Scale.y, v1->Scale.x);
		if ((Collected1 && v1->CharIndex == 4) || (Collected2 && v1->CharIndex == 5) || (Collected3 && v1->CharIndex == 6) || (Collected4 && v1->CharIndex == 7) || (Collected5 && v1->CharIndex == 8))
		{
			matlist_00116FA0X[0].attrflags |= NJD_FLAG_USE_ALPHA;
			matlist_00116FA0X[0].diffuse.argb.a = 255 - v1->InvulnerableTime;
		}
		ProcessModelNode_AB_Wrapper(&poster, v1->Scale.x);
		matlist_00116FA0X[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
		matlist_00116FA0X[0].diffuse.argb.a = 255;
		njPopMatrix(1u);
	}
}

static void FamitsuPoster_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
	v1 = a1->Data1;
	if (v1->NextAction == CurrentAct)
	{
		if (!ChallengeAction)
		{
			Collected1 = false;
			Collected2 = false;
			Collected3 = false;
			Collected4 = false;
			Collected5 = false;
		}
		else
		{
			if ((!Collected1 && v1->CharIndex == 4) || (!Collected2 && v1->CharIndex == 5) || (!Collected3 && v1->CharIndex == 6) || (!Collected4 && v1->CharIndex == 7) || (!Collected5 && v1->CharIndex == 8))
			{
				v1->InvulnerableTime = 0;
				v1->Scale.x = 1.0f;
				v1->Scale.y = 1.0f;
				v1->Scale.z = 1.0f;
				if (IsPlayerInsideSphere(&v1->Position, 15))
				{
					if (v1->CharIndex == 4)
					{
						Collected1 = true;
						PlaySound(28, 0, 0, 0);
						if (Collected1 && Collected2 && Collected3 && Collected4 && Collected5) DisplayHintText(FamitsuMessage1, 180); else DisplayHintText(FamitsuMessage5, 180);
						HintTimer = 60;
					}
					if (v1->CharIndex == 5)
					{
						Collected2 = true;
						PlaySound(28, 0, 0, 0);
						if (Collected1 && Collected2 && Collected3 && Collected4 && Collected5) DisplayHintText(FamitsuMessage1, 180); else DisplayHintText(FamitsuMessage6, 180);
						HintTimer = 60;
					}
					if (v1->CharIndex == 6)
					{
						Collected3 = true;
						PlaySound(28, 0, 0, 0);
						if (Collected1 && Collected2 && Collected3 && Collected4 && Collected5) DisplayHintText(FamitsuMessage1, 180); else DisplayHintText(FamitsuMessage7, 180);
						HintTimer = 60;
					}
					if (v1->CharIndex == 7)
					{
						Collected4 = true;
						PlaySound(28, 0, 0, 0);
						if (Collected1 && Collected2 && Collected3 && Collected4 && Collected5) DisplayHintText(FamitsuMessage1, 180); else DisplayHintText(FamitsuMessage8, 180);
						HintTimer = 60;
					}
					if (v1->CharIndex == 8)
					{
						Collected5 = true;
						PlaySound(28, 0, 0, 0);
						if (Collected1 && Collected2 && Collected3 && Collected4 && Collected5) DisplayHintText(FamitsuMessage1, 180); else DisplayHintText(FamitsuMessage9, 180);
						HintTimer = 60;
					}
				}
			}
			if ((Collected1 && v1->CharIndex == 4) || (Collected2 && v1->CharIndex == 5) || (Collected3 && v1->CharIndex == 6) || (Collected4 && v1->CharIndex == 7) || (Collected5 && v1->CharIndex == 8))
			{
				if (v1->InvulnerableTime < 255) v1->InvulnerableTime = v1->InvulnerableTime + 8;
				if (v1->InvulnerableTime > 255) v1->InvulnerableTime = 255;
				if (v1->Scale.x > 0.05f)
				{
					v1->Scale.x = v1->Scale.x*0.95f;
					v1->Scale.y = v1->Scale.y*0.95f;
					v1->Scale.z = v1->Scale.z*0.95f;
				}
			}
			if (v1->Scale.x > 0.05f) FamitsuPoster_Display(a1);
		}
	}
}

static void FamitsuPoster_Load(ObjectMaster *a1)
{
	a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))FamitsuPoster_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))FamitsuPoster_Display;
}

static void FamitsuBalloons_Display(ObjectMaster *a1)
{
	EntityData1 *v1;
	Angle v2;
	Angle v3;
	Angle v4;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		njSetTexture(&texlist_famitsu);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
		v2 = v1->Rotation.x;
		v3 = v1->Rotation.y;
		v4 = v1->Rotation.z;
		njRotateXYZ(0, v2, v3, v4);
		if (v1->CharIndex == 9) ProcessModelNode_AB_Wrapper(&balloon_start, v1->Scale.x);
		else ProcessModelNode_AB_Wrapper(&balloon_finish, v1->Scale.x);
		njPopMatrix(1u);
	}
}

static void FamitsuBalloons_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
	int SpeedY;
	Angle v2;
	Angle v3;
	Angle v4;
	NJS_OBJECT *v5; // eax@2
	v1 = a1->Data1;
	if (v1->NextAction == CurrentAct)
	{
		SpeedY = (v1->CharID) * 16;
		v2 = v1->Rotation.x;
		v3 = v1->Rotation.y;
		v4 = v1->Rotation.z;
		v3 = (v3 + int(SpeedY)) % 65535;
		v1->Rotation.y = v3;
		if (v1->CharIndex == 9)
		{
			if (ChallengeAction)
			{
				matlist_balloon[0].attrflags |= NJD_FLAG_USE_ALPHA;
				if (matlist_balloon[0].diffuse.argb.a > 8) matlist_balloon[0].diffuse.argb.a = matlist_balloon[0].diffuse.argb.a - 8;
				if (matlist_balloon[0].diffuse.argb.a < 8) matlist_balloon[0].diffuse.argb.a = 0;
				if (v1->Scale.x > 0.05f)
				{
					v1->Scale.x = v1->Scale.x*0.95f;
					v1->Scale.y = v1->Scale.y*0.95f;
					v1->Scale.z = v1->Scale.z*0.95f;
				}
			}
			if (!ChallengeAction)
			{
				matlist_balloon[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
				matlist_balloon[0].diffuse.argb.a = 255;
				if (v1->Scale.x < 1.5f)
				{

					v1->Scale.x = v1->Scale.x*1.05f;
					v1->Scale.y = v1->Scale.y*1.05f;
					v1->Scale.z = v1->Scale.z*1.05f;
					if (v1->Scale.y >= 1.5f)
					{
						v1->Scale.x = 1.5f;
						v1->Scale.y = 1.5f;
						v1->Scale.z = 1.5f;
					}
				}
			}
			if (!ChallengeAction && IsPlayerInsideSphere(&v1->Position, 15))
			{
				if (HintTimer <= 0)
				{
					PlaySound(12, 0, 0, 0);
					DisplayHintText(FamitsuMessage4, 180);
					Collected1 = false;
					Collected2 = false;
					Collected3 = false;
					Collected4 = false;
					Collected5 = false;
					CollectedAll = 0;
					ChallengeAction = true;
					HintTimer = 60;
				}
			}
		}
		else
		{
			if (!ChallengeAction)
			{
				matlist_balloon_2[0].attrflags |= NJD_FLAG_USE_ALPHA;
				if (matlist_balloon_2[0].diffuse.argb.a > 8) matlist_balloon_2[0].diffuse.argb.a = matlist_balloon_2[0].diffuse.argb.a - 8;
				if (matlist_balloon_2[0].diffuse.argb.a < 8) matlist_balloon_2[0].diffuse.argb.a = 0;
				if (v1->Scale.x > 0.05f)
				{
					v1->Scale.x = v1->Scale.x*0.95f;
					v1->Scale.y = v1->Scale.y*0.95f;
					v1->Scale.z = v1->Scale.z*0.95f;
				}
			}
			if (ChallengeAction)
			{
				matlist_balloon_2[0].attrflags &= ~NJD_FLAG_USE_ALPHA;
				matlist_balloon_2[0].diffuse.argb.a = 255;
				if (v1->Scale.x < 1.5f)
				{
					v1->Scale.x = v1->Scale.x*1.05f;
					v1->Scale.y = v1->Scale.y*1.05f;
					v1->Scale.z = v1->Scale.z*1.05f;
					if (v1->Scale.y >= 1.5f)
					{
						v1->Scale.x = 1.5f;
						v1->Scale.y = 1.5f;
						v1->Scale.z = 1.5f;
					}
				}
			}
			if (ChallengeAction && IsPlayerInsideSphere(&v1->Position, 15))
			{
				if (CollectedAll >= 5)
				{
					if (HintTimer <= 0)
					{
						PlaySound(12, 0, 0, 0);
						snprintf(ResultText, LengthOfArray(ResultText),
							"Your result is: %d%d:%d%d:%d%d.",
							TimerTenMinutesTexanim.texid, TimerMinutesTexanim.texid,
							TimerTenSecondsTexanim.texid, TimerSecondsTexanim.texid,
							TimerMTenSecondsTexanim.texid, TimerMSecondsTexanim.texid);
						DisplayHintText(FamitsuMessage10, 180);
						Collected1 = false;
						Collected2 = false;
						Collected3 = false;
						Collected4 = false;
						Collected5 = false;
						CollectedAll = 0;
						ChallengeAction = false;
						ChallengeTimer = 0;
						HintTimer = 60;
					}
				}
				else
				{
					if (HintTimer <= 0)
					{
						PlaySound(6, 0, 0, 0);
						DisplayHintText(FamitsuMessage2, 180);
						HintTimer = 120;
					}
				}
			}
		}
		if (v1->Scale.x > 0.05f) FamitsuBalloons_Display(a1);
	}
}

static void FamitsuBalloons_Load(ObjectMaster *a1)
{
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))FamitsuBalloons_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))FamitsuBalloons_Display;
	a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
}

static void TimerFamitsu_Display(ObjectMaster *a1)
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

static void TimerFamitsu_Main(ObjectMaster *a1)
{
	if (((ChallengeTimer / 3600) % 60) / 10 < 1)
	{
		if (ChallengeAction)
		{
			CollectedAll = Collected1 + Collected2 + Collected3 + Collected4 + Collected5;
			ChallengeTimer++;
			TimerFamitsu_Display(a1);
		}
	}
	if (((ChallengeTimer / 3600) % 60) / 10 >= 1)
	{
		ChallengeAction = false;
		ChallengeTimer = 0;
		DisplayHintText(FamitsuMessage3, 180);
	}
}

static void TimerFamitsu_Load(ObjectMaster *a1)
{
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))TimerFamitsu_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))TimerFamitsu_Display;
	a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
}

void Famitsu_LoadStuff(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF0, FamitsuBalloons_Load);
	ObjectFunc(OF1, FamitsuPoster_Load);
	ObjectFunc(OF2, TimerFamitsu_Load);
	setdata_dlc.Distance = 612800.0f;
	if (GameMode == GameModes_Adventure_Field || GameMode == GameModes_Mission)
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
			//Balloons
			obj = LoadObject((LoadObj)2, 3, OF0);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 102;
				ent->Position.y = 30;
				ent->Position.z = 1495;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0;
				ent->Rotation.z = 0;
				if (!ChallengeAction)
				{
					ent->Scale.x = 1.5f;
					ent->Scale.y = 1.5f;
					ent->Scale.z = 1.5f;
				}
				else
				{
					ent->Scale.x = 0.05f;
					ent->Scale.y = 0.05f;
					ent->Scale.z = 0.05f;
				}
				ent->CharIndex = 9;
				ent->CharID = 10;
				ent->NextAction = 3;
			}
			obj = LoadObject((LoadObj)2, 3, OF0);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = -15;
				ent->Position.y = 105;
				ent->Position.z = 1305;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0;
				ent->CharIndex = 1;
				ent->Rotation.z = 0;
				if (ChallengeAction)
				{
					ent->Scale.x = 1.5f;
					ent->Scale.y = 1.5f;
					ent->Scale.z = 1.5f;
				}
				else
				{
					ent->Scale.x = 0.05f;
					ent->Scale.y = 0.05f;
					ent->Scale.z = 0.05f;
				}
				ent->CharID = 10;
				ent->NextAction = 1;
			}
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 435;
				ent->Position.y = 26;
				ent->Position.z = 652;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0x4000;
				ent->Rotation.z = 0;
				ent->CharIndex = 5;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
				ent->NextAction = 0;
			}
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = -275;
				ent->Position.y = -10;
				ent->Position.z = 1938;
				ent->Rotation.x = 0x4000;
				ent->Rotation.y = 0x4000;
				ent->Rotation.z = 0;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
				ent->CharIndex = 6;
				ent->NextAction = 4;
			}
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = -535;
				ent->Position.y = 27;
				ent->Position.z = 1458;
				ent->Rotation.x = 0x4000;
				ent->Rotation.y = 0x4000;
				ent->Rotation.z = 0;
				ent->CharIndex = 7;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
				ent->NextAction = 1;
			}
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = -66;
				ent->Position.y = 229;
				ent->Position.z = 1205;
				ent->Rotation.x = 0x4000;
				ent->Rotation.y = 0x93E9;
				ent->Rotation.z = 0;
				ent->CharIndex = 8;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
				ent->NextAction = 1;
			}
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 236;
				ent->Position.y = 18;
				ent->Position.z = 1033;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0;
				ent->Rotation.z = 0;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
				ent->CharIndex = 4;
				ent->NextAction = 3;
			}
			ObjectsLoaded = true;
		}
	}
}
