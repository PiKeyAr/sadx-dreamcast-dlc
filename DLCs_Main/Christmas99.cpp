// Christmas '98 DLC functions.
#include <stdafx.h>
#include "Christmas99.h"
#include "Data/DLC_Christmas99.h"

const PVMEntry Christmas99Textures = { "SONICADV_509", (TexList *)&texlist_christmas99 }; 

static void Christmas99_Display(ObjectMaster *a1)
{
	EntityData1 *v1;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		njSetTexture(&texlist_christmas99);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		njRotateXYZ(0, v1->Rotation.x, v1->Rotation.y, v1->Rotation.z);
		njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
		ProcessModelNode_AB_Wrapper(&object_00001990_1, 1.0f);
		ProcessModelNode_AB_Wrapper(&object_00001990_2, 1.0f);
		DrawQueueDepthBias = 8000.0f;
		ProcessModelNode_A_Wrapper(&object_00001990_3, (QueuedModelFlagsB)0, 1.0f);
		DrawQueueDepthBias = 0;
		njPopMatrix(1u);
	}
}

static void Christmas99_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
	v1 = a1->Data1;
	if (CurrentLevel == 26)
	{
		if (v1->Action == CurrentLevel && v1->NextAction == CurrentAct)
		{
			if (IsPlayerInsideSphere(&v1->Position, 25))
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
					if (v1->Index == 70)
					{
						if (GetTimeOfDay() != 0 && MusicMode != 2)
						{
							StopMusic();
							sub_425800(MusicIDs_nights_s);
							MusicMode = 2;
							WriteData<1>((char*)0x0062EEF9, MusicIDs_nights_s);
						}
						if (GetTimeOfDay() == 0 && MusicMode != 1)
						{
							StopMusic();
							sub_425800(MusicIDs_nights_a);
							MusicMode = 1;
							WriteData<1>((char*)0x0062EEF9, MusicIDs_nights_a);
						}
					}
					switch (v1->CharIndex)
					{
					case 0:
						DisplayHintText(Christmas99Message0, 180);
						break;
					case 1:
						DisplayHintText(Christmas99Message1, 180);
						break;
					case 2:
						DisplayHintText(Christmas99Message2, 180);
						break;
					case 3:
						DisplayHintText(Christmas99Message3, 180);
						break;
					default:
						break;
					}
					HintTimer = 180;
				}
			}
			Christmas99_Display(a1);
		}
	}
}

void Christmas99_Load(ObjectMaster *a1)
{
	EntityData1 *v1; // edi@1
	NJS_OBJECT *v2; // eax@2
	v1 = a1->Data1;
	v2 = DynamicCOL_AddFromEntity(&object_00001990, a1, (ColFlags)0x20001001);
	v2->scl[0] = 1.0f;
	v2->scl[1] = 1.0f;
	v2->scl[2] = 1.0f;
	v2->ang[0] = v1->Rotation.x;
	v2->ang[1] = v1->Rotation.y;
	v2->ang[2] = v1->Rotation.z;
	v2->pos[0] = v1->Position.x;
	v2->pos[1] = v1->Position.y;
	v2->pos[2] = v1->Position.z;
	a1->DeleteSub = DynamicCOL_DeleteObject;
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))Christmas99_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))Christmas99_Display;
}

void Christmas99_LoadStuff()
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF0, Christmas99_Load);
	setdata_dlc.Distance = 612800.0f;
	if ((GameMode == GameModes_Adventure_Field || GameMode == GameModes_Mission) && !ObjectsLoaded)
	{
		//This damn tree
		if (CurrentCharacter != 0 || GetEventFlag(EventFlags_Sonic_SpeedHighwayClear))
		{
			obj = LoadObject((LoadObj)2, 3, OF0);
			obj->SETData.SETData = &setdata_dlc;
			if (obj)
			{
				ent = obj->Data1;
				ent->Position.x = -23;
				if (ForceSADXLayout)
				{
					ent->Position.y = -1;
				}
				else
				{
					ent->Position.y = 2;
				}
				ent->Position.z = 1673;
				ent->Index = 68;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0;
				ent->Rotation.z = 0;
				ent->Scale.x = 1.0f;
				ent->Scale.y = 1.0f;
				ent->Scale.z = 1.0f;
				ent->CharIndex = 0;
				ent->Action = 26;
				ent->NextAction = 3;
			}
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -10;
			ent->Position.y = 67;
			ent->Position.z = 1306;
			ent->Index = 68;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 1;
			ent->Action = 26;
			ent->NextAction = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -453;
			ent->Position.y = -2;
			ent->Position.z = 1406;
			ent->Index = 70;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 2;
			ent->Action = 26;
			ent->NextAction = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 265;
			if (ForceSADXLayout)
			{
				ent->Position.y = -1;
				ent->Position.z = 712;
			}
			else
			{
				ent->Position.y = 1;
				ent->Position.z = 668;
			}
			ent->Index = 70;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 3;
			ent->Action = 26;
			ent->NextAction = 0;
		}
		ObjectsLoaded = true;
	}
}
