#include <PA_BgStruct.h>

extern const char hosto04_Tiles[];
extern const char hosto04_Map[];
extern const char hosto04_Pal[];

const PA_BgStruct hosto04 = {
	PA_BgNormal,
	256, 192,

	hosto04_Tiles,
	hosto04_Map,
	{hosto04_Pal},

	43968,
	{1536}
};
