#ifndef GAME_CLASS
#define GAME_CLASS

#include <PA9.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "all_gfx.h"
#include "State.hpp"
#include "Interaction.hpp"
#include "AnimatedSprite.hpp"
#include "ClickableElement.hpp"
#include "BackGround.hpp"
#include "Scene.hpp"
#include "PageAccueil.hpp"
#include "Level1.hpp"
#include "Level1bis.hpp"
#include "Level2.hpp"
#include "Level4.hpp"
#include "Level5.hpp"
#include "Character.hpp"

class Game{
public:
	static Game* getGame();
	void launch();
	
	Scene* getCurrentScene(){return currentScene;}
	Character* getHeroe(){return heroe; }

private :
	Game();
	~Game();
	static Game* gameInstance;

	Scene* currentScene;
	Character* heroe;
	int currentLevel;
	RTC timer;
	bool playing;

	void display();
	void update();
	void init();
};


#endif //GAME_CLASS