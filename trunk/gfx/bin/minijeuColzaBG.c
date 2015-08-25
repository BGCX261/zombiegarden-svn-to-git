#include <PA_BgStruct.h>

extern const char minijeuColzaBG_Tiles[];
extern const char minijeuColzaBG_Map[];
extern const char minijeuColzaBG_Pal[];

const PA_BgStruct minijeuColzaBG = {
	PA_BgNormal,
	256, 192,

	minijeuColzaBG_Tiles,
	minijeuColzaBG_Map,
	{minijeuColzaBG_Pal},

	37888,
	{1536}
};
