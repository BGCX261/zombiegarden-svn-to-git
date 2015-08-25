#ifndef SMART_ZOMBIE_AI_CLASS
#define SMART_ZOMBIE_AI_CLASS

#include "AI.hpp"
#include "Sprite.hpp"
#include "Level1bis.hpp"

/**
 * \file SmartZombieAI.hpp
 * \class SmartZombieAI
 * \brief An artificial intelligence of a sprite in the game
 * \author JB
 *
 * This is the intelligence of a smart zombie
 *
 */
class SmartZombieAI : public AI{
	private :
		int counter;
		Level1bis* l1b;
		s8 astar(u16 width, u16 height);

	public :
		//! Constructor
		SmartZombieAI(int x, int y, Level1bis* l1b): AI(x,y){
			counter = 0;
			this->l1b = l1b;
		};
		//! Destructor
		~SmartZombieAI(){};

		//! Executes the ai
		void think();
};


#endif	// SMART_ZOMBIE_AI_CLASS