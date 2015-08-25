#include "AnimatedSprite.hpp"

void AnimatedSprite::startAnimation(int beginIndex, int endIndex){
	PA_StartSpriteAnim(	0, // screen
						this->spriteNumber, // sprite number
						beginIndex, // first frame
						endIndex, // last frame
						5); // Speed, set to 5 frames per second
	playing = 1;
}

void AnimatedSprite::startAnimation(int nbLoop){
	PA_StartSpriteAnimEx(	0, // screen
						this->spriteNumber, // sprite number
						0, // first frame
						this->nbFrames - 1, // last frame
						5,
						ANIM_LOOP,
						nbLoop); // Speed, set to 5 frames per second
	playing = 1;
}

void AnimatedSprite::stopAnimation(){
	PA_StopSpriteAnim(0, this->spriteNumber);
	playing = 0;
}