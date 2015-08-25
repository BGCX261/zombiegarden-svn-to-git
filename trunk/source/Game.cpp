#include "Game.hpp"

Game* Game::gameInstance = NULL;

Game* Game::getGame(){
	if(!gameInstance){
		gameInstance = new Game();
	}
	return gameInstance;
}

Game::Game(){
	// Initialize PAlib
	PA_Init();

	init();

	// Infinite loop to keep the program running
	while(true){
		update();
		display();
		// Wait until the next frame.
		// The DS runs at 60 frames per second.
		PA_WaitForVBL();
	}
}

Game::~Game(){
	// Initialize PAlib
	PA_Init();

	init();
}

void Game::display(){
	
}

void Game::update(){
	if(currentScene != NULL){ 
		if(currentScene->isFinished() || currentScene->isRestarting()){
			if(currentScene->isRestarting()){
				currentLevel--;//to replay the same level
			}
			delete currentScene;
			PA_ResetSpriteSys();
			PA_ResetBgSys();
			PA_ClearTextBg(0);
			PA_ClearTextBg(1);
			PA_InitText(0,0);
			PA_SetTextCol(0,31,31,31);
			PA_InitText(1,0);
			PA_SetTextCol(1,31,31,31);
			currentScene = NULL;
			AnimatedSprite* heroe_sprite = new AnimatedSprite(marche_Sprite, marche_Pal, 1, 0, 32, 32, OBJ_SIZE_32X32, 2);
			heroe = new Character(heroe_sprite, "hero", 32, 32, 90, 150);
		}else{
			currentScene->update();
		}
	}
	else{
		switch(currentLevel){
			case 0 :{ //level 0
				std::string level0_intro = "Zombie Garden DS";
				currentScene = new Level5(level0_intro, accueil, black_bg, heroe);
				PA_BoxText(1, 2, 10, 29, 12, currentScene->getIntroText().c_str(), 100);
				break;
					}
			case 1 :{ //level 1
				std::string level1_intro = "Chapitre 1 : La cabane au fond du jardin";
				currentScene = new Level1(level1_intro, lvl1_bg, black_bg, heroe);
				PA_BoxText(1, 2, 10, 29, 12, currentScene->getIntroText().c_str(), 100);
				break;
					}
			case 2 :{ //level 1 bis
				std::string level1bis_intro = "Chapitre 1 Bis : Le maïs tue";
				currentScene = new Level1bis(level1bis_intro, lvl1b_bg, black_bg, heroe);
				PA_BoxText(1, 2, 10, 29, 12, currentScene->getIntroText().c_str(), 100);
				break;
					}
			case 3 :{ //level 2
				//std::string null_intro = "Plus de niveau disponible";
				//PA_BoxText(1, 2, 10, 29, 12, null_intro.c_str(), 100);
				/*std::string level2_intro = "Chapitre 2 : American Hi-Fi";
				currentScene = new Level2(level2_intro, lvl2_bg, black_bg, heroe);
				PA_BoxText(1, 2, 10, 29, 12, currentScene->getIntroText().c_str(), 100);*/
				std::string level4_intro = "Chapitre final : Cassos";
				currentScene = new Level4(level4_intro, nivo4BG, black_bg, heroe);
				PA_BoxText(1, 2, 10, 29, 12, currentScene->getIntroText().c_str(), 100);
				break;
					} 
			case 4 :{
				std::string level5_intro = "Etendue des dégâts";
				currentScene = new Level5(level5_intro, hosto04, black_bg, heroe);
				PA_BoxText(1, 2, 10, 29, 12, currentScene->getIntroText().c_str(), 100);
				break;
					 }
			default :{
				std::string null_intro = "Fin";
				PA_BoxText(1, 2, 10, 29, 12, null_intro.c_str(), 100);
				break;
					 }
		}
		currentLevel++;
	}

	
}

void Game::init(){
	this->timer = PA_RTC;
	playing = true;
	currentLevel = 0;
	currentScene = NULL;

	PA_InitText(0,0);
	PA_SetTextCol(0,31,31,31);
	PA_InitText(1,0);
	PA_SetTextCol(1,31,31,31);

	AnimatedSprite* heroe_sprite = new AnimatedSprite(marche_Sprite, marche_Pal, 1, 0, 32, 32, OBJ_SIZE_32X32, 2);
	heroe = new Character(heroe_sprite, "hero", 32, 32, 90, 150);

}

void Game::launch(){
	// Infinite loop to keep the program running
	while(playing){
		update();
		display();
		// Wait until the next frame.
		// The DS runs at 60 frames per second.
		PA_WaitForVBL();
	}
}
