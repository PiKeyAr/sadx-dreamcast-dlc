// AT&T DLC functions.
#pragma once

#include <SADXStructs.h>
extern const PVMEntry ATT1Textures;
extern const PVMEntry ATT2Textures;
extern const PVMEntry ATT3Textures;

void ATTTimer_Load(ObjectMaster *a1);
void ATTObject_Load(ObjectMaster *a1);

void LoadATT1Stuff(void);
void LoadATT1Stuff_SS(void);
void LoadATT2Stuff_SSorMR(void);
void LoadATT3Stuff_SS(void);
void LoadATT3Stuff(void);
