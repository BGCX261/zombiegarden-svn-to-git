#include "Level1.hpp"
#include "all_gfx.h"

void Level1::init(){

	Sprite* planche_mur = new Sprite(lvl1_planche_mur_Sprite, lvl1_planche_mur_Pal, 1, 0, 32, 16, OBJ_SIZE_32X16);
	this->addClickableElement(new ClickableElement(planche_mur, "planche_mur", 32, 16, 70, 180, true, "Une planche en bois"));
	
	Sprite* tondeuse = new Sprite(lvl1_tondeuse_Sprite, lvl1_tondeuse_Pal, 1, 0, 32, 32, OBJ_SIZE_32X32);
	this->addClickableElement(new ClickableElement(tondeuse, "tondeuse", 32, 32, 127, 140, true, "Ma fidèle tondeuse"));

	Sprite* planche_sol = new Sprite(lvl1_planche_sol_Sprite, lvl1_planche_sol_Pal, 1, 0, 32, 32, OBJ_SIZE_32X32);
	this->addElement(new SceneElement(planche_sol, "planche_sol", 32, 32, 127, 100, true));
	getElement("planche_sol")->setVisible(0);

	Sprite* porte = new Sprite(lvl1_porte_Sprite, lvl1_porte_Pal, 1, 0, 64, 32, OBJ_SIZE_64X32);
	this->addClickableElement(new ClickableElement(porte, "porte", 64, 32, 127, 9, true, "La porte de sortie"));
	
	Sprite* engrais = new Sprite(lvl1_etagere_Sprite, lvl1_etagere_Pal, 1, 0, 32, 64, OBJ_SIZE_32X64);
	this->addClickableElement(new ClickableElement(engrais, "engrais", 32, 64, 17, 152, true, "De l'engrais"));
	
	Sprite* essence = new Sprite(lvl1_essence_txt_Sprite, lvl1_essence_txt_Pal, 1, 0, 16, 16, OBJ_SIZE_16X16);
	this->addClickableElement(new ClickableElement(essence, "essence", 16, 16, 210, 150, true, "De l'essence"));
	// ***********************************************************************

	// Ajout des interactions
	// ***********************************************************************
	this->getClickableElement("planche_mur")->addInteraction(new Interaction("prendre_planche", 1, "Utiliser"));

	this->getClickableElement("porte")->addInteraction(new Interaction("mettre_engrais", 0, "Badigeonner"));
	
	this->getClickableElement("engrais")->addInteraction(new Interaction("prendre_engrais", 1, "Prendre"));
	
	this->getClickableElement("essence")->addInteraction(new Interaction("prendre_essence", 1, "Prendre"));
	
	this->getClickableElement("tondeuse")->addInteraction(new Interaction("allumer", 0, "Allumer"));
	this->getClickableElement("tondeuse")->addInteraction(new Interaction("mettre_essence", 0, "Remplir"));
	// ***********************************************************************

	// Ajout des mini games
	// ***********************************************************************
	currentMiniGame = new MGStartLandMower();

	//décommentez ces deux lignes pour résoudre le niveau automatiquement
	//getElement("planche_sol")->setStatus(1);
	//getClickableElement("tondeuse")->setStatus(1);
	//getClickableElement("porte")->setStatus(1);
}

void Level1::update(){
	Scene::update();
	
	//action to place the "planche" on the hole
	if ( getClickableElement("planche_mur")->getInteraction("prendre_planche")->getStatus() ){
		getClickableElement("planche_mur")->setStatus(1);
	}
	if ( getClickableElement("planche_mur")->getStatus() ){
		if( Stylus.Released && getClickableElement("planche_mur")->getY()-getElement("planche_sol")->getY()<10 && getClickableElement("planche_mur")->getX()-getElement("planche_sol")->getX()<10 ){
			getElement("planche_sol")->setStatus(1);
			getClickableElement("planche_mur")->setVisible(0);
		}
		if ( Stylus.Held && PA_SpriteTouched(getClickableElement("planche_mur")->getSprite()->getSpriteNumber()) ){
			getClickableElement("planche_mur")->setY(Stylus.Y);
			getClickableElement("planche_mur")->setX(Stylus.X);
		}
	}

	if(getElement("planche_sol")->getStatus()){
		getElement("planche_sol")->setVisible(1);
	}

	//action to switch on the "tondeuse"
	if(getClickableElement("engrais")->getInteraction("prendre_engrais")->getStatus()){
		getClickableElement("engrais")->getInteraction("prendre_engrais")->setState(0);
		getClickableElement("engrais")->getInteraction("prendre_engrais")->setStatus(1);
		getClickableElement("porte")->getInteraction("mettre_engrais")->setState(1);
	}
	if(getClickableElement("essence")->getInteraction("prendre_essence")->getStatus()){
		getClickableElement("essence")->getInteraction("prendre_essence")->setState(0);
		getClickableElement("essence")->getInteraction("prendre_essence")->setStatus(1);
		getClickableElement("tondeuse")->getInteraction("mettre_essence")->setState(1);
	}

	if(getClickableElement("tondeuse")->getInteraction("mettre_essence")->getStatus()){
		getClickableElement("tondeuse")->getInteraction("mettre_essence")->setState(0);
		getClickableElement("tondeuse")->getInteraction("mettre_essence")->setStatus(1);
		getClickableElement("tondeuse")->getInteraction("allumer")->setState(1);
		getClickableElement("tondeuse")->getInteraction("mettre_essence")->setState(0);
	}

	if ( currentMiniGame->IsValidate() && !getClickableElement("tondeuse")->getStatus()){
		PA_OutputText(1,1,1,"                                    ");
		getClickableElement("tondeuse")->setStatus(1);
		getClickableElement("tondeuse")->setState(0);
		currentMiniGame->setValidate(0);
	}

	if ( !currentMiniGame->IsValidate() && getClickableElement("tondeuse")->getInteraction("allumer")->getStatus() ){
		clearScene();
		currentMiniGame->launch();
		getClickableElement("tondeuse")->getInteraction("allumer")->setState(0);
		getClickableElement("tondeuse")->getInteraction("allumer")->setStatus(0);
	}

	if( getClickableElement("porte")->getInteraction("mettre_engrais")->getStatus() ){
		getClickableElement("porte")->getInteraction("mettre_engrais")->setStatus(0);
		getClickableElement("porte")->setStatus(1);
		getClickableElement("porte")->setSprite(new Sprite(lvl1_porte_engrais_Sprite, lvl1_porte_engrais_Pal, 1, 0, getClickableElement("porte")->getX(), getClickableElement("porte")->getY(), OBJ_SIZE_64X32));
		//PA_SetSpriteXY(0, getClickableElement("porte")->getSprite()->getSpriteNumber(), getClickableElement("porte")->getX()-getClickableElement("porte")->getWidth()/2, getClickableElement("porte")->getY()-getClickableElement("porte")->getHeight()/2);
	}


	if( getClickableElement("tondeuse")->getStatus() ){
		getClickableElement("tondeuse")->setState(0);
		if( (PA_Distance(getClickableElement("tondeuse")->getX(), getClickableElement("tondeuse")->getY(), getClickableElement("porte")->getX(), getClickableElement("porte")->getY())) >= 100 ){
			getClickableElement("tondeuse")->setY(getClickableElement("tondeuse")->getY()-1);
		}
		else{
			getClickableElement("tondeuse")->setStatus(0);
			if(getClickableElement("porte")->getStatus()){
				getClickableElement("tondeuse")->setSprite(new AnimatedSprite(explosion_Sprite, explosion_Pal, 1, 0, getClickableElement("tondeuse")->getX(), getClickableElement("tondeuse")->getY(), OBJ_SIZE_64X64, 8));
				getClickableElement("tondeuse")->setWidth(64);
				getClickableElement("tondeuse")->setHeight(64);
				PA_SetSpriteXY(0, getClickableElement("tondeuse")->getSprite()->getSpriteNumber(), getClickableElement("tondeuse")->getX()-getClickableElement("tondeuse")->getWidth()/2, getClickableElement("tondeuse")->getY()-getClickableElement("tondeuse")->getHeight()/2);
				((AnimatedSprite*)(getClickableElement("tondeuse")->getSprite()))->startAnimation(1);
				getClickableElement("porte")->setSprite(new Sprite(lvl1_porte_explosee_Sprite, lvl1_porte_explosee_Pal, 1, 0, getClickableElement("porte")->getX(), getClickableElement("porte")->getY(), OBJ_SIZE_64X32));
			}
		}

		if(getClickableElement("tondeuse")->getX() == 127 && getClickableElement("tondeuse")->getY() <= 100 && getElement("planche_sol")->getStatus() == 0){
			getClickableElement("tondeuse")->setStatus(0);
			getClickableElement("tondeuse")->setSprite(new AnimatedSprite(explosion_Sprite, explosion_Pal, 1, 0, getClickableElement("tondeuse")->getX(), getClickableElement("tondeuse")->getY(), OBJ_SIZE_64X64, 8));
			getClickableElement("tondeuse")->setWidth(64);
			getClickableElement("tondeuse")->setHeight(64);
			PA_SetSpriteXY(0, getClickableElement("tondeuse")->getSprite()->getSpriteNumber(), getClickableElement("tondeuse")->getX()-getClickableElement("tondeuse")->getWidth()/2, getClickableElement("tondeuse")->getY()-getClickableElement("tondeuse")->getHeight()/2);
			((AnimatedSprite*)(getClickableElement("tondeuse")->getSprite()))->startAnimation(1);
			
		}
	}

	if(PA_Distance(getClickableElement("tondeuse")->getX(), getClickableElement("tondeuse")->getY(), 127, 9) <=100 && PA_Distance(heroe->getX(), heroe->getY(), 127, 9) < 50){
		finished = 1;
		PA_OutputText(1, 5, 20, "Sortie atteinte !\n");
	}
	else{
		PA_OutputText(1, 5, 20, "                 \n");
	}

	for(int i=0; i<(int)elementsList.size(); i++){
		elementsList[i]->draw();
	}
	for(int j=0; j<(int)clickableElementsList.size(); j++){
		clickableElementsList[j]->draw();
	}
}