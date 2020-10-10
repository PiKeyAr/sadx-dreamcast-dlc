#pragma once

class ChallengeTimer
{
private:
	static SETObjData setdata_timer;
	static char highlightchar;
	static bool timer_flip;
	static bool pause_flip;
public:
	static bool loaded;
	static bool enable;
	static bool visible;
	static Uint32 time_current;
	static Uint32 time_target;
	static char target_total;
	static char target_current;
	static const char** message_foundall;
	static const char** message_timeup;
	static const char** message_clear;

	static void DeleteSub(ObjectMaster* a1);
	static void DisplaySub(ObjectMaster* a1);
	static void MainSub(ObjectMaster* a1);
	static void LoadSub(ObjectMaster* a1);
	static void Initialize();
};

extern ChallengeTimer timer;