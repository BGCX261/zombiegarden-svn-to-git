#include <PA_BgStruct.h>

extern const char hosto02_Tiles[];
extern const char hosto02_Map[];
extern const char hosto02_Pal[];

const PA_BgStruct hosto02 = {
	PA_BgNormal,
	256, 192,

	hosto02_Tiles,
	hosto02_Map,
	{hosto02_Pal},

	43264,
	{1536}
};
