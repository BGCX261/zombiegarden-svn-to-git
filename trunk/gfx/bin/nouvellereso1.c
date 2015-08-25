#include <PA_BgStruct.h>

extern const char nouvellereso1_Tiles[];
extern const char nouvellereso1_Map[];
extern const char nouvellereso1_Pal[];

const PA_BgStruct nouvellereso1 = {
	PA_BgNormal,
	256, 192,

	nouvellereso1_Tiles,
	nouvellereso1_Map,
	{nouvellereso1_Pal},

	46976,
	{1536}
};
