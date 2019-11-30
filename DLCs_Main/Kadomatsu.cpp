// Kadomatsu DLC functions.
#include <stdafx.h>
#include "Kadomatsu.h"
#include "Data/DLC_Kadomatsu.h"

const PVMEntry KadomatsuTextures = { "SONICADV_001", (TexList*)&texlist_kadomatsu };

static void Kadomatsu_Display(ObjectMaster* a1)
{
	EntityData1* v1;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		njSetTexture(&texlist_kadomatsu);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		njRotateXYZ(0, v1->Rotation.x, v1->Rotation.y, v1->Rotation.z);
		njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
		ProcessModelNode_D(&kadomatsu, QueuedModelFlagsB_EnableZWrite, 1.0f);
		njPopMatrix(1u);
	}
}

static void Kadomatsu_Main(ObjectMaster* a1)
{
	EntityData1* v1;
	int CollisionRadius;
	v1 = a1->Data1;
	CollisionRadius = v1->Action;
	if (CurrentLevel == 26)
	{
		if (v1->NextAction == CurrentAct)
		{
			if (IsPlayerInsideSphere(&v1->Position, CollisionRadius))
			{
				if (HintTimer <= 0)
				{
					if (v1->Index == 68 && MusicMode != 1)
					{
						StopMusic();
						sub_425800(MusicIDs_nights_a);
						MusicMode = 1;
						WriteData<1>((char*)0x0062EEF9, MusicIDs_nights_a);
					}
					if (v1->Index == 69 && MusicMode != 2)
					{
						StopMusic();
						sub_425800(MusicIDs_nights_k);
						MusicMode = 2;
						WriteData<1>((char*)0x0062EEF9, MusicIDs_nights_k);
					}
					if (v1->Index == 70 && MusicMode != 3)
					{
						StopMusic();
						sub_425800(MusicIDs_nights_s);
						MusicMode = 3;
						WriteData<1>((char*)0x0062EEF9, MusicIDs_nights_s);
					}
					switch (v1->CharIndex)
					{
					case 0:
						DisplayHintText(KadomatsuMessage0, 240);
						break;
					case 1:
						DisplayHintText(KadomatsuMessage1, 240);
						break;
					case 2:
						DisplayHintText(KadomatsuMessage2, 240);
						break;
					case 3:
						DisplayHintText(KadomatsuMessage3, 240);
						break;
					case 4:
						DisplayHintText(KadomatsuMessage4, 240);
						break;
					case 5:
						DisplayHintText(KadomatsuMessage5, 240);
						break;
					case 6:
						DisplayHintText(KadomatsuMessage6, 240);
						break;
					case 7:
						DisplayHintText(KadomatsuMessage7, 240);
						break;
					case 8:
						DisplayHintText(KadomatsuMessage8, 240);
						break;
					case 9:
						DisplayHintText(KadomatsuMessage9, 240);
						break;
					default:
						break;
					}
					HintTimer = 240;
				}
			}
			Kadomatsu_Display(a1);
		}
	}
}

void Kadomatsu_Load(ObjectMaster* a1)
{
	EntityData1* v1; // edi@1
	NJS_OBJECT* v2; // eax@2
	v1 = a1->Data1;
	v2 = DynamicCOL_AddFromEntity(&kadomatsu, a1, (ColFlags)0x20001001);
	v2->scl[0] = v1->Scale.x;
	v2->scl[1] = v1->Scale.y;
	v2->scl[2] = v1->Scale.z;
	v2->ang[0] = v1->Rotation.x;
	v2->ang[1] = v1->Rotation.y;
	v2->ang[2] = v1->Rotation.z;
	v2->pos[0] = v1->Position.x;
	v2->pos[1] = v1->Position.y;
	v2->pos[2] = v1->Position.z;
	a1->DeleteSub = DynamicCOL_DeleteObject;
	a1->MainSub = (void(__cdecl*)(ObjectMaster*))Kadomatsu_Main;
	a1->DisplaySub = (void(__cdecl*)(ObjectMaster*))Kadomatsu_Display;
}

void Kadomatsu_LoadStuff(void)
{
	ObjectMaster* obj;
	EntityData1* ent;
	ObjectFunc(OF0, Kadomatsu_Load);
	setdata_dlc.Distance = 612800.0f;
	if (!ObjectsLoaded)
	{
		//Act 4
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -308;
			ent->Position.y = 15;
			ent->Position.z = 1641;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Scale.x = 0.4f;
			ent->Scale.y = 0.4f;
			ent->Scale.z = 0.4f;
			ent->CharIndex = 0;
			ent->NextAction = 4;
			ent->Action = 0;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -286;
			ent->Position.y = 15;
			ent->Position.z = 1641;
			ent->Index = 68;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Scale.x = 0.4f;
			ent->Scale.y = 0.4f;
			ent->Scale.z = 0.4f;
			ent->CharIndex = 0;
			ent->Action = 0;
			ent->NextAction = 4;
		}
		//Act 0
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 317;
			ent->Position.y = 4;
			ent->Position.z = 282;
			ent->Index = 68;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.2f;
			ent->Scale.y = 1.2f;
			ent->Scale.z = 1.2f;
			ent->CharIndex = 2;
			ent->NextAction = 0;
			ent->Action = 20;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 224;
			ent->Position.y = 4;
			ent->Position.z = 282;
			ent->Index = 70;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.2f;
			ent->Scale.y = 1.2f;
			ent->Scale.z = 1.2f;
			ent->CharIndex = 3;
			ent->NextAction = 0;
			ent->Action = 20;
		}
		//Act 3
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 52;
			ent->Position.y = 25;
			ent->Position.z = 1384;
			ent->Index = 70;
			ent->Rotation.x = 0;
			ent->Rotation.y = 5461;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.5f;
			ent->Scale.y = 1.5f;
			ent->Scale.z = 1.5f;
			ent->CharIndex = 6;
			ent->NextAction = 3;
			ent->Action = 20;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 11;
			ent->Position.y = 25;
			ent->Position.z = 1405;
			ent->Index = 69;
			ent->Rotation.x = 0;
			ent->Rotation.y = 5461;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.5f;
			ent->Scale.y = 1.5f;
			ent->Scale.z = 1.5f;
			ent->CharIndex = 7;
			ent->NextAction = 3;
			ent->Action = 20;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -163;
			ent->Position.y = 0;
			ent->Position.z = 1721;
			ent->Index = 70;
			ent->Rotation.x = 0;
			ent->Rotation.y = 16384;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.5f;
			ent->Scale.y = 1.5f;
			ent->Scale.z = 1.5f;
			ent->CharIndex = 8;
			ent->NextAction = 3;
			ent->Action = 20;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -163;
			ent->Position.y = 0;
			ent->Position.z = 1651;
			ent->Index = 68;
			ent->Rotation.x = 0;
			ent->Rotation.y = 16384;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.5f;
			ent->Scale.y = 1.5f;
			ent->Scale.z = 1.5f;
			ent->CharIndex = 9;
			ent->NextAction = 3;
			ent->Action = 20;
		}
		//Act 1 (recreated)
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -630;
			ent->Position.y = 0;
			ent->Position.z = 927;
			ent->Index = 68;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x2F9F;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.2f;
			ent->Scale.y = 1.2f;
			ent->Scale.z = 1.2f;
			ent->CharIndex = 4;
			ent->NextAction = 1;
			ent->Action = 15;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -596;
			ent->Position.y = 0;
			ent->Position.z = 895;
			ent->Index = 70;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x994;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.2f;
			ent->Scale.y = 1.2f;
			ent->Scale.z = 1.2f;
			ent->CharIndex = 5;
			ent->NextAction = 1;
			ent->Action = 15;
		}
		ObjectsLoaded = true;
	}
}