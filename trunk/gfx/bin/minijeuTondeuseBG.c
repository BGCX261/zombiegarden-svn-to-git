#include <PA_BgStruct.h>

extern const char minijeuTondeuseBG_Tiles[];
extern const char minijeuTondeuseBG_Map[];
extern const char minijeuTondeuseBG_Pal[];

const PA_BgStruct minijeuTondeuseBG = {
	PA_BgNormal,
	256, 192,

	minijeuTondeuseBG_Tiles,
	minijeuTondeuseBG_Map,
	{minijeuTondeuseBG_Pal},

	47744,
	{1536}
};
