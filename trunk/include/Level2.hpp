#ifndef LEVEL2_CLASS
#define LEVEL2_CLASS

#include "Scene.hpp"
#include "State.hpp"

class Level2 : public Scene{
	public :
		Level2(std::string introText, PA_BgStruct bg0, PA_BgStruct bg1, Character* heroe) : Scene(introText, bg0, bg1, heroe){	
			init();
		};
		void init();
		virtual void update();
};


#endif	// LEVEL2_CLASS