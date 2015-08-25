#include <PA_BgStruct.h>

extern const char hosto03_Tiles[];
extern const char hosto03_Map[];
extern const char hosto03_Pal[];

const PA_BgStruct hosto03 = {
	PA_BgNormal,
	256, 192,

	hosto03_Tiles,
	hosto03_Map,
	{hosto03_Pal},

	43200,
	{1536}
};
