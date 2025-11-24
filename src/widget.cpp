#include<iostream>
#include<vector>
#include<memory>
#include "raylib.h"


widget::widget(int width,int height){
	InitWindow(width, height);
	SetTargetFPS(60);
}
~widget(){
	CloseWindow();
}

int widget::getWidth(){return width;}
int widget::getHeight(){return height;}
void widget::setPage(char PageName[]){
	//use unordered_map mapping between pageName and pages vector
}
