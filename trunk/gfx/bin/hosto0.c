#include <PA_BgStruct.h>

extern const char hosto0_Tiles[];
extern const char hosto0_Map[];
extern const char hosto0_Pal[];

const PA_BgStruct hosto0 = {
	PA_BgNormal,
	256, 192,

	hosto0_Tiles,
	hosto0_Map,
	{hosto0_Pal},

	43840,
	{1536}
};
