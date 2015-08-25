#include "Sprite.hpp"

int Sprite::totalNumber = 0;

Sprite::Sprite(const unsigned char* spriteName, const short unsigned int* paletteName, bool state, int rotation, int x, int y, int width, int height){
	this->spriteName = spriteName;
	this->paletteName = paletteName;
	this->spriteNumber = totalNumber;
	this->paletteNumber = totalNumber;
	this->state = state;
	this->rotation = rotation;
	isRotable = 0;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	// loads the palette of the sprite
	PA_LoadSpritePal(	0,						// Screen
						totalNumber,			// Palette number
						(void*)paletteName);	// Palette name

	// loads the sprite and displays it
	PA_CreateSprite(	0,						// Screen
						totalNumber,			// Sprite number
						(void*)spriteName,		// Sprite name
						width, height,			// Sprite size
						1,						// 256 color mode
						totalNumber,			// Sprite palette number
						x, y);					// X and Y position on the screen

	/*PA_SetSpriteMode(	0, // ecran
 						totalNumber, // Sprite
						1); // Alphablending

	// Activation de l'alpha-blending
	PA_EnableSpecialFx(	0, // ecran
						SFX_ALPHA, // Mode Alpha blending
						0, // Nothing
						SFX_BG0 | SFX_BG1 | SFX_BG2 | SFX_BG3 | SFX_BD); // Tout normal

	PA_SetSFXAlpha(		0, // Ecran
						0, // Niveau alpha, 0-15
						15); // Laisser à 15
*/
		totalNumber++;
}

void Sprite::switchState(){		// switch the state of the interaction
	if(state == 0){
		state = 1;
	}
	else{
		state = 0;
	}
}

void Sprite::enableRotation(){
	isRotable = 1;

	PA_SetSpriteRotEnable(	0,	// screen
							spriteNumber,	// sprite number
							spriteNumber);	// rotset number. You have 32 rotsets (0-31) per screen. 2 sprites with*
											// *the same rotset will be zoomed/rotated the same way...

}

void Sprite::rotate(int angle){
	if(isRotable == 1){
		// Fast function for rotations without zoom...
		PA_SetRotsetNoZoom(	0,				//screen
							spriteNumber,	// rotset
							angle);			// angle, from 0 to 511
	}
}