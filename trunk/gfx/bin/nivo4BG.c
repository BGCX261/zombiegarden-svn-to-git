#include <PA_BgStruct.h>

extern const char nivo4BG_Tiles[];
extern const char nivo4BG_Map[];
extern const char nivo4BG_Pal[];

const PA_BgStruct nivo4BG = {
	PA_BgNormal,
	256, 192,

	nivo4BG_Tiles,
	nivo4BG_Map,
	{nivo4BG_Pal},

	48896,
	{1536}
};
