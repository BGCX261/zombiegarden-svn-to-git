#ifndef PAGEACCUEIL_CLASS
#define PAGEACCUEIL_CLASS

#include "Scene.hpp"
#include "State.hpp"

class PageAccueil : public Scene{
	
	public :
		PageAccueil(std::string introText, PA_BgStruct bg0, PA_BgStruct bg1, Character* heroe) : Scene(introText, bg0, bg1, heroe){
			
		};
		virtual void update();
};


#endif	// PAGEACCUEIL_CLASS