#include <string>
#include "MiniGame.hpp"
#ifndef MG_RECOLT_COLZA_CLASS
#define MG_RECOLT_COLZA_CLASS
/**
 * \file MGRecoltColza.hpp
 * \class MGRecoltColza
 * \brief Sub-class of Sprite.
 * \author TIFF
 *
 * 
 *
 */
class MGRecoltColza : public MiniGame{

	public :
		BackGround* bgminigame0;
		int nb_cut;
		//! Constructor
		MGRecoltColza();

		//! Destructor
		virtual ~MGRecoltColza(){
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


#endif	// MG_RECOLT_COLZA_CLASS
