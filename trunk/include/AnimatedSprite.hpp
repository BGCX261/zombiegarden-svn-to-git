#include "Sprite.hpp"

#ifndef ANIMATED_SPRITE_CLASS
#define ANIMATED_SPRITE_CLASS
/**
 * \file AnimatedSprite.hpp
 * \class AnimatedSprite
 * \brief Sub-class of Sprite. Specialized for animated sprites.
 * \author Vink
 *
 * The purpose of this class is to simplify the use of the animated sprites
 *
 */
class AnimatedSprite: public Sprite {
	private :
		//! Number of frames in the animation
		int nbFrames;
		//! Indicates if the animation is playing
		bool playing;

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
		//!\param nbFrames Number of frames in the animation
		AnimatedSprite(const unsigned char* spriteName, const short unsigned int* paletteName, bool state, int rotation, int x, int y, int width, int height, int nbFrames) : Sprite(spriteName, paletteName, state, rotation, x, y, width, height){
			this->nbFrames = nbFrames;
			this->playing = 0;
		};

		//! Destructor
		~AnimatedSprite(){
			PA_DeleteSprite(0, spriteNumber);
		};

		//! Starts the animation between two indexes
		void startAnimation(int beginIndex, int endIndex);
		//! Starts the complete animation
		void startAnimation(int nbLoop=0);
		//! Stops the animation
		void stopAnimation();
		//! Indicates if the animation is playing
		bool isPlaying(){return playing;};
};


#endif	// ANIMATED_SPRITE_CLASS