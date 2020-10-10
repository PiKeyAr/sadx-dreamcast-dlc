#include <stdafx.h>
#include <SADXModLoader.h>
#include "SADXData.h"

NJS_COLOR DebugFontColorBK;
float DebugFontSizeBK;
bool DebugFontItalic = false;

enum DebugFontFlags //Stored in the alpha value
{
	FONT_ITALIC = 0x1,
	FONT_TRANSPARENTMSG = 0x2, //Make transparent when overlapped by a hint message
};

void BackupDebugFontSettings()
{
	DebugFontColorBK = DebugFontColor;
	DebugFontSizeBK = DebugFontSize;
}

void RestoreDebugFontSettings()
{
	DebugFontColor = DebugFontColorBK;
	DebugFontSize = DebugFontSizeBK;
}

void njDrawQuadTexture_Italic(NJS_QUAD_TEXTURE* points, float scale)
{
	double widthmaybe; // st7
	Float base_x; // ecx
	Float v4; // edx
	double v5; // st7
	Float v6; // ecx
	double v7; // st7
	double v8; // st7
	NJS_QUAD_TEXTURE_EX _points; // [esp+0h] [ebp-40h]

	widthmaybe = points->x2 - points->x1;
	base_x = points->x1;
	_points.y = points->y1;
	v4 = points->u1;
	_points.vx1 = widthmaybe + DebugFontItalic * 4.0f; //width
	_points.x = base_x + DebugFontItalic * 4.0f; //offset for accuracy
	v5 = points->y2 - points->y1;
	_points.u = v4;
	_points.z = scale;
	v6 = points->v1;
	_points.vy2 = v5;
	v7 = points->u2 - points->u1;
	_points.vy1 = 0.0f;
	_points.vx2 = 0.0f;
	_points.v = v6;
	_points.vu1 = v7;
	_points.vv1 = 0.0f;
	v8 = points->v2;
	_points.vu2 = 0.0f;
	_points.vv2 = v8 - points->v1;
	_points.vx2 -= DebugFontItalic * 10.0f;
	Direct3D_DrawQuad(&_points);
}

void SetHudColorAndTextureNum_Italic(int n, NJS_COLOR color)
{
	NJS_COLOR c;
	c.argb.r = color.argb.r;
	c.argb.g = color.argb.g;
	c.argb.b = color.argb.b;
	if (color.argb.a < 15)
	{
		if (color.argb.a & FONT_ITALIC) DebugFontItalic = true;
		if (color.argb.a & FONT_TRANSPARENTMSG && MessageShown) c.argb.a = 64;
		else c.argb.a = 255;
		SetHudColorAndTextureNum(n, c);
	}
	else
	{
		DebugFontItalic = false;
		SetHudColorAndTextureNum(n, color);
	}
}