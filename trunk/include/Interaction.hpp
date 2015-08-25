#include <string>
#include "Sprite.hpp"

#ifndef INTERACTION_CLASS
#define INTERACTION_CLASS
/**
 * \file Interaction.hpp
 * \class Interaction
 * \brief An interaction in the game
 * \author Vink
 *
 * This is an action that the player can execute in the game
 *
 */
class Interaction{
	private :
		//! Name of the interaction
		std::string name;
		//! Indicates if the interaction is available or not
		bool state;
		//! Indicates if the interaction is available or not
		bool status;
		//! Text to display in the game
		std::string text;
		//! Positions of the interaction
		int x;
		int y;
		int width;
		int height;
	public :
		//! Backgroung of the text
		Sprite* sprite;
	public :
		//! Constructor
		//!\param name Name of the interaction
		//!\param state State of the interaction (enabled or disabled)
		//!\param text Text to display in the game
		Interaction(std::string name, bool state, std::string text);

		//! Executes actions to execute when the interaction is activated
		void execute();
		
		//Getters and Setters
		//! Switchs the state of the interaction
		void switchState();
		//! Sets the state of the interaction
		void setState(bool value){state = value;};
		//! Sets the state of the interaction
		void setStatus(bool value){status = value;};
		//! Returns the name of the interaction
		std::string getName(){return name;};
		//! Returns the state of the interaction (enabled or disabled)
		bool getState(){return state;};
		//! Returns the state of the interaction (enabled or disabled)
		bool getStatus(){return status;};
		//! Returns the text to display for the interaction in the game
		std::string getText(){return text;};
		//! Returns the text to display for the interaction in the game
		Sprite* getSprite(){return sprite;};
		//! Sets the position of the interaction
		void setX(int newx){this->x = newx;/*PA_SetSpriteX(0, sprite->getSpriteNumber(), (this->x>>8)-width/2);*/};
		void setY(int newy){this->y = newy;/*PA_SetSpriteY(0, sprite->getSpriteNumber(), (this->y>>8)-height/2);*/};
		//! Sets the position of the interaction
		int getX(){return x;};
		int getY(){return y;};

};

#endif	// INTERACTION_CLASS