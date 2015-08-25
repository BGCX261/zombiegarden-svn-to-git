#include "Character.hpp"

Character::Character(AnimatedSprite* sprite, std::string name, int width, int height, int x, int y){
	this->name = name;
	this->sprite = sprite;
	this->width = width;
	this->height = height;
	this->x = (x) << 8;
	this->y = (y) << 8;
	this->ai = NULL;
	PA_SetSpriteXY(0, sprite->getSpriteNumber(), x - PA_GetSpriteLx(0, sprite->getSpriteNumber())/2, y - PA_GetSpriteLy(0, sprite->getSpriteNumber())/2);
	sprite->enableRotation();
}

void Character::update(){
	if(ai == NULL){// the hero
		if(Stylus.Held && PA_Distance(x>>8, y>>8, Stylus.X, Stylus.Y) > 0.5){
			if(!sprite->isPlaying()){
				sprite->startAnimation();
			}

			int angle = PA_GetAngle(x>>8, y>>8, Stylus.X, Stylus.Y);
			sprite->rotate(angle-120); // Tourne le personnage dans la bonne direction
				
			x += PA_Cos(angle);
			y -= PA_Sin(angle);
			
			setPosition8b(x, y);
		}
		else{
			sprite->stopAnimation();
		}
	}else{// an intelligent character
		ai->think();
		
		if(x != ai->getX() && y != ai->getY()){
			if(!sprite->isPlaying()){
				sprite->startAnimation();
			}
			x = ai->getX();
			y = ai->getY();
			setPosition(x,y);
		}else{
			sprite->stopAnimation();
		}
	}
}

void Character::setX(int x){
	this->x = x;
	PA_SetSpriteXY(0, sprite->getSpriteNumber(), (x>>8)-width/2, (y>>8)-height/2);
}

void Character::setY(int y){
	this->y = y;
	PA_SetSpriteXY(0, sprite->getSpriteNumber(), (x>>8)-width/2, (y>>8)-height/2);
}

void Character::setPosition8b(int x, int y){
	this->x = x;
	this->y = y;
	PA_SetSpriteXY(0, sprite->getSpriteNumber(), (x>>8)-width/2, (y>>8)-height/2);
}

void Character::setPosition(int x, int y){
	this->x = x<<8;
	this->y = y<<8;
	PA_SetSpriteXY(0, sprite->getSpriteNumber(), x-width/2, y-height/2);
}

void Character::setSprite(AnimatedSprite* sprite){
	PA_DeleteSprite(0,this->sprite->getSpriteNumber());
	this->sprite = sprite;
}