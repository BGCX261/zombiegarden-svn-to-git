#include "Level1bis.hpp"
#include "SmartZombieAI.hpp"
#include "all_gfx.h"

Level1bis::~Level1bis(){
	for(int i=0; i<11; i++){ delete[] labyrinth[i]; }
	delete[] labyrinth;
	enemiesList.clear();
}

void Level1bis::init(){
	heroe->setPosition(16, 176);//multiple de 16!

	//zombie 1
	AnimatedSprite* zombie1_sprite = new AnimatedSprite(zombimarche_Sprite, zombimarche_Pal, 1, 0, 32, 32, OBJ_SIZE_32X32, 2);
	Character* zombie1 = new Character(zombie1_sprite, "zombie1", 32, 32, 64, 128);
	enemiesList.push_back(zombie1);
	AI* ai1 = new SmartZombieAI(64,128,this);
	zombie1->setAI(ai1);

	//zombie 2
	AnimatedSprite* zombie2_sprite = new AnimatedSprite(zombimarche_Sprite, zombimarche_Pal, 1, 0, 32, 32, OBJ_SIZE_32X32, 2);
	Character* zombie2 = new Character(zombie2_sprite, "zombie2", 32, 32, 128, 64);
	enemiesList.push_back(zombie2);
	AI* ai2 = new SmartZombieAI(128,64,this);
	zombie2->setAI(ai2);

	initMaze();
}

void Level1bis::update(){

	Scene::update();

	if(PA_Distance(heroe->getX(), heroe->getY(), 120, 4) < 50){
		finished = 1;
		PA_OutputText(1, 5, 20, "Sortie atteinte !\n");
	}
	else{
		PA_OutputText(1, 5, 20, "                 \n");
	}

   for(unsigned int i=0; i < enemiesList.size(); i++){
	  enemiesList[i]->update();
   }

}

void Level1bis::initMaze(){
	///creation of the labyrinth
	int w=16,h=11;
	//allocate memory for the labyrinth
	labyrinth = (u16**)malloc(sizeof(u16*)*w);
	for(int i=0; i<w; i++){ labyrinth[i] = (u16*)malloc(sizeof(u16)*h); }
	//init the labyrinth
	for(int i=0; i<w; i++){ for(int j=0; j<h; j++){ labyrinth[i][j]=0; }}
	//ligne 1 
	labyrinth[0][0]=5; labyrinth[1][0]=5; labyrinth[2][0]=5; labyrinth[3][0]=5; labyrinth[4][0]=5; labyrinth[5][0]=5; labyrinth[6][0]=5;  
	labyrinth[8][0]=5; labyrinth[9][0]=5; labyrinth[10][0]=5; labyrinth[11][0]=5; labyrinth[12][0]=5; labyrinth[13][0]=5; labyrinth[14][0]=5;
	labyrinth[15][0]=5;
	//ligne 2
	labyrinth[6][1]=5;  labyrinth[12][1]=5;
	//ligne 3
	labyrinth[1][2]=5; labyrinth[2][2]=5; labyrinth[3][2]=5; labyrinth[4][2]=5; labyrinth[6][2]=5;
	labyrinth[8][2]=5; labyrinth[9][2]=5; labyrinth[10][2]=5; labyrinth[12][2]=5; labyrinth[13][2]=5; labyrinth[14][2]=5;
	//ligne 4
	labyrinth[1][3]=5; labyrinth[6][3]=5; labyrinth[8][3]=5; labyrinth[9][3]=5; labyrinth[10][3]=5; labyrinth[12][3]=5;
	//ligne 5
	labyrinth[1][4]=5; labyrinth[2][4]=5; labyrinth[3][4]=5; labyrinth[4][4]=5; labyrinth[6][4]=5;
	//ligne 6
	labyrinth[6][5]=5; labyrinth[7][5]=5; labyrinth[8][5]=5; labyrinth[9][5]=5; labyrinth[10][5]=5; labyrinth[11][5]=5; labyrinth[12][5]=5; 
	labyrinth[13][5]=5; labyrinth[15][5]=5;
	//ligne 7
	labyrinth[1][6]=5; labyrinth[2][6]=5; labyrinth[3][6]=5; labyrinth[4][6]=5; labyrinth[11][6]=5; labyrinth[15][6]=5;
	//ligne 8
	labyrinth[1][7]=5; labyrinth[7][7]=5; labyrinth[9][7]=5; labyrinth[10][7]=5; labyrinth[11][7]=5; labyrinth[14][7]=5; labyrinth[15][7]=5;
	//ligne 9
	labyrinth[1][8]=5; labyrinth[2][8]=5; labyrinth[3][8]=5; labyrinth[4][8]=5; labyrinth[5][8]=5; labyrinth[7][8]=5; 
	labyrinth[9][8]=5;  labyrinth[13][8]=5;  labyrinth[15][8]=5;
	//ligne 10
	labyrinth[5][9]=5; labyrinth[7][9]=5; labyrinth[8][9]=5; labyrinth[9][9]=5; labyrinth[10][9]=5; labyrinth[12][9]=5; labyrinth[13][9]=5; 
	labyrinth[15][9]=5;
	//ligne 11
	labyrinth[1][10]=5; labyrinth[2][10]=5; labyrinth[3][10]=5; labyrinth[4][10]=5; labyrinth[5][10]=5;
}