#include <PA_BgStruct.h>

extern const char minijeuColzaBG1fleche_Tiles[];
extern const char minijeuColzaBG1fleche_Map[];
extern const char minijeuColzaBG1fleche_Pal[];

const PA_BgStruct minijeuColzaBG1fleche = {
	PA_BgNormal,
	256, 192,

	minijeuColzaBG1fleche_Tiles,
	minijeuColzaBG1fleche_Map,
	{minijeuColzaBG1fleche_Pal},

	37888,
	{1536}
};
