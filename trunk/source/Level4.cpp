#include "Level4.hpp"
#include "all_gfx.h"

void Level4::init(){
	// Ajout des éléments cliquables
	// ***********************************************************************
	Sprite* voiture = new Sprite(pikup_Sprite, pikup_Pal, 1, 0, 64, 64, OBJ_SIZE_64X64);
	this->addClickableElement(new ClickableElement(voiture, "pickup", 64, 64, 187, 80, true, "un pickup"));
	
	// ***********************************************************************

	// Ajout des interactions
	// ***********************************************************************
	this->getClickableElement("pickup")->addInteraction(new Interaction("conduire_pickup", 0, "Faire le plein et GO"));

	// ***********************************************************************

	// Ajout des mini games
	// ***********************************************************************
	currentMiniGame = new MGRecoltColza();

	// ***********************************************************************

}

void Level4::update(){
	Scene::update();

	if ( Stylus.Newpress && PA_StylusInZone( 125,40, 170, 100) && !currentMiniGame->getState() && !currentMiniGame->IsValidate()){
		clearScene();
		currentMiniGame->launch();
	}

	if ( currentMiniGame->IsValidate() ){
		getClickableElement("pickup")->getInteraction("conduire_pickup")->setState(1);
		currentMiniGame->setValidate(0);
	}


	if ( getClickableElement("pickup")->getInteraction("conduire_pickup")->getStatus() ){
		getClickableElement("pickup")->setStatus(1);
	}

	if ( getClickableElement("pickup")->getStatus()){
		if ( getClickableElement("pickup")->getY() > -10 ){
			getClickableElement("pickup")->setY(getClickableElement("pickup")->getY()-1);
		}else{
			finished = 1;
			PA_OutputText(1, 5, 20, "Sortie atteinte !\n");
		}
	}


	for(int i=0; i<(int)elementsList.size(); i++){
		elementsList[i]->draw();
	}
	for(int j=0; j<(int)clickableElementsList.size(); j++){
		clickableElementsList[j]->draw();
	}

}