#include <stdafx.h>
#include "Posters.h"

#pragma warning(push)
#pragma warning(disable: 4267 4838)

//Poster

NJS_MATERIAL matlist_00116FA0X[] = {
	{ { 0xFFB2B2B2 },{ 0xFFFFFFFF }, 11, 2, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_00116FB4X[] = {
	4, 3, 2, 1, 0
};

NJS_TEX uv_00116FC0X[] = {
	{ 0, 255 },
{ 255, 255 },
{ 0 },
{ 255, 0 }
};

NJS_MESHSET_SADX meshlist_00116FD0X[] = {
	{ NJD_MESHSET_TRIMESH | 0, 1, poly_00116FB4X, NULL, NULL, NULL, uv_00116FC0X, NULL }
};

NJS_VECTOR vertex_00116FE8X[] = {
	{ -10.0f, 10.0f, 0 },
{ 10.0f, 10.0f, 0 },
{ -10.0f, -10.0f, 0 },
{ 10.0f, -10.0f, 0 }
};

NJS_VECTOR normal_00117018X[] = {
	{ 1, 0, 0 },
{ 1, 0, 0 },
{ 1, 0, 0 },
{ 1, 0, 0 }
};

NJS_MODEL_SADX attach_00117048X = { vertex_00116FE8X, normal_00117018X, LengthOfArray(vertex_00116FE8X), meshlist_00116FD0X, matlist_00116FA0X, LengthOfArray(meshlist_00116FD0X), LengthOfArray(matlist_00116FA0X),{ 0, 1.5f, 0 }, 11.71537f, NULL };

NJS_OBJECT poster = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_00117048X, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };

#pragma warning(pop)
