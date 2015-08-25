#include <PA_BgStruct.h>

extern const char minijeuColzaBGdbutfleche_Tiles[];
extern const char minijeuColzaBGdbutfleche_Map[];
extern const char minijeuColzaBGdbutfleche_Pal[];

const PA_BgStruct minijeuColzaBGdbutfleche = {
	PA_BgNormal,
	256, 192,

	minijeuColzaBGdbutfleche_Tiles,
	minijeuColzaBGdbutfleche_Map,
	{minijeuColzaBGdbutfleche_Pal},

	38016,
	{1536}
};
