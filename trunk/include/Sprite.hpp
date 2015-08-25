// Include PAlib so that you can use it
#include <PA9.h>

#include <string>

#ifndef SPRITE_CLASS
#define SPRITE_CLASS
/**
 * \file Sprite.hpp
 * \class Sprite
 * \brief Sprite container
 * \author Vink
 *
 * The purpose of this class is to simplify the use of the sprites
 *
 */
class Sprite{
	protected :
		//! Number of sprites wich are implemented
		static int totalNumber;
		//! Name of the sprite
		const unsigned char* spriteName;
		//! Name of the palette
		const short unsigned int* paletteName;
		//! Id of the sprite
		unsigned int spriteNumber;
		//! Id of the palette
		unsigned int paletteNumber;
		//! Unused
		bool state;
		//! Indicates if the sprite is rotable or not
		bool isRotable;
		//! Angle of rotation
		int rotation;
		//! position en x
		int x;
		//!position en y;
		int y;
		//!\param width Width of the sprite
		int width;
		//!\param height Height of the sprite
		int height;
	public :
		//! Constructor
		//!\param spriteName Name of the sprite
		//!\param paletteName Name of the palette
		//!\param state Unused
		//!\param rotation Angle of rotation of the sprite
		//!\param x Position on axe X
		//!\param y Position on axe Y
		//!\param width Width of the sprite
		//!\param height Height of the sprite
		Sprite(const unsigned char* spriteName, const short unsigned int* paletteName, bool state, int rotation, int x, int y, int width, int height);

		//! Destructor
		~Sprite(){
			PA_DeleteSprite(0, spriteNumber);
		};

		//! Enables the rotation on this sprite
		void enableRotation();
		//! Rotates the sprite from 0 to angle
		void rotate(int angle);

		//Getters and Setters
		//! Switch the state of the interaction
		void switchState();
		//! Returns the name of the sprite
		inline const unsigned char* getSpriteName(){return spriteName;};
		//! Returns the id of the sprite
		inline unsigned int getSpriteNumber(){return spriteNumber;};
		//! Returns the state of the sprite (unused)
		inline bool getState(){return state;};
		//! Returns the x prosition of the sprite
		inline int getX(){return PA_GetSpriteX(0,spriteNumber); }
		//! Returns the y prosition of the sprite
		inline int getY(){return PA_GetSpriteY(0,spriteNumber); }
};


#endif	// SPRITE_CLASS