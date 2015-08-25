#include "MGRecoltColza.hpp"


MGRecoltColza::MGRecoltColza(){

	state = false;
	bgminigame0 = NULL;
}

void MGRecoltColza::launch(){
	PA_OutputText(1,1,1,"FINAL MINI GAME       ");
	state = 1;
	nb_cut = 0;
	bgminigame0 = new BackGround(0, minijeuColzaBGdbutfleche);

}

void MGRecoltColza::draw(){

	if ( nb_cut == 0 ){
		if ( Stylus.Newpress && Stylus.X > 40 && Stylus.Y > 100 && Stylus.X < 70 && Stylus.Y < 120 ){
			++nb_cut;
		}
	}
	if ( nb_cut == 1 ){
		delete(bgminigame0);
		bgminigame0 = new BackGround(0, minijeuColzaBGd_but);
	
		if ( Stylus.Released && Stylus.X > 180 && Stylus.Y > 140 && Stylus.X < 215 && Stylus.Y < 170 ){
			++nb_cut;
		}
	}
	
	if ( nb_cut == 2 ){
				
		delete(bgminigame0);
		bgminigame0 = new BackGround(0, minijeuColzaBG1fleche);

		if ( Stylus.Newpress && Stylus.X > 185 && Stylus.Y > 90 && Stylus.X < 220 && Stylus.Y < 125 ){
			++nb_cut;
		}

	}
	if ( nb_cut == 3 ){
		delete(bgminigame0);
		bgminigame0 = new BackGround(0, minijeuColzaBG1);
	
		if ( Stylus.Released && Stylus.X > 45 && Stylus.Y > 145 && Stylus.X < 80 && Stylus.Y < 170 ){
			++nb_cut;
		}
	}
	if ( nb_cut == 4 ){
				
		delete(bgminigame0);
		bgminigame0 = new BackGround(0, minijeuColzaBG2fleche);

		if ( Stylus.Newpress && Stylus.X > 40 && Stylus.Y > 30 && Stylus.X < 70 && Stylus.Y < 160 ){
			++nb_cut;
		}

	}
	if ( nb_cut == 5 ){
		delete(bgminigame0);
		bgminigame0 = new BackGround(0, minijeuColzaBG2);
	
		if ( Stylus.Released && Stylus.X > 180 && Stylus.Y > 130 && Stylus.X < 210 && Stylus.Y < 160 ){
			++nb_cut;
		}
	}
	if ( nb_cut == 6 ){
		delete(bgminigame0);
		bgminigame0 = new BackGround(0, minijeuColzaBGcoup);
		if ( Stylus.Newpress ){
			++nb_cut;
		}
	}
		
}

void MGRecoltColza::actionStylus(){
	if(Stylus.Released){
		PA_OutputText(1,1,1,"FINAL MINI GAME x %d   ",nb_cut);
	}
}

void MGRecoltColza::update(){
	if ( state ){
		actionStylus();
		draw();
	
		if ( nb_cut == 7 ){
			delete(bgminigame0);
			this->validate = true;
			state = 0;
			nb_cut = 0;
		}
	}
}
