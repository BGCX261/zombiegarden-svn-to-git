#ifndef SCENE_CLASS
#define SCENE_CLASS

#include "ClickableElement.hpp"
#include "BackGround.hpp"
#include "Character.hpp"
#include "MiniGame.hpp"
#include "MGStartLandMower.hpp"
#include "MGRecoltColza.hpp"
#include <string>
#include <vector>
/**
 * \file Scene.hpp
 * \class Scene
 * \brief A scene of the game
 * \author Vink
 *
 * A scene of the game
 *
 */
class Scene{
	protected :
		//! Indicates if the scene is finished
		bool finished;
		//! Indicates if the scene has to restart
		bool restarting;
		//! Indicates if the scene is blocked
		bool blocked;
		//! Text of introduction of the scene
		std::string introText;
		//! List of the elements of the scene
		std::vector<SceneElement*> elementsList;
		//! List of the clickables elements of the scene
		std::vector<ClickableElement*> clickableElementsList;
		//! Background of the bottom screen
		BackGround* bg0;
		//! Background of the top screen
		BackGround* bg1;
		//! The heroe
		Character* heroe;
		//! The mini Game being played (null if none)
		MiniGame* currentMiniGame;

	public :
		//! Constructor
		//!\param introText Text of introduction of the scene
		//!\param bg0 Structure of the background of the bottom screen
		//!\param bg1 Structure of the background of the top screen
		Scene(std::string introText, PA_BgStruct bg0, PA_BgStruct bg1, Character* heroe);

		//! Destructor
		~Scene();

		//! Adds an element in the scene
		void addElement(SceneElement* element);
		//! Adds a clickableElement in the scene
		void addClickableElement(ClickableElement* element);
		
		//! Updates the data of the scene
		virtual void update();
		//! Checks the stylus
		void actionStylus();
		
		// Getters and Setters
		std::string getIntroText(){return introText;};
		//! Returns the list of elements
		std::vector<SceneElement*> getElementsList(){return elementsList;};
		//! Returns the list of clickable elements
		std::vector<ClickableElement*> getClickableElementsList(){return clickableElementsList;};
		//! Returns an element of the list of elements from its name
		SceneElement* getElement(std::string name);
		//! Returns a clickable element of the list of elements from its name
		ClickableElement* getClickableElement(std::string name);
		//! Indicates if the scene is finished
		bool isFinished(){return finished;};
		//! Indicates if the scene has to restart
		bool isRestarting(){return restarting;};
		//! Tells the scene it has to restart
		void setRestarting(bool restart){this->restarting = restart;};
		//! Indicates if the scene is blocked
		bool isBlocked(){return blocked;};
		//! Returns the hero
		Character* getHeroe(){return heroe;};
		//! Clear the scene, make all sceneElement invisible
		void clearScene();
		//! Make visible all sceneElement of the scene 
		void reloadScene();
};


#endif	// SCENE_CLASS