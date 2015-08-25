#ifndef CHARACTER_CLASS
#define CHARACTER_CLASS

#include "AnimatedSprite.hpp"
#include "AI.hpp"

/**
 * \file Character.hpp
 * \class Character
 * \brief Character container
 * \author Vink
 *
 * The purpose of this class is to manage the characters
 *
 */
class Character{
	protected :
		//! The visual of the character
		AnimatedSprite* sprite;
		//! Name of the character
		std::string name;
		//! The width of the character
		int width;
		//! The height of the character
		int height;
		//! Position on axe X
		int x;
		//! Position on axe Y
		int y;
		//! Artificial intelligence
		AI* ai;

	public :
		//! Constructor
		//!\param sprite Visual of the character
		//!\param width Width of the character
		//!\param height Height of the character
		//!\param x Position on axe X
		//!\param y Position on axe Y
		Character(AnimatedSprite* sprite, std::string name, int width, int height, int x, int y);

		//! Destructor
		~Character(){
			delete(sprite);
			delete(ai);
		}

		void update();

		// Getters and Setters
		//! Returns the name of the character
		std::string getName(){return name;};
		//! Returns the sprite of the character
		AnimatedSprite* getSprite(){return sprite;};
		//! Returns the position on the axe X
		int getX(){return x>>8;};
		//! Returns the position on the axe Y
		int getY(){return y>>8;};
		//! Returns the position on the axe X (8bits mode)
		int getX8b(){return x;};
		//! Returns the position on the axe Y (8bits mode)
		int getY8b(){return y;};
		//! Returns the width of the character
		int getWidth(){return width;};
		//! Returns the height of the character
		int getHeight(){return height;};
		//! Sets the position on the axe X
		void setX(int x);
		//! Sets the position on the axe Y
		void setY(int y);
		//! Sets the position (8bits mode)
		void setPosition8b(int x, int y);
		//! Sets the position
		void setPosition(int x, int y);
		//! Sets the sprite of the character
		void setSprite(AnimatedSprite* sprite);
		//! Sets the width of the character
		void setWidth(int w){width = w;};
		//! Sets the height of the character
		void setHeight(int h){height = h;};
		//! Sets the AI of the character
		void setAI(AI* ai){this->ai = ai;};
		//! Gets the AI of the character;
		AI* getAI(){return ai;};
};


#endif	// CHARACTER_CLASS