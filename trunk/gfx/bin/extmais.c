#include <PA_BgStruct.h>

extern const char extmais_Tiles[];
extern const char extmais_Map[];
extern const char extmais_Pal[];

const PA_BgStruct extmais = {
	PA_BgNormal,
	256, 192,

	extmais_Tiles,
	extmais_Map,
	{extmais_Pal},

	49152,
	{1536}
};
