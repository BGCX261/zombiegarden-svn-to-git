#include <PA_BgStruct.h>

extern const char accueil_Tiles[];
extern const char accueil_Map[];
extern const char accueil_Pal[];

const PA_BgStruct accueil = {
	PA_BgNormal,
	256, 192,

	accueil_Tiles,
	accueil_Map,
	{accueil_Pal},

	45568,
	{1536}
};
