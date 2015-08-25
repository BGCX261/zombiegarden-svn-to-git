#include "PageAccueil.hpp"
#include "all_gfx.h"

void PageAccueil::update(){
	if ( Stylus.Held && Stylus.X>10 && Stylus.X<100 && Stylus.Y>100 && Stylus.Y<150){
		finished = 1;
	}
}