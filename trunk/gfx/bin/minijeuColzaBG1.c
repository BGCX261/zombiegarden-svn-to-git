#include <PA_BgStruct.h>

extern const char minijeuColzaBG1_Tiles[];
extern const char minijeuColzaBG1_Map[];
extern const char minijeuColzaBG1_Pal[];

const PA_BgStruct minijeuColzaBG1 = {
	PA_BgNormal,
	256, 192,

	minijeuColzaBG1_Tiles,
	minijeuColzaBG1_Map,
	{minijeuColzaBG1_Pal},

	37888,
	{1536}
};
