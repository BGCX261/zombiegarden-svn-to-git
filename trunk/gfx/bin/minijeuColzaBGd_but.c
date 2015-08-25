#include <PA_BgStruct.h>

extern const char minijeuColzaBGd_but_Tiles[];
extern const char minijeuColzaBGd_but_Map[];
extern const char minijeuColzaBGd_but_Pal[];

const PA_BgStruct minijeuColzaBGd_but = {
	PA_BgNormal,
	256, 192,

	minijeuColzaBGd_but_Tiles,
	minijeuColzaBGd_but_Map,
	{minijeuColzaBGd_but_Pal},

	38016,
	{1536}
};
