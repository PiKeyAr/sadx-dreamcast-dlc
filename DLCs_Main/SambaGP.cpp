// Samba GP DLC functions.
#include <stdafx.h>
#include "SambaGP.h"
#include "Data/DLC_SambaGP.h"

const PVMEntry SambaGPTextures = { "SONICADV_511", (TexList *)&texlist_sambagp };

DataArray(FieldStartPosition, SonicSSStartArray, 0x0090BB58, 13);
DataArray(FieldStartPosition, TailsSSStartArray, 0x0090BC60, 8);
DataArray(FieldStartPosition, KnucklesSSStartArray, 0x0090BD00, 7);
DataArray(FieldStartPosition, AmySSStartArray, 0x0090BD90, 5);
DataArray(FieldStartPosition, BigSSStartArray, 0x0090BDF8, 6);
DataArray(FieldStartPosition, E102SSStartArray, 0x0090BE70, 7);

void CallSambaCircuit(void)
{
	int CircuitID = 0;
	if (CurrentAct == 3)
	{
		if (CurrentCharacter == Characters_Sonic || EverybodySuperSonicRacing)
			WriteData<1>((char*)0x004DAB4E, 0x57);
		else
			WriteData<1>((char*)0x004DAB4E, 0x19);

		switch (CurrentCharacter)
		{
			case Characters_Sonic:
			default:
				CircuitID = SonicTrack;
				break;
			case Characters_Tails:
				CircuitID = TailsTrack;
				break;
			case Characters_Knuckles:
				CircuitID = KnucklesTrack;
				break;
			case Characters_Amy:
				CircuitID = AmyTrack;
				break;
			case Characters_Gamma:
				CircuitID = GammaTrack;
				break;
			case Characters_Big:
				CircuitID = BigTrack;
				break;
		}

		SonicSSStartArray[11].Position.x = 635;
		SonicSSStartArray[11].Position.y = 1.4f;
		SonicSSStartArray[11].Position.z = 1570;
		SonicSSStartArray[11].YRot = NJM_DEG_ANG(180);

		TailsSSStartArray[6].Position.x = 635;
		TailsSSStartArray[6].Position.y = 1.4f;
		TailsSSStartArray[6].Position.z = 1570;
		TailsSSStartArray[6].YRot = NJM_DEG_ANG(180);

		KnucklesSSStartArray[5].Position.x = 635;
		KnucklesSSStartArray[5].Position.y = 1.4f;
		KnucklesSSStartArray[5].Position.z = 1570;
		KnucklesSSStartArray[5].YRot = NJM_DEG_ANG(180);

		AmySSStartArray[3].Position.x = 635;
		AmySSStartArray[3].Position.y = 1.4f;
		AmySSStartArray[3].Position.z = 1570;
		AmySSStartArray[3].YRot = NJM_DEG_ANG(180);

		BigSSStartArray[4].Position.x = 635;
		BigSSStartArray[4].Position.y = 1.4f;
		BigSSStartArray[4].Position.z = 1570;
		BigSSStartArray[4].YRot = NJM_DEG_ANG(180);

		E102SSStartArray[5].Position.x = 635;
		E102SSStartArray[5].Position.y = 1.4f;
		E102SSStartArray[5].Position.z = 1570;
		E102SSStartArray[5].YRot = NJM_DEG_ANG(180);
		LastLevel = 26;
		LastAct = 3;

		GetCharacterID(0);
		SetLevelEntrance(((unsigned int)0x2300 >> 4) & 0xF);
		camerahax_adventurefields();
		sub_412D80(LevelIDs_TwinkleCircuit, CircuitID);
	}
	else
	{
		WriteData<1>((char*)0x004DAB4E, 0x19);

		SonicSSStartArray[11].Position.x = 757.7f;
		SonicSSStartArray[11].Position.y = 50.0f;
		SonicSSStartArray[11].Position.z = 1747.0f;
		SonicSSStartArray[11].YRot = 0x4000;

		TailsSSStartArray[6].Position.x = 757.7f;;
		TailsSSStartArray[6].Position.y = 50.0f;
		TailsSSStartArray[6].Position.z = 1747.0f;
		TailsSSStartArray[6].YRot = 0x4000;

		KnucklesSSStartArray[5].Position.x = 757.7f;;
		KnucklesSSStartArray[5].Position.y = 50.0f;
		KnucklesSSStartArray[5].Position.z = 1747.0f;
		KnucklesSSStartArray[5].YRot = 0x4000;

		AmySSStartArray[3].Position.x = 757.7f;;
		AmySSStartArray[3].Position.y = 50.0f;
		AmySSStartArray[3].Position.z = 1747.0f;
		AmySSStartArray[3].YRot = 0x4000;

		BigSSStartArray[4].Position.x = 757.7f;;
		BigSSStartArray[4].Position.y = 50.0f;
		BigSSStartArray[4].Position.z = 1747.0f;
		BigSSStartArray[4].YRot = 0x4000;

		E102SSStartArray[5].Position.x = 757.7f;;
		E102SSStartArray[5].Position.y = 50.0f;
		E102SSStartArray[5].Position.z = 1747.0f;
		E102SSStartArray[5].YRot = 0x4000;

		LastLevel = 26;
		LastAct = 5;

		GetCharacterID(0);
		SetLevelEntrance((unsigned int)(0x2300 >> 4) & 0xF);
		camerahax_adventurefields();
		sub_412D80(LevelIDs_TwinkleCircuit, 0);
	}
}

void QuitTwinkleCircuit(void)
{
	if (CurrentAct == 0) StartLevelCutscene(1);
	else
	{
		GetCharacterID(0);
		SetLevelEntrance((unsigned int)(0x2300 >> 4) & 0xF);
		sub_412D80(26, 3);
	}
}

static void SambaGate_Display(ObjectMaster *a1)
{
	EntityData1 *v1;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		njSetTexture(&texlist_sambagp);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		njRotateY(0, 0xFFFFC000);
		ProcessModelNode_AB_Wrapper(&object_00000EF8, 1.0f);
		njPopMatrix(1u);
	}
}

static void SambaGate_Main(ObjectMaster *a1)
{
	DataPointer(char, off_2BBF4A0, 0x02BBF450);
	NJS_VECTOR WarpPosition = { 698, 1.4f, 1600 };
	if (CurrentLevel == 26 && CurrentAct == 3)
	{
		if (HintTimer <= 0 && IsPlayerInsideSphere(&WarpPosition, 25))
		{
			HintTimer = 120;
			DisplayHintText(SambaGPMessage0, 180);
		}
		if (IsPlayerInsideSphere(&WarpPosition, 25))
		{
			CallSambaCircuit();
		}
		SambaGate_Display(a1);
	}
}

static void LoadSambaGate(ObjectMaster *a1)
{
	ObjectMaster *v1; // esi@1
	EntityData1 *v3; // edi@1
	NJS_OBJECT *v4; // eax@2
	v4 = DynamicCOL_AddFromEntity(&object_00000EF8, a1, (ColFlags)0x20001001);
	v4->scl[0] = 1.0f;
	v4->scl[1] = 1.0f;
	v4->scl[2] = 1.0f;
	a1->DeleteSub = DynamicCOL_DeleteObject;
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))SambaGate_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))SambaGate_Display;
}

static void SambaPoster_Display(ObjectMaster *a1)
{
	Angle v2;
	EntityData1 *v1;
	v1 = a1->Data1;
	if (!DroppedFrames)
	{
		njSetTexture(&texlist_sambagp);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
		v2 = v1->Rotation.y;
		njRotateY(0, v2);
		ProcessModelNode_AB_Wrapper(&poster1, v1->Scale.x);
		njPopMatrix(1u);
	}
}

static void SambaPoster_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
	v1 = a1->Data1;
	if (v1->CharID == CurrentAct)
	{
		if (IsPlayerInsideSphere(&v1->Position, 15))
		{
			if (HintTimer <= 0)
			{
				PlaySound(6, 0, 0, 0);
				switch (v1->CharIndex)
				{
				case 0:
					DisplayHintText(SambaGPMessage1, 180);
					break;
				case 1:
					DisplayHintText(SambaGPMessage2, 180);
					break;
				case 2:
					DisplayHintText(SambaGPMessage3, 180);
					break;
				default:
					break;
				}
				HintTimer = 120;
			}
		}
		SambaPoster_Display(a1);
	}
}

static void SambaPoster_Load(ObjectMaster *a1)
{
	a1->DeleteSub = DynamicCOL_DeleteObject;
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))SambaPoster_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))SambaPoster_Display;
}

void LoadSambaGateEntry(void)
{
	ObjectMaster *obj;
	EntityData1 *ent;
	ObjectFunc(OF1, LoadSambaGate); // Samba Gate
	ObjectFunc(OF2, SambaPoster_Load); // Samba Poster
	setdata_dlc.Distance = 612800.0f;
	if ((GameMode == GameModes_Adventure_Field || GameMode == GameModes_Mission) && ObjectsLoaded == false)
	{
		//Act 1
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 263;
			ent->Position.y = 21;
			ent->Position.z = 832;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 0;
		}
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 263;
			ent->Position.y = 21;
			ent->Position.z = 773;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 0;
		}
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 422;
			ent->Position.y = 26;
			ent->Position.z = 730;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xC000;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 0;
		}
		//Act 2
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 126;
			ent->Position.y = 163;
			ent->Position.z = 1077;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0xE16C;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -279;
			ent->Position.y = 163;
			ent->Position.z = 1285;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x438E;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 1;
		}
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -545;
			ent->Position.y = 48;
			ent->Position.z = 1226;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x4000;
			ent->Rotation.z = 0;
			ent->Scale.x = 2.0f;
			ent->Scale.y = 2.0f;
			ent->Scale.z = 2.0f;
			ent->CharIndex = 0;
			ent->CharID = 1;
		}
		//Act 4
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -175;
			ent->Position.y = 12;
			ent->Position.z = 1743;
			ent->Rotation.x = 0;
			ent->Rotation.y = 0x416C;
			ent->Rotation.z = 0;
			ent->Scale.x = 1.0f;
			ent->Scale.y = 1.0f;
			ent->Scale.z = 1.0f;
			ent->CharIndex = 0;
			ent->CharID = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF1);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 698;
			ent->Position.y = 0;
			ent->Position.z = 1600;
			ent->Rotation.y = 0xC000;
		}
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 109;
			ent->Position.y = 47;
			ent->Position.z = 1344;
			ent->Rotation.y = 0x127D;
			ent->Scale.x = 1.5f;
			ent->Scale.y = 1.5f;
			ent->Scale.z = 1.5f;
			ent->CharIndex = 0;
			ent->CharID = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = -54;
			ent->Position.y = 49;
			ent->Position.z = 1426;
			ent->Rotation.y = 0x127D;
			ent->Scale.x = 1.5f;
			ent->Scale.y = 1.5f;
			ent->Scale.z = 1.5f;
			ent->CharIndex = 0;
			ent->CharID = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 410;
			ent->Position.y = 23;
			ent->Position.z = 1233;
			ent->Rotation.y = 0x8B60;
			ent->Scale.x = 2.0f;
			ent->Scale.y = 2.0f;
			ent->Scale.z = 2.0f;
			ent->CharIndex = 0;
			ent->CharID = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 510;
			ent->Position.y = 17;
			ent->Position.z = 1657;
			ent->Rotation.y = 0x8000;
			ent->Scale.x = 2.0f;
			ent->Scale.y = 2.0f;
			ent->Scale.z = 2.0f;
			ent->CharIndex = 1;
			ent->CharID = 3;
		}
		obj = LoadObject((LoadObj)2, 3, OF2);
		obj->SETData.SETData = &setdata_dlc;
		if (obj)
		{
			ent = obj->Data1;
			ent->Position.x = 577;
			ent->Position.y = 17;
			ent->Position.z = 1657;
			ent->Rotation.y = 0x8000;
			ent->Scale.x = 2.0f;
			ent->Scale.y = 2.0f;
			ent->Scale.z = 2.0f;
			ent->CharIndex = 2;
			ent->CharID = 3;
		}
		ObjectsLoaded = true;
	}
}
