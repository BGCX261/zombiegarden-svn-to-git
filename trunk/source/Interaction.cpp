#include "Interaction.hpp"
#include "all_gfx.h"

Interaction::Interaction(std::string name, bool available, std::string text){
	this->name = name;
	this->state = available;
	this->text = text;
	this->width = 64;
	this->height = 32;
	this->x = 250;
	this->y = 20;
	//Sprite* sprite = new Sprite(bouton_Sprite, bouton_Pal, 1, 0, x, y, OBJ_SIZE_64X32);
	//this->sprite = sprite;
}

void Interaction::switchState(){		// switch the state of the interaction
	if(state == 0){
		state = 1;
	}
	else{
		state = 0;
	}
}

void Interaction::execute(){			// actions to execute when the interaction is activated
	// Code to write
	
}



