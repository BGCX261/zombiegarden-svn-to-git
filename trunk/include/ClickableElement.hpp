#include "SceneElement.hpp"
#include <string>

#ifndef CLICKABLE_ELEMENT_CLASS
#define CLICKABLE_ELEMENT_CLASS
/**
 * \file ClickableElement.hpp
 * \class ClickableElement
 * \brief A clickable element of the scene
 * \author Vink
 *
 * An element of the scene wich can be clicked
 *
 */
class ClickableElement: public SceneElement {
	private :
		//! The information text of the element
		std::string infoText;

	public :
		//! Constructor
		//!\param sprite Visual of the element
		//!\param width Width of the element
		//!\param height Height of the element
		//!\param x Position on axe X
		//!\param y Position on axe Y
		//!\param visible Defines if the element is visible or not
		//!\param infoText Information text of the element
		ClickableElement(Sprite* sprite, std::string name, int width, int height, int x, int y, bool visible, std::string infoText) : SceneElement(sprite, name, width, height, x, y, visible){
			this->infoText = infoText;
		};

		//! Destructor
		~ClickableElement(){
			delete(sprite);
			interactionsList.clear();
		}

		//! Displays the element
		virtual void draw();

		// Getters and Setters
		//! Returns the introduction text
		std::string getInfoText(){return infoText;};
};


#endif	// CLICKABLE_ELEMENT_CLASS