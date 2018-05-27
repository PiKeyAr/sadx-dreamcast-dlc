// Christmas '98 DLC functions.
#include <stdafx.h>
#include "Christmas98.h"
#include "Data/DLC_Christmas98.h"

const PVMEntry Christmas98Textures = { "SONICADV_000", (TexList *)&texlist_christmas98 };

static void Christmas98_Display(ObjectMaster *a1)
{
	EntityData1 *v1;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		njSetTexture(&texlist_christmas98);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		njRotateXYZ(0, v1->Rotation.x, v1->Rotation.y, v1->Rotation.z);
		njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
		ProcessModelNode_AB_Wrapper(&object_00000F9C, 1.0f);
		njPopMatrix(1u);
	}
}

static void Christmas98_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
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
						DisplayHintText(Christmas98Message0, 240);
						break;
					case 1:
						DisplayHintText(Christmas98Message1, 240);
						break;
					case 2:
						DisplayHintText(Christmas98Message2, 240);
						break;
					case 3:
						DisplayHintText(Christmas98Message3, 240);
						break;
					case 4:
						DisplayHintText(Christmas98Message4, 240);
						break;
					case 5:
						DisplayHintText(Christmas98Message5, 240);
						break;
					case 6:
						DisplayHintText(Christmas98Message6, 240);
						break;
					case 7:
						DisplayHintText(Christmas98Message7, 240);
						break;
					default:
						break;
					}
					HintTimer = 240;
				}
			}
			Christmas98_Display(a1);
		}
	}
}

void Christmas98_Load(ObjectMaster *a1)
{
	EntityData1 *v1; // edi@1
	NJS_OBJECT *v2; // eax@2
	v1 = a1->Data1;
	v2 = DynamicCOL_AddFromEntity(&object_00000F9C, a1, (ColFlags)0x20001001);
	v2->scl[0] = v1->Scale.x;
	v2->scl[1] = v1->Scale.y;
	v2->scl[2] = v1->Scale.z;
	v2->ang[0] = v1->Rotation.x;
	v2->ang[1] = v1->Rotation.y;
	v2->ang[2] = v1->Rotation.z;
	v2->pos[0] = v1->Position.x;
	v2->pos[1] = v1->Position.y;
	v2->pos[2] = v1->Position.z;
	a1->DeleteSub = DeleteObject_DynamicCOL;
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))Christmas98_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))Christmas98_Display;
}

void Christmas98_LoadStuff(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF0, Christmas98_Load);
	setdata_dlc.Distance = 612800.0f;
	if (ObjectsLoaded == false)
	{
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -330;
			ent->Position.y = 0;
			ent->Position.z = 1720;
			ent->Index = 70;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.2f;
			ent->Scale.y = 1.2f;
			ent->Scale.z = 1.2f;
			ent->CharIndex = 0;
			ent->NextAction = 4;
			ent->Action = 20;
		}
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
			ent->Rotation.y = 0x4000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.2f;
			ent->Scale.y = 1.2f;
			ent->Scale.z = 1.2f;
			ent->CharIndex = 1;
			ent->Action = 20;
			ent->NextAction = 0;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 224;
			ent->Position.y = 4;
			ent->Position.z = 282;
			ent->Index = 69;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x4000;
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
			ent->Position.x = -525;
			ent->Position.y = 0;
			ent->Position.z = 1500;
			ent->Index = 68;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x4000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.2f;
			ent->Scale.y = 1.2f;
			ent->Scale.z = 1.2f;
			ent->CharIndex = 3;
			ent->NextAction = 1;
			ent->Action = 20;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -365;
			ent->Position.y = 0;
			ent->Position.z = 1500;
			ent->Index = 70;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x4000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.2f;
			ent->Scale.y = 1.2f;
			ent->Scale.z = 1.2f;
			ent->CharIndex = 4;
			ent->NextAction = 1;
			ent->Action = 20;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -81;
			ent->Position.y = 65;
			ent->Position.z = 1274;
			ent->Index = 68;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x5555;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.2f;
			ent->Scale.y = 1.2f;
			ent->Scale.z = 1.2f;
			ent->CharIndex = 5;
			ent->NextAction = 1;
			ent->Action = 30;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -1;
			ent->Position.y = 65;
			ent->Position.z = 1231;
			ent->Index = 69;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x5555;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.2f;
			ent->Scale.y = 1.2f;
			ent->Scale.z = 1.2f;
			ent->CharIndex = 6;
			ent->NextAction = 1;
			ent->Action = 30;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -2;
			ent->Position.y = -2;
			ent->Position.z = 1672;
			ent->Index = 68;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x5555;
			ent->Rotation.z = 0;
			ent->Scale.x = 2.4f;
			ent->Scale.y = 2.4f;
			ent->Scale.z = 2.4f;
			ent->CharIndex = 7;
			ent->NextAction = 3;
			ent->Action = 30;
		}
		ObjectsLoaded = true;
	}
}
