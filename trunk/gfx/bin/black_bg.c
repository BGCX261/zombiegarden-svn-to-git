#include <PA_BgStruct.h>

extern const char black_bg_Tiles[];
extern const char black_bg_Map[];
extern const char black_bg_Pal[];

const PA_BgStruct black_bg = {
	PA_BgNormal,
	256, 192,

	black_bg_Tiles,
	black_bg_Map,
	{black_bg_Pal},

	64,
	{1536}
};
