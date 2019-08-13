// Christmas '98 DLC functions.
#include <stdafx.h>
#include "Halloween.h"
#include "Data/DLC_Halloween.h"

const PVMEntry HalloweenTextures = { "SONICADV_505", (TexList *)&texlist_halloween };

static void Halloween_Display(ObjectMaster *a1)
{
	EntityData1 *v1;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		njSetTexture(&texlist_halloween);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		njRotateXYZ(0, v1->Rotation.x, v1->Rotation.y, v1->Rotation.z);
		njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
		if (v1->CharID == 1) ProcessModelNode_AB_Wrapper(&object_00000CC4, 1.0f); //Jack-o-lantern
		if (v1->CharID == 2) ProcessModelNode_AB_Wrapper(&poster1h, v1->Scale.x);
		if (v1->CharID == 3) ProcessModelNode_AB_Wrapper(&poster2h, v1->Scale.x);
		if (v1->CharID == 4) ProcessModelNode_AB_Wrapper(&poster3h, v1->Scale.x);
		njPopMatrix(1u);
	}
}

static void Halloween_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
	v1 = a1->Data1;
	Angle v2;
	int v3;
	v3 = (v1->Index) * 16;
	v2 = (v1->Rotation.y + v3) % 65535;
	v1->Rotation.y = v2;
	if ((CurrentLevel == 26 && CurrentAct == 3) || (CurrentLevel == 3))
	{
		if (v1->Action == CurrentLevel && v1->NextAction == CurrentAct)
		{
			if (IsPlayerInsideSphere(&v1->Position, 15))
			{
				if (HintTimer <= 0)
				{
					if (v1->CharID == 4)
					{
						PlaySound(6, 0, 0, 0);
						DisplayHintText(HalloweenMessage0, 180);
						HintTimer = 180;
					}
					if (v1->CharID == 1)
					{
						PlaySound(6, 0, 0, 0);
						DisplayHintText(HalloweenMessage1, 180);
						HintTimer = 180;
					}
				}
			}
			Halloween_Display(a1);
		}
	}
}

void Halloween_Load(ObjectMaster *a1)
{
	EntityData1 *v1; // edi@1
	NJS_OBJECT *v2; // eax@2
	v1 = a1->Data1;
	if (v1->CharID == 1)
	{
		v2 = DynamicCOL_AddFromEntity(&object_00000CC4, a1, (ColFlags)0x20001001);
		v2->scl[0] = 1.0f;
		v2->scl[1] = 1.0f;
		v2->scl[2] = 1.0f;
		v2->ang[0] = v1->Rotation.x;
		v2->ang[1] = v1->Rotation.y;
		v2->ang[2] = v1->Rotation.z;
		v2->pos[0] = v1->Position.x;
		v2->pos[1] = v1->Position.y;
		v2->pos[2] = v1->Position.z;
	}
	else v2 = nullptr;
	a1->DeleteSub = DynamicCOL_DeleteObject;
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))Halloween_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))Halloween_Display;
}

void LoadHalloweenStuff_StationSquare(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF0, Halloween_Load);
	setdata_dlc.Distance = 612800.0f;
	if (ObjectsLoaded == false)
	{
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 378;
			ent->Position.y = 22;
			ent->Position.z = 1627;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xE000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 403;
			ent->Position.y = 26;
			ent->Position.z = 1506;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xF49F;
			ent->Rotation.z = 0;
			ent->Scale.x = 3.5f;
			ent->Scale.y = 1.5f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 161;
			ent->Position.y = 105;
			ent->Position.z = 1157;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x4000;
			ent->Rotation.z = 0;
			ent->Scale.x = 4.0f;
			ent->Scale.y = 3.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -175;
			ent->Position.y = 12;
			ent->Position.z = 1742;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x4000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 327;
			ent->Position.y = 63;
			ent->Position.z = 1446;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC888;
			ent->Rotation.z = 0;
			ent->Scale.x = 3.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 327;
			ent->Position.y = 63;
			ent->Position.z = 1287;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xB777;
			ent->Rotation.z = 0;
			ent->Scale.x = 3.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -50;
			ent->Position.y = 52;
			ent->Position.z = 1424;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x127D;
			ent->Rotation.z = 0;
			ent->Scale.x = 2.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 103;
			ent->Position.y = 52;
			ent->Position.z = 1347;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x127D;
			ent->Rotation.z = 0;
			ent->Scale.x = 2.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -6;
			ent->Position.y = 42;
			ent->Position.z = 1400;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x127D;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 56;
			ent->Position.y = 42;
			ent->Position.z = 1370;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x127D;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 161;
			ent->Position.y = 105;
			ent->Position.z = 1237;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x4000;
			ent->Rotation.z = 0;
			ent->Scale.x = 4.0f;
			ent->Scale.y = 3.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 162;
			ent->Position.y = 106;
			ent->Position.z = 1077;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x4000;
			ent->Rotation.z = 0;
			ent->Scale.x = 4.0f;
			ent->Scale.y = 3.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 378;
			ent->Position.y = 22;
			ent->Position.z = 1585;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xA000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 369;
			ent->Position.y = 66;
			ent->Position.z = 1606;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 339;
			ent->Position.y = 1;
			ent->Position.z = 1606;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC000;
			ent->Rotation.z = 0xC000;
			ent->Scale.x = 3.0f;
			ent->Scale.y = 2.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 367;
			ent->Position.y = 26;
			ent->Position.z = 1437;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 0.9f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 367;
			ent->Position.y = 26;
			ent->Position.z = 1303;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 162;
			ent->Position.y = 24;
			ent->Position.z = 1247;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x4000;
			ent->Rotation.z = 0;
			ent->Scale.x = 4.0f;
			ent->Scale.y = 2.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -175;
			ent->Position.y = 12;
			ent->Position.z = 1628;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x4000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 321;
			ent->Position.y = 63;
			ent->Position.z = 1371;
			ent->Index = 0;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC000;
			ent->Rotation.z = 0;
			ent->Scale.x = 3.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 4;
			ent->Action = 26;
			ent->NextAction = 3;
		}
		ObjectsLoaded = true;
	}

}

void LoadHalloweenStuff_Twinkle1(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF0, Halloween_Load);
	setdata_dlc.Distance = 612800.0f;
	//Act 1
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -2023;
		ent->Position.y = 1750;
		ent->Position.z = -970;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 0;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -1963;
		ent->Position.y = 1750;
		ent->Position.z = -1001;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0xAFA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 0;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -1999;
		ent->Position.y = 1750;
		ent->Position.z = -917;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0x8000;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 0;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -2000;
		ent->Position.y = 1750;
		ent->Position.z = -409;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0x6000;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 3.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 0;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -1962;
		ent->Position.y = 1749;
		ent->Position.z = -925;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -2038;
		ent->Position.y = 1749;
		ent->Position.z = -926;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -1999;
		ent->Position.y = 1749;
		ent->Position.z = -953;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -6522;
		ent->Position.y = -6616;
		ent->Position.z = 23309;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 0;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -6578;
		ent->Position.y = -6616;
		ent->Position.z = 23311;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 0;
	}
}

void LoadHalloweenStuff_Twinkle2(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF0, Halloween_Load);
	setdata_dlc.Distance = 612800.0f;
	//Act 2
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -37;
		ent->Position.y = 19;
		ent->Position.z = -950;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 2.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -90;
		ent->Position.y = 1;
		ent->Position.z = -963;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0x4000;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -63;
		ent->Position.y = 1;
		ent->Position.z = -813;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0x1555;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -113;
		ent->Position.y = 1;
		ent->Position.z = -867;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0x65B0;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 722;
		ent->Position.y = 51;
		ent->Position.z = -352;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 378;
		ent->Position.y = -114;
		ent->Position.z = -760;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 6.0f;
		ent->Scale.y = 4.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 74;
		ent->Position.y = 266;
		ent->Position.z = -151;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 5.0f;
		ent->Scale.y = 3.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 74;
		ent->Position.y = 224;
		ent->Position.z = -86;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 335;
		ent->Position.y = 226;
		ent->Position.z = 516;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x07D2;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 423;
		ent->Position.y = 306;
		ent->Position.z = 480;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x1777;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -287;
		ent->Position.y = 311;
		ent->Position.z = -365;
		ent->Index = 0;
		ent->Rotation.x = 0x4000;
		ent->Rotation.y = 0x2FA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 3.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 158;
		ent->Position.y = 566;
		ent->Position.z = -115;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xA888;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 2.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 125;
		ent->Position.y = 600;
		ent->Position.z = -29;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xB777;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 2.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 214;
		ent->Position.y = 551;
		ent->Position.z = -171;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x98E3;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 2.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 117;
		ent->Position.y = 407;
		ent->Position.z = 719;
		ent->Index = 0;
		ent->Rotation.x = 0xF3E9;
		ent->Rotation.y = 0x8000;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 176;
		ent->Position.y = 714;
		ent->Position.z = 306;
		ent->Index = 0;
		ent->Rotation.x = 0xFBBB;
		ent->Rotation.y = 0x2FA4;
		ent->Rotation.z = 0x0CCC;
		ent->Scale.x = 2.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -95;
		ent->Position.y = 372;
		ent->Position.z = -895;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 8.0f;
		ent->Scale.y = 5.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 320;
		ent->Position.y = 621;
		ent->Position.z = 339;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 8.0f;
		ent->Scale.y = 5.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 329;
		ent->Position.y = 733;
		ent->Position.z = -53;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 5.0f;
		ent->Scale.y = 3.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 589;
		ent->Position.y = 163;
		ent->Position.z = 31;
		ent->Index = 0;
		ent->Rotation.x = 0xC9F4;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 627;
		ent->Position.y = 150;
		ent->Position.z = 81;
		ent->Index = 0;
		ent->Rotation.x = 0xC9F4;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 157;
		ent->Position.y = 567;
		ent->Position.z = -250;
		ent->Index = 0;
		ent->Rotation.x = 0xF8E3;
		ent->Rotation.y = 0x2FA4;
		ent->Rotation.z = 0x0AAA;
		ent->Scale.x = 2.0f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 3;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -70;
		ent->Position.y = 0;
		ent->Position.z = -958;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -114;
		ent->Position.y = 0;
		ent->Position.z = 983;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -90;
		ent->Position.y = 0;
		ent->Position.z = -383;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -90;
		ent->Position.y = 3;
		ent->Position.z = 88;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -99;
		ent->Position.y = 7;
		ent->Position.z = 568;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -45;
		ent->Position.y = 7;
		ent->Position.z = 668;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 520;
		ent->Position.y = 5;
		ent->Position.z = 669;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 598;
		ent->Position.y = 5;
		ent->Position.z = 522;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 844;
		ent->Position.y = 1;
		ent->Position.z = 314;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 653;
		ent->Position.y = 49;
		ent->Position.z = -407;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 696;
		ent->Position.y = 49;
		ent->Position.z = -441;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 363;
		ent->Position.y = 253;
		ent->Position.z = 592;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 587;
		ent->Position.y = 326;
		ent->Position.z = 425;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -290;
		ent->Position.y = 310;
		ent->Position.z = -362;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -299;
		ent->Position.y = 336;
		ent->Position.z = -183;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -18;
		ent->Position.y = 402;
		ent->Position.z = -14;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -21;
		ent->Position.y = 440;
		ent->Position.z = 180;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -19;
		ent->Position.y = 491;
		ent->Position.z = 319;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 165;
		ent->Position.y = 579;
		ent->Position.z = 482;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 324;
		ent->Position.y = 571;
		ent->Position.z = 520;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 446;
		ent->Position.y = 553;
		ent->Position.z = 481;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 259;
		ent->Position.y = 700;
		ent->Position.z = 236;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 398;
		ent->Position.y = 700;
		ent->Position.z = 235;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 307;
		ent->Position.y = 657;
		ent->Position.z = 182;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 361;
		ent->Position.y = 657;
		ent->Position.z = 182;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 331;
		ent->Position.y = 671;
		ent->Position.z = 34;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 1;
	}
}

void LoadHalloweenStuff_Twinkle3(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF0, Halloween_Load);
	setdata_dlc.Distance = 612800.0f;
	//Act 3
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 241;
		ent->Position.y = 0;
		ent->Position.z = -114;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 246;
		ent->Position.y = 0;
		ent->Position.z = -91;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 686;
		ent->Position.y = 0;
		ent->Position.z = -97;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 910;
		ent->Position.y = 0;
		ent->Position.z = -160;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 933;
		ent->Position.y = 0;
		ent->Position.z = -152;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 876;
		ent->Position.y = -32;
		ent->Position.z = -419;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 626;
		ent->Position.y = -35;
		ent->Position.z = 575;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -105;
		ent->Position.y = 0;
		ent->Position.z = -267;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -106;
		ent->Position.y = 0;
		ent->Position.z = -69;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -108;
		ent->Position.y = 91;
		ent->Position.z = 195;
		ent->Index = 10;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharIndex = 1;
		ent->CharID = 1;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 604;
		ent->Position.y = 130;
		ent->Position.z = 164;
		ent->Index = 0;
		ent->Rotation.x = 0xC9F4;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 75;
		ent->Position.y = 1;
		ent->Position.z = -282;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0x6FA4;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 927;
		ent->Position.y = 19;
		ent->Position.z = -113;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xA38E;
		ent->Rotation.z = 0;
		ent->Scale.x = 1.5f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 752;
		ent->Position.y = -12;
		ent->Position.z = -492;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x44FA;
		ent->Rotation.z = 0;
		ent->Scale.x = 2.0f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 901;
		ent->Position.y = 16;
		ent->Position.z = -219;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x4000;
		ent->Rotation.z = 0;
		ent->Scale.x = 2.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 927;
		ent->Position.y = 27;
		ent->Position.z = -233;
		ent->Index = 0;
		ent->Rotation.x = 0x2666;
		ent->Rotation.y = 0;
		ent->Rotation.z = 0;
		ent->Scale.x = 2.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -52;
		ent->Position.y = 101;
		ent->Position.z = 537;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0x6000;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -86;
		ent->Position.y = 139;
		ent->Position.z = 489;
		ent->Index = 0;
		ent->Rotation.x = 0x4000;
		ent->Rotation.y = 0xE000;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 27;
		ent->Position.y = 0;
		ent->Position.z = -11;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0x4000;
		ent->Rotation.z = 0x33E9;
		ent->Scale.x = 2.0f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 114;
		ent->Position.y = 23;
		ent->Position.z = -286;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 1.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -151;
		ent->Position.y = 91;
		ent->Position.z = 172;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -11;
		ent->Position.y = 91;
		ent->Position.z = 172;
		ent->Index = 0;
		ent->Rotation.x = 0xC000;
		ent->Rotation.y = 0x4000;
		ent->Rotation.z = 0x8000;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 1.5f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -81;
		ent->Position.y = 34;
		ent->Position.z = -163;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 4.0f;
		ent->Scale.y = 3.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = 18;
		ent->Position.y = 99;
		ent->Position.z = -2;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 5.0f;
		ent->Scale.y = 3.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -78;
		ent->Position.y = 37;
		ent->Position.z = -301;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
	obj = LoadObject((LoadObj)2, 3, OF0);
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		ent = obj->Data1;
		ent->Position.x = -81;
		ent->Position.y = 125;
		ent->Position.z = 277;
		ent->Index = 0;
		ent->Rotation.x = 0;
		ent->Rotation.y = 0xC000;
		ent->Rotation.z = 0;
		ent->Scale.x = 3.0f;
		ent->Scale.y = 2.0f;
		ent->Scale.z = 1.0f;
		ent->CharID = 2;
		ent->Action = 3;
		ent->NextAction = 2;
	}
}
