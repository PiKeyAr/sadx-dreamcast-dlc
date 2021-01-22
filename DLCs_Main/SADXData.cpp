#include <stdafx.h>
#include <SADXModLoader.h>
#include "SADXData.h"

void njDrawSprite2D_DrawNow_Point(NJS_SPRITE* sp, Int n, Float pri, NJD_SPRITE attr)
{
	NJS_TEXLIST* texlist; // ecx
	NJS_TEXANIM* texanim; // esi
	double _cx; // st7
	double cy; // st6
	float sy; // ST14_4
	float v9; // ST2C_4
	double v10; // st7
	float v11; // ST30_4
	double v12; // st7
	double v13; // st7
	float v14; // eax
	float v15; // ecx
	NJS_COLOR v16; // edi
	NJS_COLOR color_; // ST20_4
	int texid; // esi
	float result_x; // [esp+4h] [ebp-74h]
	float v20; // [esp+8h] [ebp-70h]
	float result_y; // [esp+Ch] [ebp-6Ch]
	float u1; // [esp+10h] [ebp-68h]
	float v1; // [esp+14h] [ebp-64h]
	float u2; // [esp+18h] [ebp-60h]
	float v2; // [esp+1Ch] [ebp-5Ch]
	float v26; // [esp+28h] [ebp-50h]
	NJS_VECTOR vs; // [esp+2Ch] [ebp-4Ch]
	NJS_QUAD_TEXTURE_EX points; // [esp+38h] [ebp-40h]

	if (sp)
	{
		texlist = sp->tlist;
		if (texlist)
		{
			Direct3D_SetTexList(texlist);
			texanim = &sp->tanim[n];
			u1 = (double)texanim->u1 * 0.0039215689f;
			v1 = (double)texanim->v1 * 0.0039215689f;
			u2 = (double)texanim->u2 * 0.0039215689f;
			v2 = (double)texanim->v2 * 0.0039215689f;
			_cx = (double)-texanim->cx;
			cy = (double)-texanim->cy;
			sy = (double)texanim->sy + cy;
			result_x = _cx * sp->sx;
			v26 = ((double)texanim->sx + _cx) * sp->sx;
			result_y = cy * sp->sy;
			v20 = sy * sp->sy;
			if (attr & NJD_SPRITE_ANGLE)
			{
				njPushMatrix(nj_unit_matrix_);
				njRotateZ(0, sp->ang);
				vs.x = result_x;
				vs.y = result_y;
				vs.z = 0.0;
				njCalcVector(0, &vs, &vs);
				points.x = vs.x + sp->p.x;
				v9 = vs.x;
				v10 = vs.y + sp->p.y;
				v11 = vs.y;
				vs.y = result_y;
				points.y = v10;
				vs.x = v26;
				vs.z = 0.0;
				points.z = -1.0 / pri;
				njCalcVector(0, &vs, &vs);
				points.vx1 = vs.x - v9;
				vs.x = result_x;
				v12 = vs.y;
				vs.y = v20;
				vs.z = 0.0;
				points.vy1 = v12 - v11;
				njCalcVector(0, &vs, &vs);
				points.vx2 = vs.x - v9;
				points.vy2 = vs.y - v11;
				njPopMatrixEx();
			}
			else
			{
				points.vy1 = 0.0;
				v13 = result_x + sp->p.x;
				points.vx2 = 0.0;
				points.x = v13;
				points.y = result_y + sp->p.y;
				points.z = -1.0 / pri;
				points.vx1 = v26 - result_x;
				points.vy2 = v20 - result_y;
			}
			if (attr & NJD_SPRITE_HFLIP)
			{
				v14 = u2;
				u2 = u1;
				u1 = v14;
			}
			if (attr & NJD_SPRITE_VFLIP)
			{
				v15 = v2;
				v2 = v1;
				v1 = v15;
			}
			points.u = u1;
			points.vu1 = u2 - u1;
			points.v = v1;
			points.vv1 = 0.0;
			points.vu2 = 0.0;
			points.vv2 = v2 - v1;
			if (attr & NJD_SPRITE_COLOR)
			{
				color_.argb.b = (unsigned __int64)(nj_constant_material_.b * 255.0);
				color_.argb.g = (unsigned __int64)(nj_constant_material_.g * 255.0);
				color_.argb.r = (unsigned __int64)(nj_constant_material_.r * 255.0);
				color_.argb.a = (unsigned __int64)(nj_constant_material_.a * 255.0);
				v16.color = color_.color;
			}
			else
			{
				v16.color = -1;
			}
			Direct3D_EnableHudAlpha((attr & NJD_SPRITE_ALPHA) == NJD_SPRITE_ALPHA);
			Direct3D_TextureFilterPoint();
			texid = texanim->texid;
			CurrentHUDColor = v16.color;
			Direct3D_SetTextureNum(texid);
			Direct3D_DrawQuad(&points);
			Direct3D_TextureFilterLinear();
		}
	}
}

void DrawCenteredDebugRectangle(float leftchar, float topchar, float rightchar, float bottomchar, Uint32 color)
{
	float XDelta = (float)HorizontalResolution / 640.0f - ((int)HorizontalResolution / 640);
	float FontScale = (float)VerticalResolution / 480.0f;
	float FontScaleHZ = (float)HorizontalResolution / 640.0f;
	float RightColumn = (float)HorizontalResolution / (16.0f * FontScale);
	float BottomLine = (float)VerticalResolution / (16.0f * FontScale);
	float HorizontalCenter = RightColumn / 2;
	//PrintDebug("XD: %f\n", XDelta);
	int VerticalCenter = BottomLine / 2;
	int pos_x = HorizontalCenter - (rightchar - leftchar) / 2;
	int pos_y = VerticalCenter;
	njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
	njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
	DrawRect_Queue(leftchar * FontScaleHZ * 16.0f, topchar * FontScale * 16.0f, rightchar * FontScaleHZ * 16.0f, bottomchar * FontScale * 16.0f, 62041.496f, color, QueuedModelFlagsB_EnableZWrite);
	njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
	njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
}

void DisplayCenteredDebugString(std::string str, int hzoffset = 0, int yoffset = -1)
{
	float FontScale = (float)VerticalResolution / 480.0f;
	float RightColumn = (float)HorizontalResolution / (16.0f * FontScale);
	float BottomLine = (float)VerticalResolution / (16.0f * FontScale);
	float HorizontalCenter = RightColumn / 2;
	//PrintDebug("Sc: %f, Total ch: %f, HZC: %f\n", FontScale, RightColumn, HorizontalCenter);
	float VerticalCenter = BottomLine / 2;
	int pos_x = HorizontalCenter - (str.length() / 2) + hzoffset;
	int pos_y = VerticalCenter;
	if (yoffset != -1) pos_y = yoffset;
	DisplayDebugString(NJM_LOCATION(pos_x, pos_y), str.c_str());
}