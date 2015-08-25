#include <PA_BgStruct.h>

extern const char hosto01_Tiles[];
extern const char hosto01_Map[];
extern const char hosto01_Pal[];

const PA_BgStruct hosto01 = {
	PA_BgNormal,
	256, 192,

	hosto01_Tiles,
	hosto01_Map,
	{hosto01_Pal},

	44096,
	{1536}
};
