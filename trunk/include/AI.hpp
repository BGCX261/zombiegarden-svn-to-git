#ifndef AI_CLASS
#define AI_CLASS
/**
 * \file AI.hpp
 * \class AI
 * \brief An artificial intelligence of asprite in the game
 * \author JB
 *
 * This an intelligence that scene element sprite can own
 *
 */

class AI{
	protected :
		//! the  of x position of the character
		int x;
		//! the  of y position of the character
		int y;

	public :
		//! Constructor
		AI(int x, int y){
			this->x = x;
			this->y = y;
		};
		//! Destructor
		~AI(){};

		//! Executes the ai -> finds the new position of the character
		virtual void think(){};

		//! Gets the x position
		int getX(){return x;};
		//! Gets the y position
		int getY(){return y;};
};


#endif	// AI_CLASS