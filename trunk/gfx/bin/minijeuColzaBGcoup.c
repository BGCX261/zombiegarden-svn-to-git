#include <PA_BgStruct.h>

extern const char minijeuColzaBGcoup_Tiles[];
extern const char minijeuColzaBGcoup_Map[];
extern const char minijeuColzaBGcoup_Pal[];

const PA_BgStruct minijeuColzaBGcoup = {
	PA_BgNormal,
	256, 192,

	minijeuColzaBGcoup_Tiles,
	minijeuColzaBGcoup_Map,
	{minijeuColzaBGcoup_Pal},

	37888,
	{1536}
};
