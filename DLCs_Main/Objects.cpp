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
OBJ_CONDITION setdata_dlc;

struct DXCompatibilityThing
{
	char level;
	char act;
	NJS_VECTOR position_orig;
	NJS_VECTOR position_dx;
	unsigned __int16 yrot_dx;
};

DXCompatibilityThing DXAssets[] = {
	//Launch party
	{ 26, 0, { 205, 72, 1011 }, { 102, 79, 768 }, 0x4000 },
	{ 26, 0, { 77, 308, 270 }, { 77, 308, 340 }, 0 },
	{ 26, 0, { 458, 308, 263 }, { 458, 308, 333 }, 0 },
	//AT&T3
	{ 26, 3, { -5, 41, 1400 }, { -2.75f, 41, 1403.375f }, 0x127D },
	{ 26, 3, { 57, 41, 1369 }, { 59.25f, 41, 1372.375f }, 0x127D },
	//XMAS99
	{ 26, 3, { -23, 2, 1673 }, { -23, -1, 1673 }, 0 },
	{ 26, 0, { 265, 1, 668 }, { 265, -1, 712 }, 0 },
};

enum DLCObjectActions
{
	ACTION_NORMAL = 0x0,
	ACTION_DISAPPEAR = 0x1,
	ACTION_REAPPEAR = 0x2,
};

void DLCObject_Delete(task* a1)
{
	//PrintDebug("Deleting object\n");
	DLCObjectData* data;
	//Check if data is already deleted
	if (a1->awp != nullptr)
	{
		data = (DLCObjectData*)a1->awp->work.ptr[0];
		if (data != nullptr)
		{
			//Delete message
			if (data->flags & FLAG_MESSAGE)
			{
				//PrintDebug("Delete message\n");
				delete[] a1->awp->work.ptr[1];
				a1->awp->work.ptr[1] = NULL;
			}
			//Delete collision
			if (data->flags & FLAG_SOLID || data->flags & FLAG_COLLISION_ONLY) DynamicCOL_DeleteObject((ObjectMaster*)a1);
			a1->awp->work.ptr[0] = NULL;
		}
		_HeapFree(a1->awp);
		a1->awp = NULL;
	}
	CheckThingButThenDeleteObject((ObjectMaster*)a1);
}

void DLCObject_Action(task* a1)
{
	DLCObjectData* data;
	taskwk* v1;
	v1 = a1->twp;
	data = (DLCObjectData*)a1->awp->work.ptr[0];
	if (v1->wtimer > 0 || data->flags & FLAG_COLLISION_ONLY) return; //Don't continue if old action is still taking place or of the object is collision only
	if (data->flags & FLAG_COLLECTIBLE && !timer.enable) return;
	//PrintDebug("Action!\n");
	v1->wtimer = 60;
	if (data->flags & FLAG_COLLECTIBLE)
	{
		v1->mode = ACTION_DISAPPEAR;
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
				v1->mode = ACTION_DISAPPEAR;
				CreateHintMessage(CreateSubtitleText, (const char**)a1->awp->work.ptr[1], 120);
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
			CreateHintMessage(CreateSubtitleText, (const char**)a1->awp->work.ptr[1], 120);
		}
	}
	//CHALLENGE and TIMER are mutually exclusive
	if (data->flags & FLAG_CHALLENGE)
	{
		timer.time_target = (data->objectid * 10) / 60;
		timer.enable = true;
		timer.visible = true;
		data->collected = true;
		v1->mode = ACTION_DISAPPEAR;
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
			//Converted to ADX
			if (meta.adx)
			{
				StopMusic();
				InitializeSoundManager();
				PlayMusic((MusicIDs)(0x44 + data->sound)); //NIGTS_A, NIGHTS_S, NIGHTS_K
			}
			//Converted to DAT
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

void DLCObject_Display(task* a1)
{
	DLCObjectData* data;
	taskwk* v1;
	v1 = a1->twp;
	int texid_bk = 0;

	//Safety checks
	if (a1->awp == nullptr)
	{
		//PrintDebug("Display sub why?\n");
		return;
	}
	data = (DLCObjectData*)a1->awp->work.ptr[0];
	if (data == nullptr)
	{
		//PrintDebug("Display sub why?\n");
		return;
	}
	if (data->flags & FLAG_COLLECTIBLE && !timer.enable)
	{
		//PrintDebug("Collectible why?\n");
		return;
	}
	if (data->model == NULL || data->flags & FLAG_COLLISION_ONLY)
	{
		//PrintDebug("Collision why? %f\n", v1->pos.y);
		return;
	}
	if (!MissedFrames && v1->scl.x > 0.01f)
	{
		njControl3D_Backup();
		BackupConstantAttr();
		njSetTexture(&maintexlist);
		njPushMatrix(0);
		njTranslateV(0, &v1->pos);
		njRotateXYZ(0, v1->ang.x, v1->ang.y, v1->ang.z);
		njScale(0, v1->scl.x, v1->scl.y, v1->scl.z);
		if (data->objecttype == TYPE_SPRITE)
		{
			if (v1->mode == ACTION_DISAPPEAR || v1->mode == ACTION_REAPPEAR)
			{
				njControl3D_Add(NJD_CONTROL_3D_CONSTANT_MATERIAL | NJD_CONTROL_3D_CONSTANT_ATTR);
				AddConstantAttr(0, NJD_FLAG_USE_ALPHA);
				float alpha = (max(0, 255.0f - (float)v1->wtimer)) / 255.0f;
				SetMaterialAndSpriteColor_Float(alpha, 1.0f, 1.0f, 1.0f);
			}
			DrawQueueDepthBias = -47000.0f;
			ProcessModelNode(data->model, QueuedModelFlagsB_EnableZWrite, v1->scl.x);
		}
		else
		{
			switch (meta.rendermode)
			{
			case 1:
				ProcessModelNode_A(data->model);
				break;
			case 2:
				ProcessModelNode_B(data->model, v1->scl.x);
				break;
			case 3:
				ProcessModelNode_C(data->model, QueuedModelFlagsB_EnableZWrite, v1->scl.x);
				break;
			case 4:
				ProcessModelNode_D(data->model, QueuedModelFlagsB_EnableZWrite, v1->scl.x);
				break;
			case 5:
				ProcessModelNode_E(data->model, QueuedModelFlagsB_EnableZWrite, v1->scl.x);
				break;
			case 6:
				ProcessModelNode_F(data->model);
				break;
			default:
				ProcessModelNode_AB_Wrapper(data->model, v1->scl.x);
				break;
			}
		}
		DrawQueueDepthBias = 0.0f;
		njPopMatrix(1u);
		RestoreConstantAttr();
		njControl3D_Restore();
	}
}

void DLCObject_Main(task* a1)
{
	DLCObjectData* data;
	taskwk* v1;
	anywk* v2;
	v1 = a1->twp;
	v2 = a1->awp;

	//Failsafe stuff
	if (v2 == nullptr)
		return;
	data = (DLCObjectData*)a1->awp->work.ptr[0];
	if (data == nullptr)
		return;
	
	//Delete if found in wrong level
	if (data->level != CurrentLevel || data->act != CurrentAct)
	{
		a1->dest(a1);
		DeleteObjectMaster((ObjectMaster*)a1);
	}
	
	//Rotate
	v1->ang.x = v1->ang.x + data->rotspeed_x * 16 % 65535;
	v1->ang.y = v1->ang.y + data->rotspeed_y * 16 % 65535;
	v1->ang.z = v1->ang.z + data->rotspeed_z * 16 % 65535;
	
	//Trigger action
	if (!data->collected && IsPlayerInsideSphere(&v1->pos, data->radius)) DLCObject_Action(a1);
	else if (v1->wtimer > 0) v1->wtimer--;
	
	//Set to reappear if not collected
	if (data->flags & FLAG_TIMER)
	{
		if (timer.enable && v1->mode == ACTION_DISAPPEAR) v1->mode = ACTION_REAPPEAR;
	}
	if (data->flags & FLAG_COLLECTIBLE)
	{
		if (!data->collected && v1->mode == ACTION_DISAPPEAR) v1->mode = ACTION_REAPPEAR;
	}
	
	//Check if appearing or disappearing
	switch (v1->mode)
	{
	case ACTION_DISAPPEAR:
		if (v1->scl.x > 0.01f)
		{
			//PrintDebug("Disappear");
			v1->scl.x = v1->scl.x * 0.95f;
			v1->scl.y = v1->scl.y * 0.95f;
			v1->scl.z = v1->scl.z * 0.95f;
			if (v1->wtimer <= 255) v1->wtimer = min(255, v1->wtimer + 8);
		}
		break;
	case ACTION_REAPPEAR:
		if (v1->scl.x < 1.0f)
		{
			//PrintDebug("Reappear\n");
			v1->scl.x = v1->scl.x * 1.05f;
			v1->scl.y = v1->scl.y * 1.05f;
			v1->scl.z = v1->scl.z * 1.05f;
			if (v1->wtimer >= 0) v1->wtimer = max(0, v1->wtimer - 8);
		}
		else
		{
			v1->scl.x = 1.0f;
			v1->scl.y = 1.0f;
			v1->scl.z = 1.0f;
			v1->mode = ACTION_NORMAL;
			v1->wtimer = 0;
		}
		break;
	}
	
	//Display or hide
	if (!timer.enable)
	{
		if (data->flags & FLAG_TIMER || data->flags & FLAG_COLLECTIBLE)
		{
			//PrintDebug("Hide collectible\n");
			v1->mode = ACTION_DISAPPEAR;
			return;
		}
	}
	DLCObject_Display(a1);
}

void DLCObject_Load(ObjectMaster* ax)
{
	task* a1 = (task*)ax;
	NJS_OBJECT* collision;
	DLCObjectData* data;
	taskwk* v1;
	anywk* v2;
	v1 = a1->twp;
	data = (DLCObjectData*)a1->awp->work.ptr[0];

	//Load message
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
		a1->awp->work.ptr[1] = arr;
	}

	//Create collision
	if (data->flags & FLAG_SOLID)
	{
		//PrintDebug("Solid\n");
		collision = ObjectArray_GetFreeObject();
		v1->counter.ptr = collision;
		collision->model = data->model->model;
		collision->evalflags = 0x10;
		collision->ang[0] = v1->ang.x;
		collision->ang[1] = v1->ang.y;
		collision->ang[2] = v1->ang.z;
		collision->scl[0] = 1.0f;
		collision->scl[1] = 1.0f;
		collision->scl[2] = 1.0f;
		collision->pos[0] = v1->pos.x;
		collision->pos[1] = v1->pos.y;
		collision->pos[2] = v1->pos.z;
		DynamicCOL_Add((ColFlags)0x20000001, (ObjectMaster*)a1, collision);
	}
	else collision = nullptr;

	//Create timer
	if (data->flags & FLAG_TIMER)
	{
		timer.Initialize();
		timer.target_total = data->objectid;
	}
	
	//Set action
	if (data->collected)
	{
		v1->mode = ACTION_DISAPPEAR;
		v1->scl.x = 0.01f;
		v1->scl.y = 0.01f;
		v1->scl.z = 0.01f;
	}
	else if (v1->mode == ACTION_DISAPPEAR) v1->mode = ACTION_REAPPEAR;

	//Set subs
	a1->exec = (void(__cdecl*)(task*))DLCObject_Main;
	a1->disp = (void(__cdecl*)(task*))DLCObject_Display;
	a1->dest = (void(__cdecl*)(task*))DLCObject_Delete;
}

void LoadDLCObject(DLCObjectData* data)
{
	task* obj;
	taskwk* ent;
	anywk* awk;

	obj = (task*)LoadObject(LoadObj_Data1, 3, DLCObject_Load);
	obj->awp = (anywk*)_HeapAlloc(1, 48);
	setdata_dlc.unionStatus.fRangeOut = 612800.0f;
	obj->ocp = &setdata_dlc;
	if (obj)
	{
		awk = obj->awp;
		awk->work.ptr[0] = data;
		ent = (taskwk*)obj->twp;
		ent->pos.x = data->x;
		ent->pos.y = data->y;
		ent->pos.z = data->z;
		ent->ang.x = data->rot_x;
		ent->ang.y = data->rot_y;
		ent->ang.z = data->rot_z;
		ent->scl.x = data->scale_x;
		ent->scl.y = data->scale_y;
		ent->scl.z = data->scale_z;
		
		//DX stuff
		if (meta.dxmode)
		{
			for (int i = 0; i < LengthOfArray(DXAssets); i++)
			{
				if (data->level == DXAssets[i].level && data->act == DXAssets[i].act)
				{
					if (data->x == DXAssets[i].position_orig.x && data->y == DXAssets[i].position_orig.y && data->z == DXAssets[i].position_orig.z)
					{
						ent->pos.x = DXAssets[i].position_dx.x;
						ent->pos.y = DXAssets[i].position_dx.y;
						ent->pos.z = DXAssets[i].position_dx.z;
						ent->ang.y = DXAssets[i].yrot_dx;
					}
				}
			}
		}
	}
}
