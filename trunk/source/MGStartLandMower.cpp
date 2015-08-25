#include "MGStartLandMower.hpp"


MGStartLandMower::MGStartLandMower(){

	state = false;
	Sprite* starter_sprite = new Sprite(minijeuTondeuselevier_Sprite, minijeuTondeuselevier_Pal, 1, 0, 16, 16, OBJ_SIZE_16X16);
	starter = new SceneElement(starter_sprite, "levier", 16, 16, 5000, 5000, true);
	bgminigame0 = NULL;
	posX_initiale_starter = 98;
	posY_initiale_starter = 122;
	nb_start_to_win = 3;
	nb_start = 0;
}

void MGStartLandMower::launch(){
	PA_OutputText(1,1,1,"MINI GAME NUMBER ONE       ");
	state = 1;
	bgminigame0 = new BackGround(0, minijeuTondeuseBG);
	starter->setX(posX_initiale_starter);
	starter->setY(posY_initiale_starter);
}

void MGStartLandMower::draw(){

	if ( Stylus.Held && PA_SpriteTouched(starter->getSprite()->getSpriteNumber()) ){
		if ( Stylus.Y > posY_initiale_starter && Stylus.Y < posY_initiale_starter+27 ){
			starter->setY(Stylus.Y);
		}
		if ( Stylus.X > posX_initiale_starter && Stylus.X < posX_initiale_starter+5 ){
			starter->setX(Stylus.X);
		}
	}else{
		if ( starter->getX() != posX_initiale_starter ){
			if ( starter->getX() > posX_initiale_starter )
				starter->setX(starter->getX()-1);
			else if ( starter->getX() < posX_initiale_starter )
				starter->setX(starter->getX()+1);
		}
		if ( starter->getY() != posY_initiale_starter ){
			if ( starter->getY() > posY_initiale_starter )
				starter->setY(starter->getY()-1);
			else
				starter->setY(starter->getY()+1);
		}
	}
		
}

void MGStartLandMower::actionStylus(){

	if(Stylus.Released){
		if ( Stylus.Y > posY_initiale_starter+27 ){
			++nb_start;
			PA_OutputText(1,1,1,"MINI GAME NUMBER ONE  x %d   ",nb_start);
		}
	}
}

void MGStartLandMower::update(){
	if ( state ){
		actionStylus();
		draw();
	}
	if ( nb_start == nb_start_to_win ){
		delete(bgminigame0);
		starter->setVisible(0);
		starter->setX(260);
		this->validate = true;
		state = 0;
		nb_start = 0;
		
	}
}
