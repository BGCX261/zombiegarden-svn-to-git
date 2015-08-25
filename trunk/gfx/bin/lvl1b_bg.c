#include <PA_BgStruct.h>

extern const char lvl1b_bg_Tiles[];
extern const char lvl1b_bg_Map[];
extern const char lvl1b_bg_Pal[];

const PA_BgStruct lvl1b_bg = {
	PA_BgNormal,
	256, 192,

	lvl1b_bg_Tiles,
	lvl1b_bg_Map,
	{lvl1b_bg_Pal},

	49152,
	{1536}
};
