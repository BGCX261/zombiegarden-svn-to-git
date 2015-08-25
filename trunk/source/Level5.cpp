#include "Level5.hpp"
#include "all_gfx.h"

void Level5::init(){
	// Ajout des éléments cliquables
	// ***********************************************************************


	// ***********************************************************************

	// Ajout des interactions
	// ***********************************************************************

}

void Level5::update(){
	Scene::update();

	if ( Stylus.Released )
		finished = 1;
}