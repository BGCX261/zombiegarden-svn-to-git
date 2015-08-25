#include <PA_BgStruct.h>

extern const char minijeuColzaBG2_Tiles[];
extern const char minijeuColzaBG2_Map[];
extern const char minijeuColzaBG2_Pal[];

const PA_BgStruct minijeuColzaBG2 = {
	PA_BgNormal,
	256, 192,

	minijeuColzaBG2_Tiles,
	minijeuColzaBG2_Map,
	{minijeuColzaBG2_Pal},

	37888,
	{1536}
};
