#ifndef BACKGROUND_CLASS
#define BACKGROUND_CLASS

#include "Sprite.hpp"
/**
 * \file Background.hpp
 * \class Background
 * \brief A background image
 * \author Vink
 *
 * A background image
 *
 */
class BackGround {
	private :
		//! Number of background wich are implemented
		static int bgNumber;
		//! The visual of the background
		Sprite* sprite;
		//! The screen where the background is
		int screen;
		//! The name of the background
		PA_BgStruct bgName;
		//! The number of the current background
		int bgNum;

	public :
		//! Constructor
		//!\param screen Screen where display
		//!\param bg Background
		BackGround(int screen, PA_BgStruct bg);

		//! Destructor
		~BackGround();

		//! setters and getters
		PA_BgStruct getName(){return bgName;};
		int getNum(){return bgNum;};
};


#endif	// BACKGROUND_CLASS