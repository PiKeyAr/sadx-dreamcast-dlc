#include <stdafx.h>
#include "Timer.h"

NJS_TEXANIM HedgehogCountTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE HedgehogCount = { { HorizontalStretch * 540, VerticalStretch * 455, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &HedgehogCountTexanim };

NJS_TEXANIM HedgehogCountSlashTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE HedgehogCountSlash = { { HorizontalStretch * 556, VerticalStretch * 455, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &HedgehogCountSlashTexanim };

NJS_TEXANIM HedgehogCountTotalTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE HedgehogCountTotal = { { HorizontalStretch * 572, VerticalStretch * 455, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &HedgehogCountTotalTexanim };

NJS_TEXANIM CardTenCountTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE CardTenCount = { { HorizontalStretch * 524, VerticalStretch * 455, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &CardTenCountTexanim };

NJS_TEXANIM CardCountTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE CardCount = { { HorizontalStretch * 540, VerticalStretch * 455, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &CardCountTexanim };

NJS_TEXANIM CardCountSlashTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE CardCountSlash = { { HorizontalStretch * 556, VerticalStretch * 455, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &CardCountSlashTexanim };

NJS_TEXANIM CardCountTotalTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE CardCountTotal = { { HorizontalStretch * 572, VerticalStretch * 455, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &CardCountTotalTexanim };

NJS_TEXANIM CardCountTotal2Texanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE CardCountTotal2 = { { HorizontalStretch * 588, VerticalStretch * 455, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &CardCountTotal2Texanim };

NJS_TEXANIM TimerTenMinutesTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE TimerTenMinutes = { { HorizontalStretch * 500, VerticalStretch * 436, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &TimerTenMinutesTexanim };

NJS_TEXANIM TimerMinutesTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE TimerMinutes = { { HorizontalStretch * 516, VerticalStretch * 436, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &TimerMinutesTexanim };

NJS_TEXANIM TimerColon1Texanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE TimerColon1 = { { HorizontalStretch * 532, VerticalStretch * 436, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &TimerColon1Texanim };

NJS_TEXANIM TimerTenSecondsTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE TimerTenSeconds = { { HorizontalStretch * 548, VerticalStretch * 436, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &TimerTenSecondsTexanim };

NJS_TEXANIM TimerSecondsTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE TimerSeconds = { { HorizontalStretch * 564, VerticalStretch * 436, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &TimerSecondsTexanim };

NJS_TEXANIM TimerColon2Texanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE TimerColon2 = { { HorizontalStretch * 580, VerticalStretch * 436, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &TimerColon2Texanim };

NJS_TEXANIM TimerMTenSecondsTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE TimerMTenSeconds = { { HorizontalStretch * 596, VerticalStretch * 436, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &TimerMTenSecondsTexanim };

NJS_TEXANIM TimerMSecondsTexanim = { 16, 16, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0 };
NJS_SPRITE TimerMSeconds = { { HorizontalStretch * 612, VerticalStretch * 436, 0.0f }, 1.0f, 1.0f, 0, (NJS_TEXLIST*)0x00912DF4, &TimerMSecondsTexanim };
