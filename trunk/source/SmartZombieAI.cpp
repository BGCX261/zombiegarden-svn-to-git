#include "SmartZombieAI.hpp"
#include "Game.hpp"

void SmartZombieAI::think(){
	if(counter == (20)){
		counter = 0;
		int xx,yy;

		//find the corresponding character's position
		Character* zombie = NULL;
		for(unsigned int i=0; i<l1b->getEnemiesList().size(); i++){
			if(l1b->getEnemiesList()[i]->getAI() == this){
				zombie = l1b->getEnemiesList()[i];
			}
		}
		x = (zombie->getX()+8)/16.0;
		y = (zombie->getY()+8)/16.0;
		x--;y--;
		//PA_Print(0,"%d-%d ",x,y);
		if(l1b->getMaze()[x][y] == 5){ PA_Print(0,"mur "); }

		//set the start position
		l1b->getMaze()[x][y] = 1;

		//find the hero
		Character* hero = l1b->getHeroe();

		xx = (hero->getX()+8)/16.0;
		yy = (hero->getY()+8)/16.0;
		xx--;yy--;
		//PA_Print(0,"%d-%d ",xx,yy);

		//set the destination positon
		l1b->getMaze()[xx][yy] = 2;

		//resolve the path
		s8 direction = astar(16,11);
		//PA_Print(0,"%d ",direction);
		
		l1b->getMaze()[x][y]=0;
		switch(direction){
			case 1: { //PA_Astar thinks that Left is the best
				x--; // move left
				zombie->getSprite()->rotate(90); 
				break;
			}
			case 2: { //PA_Astar thinks that Right is the best
				x++; // move right
				zombie->getSprite()->rotate(-90); 
				break;
			}
			case 3:{  //PA_Astar thinks that Up is the best
				y--; //move up
				zombie->getSprite()->rotate(0); 
				break;
			}
			case 4:{ //PA_Astar thinks that Down is the best
				y++; // move down
				zombie->getSprite()->rotate(180); 
				break;
			case -1: // there's no possible path or the path is complete.
				break;
			}
		}
		l1b->getMaze()[xx][yy] = 0;

		if(xx==x && yy==y){ l1b->setRestarting(true); }
		
		x++;y++;
		x = x*16;
		y = y*16;

		//PA_Print(0,"%d-%d ",x,y);
	}else{
		counter++;
	}
} 

//copy from PA_IA.c
s8 SmartZombieAI::astar(u16 width, u16 height) {
	u16 maze2[width][height];
	u8 chemin[width][height];
	u8 bloc[width][height];
	u8 arriveex = 0, arriveey = 0, debutx = 0, debuty = 0;
	u8 i, j;
	u8 exit;

	for (j = 0; j < height; j++)for (i = 0; i < width; i++)maze2[i][j] = l1b->getMaze()[i][j];
	
	for (j = 0; j < height; j++)for (i = 0; i < width; i++)bloc[i][j] = 0;

	for (j = 0; j < height; j++)for (i = 0; i < width; i++) {
			if (maze2[i][j] == 1) {
				debutx = i;  debuty = j;
			}

			if (maze2[i][j] == 2) {
				maze2[i][j] = 0;  arriveex = i;  arriveey = j;
			}

			if (maze2[i][j] == 5) {
				maze2[i][j] = 0;  bloc[i][j] = 1;
			}
		}

	while (1) {
		if (maze2[arriveex][arriveey] != 0)break;

		exit = 1;

		for (j = 0; j < height; j++)	for (i = 0; i < width; i++) {
				if (maze2[i][j] > 0) {
					if (j < height - 1 && maze2[i][j+1] == 0 && bloc[i][j+1] == 0) {
						maze2[i][j+1] = maze2[i][j] + 1; exit = 0;
					}

					if (j > 0 && maze2[i][j-1] == 0 && bloc[i][j-1] == 0) {
						maze2[i][j-1] = maze2[i][j] + 1; exit = 0;
					}

					if (i < width - 1 && maze2[i+1][j] == 0 && bloc[i+1][j] == 0) {
						maze2[i+1][j] = maze2[i][j] + 1; exit = 0;
					}

					if (i > 0 && maze2[i-1][j] == 0 && bloc[i-1][j] == 0) {
						maze2[i-1][j] = maze2[i][j] + 1; exit = 0;
					}
				}
			}

		if (exit == 1) return -1;
	}

	for (j = 0; j < height; j++)for (i = 0; i < width; i++)chemin[i][j] = 0;

	while (1) {
		if (chemin[debutx][debuty] == 1)break;

		chemin[arriveex][arriveey] = 1;

		if (arriveey < height - 1 && maze2[arriveex][arriveey+1] < maze2[arriveex][arriveey] && maze2[arriveex][arriveey+1] != 0 && bloc[arriveex][arriveey+1] == 0) arriveey++;
		else if (arriveey > 0 && maze2[arriveex][arriveey-1] < maze2[arriveex][arriveey] && maze2[arriveex][arriveey-1] != 0 && bloc[arriveex][arriveey-1] == 0) arriveey--;
		else if (arriveex < width - 1 && maze2[arriveex+1][arriveey] < maze2[arriveex][arriveey] && maze2[arriveex+1][arriveey] != 0 && bloc[arriveex+1][arriveey] == 0) arriveex++;
		else if (arriveex > 0 && maze2[arriveex-1][arriveey] < maze2[arriveex][arriveey] && maze2[arriveex-1][arriveey] != 0 && bloc[arriveex-1][arriveey] == 0) arriveex--;
	}

	if (chemin[debutx-1][debuty] == 1)return 1;
	else if (chemin[debutx+1][debuty] == 1)return 2;
	else if (chemin[debutx][debuty-1] == 1)return 3;
	else if (chemin[debutx][debuty+1] == 1)return 4;

	return 0;
}