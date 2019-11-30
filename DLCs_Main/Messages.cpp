#include <stdafx.h>
#include "Messages.h"

char ResultText[128];

const char *const Y2KMessage1[] = {
	"\aTry to find it!\nIt's also in the Action Stage.",
	NULL,
};

const char *const Y2KMessage2[] = {
	"\aA happy new year in 2K!\nPlease Support Sonic in 2K.",
	NULL,
};

const char *const Y2KMessage3[] = {
	"\aA happy new year in 2K!\nWish you a good new year!",
	NULL,
};

const char *const Y2KMessage4[] = {
	"\aA happy new year in 2K!\nSonic runs through 2K!",
	NULL,
};

const char *const Y2KMessage5[] = {
	"\aA happy new year in 2K!\nTails smiles through 2K!",
	NULL,
};

const char *const Y2KMessage6[] = {
	"\aA happy new year in 2K!\nKnuckles digs through 2K!",
	NULL,
};

const char *const SambaGPMessage0[] = {
	"	Samba GP\n	START!",
	NULL,
};

const char *const SambaGPMessage1[] = {
	"	Twinkle Circuit\n	Samba GP Grand Opening!",
	NULL,
};

const char *const SambaGPMessage2[] = {
	"	The contest is over,\n	but you can still play the course.",
	NULL,
};

const char *const SambaGPMessage3[] = {
	"	Collecting the rings increases\n	bumper car acceleration.",
	NULL,
};

const char *const ReebokMessage1[] = {
	"	Reebok DMX Speed Challenge\n	at Emerald Coast Now Open!",
	NULL,
};

const char *const ReebokMessage2[] = {
	"\aYou aren't done yet!\nFind the remaining shoes!",
	"\aLeave Emerald Coast\nto quit the challenge.",
	NULL,
};

const char *const ReebokMessage3[] = {
	"	Time's up.\nPlease try again.",
	NULL,
};

const char *const ReebokMessage4[] = {
	"	Shoes found!\nThere are more hidden elsewhere!",
	NULL,
};

const char *const ReebokMessage5[] = {
	"	5th pair found!\nGo to the goal on the lighthouse!",
	NULL,
};

const char *const ReebokMessage6[] = {
	"	Find all 5 pairs of Reebok DMXs\n	Stolen by Dr. Robotnik!",
	NULL,
};

const char *const ReebokMessage7[] = {
	"	Reebok DMX Speed Challenge\n	Start!",
	NULL,
};

const char *const ReebokMessage8[] = {
	"	You can't continue from here.\n	Please delete Reebok file.",
	NULL,
};

const char *const ReebokMessage9[] = {
	"	Congratulations!\n	Now saving your clear time.",
	ResultText,
	"\aThe challenge is over.\nGo back to Station Square to restart.",
	NULL,
};

const char *const QuoMessage1[] = {
	"	Rush to the Mystic Ruins goal, now!",
	NULL,
};

const char *const QuoMessage2[] = {
	"	You aren't done yet!\n	Find the remaining QUO cards!",
	"	To quit the challenge,\n	press Y in the pause menu.",
	NULL,
};

const char *const QuoMessage3[] = {
	"	Time over!\n	Try again from the beginning.",
	NULL,
};

const char *const QuoMessage4[] = {
	"	- Challenge start -\n	Collect 6 MD Yukawa QUO cards!",
	NULL,
};

const char *const QuoMessage5[] = {
	"	Oops, you've got the old man there!\n	- Hidekazu Yukawa -",
	NULL,
};

const char *const QuoMessage6[] = {
	"	So you found me, huh.\n	- Hidekazu Yukawa -",
	NULL,
};

const char *const QuoMessage7[] = {
	"	The Hidekazu Yukawa man is going\n	to work even harder from now on.",
	"	- Hidekazu Yukawa -",
	NULL,
};

const char *const QuoMessage8[] = {
	"	You might break a nail\n	if you fell from here.",
	"	- Hidekazu Yukawa -",
	NULL,
};

const char *const QuoMessage9[] = {
	"	Ooh! You've gone so far to find these!\n	- Hidekazu Yukawa -",
	NULL,
};

const char *const QuoMessage10[] = {
	"	The cards can be used nationwide.\n	Use them well!",
	"	- Hidekazu Yukawa -",
	NULL,
};

const char *const QuoMessage11[] = {
	"	Congratulations!\n	You've cleared the card hunting game!",
	ResultText,
	"	The challenge is over.\n	Touch the red balloon again to restart.",
	NULL,
};

const char *const LaunchPartyMessage1[] = {
	"\aThank you for choosing Sonic!\nFrom Sonic Team.",
	NULL,
};

const char *const LaunchPartyMessage2[] = {
	"\aWelcome to the Dreamcast Launch!\nThis is just the beginning.",
	NULL,
};

const char *const LaunchPartyMessage3[] = {
	"\aFrom all of us on the Sonic Team,\nThank you very much!",
	NULL,
};

const char *const LaunchPartyMessage4_JP[] = {
	"\aUS Dreamcast Launch 9-9-99!\nThank you for supporting us! ",
	NULL,
};

const char *const LaunchPartyMessage4_US[] = {
	"\aUS Dreamcast Launch 9-9-99!\nThank you for supporting us! ",
	NULL,
};

const char *const LaunchPartyMessage4_EU[] = {
	"\aEU Dreamcast Launch 14-10-99!\nThank you for supporting us! ",
	NULL,
};

const char *const LaunchPartyMessage5[] = {
	"\aLook for more cool stuff online!\nYou ain't seen nothing yet!",
	NULL,
};

const char *const LaunchPartyMessage6[] = {
	"\aWorld Rankings, Download files\nand more only on our website.",
	NULL,
};

const char *const HalloweenMessage0[] = {
	"	Halloween Party is being held at\n	Twinkle Park now!",
	NULL,
};

const char *const HalloweenMessage1[] = {
	"	Trick or Treat!",
	NULL,
};

const char *const FamitsuMessage1[] = {
	"	Oh no, I'm beaten!\n	Gotta rush to the goal now!",
	NULL,
};

const char *const FamitsuMessage2[] = {
	"	You aren't done yet!\n	Find the remaining Sonics!",
	"	To quit the challenge,\n	press Y in the pause menu.",
	NULL,
};

const char *const FamitsuMessage3[] = {
	"	Time over!\n	Try again from the beginning.",
	NULL,
};

const char *const FamitsuMessage4[] = {
	"	- Challenge start -\n	Find Sonic in 5 secret spots!",
	NULL,
};

const char *const FamitsuMessage5[] = {
	"	I'm Famitsu's special hedgehog friend!",
	NULL,
};

const char *const FamitsuMessage6[] = {
	"	I wanna become a blue hedgehog!",
	NULL,
};

const char *const FamitsuMessage7[] = {
	"	New Famitsu issue\n	every Friday!",
	NULL,
};

const char *const FamitsuMessage8[] = {
	"	Thank you for staying\n	with Sonic and Famitsu!",
	"	Let's be good friends, alright?",
	NULL,
};

const char *const FamitsuMessage9[] = {
	"	You can meet\n	me at Famitsu, too!",
	NULL,
};

const char *const FamitsuMessage10[] = {
	"	Congratulations!\n	You've won the game of hide-and-seek!",
	ResultText,
	"	The challenge is over.\n	Touch the red balloon again to restart.",
	NULL,
};

const char *const Christmas99Message0[] = {
	"	Merry X'mas!!\n	Please keep in touch with Sonic!",
	NULL,
};

const char *const Christmas99Message1[] = {
	"	Merry X'mas!!\n	Best wishes!",
	NULL,
};

const char *const Christmas99Message2[] = {
	"	Merry X'mas!!\n	Happy New Year!",
	NULL,
};

const char *const Christmas99Message3[] = {
	"	Merry X'mas!!\n	Countdown to year 2000!",
	NULL,
};

const char *const Christmas98Message0[] = {
	"	Here's wishing you a romantic X'mas!\n	-Hotel manager-",
	NULL,
};

const char *const Christmas98Message1[] = {
	"	Be careful not to eat too much cake!",
	NULL,
};

const char *const Christmas98Message2[] = {
	"	Santa will bring gifts to\n	all the good boys and girls!",
	NULL,
};

const char *const Christmas98Message3[] = {
	"	Let's spend this X'mas\n	going out together with our Chao.",
	NULL,
};

const char *const Christmas98Message4[] = {
	"	Two lovers are playing\n	Sonic Adventure on a holy night.",
	NULL,
};

const char *const Christmas98Message5[] = {
	"	Christmas sale now on!\n	-Central Department Store-",
	NULL,
};

const char *const Christmas98Message6[] = {
	"	Merry X'mas to all our fellow citizens!\n	-Station Square Mayor-",
	NULL,
};
const char *const Christmas98Message7[] = {
	"	May this Christmas become\n	your greatest day!",
	NULL,
};

const char *const ATT1_Message1[] = {
	"	If you touch the Start Plate,\n	you'll go to Speed Highway!",
	NULL,
};

const char *const ATT1_Message2[] = {
	"	Touch the Goal Plate after\n	Speed Highway is finished.",
	NULL,
};

const char *const ATT1_Message3[] = {
	"	Time Over!\n	Please try again.",
	NULL,
};

const char *const ATT1_Message4[] = {
	"	-CLEAR-\n	Go back to Station Square!",
	NULL,
};

const char *const ATT1_Message5[] = {
	"	AT&T Time Attack Contest\n	-START-",
	NULL,
};

const char *const ATT1_Message6[] = {
	"	You can't continue from here.\n	Please remove the AT&T file.",
	NULL,
};

const char *const ATT1_Message7[] = {
	"	Congratulations!\n	Now saving your clear time.",
	ResultText,
	"\a	The challenge is over.\n	Touch the Start Plate again to restart.",
	NULL,
};

const char *const ATT2_Message0[] = {
	"	All treasures found!\n	Now, hurry to the goal!!!",
	NULL,
};

const char *const ATT2_Message1[] = {
	"	Results will be saved\n	on the memory card.",
	NULL,
};

const char *const ATT2_Message2[] = {
	"	Time's up.\n	Please try again.",
	NULL,
};

const char *const ATT2_Message3[] = {
	"	AT&T Treasure Hunt Time Attack\n	Start",
	NULL,
};

const char *const ATT2_Message4[] = {
	"	Congratulations!\n	Treasure Hunt Time Attack Cleared!",
	ResultText,
	"\a	The challenge is over.\n	Touch the Start Plate again to restart.",
	NULL,
};

const char *const ATT2_Message5[] = {
	"	Treasure found!\n	Good job!",
	NULL,
};

const char *const ATT2_Message6[] = {
	"	Treasure found!\n	Way to go!!",
	NULL,
};

const char *const ATT2_Message7[] = {
	"	Treasure found!\n	Great Digging!!",
	NULL,
};

const char *const ATT2_Message8[] = {
	"	Treasure found!\n	You're awesome!",
	NULL,
};

const char *const ATT2_Message9[] = {
	"	Treasure Time Attack\n	at the Mystic Ruins Now Open!",
	NULL,
};

const char *const ATT2_Message10[] = {
	"	Stuck? Stand in front of\n	the shack, do the dash punch.",
	NULL,
};

const char *const ATT2_Message11[] = {
	"	Check out where you placed\n	the windy stone.",
	NULL,
};

const char *const ATT2_Message12[] = {
	"	The treasure's somewhere\n	near the mine cart.",
	NULL,
};

const char *const ATT2_Message13[] = {
	"	The treasure's somewhere\n	in front of this sign.",
	NULL,
};

const char *const ATT2_Message14[] = {
	"	No treasures around here!",
	NULL,
};

const char *const ATT2_Message15[] = {
	"	Top Time Attack winners\n	will win a prize!!!",
	NULL,
};

const char *const ATT2_Message16[] = {
	"	You aren't done yet!\n	Find more treasures!",
	"\aTo quit the challenge,\npress Y in the pause menu.",
	NULL,
};

const char *const ATT3_Message0[] = {
	"	All Gates cleared! Goal!",
	NULL,
};

const char *const ATT3_Message1[] = {
	"	Now saving your clear time.",
	NULL,
};

const char *const ATT3_Message2[] = {
	"	Time was up.\n	You have to start again.",
	NULL,
};

const char *const ATT3_Message3[] = {
	"	Go through 10 blue gates\n	to reach the goal!",
	NULL,
};

const char *const ATT3_Message4[] = {
	ResultText,
	"	The challenge is over.\n	Re-enter Sand Hill to restart.",
	NULL,
};

const char *const ATT3_Message5[] = {
	"	Time attack Race is\n	holding at Sand Hill!",
	NULL,
};

const char *const ATT3_Message6[] = {
	"	Gate 1 passed!!",
	NULL,
};

const char *const ATT3_Message7[] = {
	"	Gate 2 passed!!",
	NULL,
};

const char *const ATT3_Message8[] = {
	"	Gate 3 passed!!",
	NULL,
};

const char *const ATT3_Message9[] = {
	"	Gate 4 passed!!",
	NULL,
};

const char *const ATT3_Message10[] = {
	"	Gate 5 passed!!",
	NULL,
};

const char *const ATT3_Message11[] = {
	"	Gate 6 passed!!",
	NULL,
};

const char *const ATT3_Message12[] = {
	"	Gate 7 passed!!",
	NULL,
};

const char *const ATT3_Message13[] = {
	"	Gate 8 passed!!",
	NULL,
};

const char *const ATT3_Message14[] = {
	"	Gate 9 passed!!",
	NULL,
};

const char *const ATT3_Message15[] = {
	"	Gate 10 passed!!",
	NULL,
};

const char *const ATT3_Message16[] = {
	"	You didn't pass all 10 gates.\n	Re-enter Sand Hill to try again.",
	NULL,
};

const char* const KadomatsuMessage0[] = {
	"	\n	-Hotel manager-",
	NULL,
};

const char* const KadomatsuMessage1[] = {
	"	\n	-Hotel manager-",
	NULL,
};

const char* const KadomatsuMessage2[] = {
	"	Be careful not to eat\n	too many rice cakes!",
	NULL,
};

const char* const KadomatsuMessage3[] = {
	"	Don't squander your New Year\n	gift money, alright?",
	NULL,
};

const char* const KadomatsuMessage4[] = {
	"	We pray for continued prosperity in\n	the new year! - Casinopolis Manager",
	NULL,
};

const char* const KadomatsuMessage5[] = {
	"	We'll be sure to fix the door switch\n	 this year - Casinopolis Manager",
	NULL,
};

const char* const KadomatsuMessage6[] = {
	"	Happy New Year!\n	-Sonic Team-",
	NULL,
};

const char* const KadomatsuMessage7[] = {
	"	Please support us in the new year too\n	-Sonic Team-",
	NULL,
};

const char* const KadomatsuMessage8[] = {
	"	Spend New Year's Eve playing Chao Race\n	together with your family",
	NULL,
};

const char* const KadomatsuMessage9[] = {
	"	On your first shrine visit this year\n	take your Chao with you",
	NULL,
};