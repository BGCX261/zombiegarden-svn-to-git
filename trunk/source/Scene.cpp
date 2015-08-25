#include "Scene.hpp"

Scene::Scene(std::string introText, PA_BgStruct bg0, PA_BgStruct bg1, Character* heroe){
	finished = 0;
	restarting = 0;
	blocked = 0;
	this->introText = introText;
	this->bg0 = new BackGround(0, bg0);
	this->bg1 = new BackGround(1, bg1);
	this->heroe = heroe;
	this->currentMiniGame = NULL;
}

Scene::~Scene(){
	delete(bg0);
	delete(bg1);
	delete currentMiniGame;
	elementsList.clear();
}

void Scene::addElement(SceneElement* element){
	elementsList.push_back(element);
}

void Scene::addClickableElement(ClickableElement* element){
	clickableElementsList.push_back(element);
}
		
void Scene::update(){

	if (currentMiniGame!=NULL){
		if ( currentMiniGame->getState() ){
			
			currentMiniGame->update();
		}else{
			heroe->update();
			actionStylus();
		}
		
		if ( !currentMiniGame->getState() && currentMiniGame->IsValidate() ){
			PA_OutputText(1,1,1,"nique sa grand mere");
			reloadScene();
		}

	}else{
		heroe->update();
		actionStylus();
	}
}

void Scene::actionStylus(){
	if( Stylus.Newpress ) {
		for ( std::vector<ClickableElement*>::iterator itc = clickableElementsList.begin(); itc != clickableElementsList.end(); ++itc ){
			if( (*itc)->getState() && !(*itc)->getStatus()){
				int cpt = 0;
				for(unsigned int i=0; i<(*itc)->getInteractions().size(); i++){
					if ( (*itc)->getInteractions()[i]->getState() ){
						if ( PA_StylusInZone((*itc)->getInteractions()[i]->getX(), (*itc)->getInteractions()[i]->getY()-10/*-8*/+cpt, (*itc)->getInteractions()[i]->getX()+150/*+64*/, (*itc)->getInteractions()[i]->getY()+cpt) ){
								
							PA_OutputText(1,1,1,"Choix = %s %s",(*itc)->getInteractions()[i]->getText().c_str(),(*itc)->getName().c_str()); 
							//(*itc)->getInteractions()[i]->execute();
							(*itc)->getInteractions()[i]->setStatus(1);
							(*itc)->setState(false);
							PA_ClearTextBg(0); 
						}
						cpt+=8;
					}
				}
			}	
			
			if( PA_SpriteTouched((*itc)->sprite->getSpriteNumber()) ){
				PA_ClearTextBg(0); 
				PA_OutputText(1,1,1,"                                     "); 
				(*itc)->setState(!(*itc)->getState()); 
			}

		}
	}
		
}
		
SceneElement* Scene::getElement(std::string name){
	for(unsigned int i=0; i<elementsList.size(); i++){
		if(elementsList[i]->getName().compare(name) == 0){
			return elementsList[i];
		}
	}

	return NULL;
}
		
ClickableElement* Scene::getClickableElement(std::string name){
	for(unsigned int i=0; i<clickableElementsList.size(); i++){
		if(clickableElementsList[i]->getName().compare(name) == 0){
			return clickableElementsList[i];
		}
	}

	return NULL;
}


void Scene::clearScene(){
	heroe->getSprite()->stopAnimation();
	heroe->setY(15);
	heroe->setX(15);
	PA_DeleteBg(0, this->bg0->getNum());
	//delete(bg0);
	for(unsigned int i=0; i<clickableElementsList.size(); i++){
		clickableElementsList[i]->setX(clickableElementsList[i]->getX()+260);
	}
	for(unsigned int i=0; i<elementsList.size(); i++){
		elementsList[i]->setX(elementsList[i]->getX()+260);
	}
}


void Scene::reloadScene(){
	heroe->getSprite()->startAnimation();
	this->bg0 = new BackGround(0, this->bg0->getName());
	for(unsigned int i=0; i<clickableElementsList.size(); i++){
		clickableElementsList[i]->setX(clickableElementsList[i]->getX()-260);
	}
	for(unsigned int i=0; i<elementsList.size(); i++){
		elementsList[i]->setX(elementsList[i]->getX()-260);
	}
}