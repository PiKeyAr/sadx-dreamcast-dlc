#pragma once
#include <IniFile.hpp>

enum DLCObjectTypes
{
	TYPE_MODEL = 0,
	TYPE_SPRITE = 0x80,
	TYPE_INVISIBLE = 0xFF,
};

enum DLCRegionLocks
{
	Disabled = -1,
	Japan = 1,
	US = 3,
	Europe = 4,
	All = 7,
};

enum DLCObjectFlags
{
	FLAG_SOLID = BIT_8,
	FLAG_SOUND = BIT_9,
	FLAG_MESSAGE = BIT_10,
	FLAG_COLLISION_ONLY = BIT_11,
	FLAG_WARP = BIT_12,
	FLAG_COLLECTIBLE = BIT_13,
	FLAG_TIMER = BIT_14,
	FLAG_CHALLENGE = BIT_15,
	UNKNOWN_0 = BIT_0, //??
	UNKNOWN_4 = BIT_4, //??
	UNUSED_1 = BIT_1,
	UNUSED_2 = BIT_2,
	UNUSED_3 = BIT_3,
	UNUSED_5 = BIT_5,
	UNUSED_6 = BIT_6,
	UNUSED_7 = BIT_7,
};

class DLCObjectData
{
public:
	Uint8 level;
	Uint8 act;
	float scale_x;
	float scale_y;
	float scale_z;
	Sint8 rotspeed_x;
	Sint8 rotspeed_y;
	Sint8 rotspeed_z;
	DLCObjectTypes objecttype;
	Uint8 textureid;
	DLCObjectFlags flags;
	Uint8 objectid;
	//byte unknown3;
	Uint8 message;
	float radius;
	Uint8 warplevel;
	Uint8 sound;
	unsigned __int16 rot_x;
	unsigned __int16 rot_y;
	unsigned __int16 rot_z;
	float x;
	float y;
	float z;
	
	NJS_OBJECT* model;
	bool collected;
	bool loaded;

	void Load(const IniFile* ini, Uint8 id);
	void Info(Uint8 id);
};

class DLCMetadata
{
public:
	static std::string title;
	static std::string description;
	static std::string appname;
	static Uint32 dlc_id;
	static bool has_mlt;
	static bool chars_sonic;
	static bool chars_tails;
	static bool chars_knuckles;
	static bool chars_e102;
	static bool chars_amy;
	static bool chars_big;
	static Uint8 rendermode_model;
	static Uint8 rendermode_flat;
	static float depth_model;
	static float depth_flat;
	static Uint8 whatever;
	static DLCRegionLocks region;
	static DLCObjectData items[256];
	static std::string JapaneseStrings[16];
	static std::string EnglishStrings[16];
	static std::string FrenchStrings[16];
	static std::string SpanishStrings[16];
	static std::string GermanStrings[16];
	static bool adx;
	static bool dxmode;

	static void Load(const IniFile* ini);
	static void Info();
};	

extern NJS_TEXLIST maintexlist;
extern DLCMetadata meta;

extern const char* path_model;
extern const char* path_model_flat;
extern NJS_OBJECT* poster_model;
extern NJS_TEXLIST checker_texlist;
extern bool EnableCircuitMenu;
extern bool SuperSonicRacing;
extern int Codepage;