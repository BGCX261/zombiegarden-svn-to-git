#include "AnimatedSprite.hpp"
#include "Interaction.hpp"
#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#ifndef SCENE_ELEMENT_CLASS
#define SCENE_ELEMENT_CLASS
/**
 * \file SceneElement.hpp
 * \class SceneElement
 * \brief An element of the scene
 * \author Vink
 *
 * An element of the scene
 *
 */
class SceneElement {
	protected :
		//! Name of the element
		std::string name;
		//! The width of the element
		int width;
		//! The height of the element
		int height;
		//! Position on axe X
		int x;
		//! Position on axe Y
		int y;
		//! Defines if the element is visible or not
		bool visible;
		//! The status of the element (activated or not)
		bool status;
		//! List of interactions of the element
		std::vector<Interaction*> interactionsList;
	public :
		//! The visual of the element
		Sprite* sprite;
		//! state of the element, if it is clicked or not, if its menu is visible or not
		bool state;
	public :
		//! Constructor without sprite (maybe an invisible element)
		//!\param width Width of the element
		//!\param height Height of the element
		//!\param x Position on axe X
		//!\param y Position on axe Y
		//!\param visible Defines if the element is visible or not
		SceneElement(std::string name, int width, int height, int x, int y, bool visible);

		//! Constructor with a sprite
		//!\param sprite Visual of the element
		//!\param width Width of the element
		//!\param height Height of the element
		//!\param x Position on axe X
		//!\param y Position on axe Y
		//!\param visible Defines if the element is visible or not
		SceneElement(Sprite* sprite, std::string name, int width, int height, int x, int y, bool visible);

		//! Destructor
		~SceneElement(){
			delete(sprite);
			interactionsList.clear();
		}

		//! Adds an interaction into the list of the interactions of the element
		void addInteraction(Interaction* interaction);

		//! Displays the element
		virtual void draw();

		// Getters and Setters
		//! Indicates if the element is visible or not
		bool isVisible(){return visible;};
		//! Returns the list of the interactions of the element
		std::vector<Interaction*> getInteractions(){return interactionsList;};
		//! Returns an interaction of the element from its indice
		Interaction* getInteraction(int indice){return interactionsList[indice];};
		//! Returns an interaction of the element from its name
		Interaction* getInteraction(std::string name);
		//! Returns the name of the element
		std::string getName(){return name;};
		//! Returns the sprite of the element
		Sprite* getSprite(){return sprite;};
		//! Returns the position on the axe X
		int getX(){return x;};
		//! Returns the position on the axe Y
		int getY(){return y;};
		//! Returns the width of the element
		int getWidth(){return width;};
		//! Returns the height of the element
		int getHeight(){return height;};
		//! Sets the element in visible (or not)
		void setVisible(bool value){visible = value;};
		//! Sets the position on the axe X
		void setX(int x);
		//! Sets the position on the axe Y
		void setY(int y);
		//! Sets the position
		void setPosition(int x, int y);
		//! Returns the status of the element (activated or not)
		bool getStatus(){return status;};
		//! Sets the status of the element
		void setStatus(bool value){status = value;};
		//! Sets the sprite of the element
		void setSprite(Sprite* sprite);
		//! Sets the width of the element
		void setWidth(int w){width = w;};
		//! Sets the height of the element
		void setHeight(int h){height = h;};
		//! Returns state
		bool getState(){return state;};
		//! Modify state
		void setState(bool b){state = b;};
};


#endif	// SCENE_ELEMENT_CLASS