// Quo DLC functions.
#include <stdafx.h>
#include "Quo.h"

const PVMEntry QuoTextures = { "SONICADV_002", (TexList *)&texlist_quo };

static void QUOPoster_Display(ObjectMaster *a1)
{
	EntityData1 *v1;
	Angle v2;
	Angle v3;
	Angle v4;
	int RotationSpeed;
	v1 = a1->Data1;
	if (!DroppedFrames && !IsGamePaused())
	{
		njSetTexture(&texlist_quo);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		v2 = v1->Rotation.x;
		v3 = v1->Rotation.y;
		v4 = v1->Rotation.z;
		njRotateXYZ(0, v2, v3, v4);
		njScale(0, v1->Scale.z, v1->Scale.y, v1->Scale.x);
		if ((CollectedSS1 && v1->Index == 0) || (CollectedSS2 && v1->Index == 1) || (CollectedSS3 && v1->Index == 2) || (CollectedMR1 && v1->Index == 3) || (CollectedMR2 && v1->Index == 4) || (CollectedMR3 && v1->Index == 5))
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

static void QUOPoster_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
	Angle v3;
	int SpeedY;
	v1 = a1->Data1;
	if (v1->Action == CurrentLevel && v1->NextAction == CurrentAct)
	{
		if (!ChallengeAction)
		{
			CollectedSS1 = false;
			CollectedSS2 = false;
			CollectedSS3 = false;
			CollectedMR1 = false;
			CollectedMR2 = false;
			CollectedMR3 = false;
		}
		else
		{
			if ((!CollectedSS1 && v1->Index == 0) || (!CollectedSS2 && v1->Index == 1) || (!CollectedSS3 && v1->Index == 2) || (!CollectedMR1 && v1->Index == 3) || (!CollectedMR2 && v1->Index == 4) || (!CollectedMR3 && v1->Index == 5))
			{
				v1->InvulnerableTime = 0;
				v1->Scale.x = 1.0f;
				v1->Scale.y = 1.0f;
				v1->Scale.z = 1.0f;
				if (IsPlayerInsideSphere(&v1->Position, 15))
				{
					if (v1->Index == 0)
					{
						CollectedSS1 = true;
						PlaySound(30, 0, 0, 0);
						if (CollectedSS1 && CollectedSS2 && CollectedSS3 && CollectedMR1 && CollectedMR2 && CollectedMR3) DisplayHintText(QuoMessage1, 180); else DisplayHintText(QuoMessage5, 180);
						HintTimer = 60;
					}
					if (v1->Index == 1)
					{
						CollectedSS2 = true;
						PlaySound(30, 0, 0, 0);
						if (CollectedSS1 && CollectedSS2 && CollectedSS3 && CollectedMR1 && CollectedMR2 && CollectedMR3) DisplayHintText(QuoMessage1, 180); else DisplayHintText(QuoMessage6, 180);
						HintTimer = 60;
					}
					if (v1->Index == 2)
					{
						CollectedSS3 = true;
						PlaySound(30, 0, 0, 0);
						if (CollectedSS1 && CollectedSS2 && CollectedSS3 && CollectedMR1 && CollectedMR2 && CollectedMR3) DisplayHintText(QuoMessage1, 180); else DisplayHintText(QuoMessage7, 180);
						HintTimer = 60;
					}
					if (v1->Index == 3)
					{
						CollectedMR1 = true;
						PlaySound(30, 0, 0, 0);
						if (CollectedSS1 && CollectedSS2 && CollectedSS3 && CollectedMR1 && CollectedMR2 && CollectedMR3) DisplayHintText(QuoMessage1, 180); else DisplayHintText(QuoMessage10, 180);
						HintTimer = 60;
					}
					if (v1->Index == 4)
					{
						CollectedMR2 = true;
						PlaySound(30, 0, 0, 0);
						if (CollectedSS1 && CollectedSS2 && CollectedSS3 && CollectedMR1 && CollectedMR2 && CollectedMR3) DisplayHintText(QuoMessage1, 180); else DisplayHintText(QuoMessage8, 180);
						HintTimer = 60;
					}
					if (v1->Index == 5)
					{
						CollectedMR3 = true;
						PlaySound(30, 0, 0, 0);
						if (CollectedSS1 && CollectedSS2 && CollectedSS3 && CollectedMR1 && CollectedMR2 && CollectedMR3) DisplayHintText(QuoMessage1, 180); else DisplayHintText(QuoMessage9, 180);
						HintTimer = 60;
					}
				}
			}
			if ((CollectedSS1 && v1->Index == 0) || (CollectedSS2 && v1->Index == 1) || (CollectedSS3 && v1->Index == 2) || (CollectedMR1 && v1->Index == 3) || (CollectedMR2 && v1->Index == 4) || (CollectedMR3 && v1->Index == 5))
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
			SpeedY = v1->CharID;
			v3 = v1->Rotation.y;
			v3 = (v3 + SpeedY * 16) % 65535;
			v1->Rotation.y = v3;
			if (v1->Scale.x > 0.05f) QUOPoster_Display(a1);
		}
	}
}

static void QUOPoster_Load(ObjectMaster *a1)
{
	a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))QUOPoster_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))QUOPoster_Display;
}

static void QUOBalloons_Display(ObjectMaster *a1)
{
	EntityData1 *v1;
	Angle v2;
	Angle v3;
	Angle v4;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		njSetTexture(&texlist_quo);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
		v2 = v1->Rotation.x;
		v3 = v1->Rotation.y;
		v4 = v1->Rotation.z;
		njRotateXYZ(0, v2, v3, v4);
		if (v1->CharIndex == 3) ProcessModelNode_AB_Wrapper(&balloon_start, v1->Scale.x);
		else ProcessModelNode_AB_Wrapper(&balloon_finish, v1->Scale.x);
		njPopMatrix(1u);
	}
}

static void QUOBalloons_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
	int SpeedY;
	Angle v2;
	Angle v3;
	Angle v4;
	NJS_OBJECT *v5; // eax@2
	v1 = a1->Data1;
	if (v1->Action == CurrentLevel && v1->NextAction == CurrentAct)
	{
		SpeedY = (v1->CharID) * 16;
		v2 = v1->Rotation.x;
		v3 = v1->Rotation.y;
		v4 = v1->Rotation.z;
		v3 = (v3 + int(SpeedY)) % 65535;
		v1->Rotation.y = v3;
		if (v1->CharIndex == 3)
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
					DisplayHintText(QuoMessage4, 180);
					CollectedSS1 = false;
					CollectedSS2 = false;
					CollectedSS3 = false;
					CollectedMR1 = false;
					CollectedMR2 = false;
					CollectedMR3 = false;
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
				if (CollectedAll >= 6)
				{
					if (HintTimer <= 0)
					{
						PlaySound(12, 0, 0, 0);
						snprintf(ResultText, LengthOfArray(ResultText),
							"Your result is: %d%d:%d%d:%d%d.",
							TimerTenMinutesTexanim.texid, TimerMinutesTexanim.texid,
							TimerTenSecondsTexanim.texid, TimerSecondsTexanim.texid,
							TimerMTenSecondsTexanim.texid, TimerMSecondsTexanim.texid);
						DisplayHintText(QuoMessage11, 180);
						CollectedSS1 = false;
						CollectedSS2 = false;
						CollectedSS3 = false;
						CollectedMR1 = false;
						CollectedMR2 = false;
						CollectedMR3 = false;
						CollectedAll = 0;
						ChallengeAction = false;
						ChallengeTimer = 0;
						HintTimer = 180;
					}
				}
				else
				{
					if (HintTimer <= 0)
					{
						PlaySound(6, 0, 0, 0);
						DisplayHintText(QuoMessage2, 180);
						HintTimer = 120;
					}
				}
			}
		}
		if (v1->Scale.x > 0.05f) QUOBalloons_Display(a1);
	}
}

static void QUOTimer_Display(ObjectMaster *a1)
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
	CardCountTotalTexanim.texid = 6;
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

static void QUOTimer_Main(ObjectMaster *a1)
{
	if (((ChallengeTimer / 3600) % 60) / 10 < 1)
	{
		if (ChallengeAction)
		{
			CollectedAll = CollectedSS1 + CollectedSS2 + CollectedSS3 + CollectedMR1 + CollectedMR2 + CollectedMR3;
			ChallengeTimer++;
			QUOTimer_Display(a1);
		}
	}
	if (((ChallengeTimer / 3600) % 60) / 10 >= 1)
	{
		ChallengeAction = false;
		ChallengeTimer = 0;
		DisplayHintText(QuoMessage3, 180);
	}
}

static void QUOTimer_Load(ObjectMaster *a1)
{
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))QUOTimer_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))QUOTimer_Display;
	a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
}

static void QUOBalloons_Load(ObjectMaster *a1)
{
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))QUOBalloons_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))QUOBalloons_Display;
	a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
}

void LoadQUOStuff(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF0, QUOBalloons_Load);
	ObjectFunc(OF1, QUOPoster_Load);
	ObjectFunc(OF2, QUOTimer_Load);
	setdata_dlc.Distance = 612800.0f;
	if (GameMode == GameModes_Adventure_Field || GameMode == GameModes_Mission)
	{
		if (!TimerLoaded)
		{
			//QUOTimer
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
			TimerLoaded = true;
		}
		//Station Square objects
		if (CurrentLevel == 26 && !ObjectsLoaded_SS)
		{
			//Balloon
			obj = LoadObject((LoadObj)2, 3, OF0);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 44;
				ent->Position.y = 50;
				ent->Position.z = 1418;
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
				ent->CharIndex = 3;
				ent->CharID = 10;
				ent->Action = 26;
				ent->NextAction = 3;
			}
			//Cards
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = -163;
				ent->Position.y = 60;
				ent->Position.z = 1788;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0x6000;
				ent->Rotation.z = 0;
				ent->CharIndex = 4;
				//ent->CharID = 10;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
				ent->Action = 26;
				ent->NextAction = 3;
				ent->Index = 0;
			}
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 540;
				ent->Position.y = -14;
				ent->Position.z = 1377;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0;
				ent->Rotation.z = 0;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
				ent->CharIndex = 5;
				ent->Action = 26;
				ent->NextAction = 3;
				ent->CharID = 10;
				ent->Index = 1;
			}
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 161;
				ent->Position.y = 23;
				ent->Position.z = 1260;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0x4000;
				ent->Rotation.z = 0;
				ent->CharIndex = 6;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
				//ent->CharID = 0;
				ent->Action = 26;
				ent->NextAction = 3;
				ent->Index = 2;
			}
			ObjectsLoaded_SS = true;
		}
		//Mystic Ruins objects
		if (CurrentLevel == 33 && !ObjectsLoaded_MR)
		{
			//Balloon
			obj = LoadObject((LoadObj)2, 3, OF0);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = -97;
				ent->Position.y = 107;
				ent->Position.z = 1106;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0;
				ent->Rotation.z = 0;
				ent->CharIndex = 10;
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
				ent->Action = 33;
				ent->NextAction = 0;
			}
			//Cards
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 175;
				ent->Position.y = -8;
				ent->Position.z = 72;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0;
				ent->Rotation.z = 0;
				ent->CharIndex = 9;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
				ent->Action = 33;
				ent->NextAction = 0;
				ent->Index = 3;
				ent->CharID = 10;
			}
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 1574;
				ent->Position.y = 12;
				ent->Position.z = 528;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0;
				ent->Rotation.z = 0;
				ent->CharIndex = 5;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
				ent->Action = 33;
				ent->NextAction = 0;
				ent->Index = 4;
				ent->CharID = 10;
			}
			obj = LoadObject((LoadObj)2, 3, OF1);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = 496;
				ent->Position.y = 214;
				ent->Position.z = 502;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0;
				ent->Rotation.z = 0;
				ent->CharIndex = 7;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
				ent->Action = 33;
				ent->NextAction = 0;
				ent->Index = 5;
				ent->CharID = 10;
			}
			ObjectsLoaded_MR = true;
		}
	}
}
