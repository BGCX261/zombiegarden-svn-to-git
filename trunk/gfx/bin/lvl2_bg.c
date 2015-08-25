#include <PA_BgStruct.h>

extern const char lvl2_bg_Tiles[];
extern const char lvl2_bg_Map[];
extern const char lvl2_bg_Pal[];

const PA_BgStruct lvl2_bg = {
	PA_BgNormal,
	256, 192,

	lvl2_bg_Tiles,
	lvl2_bg_Map,
	{lvl2_bg_Pal},

	49152,
	{1536}
};
