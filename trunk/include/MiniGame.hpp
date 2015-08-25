#include <string>
#include "Scene.hpp"
#include "all_gfx.h"

#ifndef MINI_GAME_CLASS
#define MINI_GAME_CLASS
/**
 * \file MiniGame.hpp
 * \class MiniGame
 * \brief Sub-class of Sprite.
 * \author Baaaap
 *
 * 
 *
 */
class MiniGame{
	protected :
		//! State of the game
		bool state;
		//! Tells the player what's the purpose of the mini game
		std::string instruction;
		//! State of the game
		bool validate;

	public :
		//! Constructor
		MiniGame(){

		};

		//! Destructor
		virtual ~MiniGame(){
			
		};

		//! 
		virtual void launch()=0;
		//! 
		virtual void draw()=0;
		//! 
		virtual void actionStylus()=0;
		//!
		bool getState(){return state;};
		//!
		virtual void update()=0;
		//!
		bool IsValidate(){ return validate;};
		//!
		void setValidate(bool value){ validate = value;};
};


#endif	// MINI_GAME_CLASS