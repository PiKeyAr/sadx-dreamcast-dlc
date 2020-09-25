#include <stdafx.h>
#include <SADXModLoader.h>
#include "Metadata.h"
#include "ChallengeTimer.h"
#include "SADXData.h"
#include <fstream>
#include <assert.h>
#include <list> 
#include <iterator> 
using namespace std;

list <int> ::iterator it;

ChallengeTimer timer;
SETObjData setdata_dlc;

enum DLCObjectActions
{
	ACTION_NORMAL = 0x0,
	ACTION_DISAPPEAR = 0x1,
	ACTION_REAPPEAR = 0x2,
};

void DLCObject_Delete(ObjectMaster* a1)
{
	//PrintDebug("Deleting object\n");
	DLCObjectData* data;
	EntityData1* v1;
	v1 = a1->Data1;
	data = (DLCObjectData*)a1->UnknownB_ptr;
	if (data == nullptr)
	{
		//PrintDebug("Delete sub why?");
		return;
	}
	//Delete message
	if (data->flags & FLAG_MESSAGE)
	{
		const char** arr = (const char**)v1->LoopData;
		delete[] arr;
		arr = NULL;
	}
	
	//Delete collision
	a1->UnknownB_ptr = NULL;
	if (data->flags & FLAG_SOLID || data->flags & FLAG_COLLISION_ONLY) DynamicCOL_DeleteObject(a1);
	else CheckThingButThenDeleteObject(a1);
}

void DLCObject_Action(ObjectMaster* a1)
{
	DLCObjectData* data;
	EntityData1* v1;
	v1 = a1->Data1;
	data = (DLCObjectData*)a1->UnknownB_ptr;
	if (v1->InvulnerableTime > 0 || data->flags & FLAG_COLLISION_ONLY) return; //Don't continue if old action is still taking place or of the object is collision only
	if (data->flags & FLAG_COLLECTIBLE && !timer.enable) return;
	//PrintDebug("Action!\n");
	v1->InvulnerableTime = 60;
	if (data->flags & FLAG_COLLECTIBLE)
	{
		v1->Action = ACTION_DISAPPEAR;
		data->collected = true;
		timer.target_current++;
	}
	if (data->flags & FLAG_MESSAGE)
	{
		//Found all
		if (data->flags & FLAG_COLLECTIBLE && timer.target_current >= timer.target_total)
		{
			HintDuration = 120;
			CreateHintMessage(CreateSubtitleText, timer.message_foundall, 120);
		}
		else if (data->flags & FLAG_TIMER)
		{
			//Found all
			if (timer.enable && timer.target_current >= timer.target_total)
			{
				HintDuration = 120;
				CreateHintMessage(CreateSubtitleText, timer.message_clear, 120);
				timer.enable = false;
				data->collected = true;
				v1->Action = ACTION_DISAPPEAR;
				CreateHintMessage(CreateSubtitleText, (const char**)v1->LoopData, 120);
			}
			//Time over
			else if (timer.time_current > timer.time_target * 3600)
			{
				HintDuration = 120;
				CreateHintMessage(CreateSubtitleText, timer.message_timeup, 120);
				timer.enable = false;
			}
		}
		else
		{
			HintDuration = 120;
			CreateHintMessage(CreateSubtitleText, (const char**)v1->LoopData, 120);
		}
	}
	//CHALLENGE and TIMER are mutually exclusive
	if (data->flags & FLAG_CHALLENGE)
	{
		timer.time_target = (data->objectid * 10) / 60;
		timer.enable = true;
		timer.visible = true;
		data->collected = true;
		v1->Action = ACTION_DISAPPEAR;
	}
	//WARP and SOUND are mutually exclusive
	if (data->flags & FLAG_WARP)
	{
		NextLevel = data->warplevel;
		NextAct = data->sound;
		CutsceneMode = 3;
	}
	else if (data->flags & FLAG_SOUND)
	{
		if (data->flags & FLAG_TIMER && timer.target_current < timer.target_total) return;
		switch (data->warplevel)
		{
		//Play ADX BGM
		case 15:
			StopMusic();
			InitializeSoundManager();
			PlayMusic((MusicIDs)data->sound);
			break;
		//Play MLT
		case 8:
			if (meta.adx)
			{
				StopMusic();
				InitializeSoundManager();
				PlayMusic((MusicIDs)(0x44 + data->sound)); //NIGTS_A, NIGHTS_S, NIGHTS_K
			}
		//Play MLT (DAT)
			else
			{
				PlaySound(0x567, 0, 0, 0); //SE_DL_DOWNLOAD
			}
			break;
		//0x000 - 0 (COMMON)
		case 0:
			PlaySound(data->sound, 0, 0, 0);
			break;
		//0x101 - 1 (CHAO_EFX)
		case 1:
			PlaySound(0x101 + data->sound + 1, 0, 0, 0);
			break;
		//0x2E1 - 2 (CHECK_SHEET)
		case 2:
			PlaySound(0x2E1 + data->sound + 1, 0, 0, 0);
			break;
		//0x31B - 3 (P_AMY)
		case 3:
			PlaySound(0x31B + data->sound + 1, 0, 0, 0);
			break;
		//0x175 - 4 (CHAOVOICE)
		case 4:
			PlaySound(0x175 + data->sound + 1, 0, 0, 0);
			break;
		//0x45B - 5 (CHAOVOICE)
		case 5:
			PlaySound(0x45B + data->sound + 1, 0, 0, 0);
			break;
		//0x4C5 - 6 (V_SONICTAILS)
		case 6:
			PlaySound(0x4C5 + data->sound + 1, 0, 0, 0);
			break;
		//0x55D - 7 (Chao music thing)
		case 7:
			PlaySound(0x55D + data->sound + 1, 0, 0, 0);
			break;
		}
	}
}

void DLCObject_Display(ObjectMaster* a1)
{
	DLCObjectData* data;
	EntityData1* v1;
	v1 = a1->Data1;
	data = (DLCObjectData*)a1->UnknownB_ptr;
	int texid_bk = 0;
	if (data == nullptr)
	{
		//PrintDebug("Display sub why?\n");
		return;
	}
	if (data->flags & FLAG_COLLECTIBLE && !timer.enable) return;
	if (data->model == NULL || data->flags & FLAG_COLLISION_ONLY) return;
	if (!MissedFrames && v1->Scale.x > 0.01f)
	{
		njControl3D_Backup();
		BackupConstantAttr();
		njControl3D_Add(NJD_CONTROL_3D_CONSTANT_MATERIAL | NJD_CONTROL_3D_CONSTANT_ATTR);
		if (v1->Action == ACTION_DISAPPEAR || v1->Action == ACTION_REAPPEAR)
		{
			AddConstantAttr(0, NJD_FLAG_USE_ALPHA);
			SetMaterialAndSpriteColor_Float(max(v1->Scale.x, 0), 1.0f, 1.0f, 1.0f);
		}
		else
			SetMaterialAndSpriteColor_Float(1.0f, 1.0f, 1.0f, 1.0f);
		njSetTexture(&maintexlist);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		njRotateXYZ(0, v1->Rotation.x, v1->Rotation.y, v1->Rotation.z);
		njScale(0, v1->Scale.x, v1->Scale.y, v1->Scale.z);
		if (data->objecttype == TYPE_SPRITE) DrawQueueDepthBias = -47000.0f;
		ProcessModelNode(data->model, QueuedModelFlagsB_EnableZWrite, 1.0f);
		DrawQueueDepthBias = 0.0f;
		njPopMatrix(1u);
		RestoreConstantAttr();
		njControl3D_Restore();
	}
}

void DLCObject_Main(ObjectMaster* a1)
{
	DLCObjectData* data;
	EntityData1* v1;
	v1 = a1->Data1;
	data = (DLCObjectData*)a1->UnknownB_ptr;
	if (data == nullptr)
	{
		return;
	}
	//Delete if found in wrong level
	if (data->level != CurrentLevel || data->act != CurrentAct)
	{
		a1->DeleteSub(a1);
		DeleteObjectMaster(a1);
	}
	//Rotate
	v1->Rotation.x = v1->Rotation.x + data->rotspeed_x * 16 % 65535;
	v1->Rotation.y = v1->Rotation.y + data->rotspeed_y * 16 % 65535;
	v1->Rotation.z = v1->Rotation.z + data->rotspeed_z * 16 % 65535;
	//Trigger action
	if (!data->collected && IsPlayerInsideSphere(&v1->Position, data->radius)) DLCObject_Action(a1);
	else if (v1->InvulnerableTime > 0) v1->InvulnerableTime--;
	//Set to reappear if not collected
	if (!data->collected && v1->Action == ACTION_DISAPPEAR) v1->Action = ACTION_REAPPEAR;
	//Check if appearing or disappearing
	switch (v1->Action)
	{
	case ACTION_DISAPPEAR:
		if (v1->Scale.x > 0.01f)
		{
			v1->Scale.x = v1->Scale.x * 0.95f;
			v1->Scale.y = v1->Scale.y * 0.95f;
			v1->Scale.z = v1->Scale.z * 0.95f;
		}
		break;
	case ACTION_REAPPEAR:
		if (v1->Scale.x < 1.0f)
		{
			v1->Scale.x = v1->Scale.x * 1.05f;
			v1->Scale.y = v1->Scale.y * 1.05f;
			v1->Scale.z = v1->Scale.z * 1.05f;
		}
		if (v1->Scale.x >= 1.0f)
		{
			v1->Scale.x = 1.0f;
			v1->Scale.y = 1.0f;
			v1->Scale.z = 1.0f;
			v1->Action = ACTION_NORMAL;
		}
		break;
	}
	//Display
	if (data->flags & FLAG_COLLECTIBLE && !timer.enable) return;
	DLCObject_Display(a1);
}

void DLCObject_Load(ObjectMaster* a1)
{
	NJS_OBJECT* collision;
	DLCObjectData* data;
	EntityData1* v1;
	v1 = a1->Data1;
	data = (DLCObjectData*)a1->UnknownB_ptr;
	if (data->flags & FLAG_MESSAGE)
	{
		const char** arr = new const char* [2];
		switch (TextLanguage)
		{
		case 0:
			arr[0] = meta.JapaneseStrings[data->message].c_str();
			break;
		case 2:
			arr[0] = meta.FrenchStrings[data->message].c_str();
			break;
		case 3:
			arr[0] = meta.SpanishStrings[data->message].c_str();
			break;
		case 4:
			arr[0] = meta.GermanStrings[data->message].c_str();
			break;
		case 1:
		default:
			arr[0] = meta.EnglishStrings[data->message].c_str();
			break;
		}
		arr[1] = NULL;
		v1->LoopData = (Loop*)arr;
	}
	//Create collision
	if (data->flags & FLAG_SOLID)
	{
		//PrintDebug("Solid\n");
		collision = ObjectArray_GetFreeObject();
		*(NJS_OBJECT**)&v1->CharIndex = collision;
		collision->model = data->model->model;
		collision->evalflags = 0x10;
		collision->ang[0] = v1->Rotation.x;
		collision->ang[1] = v1->Rotation.y;
		collision->ang[2] = v1->Rotation.z;
		collision->scl[0] = 1.0f;
		collision->scl[1] = 1.0f;
		collision->scl[2] = 1.0f;
		collision->pos[0] = v1->Position.x;
		collision->pos[1] = v1->Position.y;
		collision->pos[2] = v1->Position.z;
		DynamicCOL_Add((ColFlags)0x20000001, a1, collision);
	}
	else collision = nullptr;
	//Create timer
	if (data->flags & FLAG_TIMER)
	{
		timer.Initialize();
		timer.target_total = data->objectid;
	}
	a1->MainSub = (void(__cdecl*)(ObjectMaster*))DLCObject_Main;
	a1->DisplaySub = (void(__cdecl*)(ObjectMaster*))DLCObject_Display;
	a1->DeleteSub = (void(__cdecl*)(ObjectMaster*))DLCObject_Delete;
	//Set action
	if (data->collected)
	{
		v1->Action = ACTION_DISAPPEAR;
		v1->Scale.x = 0.01f;
		v1->Scale.y = 0.01f;
		v1->Scale.z = 0.01f;
	}
	else if (v1->Action == ACTION_DISAPPEAR) v1->Action = ACTION_REAPPEAR;
}

void LoadDLCObject(DLCObjectData* data)
{
	ObjectMaster* obj;
	EntityData1* ent;

	obj = LoadObject((LoadObj)2, 3, DLCObject_Load);
	setdata_dlc.Distance = 612800.0f;
	obj->SETData.SETData = &setdata_dlc;
	if (obj)
	{
		obj->UnknownB_ptr = data;
		ent = obj->Data1;
		ent->Position.x = data->x;
		ent->Position.y = data->y;
		ent->Position.z = data->z;
		ent->Rotation.x = data->rot_x;
		ent->Rotation.y = data->rot_y;
		ent->Rotation.z = data->rot_z;
		ent->Scale.x = data->scale_x;
		ent->Scale.y = data->scale_y;
		ent->Scale.z = data->scale_z;
	}
}
