#pragma once

#pragma warning(push)
#pragma warning(disable: 4267 4838)

NJS_TEXNAME textures_kadomatsu[7];
NJS_TEXLIST texlist_kadomatsu = { arrayptrandlength(textures_kadomatsu) };

NJS_MATERIAL matlistK_00000008[] = {
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 0, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 1, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_FLIP_V | NJD_FLAG_FLIP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 4, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 0, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 2, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_FLIP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_ALPHA | NJD_FLAG_USE_TEXTURE | NJD_FLAG_DOUBLE_SIDE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 5, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_ALPHA | NJD_FLAG_USE_TEXTURE | NJD_FLAG_DOUBLE_SIDE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 6, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 3, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_000000A8[] = {
	0x8000u | 14, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2
};

Sint16 poly_000000C6[] = {
	3, 8, 10, 6,
	0x8000u | 5, 6, 4, 10, 2, 0
};

Sint16 poly_000000DA[] = {
	0x8000u | 14, 14, 13, 12, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13
};

Sint16 poly_000000F8[] = {
	3, 18, 20, 16,
	5, 20, 22, 16, 12, 14
};

Sint16 poly_0000010C[] = {
	0x8000u | 5, 27, 24, 26, 31, 25,
	0x8000u | 5, 29, 30, 28, 24, 27,
	0x8000u | 5, 74, 71, 73, 78, 72,
	0x8000u | 5, 76, 77, 75, 71, 74,
	0x8000u | 5, 82, 79, 81, 86, 80,
	3, 85, 84, 83,
	3, 83, 79, 85,
	4, 83, 87, 79, 82
};

Sint16 poly_00000162[] = {
	3, 34, 32, 37,
	5, 34, 35, 32, 36, 33
};

Sint16 poly_00000176[] = {
	11, 39, 43, 44, 45, 46, 47, 48, 42, 38, 39, 40,
	3, 44, 40, 39,
	11, 50, 54, 55, 56, 57, 58, 59, 52, 49, 50, 51,
	3, 55, 51, 50,
	11, 61, 65, 66, 67, 68, 69, 70, 63, 60, 61, 62,
	3, 66, 62, 61
};

Sint16 poly_000001D6[] = {
	3, 46, 48, 41,
	4, 46, 41, 44, 40,
	3, 41, 48, 38,
	3, 38, 40, 41,
	3, 57, 59, 53,
	4, 57, 53, 55, 51,
	3, 53, 59, 49,
	3, 49, 51, 53,
	3, 68, 70, 64,
	4, 68, 64, 66, 62,
	3, 64, 70, 60,
	3, 60, 62, 64
};

NJS_TEX uv_0000023C[] = {
	{ 0, 255 },
	{ 0 },
	{ 507, 255 },
	{ 507, 0 },
	{ 1014, 255 },
	{ 1014, 0 },
	{ 1529, 255 },
	{ 1529, 0 },
	{ 2037, 255 },
	{ 2037, 0 },
	{ 2544, 255 },
	{ 2544, 0 },
	{ 3059, 255 },
	{ 3059, 0 }
};

NJS_TEX uv_00000274[] = {
	{ 509, 127 },
	{ 254, 255 },
	{ 510, -127 },
	{ 510, -127 },
	{ 255, -254 },
	{ 254, 255 },
	{ 0, -127 },
	{ 0, 127 }
};

NJS_TEX uv_00000294[] = {
	{ 1529, -510 },
	{ 1529, 255 },
	{ 1272, -510 },
	{ 1272, 255 },
	{ 1018, -510 },
	{ 1018, 255 },
	{ 764, -510 },
	{ 764, 255 },
	{ 507, -510 },
	{ 507, 255 },
	{ 253, -510 },
	{ 253, 255 },
	{ 0, -510 },
	{ 0, 255 }
};

NJS_TEX uv_000002CC[] = {
	{ 0, -63 },
	{ 0, -701 },
	{ 637, 254 },
	{ 0, -701 },
	{ 637, -1020 },
	{ 637, 254 },
	{ 1275, -701 },
	{ 1274, -63 }
};

NJS_TEX uv_000002EC[] = {
	{ 0 },
	{ 38, 194 },
	{ 154, 0 },
	{ 246, 162 },
	{ 254, 32 },
	{ 254, 32 },
	{ 246, 162 },
	{ 148, 0 },
	{ 20, 186 },
	{ 0 },
	{ 0 },
	{ 46, 254 },
	{ 138, 0 },
	{ 246, 254 },
	{ 254, 26 },
	{ 254, 0 },
	{ 246, 254 },
	{ 136, 0 },
	{ 84, 252 },
	{ 0 },
	{ 0 },
	{ 56, 254 },
	{ 192, 0 },
	{ 152, 254 },
	{ 254, 80 },
	{ 164, 254 },
	{ 254, 32 },
	{ 108, 0 },
	{ 192, 0 },
	{ 106, 254 },
	{ 164, 254 },
	{ 0 },
	{ 192, 0 },
	{ 106, 254 },
	{ 0 }
};

NJS_TEX uv_00000378[] = {
	{ 1, 1 },
	{ 253, 253 },
	{ 1, 253 },
	{ 1, 1 },
	{ 253, 1 },
	{ 253, 253 },
	{ 1, 1 },
	{ 1, 253 }
};

NJS_TEX uv_00000398[] = {
	{ 61, 253 },
	{ 319, 254 },
	{ 319, -410 },
	{ 445, 254 },
	{ 445, -237 },
	{ 573, 254 },
	{ 573, -147 },
	{ 702, 254 },
	{ 702, -237 },
	{ 827, 254 },
	{ 827, -410 },
	{ 319, -410 },
	{ 61, -410 },
	{ 61, 253 },
	{ 62, 253 },
	{ 319, 255 },
	{ 319, -918 },
	{ 445, 255 },
	{ 445, -743 },
	{ 573, 255 },
	{ 573, -650 },
	{ 702, 255 },
	{ 702, -743 },
	{ 827, 255 },
	{ 827, -918 },
	{ 319, -918 },
	{ 62, -918 },
	{ 62, 253 },
	{ 61, 254 },
	{ 319, 255 },
	{ 319, -665 },
	{ 445, 255 },
	{ 445, -493 },
	{ 573, 255 },
	{ 573, -402 },
	{ 702, 255 },
	{ 702, -493 },
	{ 827, 255 },
	{ 827, -665 },
	{ 319, -665 },
	{ 61, -667 },
	{ 61, 254 }
};

NJS_TEX uv_00000440[] = {
	{ 251, 251 },
	{ 3, 251 },
	{ 123, 3 },
	{ 3, 251 },
	{ 123, 3 },
	{ 251, 251 },
	{ 251, 251 },
	{ 123, 3 },
	{ 251, 251 },
	{ 3, 251 },
	{ 251, 251 },
	{ 3, 251 },
	{ 123, 3 },
	{ 251, 251 },
	{ 3, 251 },
	{ 123, 3 },
	{ 3, 251 },
	{ 123, 3 },
	{ 251, 251 },
	{ 251, 251 },
	{ 123, 3 },
	{ 251, 251 },
	{ 3, 251 },
	{ 251, 251 },
	{ 3, 251 },
	{ 123, 3 },
	{ 251, 251 },
	{ 3, 251 },
	{ 123, 3 },
	{ 3, 251 },
	{ 123, 3 },
	{ 251, 251 },
	{ 251, 251 },
	{ 123, 3 },
	{ 251, 251 },
	{ 3, 251 },
	{ 251, 251 },
	{ 3, 251 },
	{ 123, 3 }
};

NJS_MESHSET_SADX meshlist_000004DC[] = {
	{ NJD_MESHSET_TRIMESH | 0, 1, poly_000000A8, NULL, NULL, NULL, uv_0000023C, NULL },
	{ NJD_MESHSET_TRIMESH | 1, 2, poly_000000C6, NULL, NULL, NULL, uv_00000274, NULL },
	{ NJD_MESHSET_TRIMESH | 2, 1, poly_000000DA, NULL, NULL, NULL, uv_00000294, NULL },
	{ NJD_MESHSET_TRIMESH | 3, 2, poly_000000F8, NULL, NULL, NULL, uv_000002CC, NULL },
	{ NJD_MESHSET_TRIMESH | 6, 6, poly_00000176, NULL, NULL, NULL, uv_00000398, NULL },
	{ NJD_MESHSET_TRIMESH | 7, 12, poly_000001D6, NULL, NULL, NULL, uv_00000440, NULL },
	{ NJD_MESHSET_TRIMESH | 4, 8, poly_0000010C, NULL, NULL, NULL, uv_000002EC, NULL },
	{ NJD_MESHSET_TRIMESH | 5, 2, poly_00000162, NULL, NULL, NULL, uv_00000378, NULL },
};

NJS_VECTOR vertex_0000059C[] = {
	{ 4.348569f, 1.189678f, 2.542426f },
	{ 4.348567f, 0.055677f, -2.542427f },
	{ 4.348567f, 1.189678f, -2.542427f },
	{ 0, 0.055677f, -5.084854f },
	{ 0, 1.189678f, -5.084854f },
	{ -4.348568f, 0.055677f, -2.542426f },
	{ -4.348568f, 1.189678f, -2.542426f },
	{ -4.348567f, 0.055677f, 2.542428f },
	{ -4.348567f, 1.189678f, 2.542428f },
	{ 0.000001f, 0.055677f, 5.084854f },
	{ 0.000001f, 1.189678f, 5.084854f },
	{ 4.348569f, 0.055677f, 2.542426f },
	{ 2.805906f, 5.261527f, 1.640496f },
	{ 2.805905f, 1.211526f, -1.640496f },
	{ 2.805905f, 5.261527f, -1.640496f },
	{ 0, 1.211526f, -3.280992f },
	{ 0, 5.261527f, -3.280992f },
	{ -2.805905f, 1.211526f, -1.640496f },
	{ -2.805905f, 5.261527f, -1.640496f },
	{ -2.805905f, 1.211526f, 1.640497f },
	{ -2.805905f, 5.261527f, 1.640497f },
	{ 0.000001f, 1.211526f, 3.280993f },
	{ 0.000001f, 5.261527f, 3.280993f },
	{ 2.805906f, 1.211526f, 1.640496f },
	{ 0, 4.713521f, 1.819403f },
	{ -3.660007f, 5.991028f, -2.814538f },
	{ -4.469686f, 6.401822f, -0.26818f },
	{ -0.028153f, 8.76419f, 3.139332f },
	{ 4.48715f, 6.436315f, -0.147261f },
	{ 3.643033f, 5.87253f, -2.660505f },
	{ 2.156787f, 5.094642f, -2.149337f },
	{ -2.135606f, 5.134625f, -2.066932f },
	{ 0, 5.429468f, 2.499679f },
	{ -2.651417f, 5.061472f, 2.771953f },
	{ 3.08169f, 7.869514f, 2.971073f },
	{ 0, 8.480785f, 3.519175f },
	{ -2.786115f, 7.924892f, 2.971073f },
	{ 2.615146f, 4.995054f, 2.75856f },
	{ 0.813765f, 11.6554f, 0.7298779f },
	{ 0.503324f, 5.242936f, -0.255588f },
	{ 0.503324f, 13.89704f, -0.255588f },
	{ -0.002818f, 11.69094f, 0.250235f },
	{ 0.813765f, 5.242936f, 0.7298779f },
	{ -0.516899f, 5.242936f, -0.255626f },
	{ -0.516899f, 13.89704f, -0.255626f },
	{ -0.835344f, 5.242936f, 0.713919f },
	{ -0.835344f, 11.6554f, 0.713919f },
	{ -0.00284f, 5.242936f, 1.306179f },
	{ -0.00284f, 10.47558f, 1.306179f },
	{ 1.651886f, 17.9988f, -0.607156f },
	{ 1.343917f, 5.242934f, -1.572113f },
	{ 1.343917f, 20.24044f, -1.572113f },
	{ 1.651886f, 5.242934f, -0.607156f },
	{ 0.8281659f, 18.03435f, -1.085222f },
	{ 0.327104f, 5.242934f, -1.57215f },
	{ 0.327104f, 20.24044f, -1.57215f },
	{ 0.004425f, 5.242934f, -0.62186f },
	{ 0.004425f, 17.9988f, -0.62186f },
	{ 0.828144f, 5.242934f, -0.022032f },
	{ 0.828144f, 16.81898f, -0.022032f },
	{ -0.018585f, 14.98568f, -0.6266389f },
	{ -0.321359f, 5.242935f, -1.601151f },
	{ -0.321359f, 17.22732f, -1.601151f },
	{ -0.018585f, 5.242935f, -0.6266389f },
	{ -0.844743f, 15.02123f, -1.102346f },
	{ -1.334676f, 5.242935f, -1.600021f },
	{ -1.334676f, 17.22732f, -1.600021f },
	{ -1.665895f, 5.242935f, -0.6370479f },
	{ -1.665895f, 14.98568f, -0.6370479f },
	{ -0.8447649f, 5.242935f, -0.042582f },
	{ -0.8447649f, 13.80586f, -0.042582f },
	{ 0, 4.7482f, 1.124034f },
	{ -1.474242f, 8.197766f, -4.103821f },
	{ -3.534062f, 10.02343f, -0.945372f },
	{ -0.057224f, 10.80935f, 2.344835f },
	{ 3.238012f, 10.01742f, -0.860721f },
	{ 1.241221f, 8.481857f, -4.005652f },
	{ 1.937852f, 4.816271f, -0.840791f },
	{ -1.913516f, 4.806808f, -0.964398f },
	{ -0.097158f, 4.886914f, 1.43602f },
	{ -1.661161f, 7.031089f, -3.996007f },
	{ -4.69318f, 7.372614f, -1.945057f },
	{ -2.110183f, 9.512432f, 2.705029f },
	{ 4.919979f, 7.534337f, -1.835783f },
	{ 1.662474f, 7.070573f, -3.996094f },
	{ 1.980957f, 5.080787f, -0.973884f },
	{ -1.77664f, 5.226701f, -0.887358f },
	{ 1.934127f, 9.659688f, 2.601033f }
};

NJS_VECTOR normal_000009BC[] = {
	{ 0.687059f, 0.6103899f, 0.394175f },
	{ 0.867388f, 0, -0.497632f },
	{ 0.687059f, 0.6103899f, -0.394175f },
	{ 0, 0, -1 },
	{ 0, 0.609206f, -0.793012f },
	{ -0.867388f, 0, -0.497632f },
	{ -0.687059f, 0.6103899f, -0.394175f },
	{ -0.867388f, 0, 0.497632f },
	{ -0.687059f, 0.6103899f, 0.394175f },
	{ 0, 0, 1 },
	{ 0, 0.609206f, 0.793012f },
	{ 0.867388f, 0, 0.497632f },
	{ 0.687059f, 0.6103899f, 0.394175f },
	{ 0.867388f, 0, -0.497632f },
	{ 0.687059f, 0.6103899f, -0.394175f },
	{ 0, 0, -1 },
	{ 0, 0.609206f, -0.793012f },
	{ -0.867388f, 0, -0.497632f },
	{ -0.687059f, 0.6103899f, -0.394175f },
	{ -0.867388f, 0, 0.497632f },
	{ -0.687059f, 0.6103899f, 0.394175f },
	{ 0, 0, 1 },
	{ 0, 0.609206f, 0.793012f },
	{ 0.867388f, 0, 0.497632f },
	{ -0.002977f, -0.623854f, 0.781535f },
	{ -0.484864f, -0.874492f, -0.013096f },
	{ -0.507808f, -0.788056f, 0.347991f },
	{ -0.010536f, -0.30987f, 0.950721f },
	{ 0.497755f, -0.7783639f, 0.38261f },
	{ 0.47368f, -0.879865f, 0.038283f },
	{ 0.433574f, -0.896013f, 0.095786f },
	{ -0.435658f, -0.897612f, 0.06704199f },
	{ -0.00057f, -0.191961f, 0.981402f },
	{ 0.110698f, -0.06376199f, 0.991807f },
	{ 0.010107f, -0.201964f, 0.979341f },
	{ -0.008382999f, -0.316885f, 0.948427f },
	{ -0.018291f, -0.20527f, 0.978535f },
	{ -0.107554f, -0.055929f, 0.992625f },
	{ 0.678066f, 0.417092f, 0.605195f },
	{ 0.591427f, 0, -0.806358f },
	{ 0.470004f, 0.874419f, -0.120365f },
	{ -0.00945f, 0.469245f, 0.8830169f },
	{ 0.947482f, 0, 0.31981f },
	{ -0.58648f, 0, -0.8099639f },
	{ -0.469753f, 0.8746f, -0.120031f },
	{ -0.950003f, 0, 0.31224f },
	{ -0.689679f, 0.41229f, 0.5952809f },
	{ -0.001895f, 0, 0.999998f },
	{ -0.002366f, 0.151875f, 0.9883969f },
	{ 0.6820599f, 0.415043f, 0.6021079f },
	{ 0.589912f, 0, -0.807468f },
	{ 0.468147f, 0.875834f, -0.117275f },
	{ 0.948566f, 0, 0.316578f },
	{ -0.004803f, 0.466525f, 0.884495f },
	{ -0.582425f, 0, -0.812885f },
	{ -0.468428f, 0.875791f, -0.116468f },
	{ -0.953236f, 0, 0.302226f },
	{ -0.692419f, 0.415224f, 0.590037f },
	{ -0.005888f, 0, 0.999983f },
	{ -0.00607f, 0.152862f, 0.988229f },
	{ 0.680366f, 0.413026f, 0.605402f },
	{ 0.592551f, 0, -0.805533f },
	{ 0.469307f, 0.874872f, -0.119789f },
	{ 0.946979f, 0, 0.321295f },
	{ -0.001307f, 0.46807f, 0.88369f },
	{ -0.581292f, 0, -0.813695f },
	{ -0.469139f, 0.875233f, -0.117798f },
	{ -0.953412f, 0, 0.301671f },
	{ -0.691836f, 0.417879f, 0.588847f },
	{ -0.005631f, 0, 0.999984f },
	{ -0.005672f, 0.152388f, 0.988304f },
	{ -0.002176f, -0.24457f, 0.969629f },
	{ -0.870478f, -0.268911f, -0.412255f },
	{ -0.908748f, -0.255127f, 0.330283f },
	{ 0.000027f, -0.197448f, 0.9803129f },
	{ 0.9282399f, -0.217395f, 0.301843f },
	{ 0.868572f, -0.218826f, -0.444632f },
	{ 0.891576f, -0.221358f, 0.395086f },
	{ -0.889501f, -0.277648f, 0.362904f },
	{ -0.005666f, -0.56867f, 0.8225459f },
	{ -0.406174f, -0.7836789f, -0.469968f },
	{ -0.649339f, -0.755512f, 0.08694699f },
	{ -0.352762f, -0.387222f, 0.851832f },
	{ 0.684977f, -0.716127f, 0.134048f },
	{ 0.45023f, -0.723259f, -0.523631f },
	{ 0.661822f, -0.722392f, 0.200353f },
	{ -0.615806f, -0.77911f, 0.117349f },
	{ 0.376713f, -0.367849f, 0.850161f }
};

NJS_MODEL_SADX attach_00000DDC = { vertex_0000059C, normal_000009BC, LengthOfArray<Sint32>(vertex_0000059C), meshlist_000004DC, matlistK_00000008, LengthOfArray<Uint16>(meshlist_000004DC), LengthOfArray<Uint16>(matlistK_00000008), { 0.1134f, 10.14806f, 0 }, 11.30097f, NULL };

NJS_OBJECT kadomatsu = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_00000DDC, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };

#pragma warning(pop)