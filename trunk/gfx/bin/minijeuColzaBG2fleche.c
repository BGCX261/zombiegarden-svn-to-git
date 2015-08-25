#include <PA_BgStruct.h>

extern const char minijeuColzaBG2fleche_Tiles[];
extern const char minijeuColzaBG2fleche_Map[];
extern const char minijeuColzaBG2fleche_Pal[];

const PA_BgStruct minijeuColzaBG2fleche = {
	PA_BgNormal,
	256, 192,

	minijeuColzaBG2fleche_Tiles,
	minijeuColzaBG2fleche_Map,
	{minijeuColzaBG2fleche_Pal},

	37888,
	{1536}
};
