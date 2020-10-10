#include <stdafx.h>
#include <SADXModLoader.h>
#include "lanternapi.h"

material_register* material_register_ptr;
set_diffuse* set_diffuse_ptr;
bool DLLLoaded_Lantern;

NJS_MATERIAL* TemporaryMaterialArray[] = {nullptr};

bool ForceWhiteDiffuse(NJS_MATERIAL* material, uint32_t flags)
{
	int diffuseindex = 3;
	if (CurrentLevel == LevelIDs_SpeedHighway || CurrentLevel == LevelIDs_RedMountain || (CurrentLevel == LevelIDs_IceCap && CurrentAct < 1) || CurrentLevel == LevelIDs_Casinopolis || (CurrentLevel == LevelIDs_FinalEgg && CurrentAct == 2) || CurrentLevel == LevelIDs_HotShelter || CurrentLevel == LevelIDs_EggViper || (CurrentLevel == LevelIDs_EggCarrierInside && CurrentAct == 1)) diffuseindex = 1;
	if ((CurrentLevel == LevelIDs_IceCap && CurrentAct >= 1) || (CurrentLevel == LevelIDs_FinalEgg && CurrentAct == 0)) diffuseindex = 5;
	if (CurrentLevel == LevelIDs_FinalEgg && CurrentAct == 1) diffuseindex = 1;
	set_diffuse_ptr(diffuseindex, false);
	return true;
}

void AddWhiteDiffuseMaterial(NJS_MATERIAL* material)
{
	if (!DLLLoaded_Lantern) return;
	TemporaryMaterialArray[0] = material;
	material_register_ptr(TemporaryMaterialArray, 1, ForceWhiteDiffuse);
}