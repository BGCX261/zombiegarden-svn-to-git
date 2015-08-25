#ifndef LEVEL5_CLASS
#define LEVEL5_CLASS

#include "Scene.hpp"
#include "State.hpp"

class Level5 : public Scene{
	public :
		Level5(std::string introText, PA_BgStruct bg0, PA_BgStruct bg1, Character* heroe) : Scene(introText, bg0, bg1, heroe){	
			init();
		};
		void init();
		virtual void update();
};


#endif	// LEVEL5_CLASS