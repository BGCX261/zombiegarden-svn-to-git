#include "BackGround.hpp"

int BackGround::bgNumber = 0;

BackGround::BackGround(int screen, PA_BgStruct bg){
	this->screen = screen;
	this->bgName = bg;
	bgNumber++;
	this->bgNum = bgNumber;
	PA_LoadBackground(screen, bgNumber, &bg);
}

BackGround::~BackGround(){
	PA_DeleteBg(screen, this->bgNum);
	bgNumber--;
}