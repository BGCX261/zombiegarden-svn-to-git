#include "Level5.hpp"
#include "all_gfx.h"

void Level5::init(){
	// Ajout des �l�ments cliquables
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