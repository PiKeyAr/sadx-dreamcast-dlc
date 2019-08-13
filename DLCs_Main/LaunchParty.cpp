// Launch Party DLC functions.
#include <stdafx.h>
#include "LaunchParty.h"
#include "Data/DLC_LaunchParty.h"

const PVMEntry LaunchPartyUSTextures = { "SONICADV_501", (TexList *)&texlist_launch };
const PVMEntry LaunchPartyEUTextures = { "SONICADV_502", (TexList *)&texlist_launch };
const PVMEntry LaunchPartyJPTextures = { "SONICADV_503", (TexList *)&texlist_launch };

static void LaunchPosterDisplay(ObjectMaster *a1)
{
	EntityData1 *v1;
	Angle v2;
	Angle v3;
	Angle v4;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		njSetTexture(&texlist_launch);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		v2 = v1->Rotation.x;
		v3 = v1->Rotation.y + 0xC000;
		v4 = v1->Rotation.z;
		njRotateXYZ(0, v2, v3, v4);
		njScale(0, v1->Scale.z, v1->Scale.y, v1->Scale.x);
		ProcessModelNode_AB_Wrapper(&launchposter, v1->Scale.x);
		njPopMatrix(1u);
	}
}

static void LaunchPosterMain(ObjectMaster *a1)
{
	EntityData1 *v1;
	v1 = a1->Data1;
	if (v1->NextAction == CurrentAct)
	{
		if (IsPlayerInsideSphere(&v1->Position, 15))
		{
			if (HintTimer <= 0)
			{
				switch (v1->CharIndex)
				{
				case 0:
					DisplayHintText(LaunchPartyMessage1, 180);
					break;
				case 1:
					DisplayHintText(LaunchPartyMessage2, 180);
					break;
				case 2:
					DisplayHintText(LaunchPartyMessage3, 180);
					break;
				case 3:
					if (LaunchPartyDLCMode == 0)
						DisplayHintText(LaunchPartyMessage4_US, 180);
					if (LaunchPartyDLCMode == 1)
						DisplayHintText(LaunchPartyMessage4_EU, 180);
					if (LaunchPartyDLCMode == 2)
						DisplayHintText(LaunchPartyMessage4_JP, 180);
					break;
				case 4:
					DisplayHintText(LaunchPartyMessage5, 180);
					break;
				case 5:
					DisplayHintText(LaunchPartyMessage6, 180);
					break;
				default:
					break;
				}
				HintTimer = 120;
			}
		}
		LaunchPosterDisplay(a1);
	}
}

static void LaunchPosterLoad(ObjectMaster *a1)
{
	a1->DeleteSub = DynamicCOL_DeleteObject;
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))LaunchPosterMain;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))LaunchPosterDisplay;
}

static void LaunchPosterColli_Load(ObjectMaster *a1)
{
	Angle Wha;
	EntityData1* v1;
	NJS_OBJECT* v5;
	v1 = a1->Data1;
	if (v1->NextAction == CurrentAct)
	{
		Wha = v1->Rotation.y + 0xC000;
		v1->Rotation.y = Wha;
		v5 = DynamicCOL_AddFromEntity(&launchposter_colli, a1, (ColFlags)0x20001001);
		v5->scl[0] = 1.0f;
		v5->scl[1] = 1.0f;
		v5->scl[2] = 1.0f;
		a1->DeleteSub = DynamicCOL_DeleteObject;
		a1->MainSub = (void(__cdecl *)(ObjectMaster *))nullsub;
		a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))nullsub;
	}
}

static void PartyBalloons_Display(ObjectMaster *a1)
{
	EntityData1 *v1;
	Angle v2;
	Angle v3;
	Angle v4;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		njSetTexture(&texlist_launch);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
		v2 = v1->Rotation.x;
		v3 = v1->Rotation.y;
		v4 = v1->Rotation.z;
		njRotateXYZ(0, v2, v3, v4);
		ProcessModelNode_C(&object_0000180C, (QueuedModelFlagsB)4, v1->Scale.x);
		//ProcessModelNode_AB_Wrapper(&object_0000180C, v1->Scale.x);
		njPopMatrix(1u);
	}
}

static void PartyBalloons_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
	int SpeedX;
	int SpeedY;
	int SpeedZ;
	Angle v2;
	Angle v3;
	Angle v4;
	NJS_OBJECT *v5; // eax@2
	v1 = a1->Data1;
	if (v1->NextAction == CurrentAct)
	{
		SpeedX = (v1->Action) * 16;
		SpeedY = (v1->CharID) * 16;
		SpeedZ = (v1->CharIndex) * 16;
		v2 = v1->Rotation.x;
		v3 = v1->Rotation.y;
		v4 = v1->Rotation.z;
		v2 = (v2 + int(SpeedX)) % 65535;
		v3 = (v3 + int(SpeedY)) % 65535;
		v4 = (v4 + int(SpeedZ)) % 65535;
		v1->Rotation.x = v2;
		v1->Rotation.y = v3;
		v1->Rotation.z = v4;
		if (IsPlayerInsideSphere(&v1->Position, 15))
		{
			if (HintTimer <= 0)
			{
				PlaySound(23, 0, 0, 0);
				DisplayHintText(LaunchPartyMessage1, 180);
				HintTimer = 180;
			}
		}
		PartyBalloons_Display(a1);
	}
}

static void PartyBalloons_Load(ObjectMaster *a1)
{
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))PartyBalloons_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))PartyBalloons_Display;
	a1->DeleteSub = DynamicCOL_DeleteObject;
}

void LoadLaunchPartyStuff_SS(void)
{

	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF0, PartyBalloons_Load);
	ObjectFunc(OF1, LaunchPosterLoad);
	ObjectFunc(OF2, LaunchPosterColli_Load);
	setdata_dlc.Distance = 612800.0f;
	if (!ObjectsLoaded)
	{
		//Act 5 (CurrentAct 4)
		//Posters
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -297;
			ent->Position.y = 19;
			ent->Position.z = 1627;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->CharIndex = 0;
			ent->Scale.x = 2.0f;
			ent->Scale.y = 0.5f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 4;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -370;
			ent->Position.y = 1;
			ent->Position.z = 1617;
			ent->Rotation.x = 0x4000;
			ent->Rotation.y = 0xC000;
			ent->Rotation.z = 0xC000;
			ent->CharIndex = 1;
			ent->Scale.x = 2.0f;
			ent->Scale.y = 0.5f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 4;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -342;
			ent->Position.y = 26;
			ent->Position.z = 2016;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x8000;
			ent->Rotation.z = 0;
			ent->CharIndex = 2;
			ent->Scale.x = 3.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 4;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -242;
			ent->Position.y = 25;
			ent->Position.z = 2016;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x8000;
			ent->Rotation.z = 0;
			ent->CharIndex = 5;
			ent->Scale.x = 3.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 4;
		}
		//Act 4 (CurrentAct 3)
		//Poster collision
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 285;
			ent->Position.y = 13;
			ent->Position.z = 1682;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x927D;
			ent->Rotation.z = 0;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 181;
			ent->Position.y = 13;
			ent->Position.z = 1731;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x927D;
			ent->Rotation.z = 0;
			ent->NextAction = 3;
		}
		//Posters
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 27;
			ent->Position.y = 91;
			ent->Position.z = 1385;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x1333;
			ent->Rotation.z = 0;
			ent->CharIndex = 1;
			ent->Scale.x = 3.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -139;
			ent->Position.y = 36;
			ent->Position.z = 1676;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x4000;
			ent->Rotation.z = 0;
			ent->CharIndex = 3;
			ent->Scale.x = 3.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 320;
			ent->Position.y = 64;
			ent->Position.z = 1365;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC000;
			ent->Rotation.z = 0;
			ent->CharIndex = 4;
			ent->Scale.x = 3.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 260;
			ent->Position.y = 112;
			ent->Position.z = 1040;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->CharIndex = 5;
			ent->Scale.x = 7.0f;
			ent->Scale.y = 2.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 629;
			ent->Position.y = 128;
			ent->Position.z = 962;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC000;
			ent->Rotation.z = 0;
			ent->CharIndex = 1;
			ent->Scale.x = 7.0f;
			ent->Scale.y = 2.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 285;
			ent->Position.y = 13;
			ent->Position.z = 1682;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x927D;
			ent->Rotation.z = 0;
			ent->CharIndex = 1;
			ent->Scale.x = 3.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 181;
			ent->Position.y = 13;
			ent->Position.z = 1731;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x927D;
			ent->Rotation.z = 0;
			ent->CharIndex = 2;
			ent->Scale.x = 3.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 3;
		}
		//PartyBalloons
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 150;
			ent->Position.y = 55;
			ent->Position.z = 1514;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 3;
			ent->CharID = 4;
			ent->CharIndex = 5;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 66;
			ent->Position.y = 55;
			ent->Position.z = 1560;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 1;
			ent->CharID = 0;
			ent->CharIndex = 1;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 308;
			ent->Position.y = 55;
			ent->Position.z = 1630;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 0;
			ent->CharID = 0;
			ent->CharIndex = 1;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 317;
			ent->Position.y = 55;
			ent->Position.z = 1244;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 7;
			ent->CharID = 8;
			ent->CharIndex = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 208;
			ent->Position.y = 55;
			ent->Position.z = 1120;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 1;
			ent->CharID = 0;
			ent->CharIndex = 1;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 3;
		}
		//Act 1 (CurrentAct 0)
		//Posters
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 270;
			ent->Position.y = 89;
			ent->Position.z = 252;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->CharIndex = 1;
			ent->Scale.x = 7.0f;
			ent->Scale.y = 2.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 0;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 51;
			ent->Position.y = 16;
			ent->Position.z = 727;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->CharIndex = 0;
			ent->Scale.x = 0.9f;
			ent->Scale.y = 0.3f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 0;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			if (ForceSADXLayout)
			{
				ent->Position.x = 102;
				ent->Position.y = 79;
				ent->Position.z = 768;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0x4000;
				ent->Rotation.z = 0;
			}
			else
			{
				ent->Position.x = 205;
				ent->Position.y = 72;
				ent->Position.z = 1011;
				ent->Rotation.x = 0;
				ent->Rotation.y = 0x8000;
				ent->Rotation.z = 0;
			}
			ent->CharIndex = 3;
			ent->Scale.x = 7.0f;
			ent->Scale.y = 2.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 0;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 700;
			ent->Position.y = 65;
			ent->Position.z = 829;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC000;
			ent->Rotation.z = 0;
			ent->CharIndex = 4;
			ent->Scale.x = 7.0f;
			ent->Scale.y = 2.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 0;
		}
		//PartyBalloons
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 263;
			ent->Position.y = 55;
			ent->Position.z = 670;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 1;
			ent->CharID = 2;
			ent->CharIndex = 1;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 0;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 263;
			ent->Position.y = 55;
			ent->Position.z = 803;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 3;
			ent->CharID = 2;
			ent->CharIndex = 7;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 0;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 77;
			ent->Position.y = 308;
			if (ForceSADXLayout)
			{
				ent->Position.z = 340;
			}
			else
			{
				ent->Position.z = 270;
			}
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 3;
			ent->CharID = 9;
			ent->CharIndex = 1;
			ent->Scale.x = 4.0f;
			ent->Scale.y = 4.0f;
			ent->Scale.z = 4.0f;
			ent->NextAction = 0;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 458;
			ent->Position.y = 308;
			if (ForceSADXLayout)
			{
				ent->Position.z = 333;
			}
			else
			{
				ent->Position.z = 263;
			}
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 1;
			ent->CharID = 0;
			ent->CharIndex = 1;
			ent->Scale.x = 4.0f;
			ent->Scale.y = 4.0f;
			ent->Scale.z = 4.0f;
			ent->NextAction = 0;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 564;
			ent->Position.y = 55;
			ent->Position.z = 758;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 1;
			ent->CharID = 2;
			ent->CharIndex = 1;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 0;
		}
		//Act 2 (CurrentAct 1)
		//Posters
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -254;
			ent->Position.y = 79;
			ent->Position.z = 1239;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x2666;
			ent->Rotation.z = 0;
			ent->CharIndex = 1;
			ent->Scale.x = 1.4f;
			ent->Scale.y = 0.7f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -336;
			ent->Position.y = 20;
			ent->Position.z = 1382;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC16C;
			ent->Rotation.z = 0;
			ent->CharIndex = 5;
			ent->Scale.x = 1.4f;
			ent->Scale.y = 0.7f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -445;
			ent->Position.y = 42;
			ent->Position.z = 1502;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x8000;
			ent->Rotation.z = 0;
			ent->CharIndex = 4;
			ent->Scale.x = 3.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -543;
			ent->Position.y = 46;
			ent->Position.z = 1224;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x4000;
			ent->Rotation.z = 0;
			ent->CharIndex = 3;
			ent->Scale.x = 2.1f;
			ent->Scale.y = 0.6f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -437;
			ent->Position.y = 53;
			ent->Position.z = 906;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->CharIndex = 2;
			ent->Scale.x = 4.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -416;
			ent->Position.y = 36;
			ent->Position.z = 2020;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->CharIndex = 3;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 1;
		}
		//PartyBalloons
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -78;
			ent->Position.y = 122;
			ent->Position.z = 1257;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 2;
			ent->CharID = 2;
			ent->CharIndex = 1;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -15;
			ent->Position.y = 122;
			ent->Position.z = 1223;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 2;
			ent->CharID = 0;
			ent->CharIndex = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -610;
			ent->Position.y = 65;
			ent->Position.z = 979;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 0;
			ent->CharID = 1;
			ent->CharIndex = 1;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -549;
			ent->Position.y = 65;
			ent->Position.z = 908;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 3;
			ent->CharID = 1;
			ent->CharIndex = 1;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -364;
			ent->Position.y = 158;
			ent->Position.z = 810;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 3;
			ent->CharID = 1;
			ent->CharIndex = 2;
			ent->Scale.x = 5.0f;
			ent->Scale.y = 5.0f;
			ent->Scale.z = 5.0f;
			ent->NextAction = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF0);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -416;
			ent->Position.y = 36;
			ent->Position.z = 2020;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0;
			ent->Rotation.z = 0;
			ent->Action = 3;
			ent->CharID = 4;
			ent->CharIndex = 2;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->NextAction = 1;
		}
		ObjectsLoaded = true;
	}
}
