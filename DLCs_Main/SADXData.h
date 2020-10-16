#pragma once
#include "lanternapi.h"

struct DATEntry
{
	int NameOffset;
	int DataOffset;
	int DataLength;
};

struct SoundbankData
{
	int ArchiveID[4];
	char* Filename;
	void* DATFile;
	int NumSFX;
	DATEntry DATEntries;
};

DataPointer(NJS_ARGB, nj_constant_material_, 0x3D0F7F0);
DataPointer(NJS_MATRIX, nj_unit_matrix_, 0x389D650);
DataPointer(int, HintDuration, 0x3C58208);
DataPointer(int, MessageShown, 0x3C58258);
DataArray(SoundbankData*, SoundBankMemoryData, 0x3B291C8, 8);

FunctionPointer(SoundbankData*, LoadSoundBank, (LPCSTR lpString2, int a4), 0x4B4D10);
FunctionPointer(void, DisplayHintText_, (const char* strings, int duration), 0x4B79C0);
FunctionPointer(void, CreateSubtitleText, (int* a1), 0x4B7710);
FunctionPointer(void, CreateHintMessage, (void* a1, const char** a2, int a3), 0x4B7920);
FunctionPointer(void, DrawModelCallback_QueueSprite, (void(__cdecl* function)(NJS_SPRITE*), NJS_SPRITE* data, float depth, QueuedModelFlagsB queueflags), 0x404840);
FunctionPointer(void, ProcessModelNode_A, (NJS_OBJECT* a1), 0x4034B0);
FunctionPointer(void, ProcessModelNode_E, (NJS_OBJECT* a1, QueuedModelFlagsB a2, float a3), 0x40A1E0);
FunctionPointer(void, ProcessModelNode_F, (NJS_OBJECT *a1), 0x40A280);

extern material_register* material_register_ptr;
extern set_diffuse* set_diffuse_ptr;
extern bool DLLLoaded_Lantern;