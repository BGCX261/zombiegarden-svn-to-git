#include "SceneElement.hpp"

SceneElement::SceneElement(std::string name, int width, int height, int x, int y, bool visible){
	this->name = name;
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	this->visible = visible;
	this->status = 0;
	this->state = false;
}

SceneElement::SceneElement(Sprite* sprite, std::string name, int width, int height, int x, int y, bool visible){
	this->name = name;
	this->sprite = sprite;
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	this->visible = visible;
	this->status = 0;
	this->state = false;
	draw();
}

void SceneElement::addInteraction(Interaction* interaction){
	interactionsList.push_back(interaction);
}

void SceneElement::draw(){
	
	if(this->visible){
		PA_SetSpriteXY(0, sprite->getSpriteNumber(), x - PA_GetSpriteLx(0, sprite->getSpriteNumber())/2, y - PA_GetSpriteLy(0, sprite->getSpriteNumber())/2);
		if ( this->getState() && !this->getStatus()){
			int cpt = 0;
			for ( std::vector<Interaction*>::iterator it = interactionsList.begin(); it != interactionsList.end(); ++it ){
				if ( (*it)->getState() ){
					//we draw the mini menu
					PA_BoxText(0,((x+width/2)*31)/255, (y*23)/191+cpt, 31, 23, (*it)->getText().c_str(), 100);
					(*it)->setX(x+width/2);
					(*it)->setY(y);
					cpt++;
				}
			}
		}
	}
	else{
		PA_SetSpriteXY(0, sprite->getSpriteNumber(), 5000, 5000);
	
	}
	
}

Interaction* SceneElement::getInteraction(std::string name){
	for(unsigned int i=0; i<interactionsList.size(); i++){
		if(interactionsList[i]->getName().compare(name) == 0){
			return interactionsList[i];
		}
	}

	return NULL;
}

void SceneElement::setX(int x){
	this->x = x;
	PA_SetSpriteXY(0, sprite->getSpriteNumber(), x-width/2, y-height/2);
}

void SceneElement::setY(int y){
	this->y = y;
	PA_SetSpriteXY(0, sprite->getSpriteNumber(), x-width/2, y-height/2);
}

void SceneElement::setPosition(int x, int y){
	this->x = x;
	this->y = y;
	PA_SetSpriteXY(0, sprite->getSpriteNumber(), x-width/2, y-height/2);
}

void SceneElement::setSprite(Sprite* sprite){
	PA_DeleteSprite(0,this->sprite->getSpriteNumber());
	this->sprite = sprite;
}