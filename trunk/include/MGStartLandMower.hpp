#include <string>
#include "MiniGame.hpp"
#ifndef MG_START_LANDMOWER_CLASS
#define MG_START_LANDMOWER_CLASS
/**
 * \file MGStartLandMower.hpp
 * \class MGStartLandMower
 * \brief Sub-class of Sprite.
 * \author NATH TIFF
 *
 * 
 *
 */
class MGStartLandMower : public MiniGame{

	public :
		SceneElement* starter;
		BackGround* bgminigame0;
		int posX_initiale_starter;
		int posY_initiale_starter;
		int nb_start_to_win;
		int nb_start;

		//! Constructor
		MGStartLandMower();

		//! Destructor
		virtual ~MGStartLandMower(){
			//delete(bgminigame0);
		};

		//! 
		virtual void launch();
		//! 
		virtual void draw();
		//! 
		virtual void actionStylus();
		//!
		virtual void update();
};


#endif	// MG_START_LANDMOWER_CLASS
