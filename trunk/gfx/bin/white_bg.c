#include <PA_BgStruct.h>

extern const char white_bg_Tiles[];
extern const char white_bg_Map[];
extern const char white_bg_Pal[];

const PA_BgStruct white_bg = {
	PA_BgNormal,
	256, 192,

	white_bg_Tiles,
	white_bg_Map,
	{white_bg_Pal},

	64,
	{1536}
};
