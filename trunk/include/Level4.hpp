#ifndef LEVEL4_CLASS
#define LEVEL4_CLASS

#include "Scene.hpp"
#include "State.hpp"

class Level4 : public Scene{
	public :
		Level4(std::string introText, PA_BgStruct bg0, PA_BgStruct bg1, Character* heroe) : Scene(introText, bg0, bg1, heroe){	
			init();
		};
		void init();
		virtual void update();
};


#endif	// LEVEL4_CLASS