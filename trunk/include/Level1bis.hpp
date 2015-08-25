#ifndef LEVEL1BIS_CLASS
#define LEVEL1BIS_CLASS

#include <PA9.h>
#include "Scene.hpp"
#include "State.hpp"
#include "Character.hpp"

//corn maze escape
class Level1bis : public Scene{
	private :
		//! The maze
		u16** labyrinth;
		//! List of the elements of the scene
		std::vector<Character*> enemiesList;

		void initMaze();

	public :
		Level1bis(std::string introText, PA_BgStruct bg0, PA_BgStruct bg1, Character* heroe) : Scene(introText, bg0, bg1, heroe){
			init();
		};
		~Level1bis();
		void init();
		virtual void update();

		u16** getMaze(){return labyrinth;};
		std::vector<Character*> getEnemiesList(){return enemiesList;};
};


#endif	// LEVEL1BIS_CLASS