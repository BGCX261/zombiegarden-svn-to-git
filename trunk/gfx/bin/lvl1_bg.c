#include <PA_BgStruct.h>

extern const char lvl1_bg_Tiles[];
extern const char lvl1_bg_Map[];
extern const char lvl1_bg_Pal[];

const PA_BgStruct lvl1_bg = {
	PA_BgNormal,
	256, 192,

	lvl1_bg_Tiles,
	lvl1_bg_Map,
	{lvl1_bg_Pal},

	46976,
	{1536}
};
