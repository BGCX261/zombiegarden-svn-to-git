#include <PA_BgStruct.h>

extern const char lvl2_bg2_Tiles[];
extern const char lvl2_bg2_Map[];
extern const char lvl2_bg2_Pal[];

const PA_BgStruct lvl2_bg2 = {
	PA_BgNormal,
	256, 192,

	lvl2_bg2_Tiles,
	lvl2_bg2_Map,
	{lvl2_bg2_Pal},

	13248,
	{1536}
};
