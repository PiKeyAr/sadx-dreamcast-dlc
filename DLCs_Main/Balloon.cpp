#include <stdafx.h>
#include "Balloon.h"

#pragma warning(push)
#pragma warning(disable: 4838)

NJS_TEXNAME textures_famitsu[3];
NJS_TEXLIST texlist_famitsu = { arrayptrandlength(textures_famitsu) };

NJS_TEXNAME textures_quo[3];
NJS_TEXLIST texlist_quo = { arrayptrandlength(textures_quo) };

NJS_MATERIAL matlist_balloon[] = {
	{ { 0xFFB2B2B2 },{ 0xFFFFFFFF }, 11, 0, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC }
};

NJS_MATERIAL matlist_balloon_2[] = {
	{ { 0xFFB2B2B2 },{ 0xFFFFFFFF }, 11, 1, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_000000AC[] = {
	4, 8, 4, 7, 3,
	4, 16, 12, 15, 11,
	4, 24, 20, 23, 19
};

Sint16 poly_0000001C[] = {
	9, 2, 0, 6, 10, 7, 11, 8, 12, 9,
	4, 2, 6, 3, 7,
	4, 9, 5, 8, 4,
	4, 11, 10, 14, 0,
	0x8000u | 18, 16, 12, 13, 9, 1, 5, 25, 4, 24, 3, 23, 2, 22, 0, 18, 14, 15, 11,
	0x8000u | 7, 16, 13, 17, 1, 21, 25, 24,
	0x8000u | 5, 19, 16, 20, 17, 21,
	0x8000u | 5, 22, 18, 19, 15, 16,
	3, 22, 23, 19,
	3, 20, 24, 21
};

NJS_TEX uv_000001C4_F[] = {
	{ 254, 0 },
{ 0 },
{ 254, 255 },
{ 0, 255 },
{ 254, 0 },
{ 0 },
{ 254, 255 },
{ 0, 255 },
{ 254, 0 },
{ 0 },
{ 254, 255 },
{ 0, 255 }
};

NJS_TEX uv_000000CC[] = {
	{ 206, 127 },
{ 127, 127 },
{ 166, 206 },
{ 88, 206 },
{ 191, 255 },
{ 63, 255 },
{ 191, 255 },
{ 63, 255 },
{ 166, 206 },
{ 206, 127 },
{ 166, 206 },
{ 255, 127 },
{ 191, 255 },
{ 166, 206 },
{ 206, 127 },
{ 191, 255 },
{ 255, 127 },
{ 63, 255 },
{ 88, 206 },
{ 48, 127 },
{ 127, 127 },
{ 0, 127 },
{ 63, 255 },
{ 88, 206 },
{ 166, 206 },
{ 127, 127 },
{ 206, 127 },
{ 166, 48 },
{ 255, 127 },
{ 191, 0 },
{ 255, 127 },
{ 191, 0 },
{ 206, 127 },
{ 166, 48 },
{ 127, 127 },
{ 88, 48 },
{ 48, 127 },
{ 0, 127 },
{ 63, 255 },
{ 0, 127 },
{ 88, 206 },
{ 48, 127 },
{ 127, 127 },
{ 88, 48 },
{ 166, 48 },
{ 191, 0 },
{ 63, 0 },
{ 0, 127 },
{ 63, 0 },
{ 48, 127 },
{ 88, 48 },
{ 166, 48 },
{ 88, 48 },
{ 63, 0 },
{ 0, 127 },
{ 0, 127 },
{ 166, 48 },
{ 191, 0 },
{ 63, 0 },
{ 63, 0 },
{ 191, 0 },
{ 88, 48 }
};

NJS_MESHSET_SADX meshlist_000001F4[] = {
	{ NJD_MESHSET_TRIMESH | 0, 3, poly_000000AC, NULL, NULL, NULL, uv_000001C4_F, NULL },
{ NJD_MESHSET_TRIMESH | 0, 10, poly_0000001C, NULL, NULL, NULL, uv_000000CC, NULL }
};

NJS_VECTOR vertex_00000224[] = {
	{ 0, -9.480008f, 0 },
{ 0, 9.480008f, 0 },
{ 5.877852f, -8.09017f, 0 },
{ 9.510565f, -4.18588f, 0 },
{ 9.510565f, 4.185881f, 0 },
{ 5.877852f, 8.09017f, 0 },
{ 2.938926f, -8.09017f, -5.09037f },
{ 4.755282f, -4.18588f, -8.23639f },
{ 4.755282f, 4.185881f, -8.23639f },
{ 2.938926f, 8.09017f, -5.090369f },
{ -2.938927f, -8.09017f, -5.090369f },
{ -4.755283f, -4.18588f, -8.236389f },
{ -4.755283f, 4.185881f, -8.236389f },
{ -2.938926f, 8.09017f, -5.090369f },
{ -5.877852f, -8.09017f, 0.000001f },
{ -9.510565f, -4.18588f, 0.000002f },
{ -9.510565f, 4.185881f, 0.000002f },
{ -5.877852f, 8.09017f, 0.000001f },
{ -2.938925f, -8.09017f, 5.09037f },
{ -4.755281f, -4.18588f, 8.236391f },
{ -4.755281f, 4.185881f, 8.236391f },
{ -2.938925f, 8.09017f, 5.09037f },
{ 2.938928f, -8.09017f, 5.090369f },
{ 4.755285f, -4.18588f, 8.236389f },
{ 4.755285f, 4.185881f, 8.236389f },
{ 2.938927f, 8.09017f, 5.090369f }
};

NJS_VECTOR normal_0000035C[] = {
	{ 0, -1, 0 },
{ 0, 1, 0 },
{ 0.56747f, -0.8233939f, 0 },
{ 0.9434969f, -0.331381f, 0 },
{ 0.9434969f, 0.331381f, 0 },
{ 0.56747f, 0.8233939f, 0 },
{ 0.283735f, -0.8233939f, -0.491443f },
{ 0.471749f, -0.331381f, -0.817093f },
{ 0.471749f, 0.331381f, -0.817093f },
{ 0.283735f, 0.8233939f, -0.491443f },
{ -0.283735f, -0.8233939f, -0.491443f },
{ -0.471749f, -0.331381f, -0.8170919f },
{ -0.471749f, 0.331381f, -0.8170919f },
{ -0.283735f, 0.8233939f, -0.491443f },
{ -0.56747f, -0.8233939f, 0 },
{ -0.9434969f, -0.331381f, 0 },
{ -0.9434969f, 0.331381f, 0 },
{ -0.56747f, 0.8233939f, 0 },
{ -0.283735f, -0.8233939f, 0.491443f },
{ -0.471749f, -0.331381f, 0.817093f },
{ -0.471749f, 0.331381f, 0.817093f },
{ -0.283735f, 0.8233939f, 0.491443f },
{ 0.283735f, -0.8233939f, 0.491443f },
{ 0.471749f, -0.331381f, 0.8170919f },
{ 0.471749f, 0.331381f, 0.8170919f },
{ 0.283735f, 0.8233939f, 0.491443f }
};

NJS_MODEL_SADX attach_00000494 = { vertex_00000224, normal_0000035C, LengthOfArray<Sint32>(vertex_00000224), meshlist_000001F4, matlist_balloon, LengthOfArray<Uint16>(meshlist_000001F4), LengthOfArray<Uint16>(matlist_balloon),{ 0 }, 12.58129f, NULL };

NJS_MODEL_SADX attach_00000494_2 = { vertex_00000224, normal_0000035C, LengthOfArray<Sint32>(vertex_00000224), meshlist_000001F4, matlist_balloon_2, LengthOfArray<Uint16>(meshlist_000001F4), LengthOfArray<Uint16>(matlist_balloon_2),{ 0 }, 12.58129f, NULL };

NJS_OBJECT balloon_start = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_00000494, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };

NJS_OBJECT balloon_finish = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_00000494_2, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };

#pragma warning(pop)
