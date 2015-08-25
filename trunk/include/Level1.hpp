#ifndef LEVEL1_CLASS
#define LEVEL1_CLASS

#include "Scene.hpp"
#include "State.hpp"

class Level1 : public Scene{
	
	public :
		Level1(std::string introText, PA_BgStruct bg0, PA_BgStruct bg1, Character* heroe) : Scene(introText, bg0, bg1, heroe){
			init();
		};
		void init();
		virtual void update();
};


#endif	// LEVEL1_CLASS