#include<iostream>
#include<vector>
#include<memory>
#include "raylib.h"
#include "widget.hpp"



//------------------Widget----------------------------------------
widget::widget(int width,int height, const char* title) 
: width(width), height(height), title(title){
	pColor = BLACK;
	sColor = BROWN;
	InitWindow(width, height, title);
	SetTargetFPS(60);

	jammyBar = std::make_unique<pageBar>();
}
widget::~widget(){
	CloseWindow();
}

int widget::getWidth(){return width;}
int widget::getHeight(){return height;}
void widget::setPColor(Color newColor){}
void widget::setSColor(Color newColor){}

void widget::runJammyDodger(){
	while(!WindowShouldClose()){
		BeginDrawing();
			ClearBackground(RAYWHITE);
			update();
			jammyBar->drawPageBar();
		EndDrawing();
	}
}

void widget::addPage(const char* title){
	jammyBar->addPage(title);
}

void widget::update(){
	//check if mouse is down
	//check if mouse is over a button
	//if mouse is over button use action function for that button 
	bool mousePressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

	if (mousePressed){
		Vector2 mousePos = GetMousePosition();

		jammyBar->update(mousePos);
		
	}
}

void widget::setPage(const char* title){
	//use unordered_map mapping between pageName and pages vector
}

//----------------------PageBar----------------------------
pageBar::~pageBar(){}
pageBar::pageBar(int width,int height,Color color){
	this->width = width;
	this->height = height;
	this->color = color;
	this->nextFree = 0;
}

int pageBar::getWidth(){return width;}
int pageBar::getHeight(){return height;}
int pageBar::getNextFree(){return nextFree;}

void pageBar::drawPageBar(){
	DrawRectangle(0,0,width, height, color);
	int x = 0;

	for (const auto&p : pages){
		if (p->getX() == -1){p->setX(x);}
		if (p->getY() == -1){p->setY(height - p->getHeight());}

		DrawRectangle(x, height - p->getHeight(), p->getWidth(), p->getHeight(), p->getColor());
		DrawText(p->getTitle(), x+5, height-p->getHeight()+(p->getHeight() / 3), 10, GRAY);

		x = x + p->getWidth() + 2;
	}
}

void pageBar::addPage(const char* title){
	pages.push_back(std::make_unique<page>());
	pages[nextFree]->setTitle(title);
	pages[nextFree]->setIndex(nextFree);
	if (nextFree == 0){pages[nextFree]->setColor(DARKBLUE);}
	nextFree++;
}

void pageBar::activatePage(int pageIndex){
	//Return tab to normal colour 
	//change colour of new active tab
	
	pages[activePage]->setColor(BLACK);
	pages[pageIndex]->setColor(DARKBLUE);
	activePage = pageIndex;
}

void pageBar::update(Vector2 mousePos){
	for (const auto& p : pages){
		if (CheckCollisionPointRec(mousePos, p->getRec())){
			activatePage(p->getIndex());
		}
	}
}

//--------------------Page-------------------------
page::page(int width,int height,Color color) 
: width(width), height(height), color(color){
	y = -1;
	x = -1;
}
page::~page(){}

int page::getWidth(){return width;}
int page::getHeight(){return height;}
Color page::getColor(){return color;}
int page::getX(){return x;}
int page::getY(){return y;}
int page::getIndex(){return index;}
void page::setX(int newX){x=newX;}
void page::setY(int newY){y=newY;}
void page::setIndex(int newIndex){index = newIndex;}
void page::setColor(Color newColor){color = newColor;}
const char* page::getTitle(){return title;}
Rectangle page::getRec(){return Rectangle{(float)x, (float)y, (float)width, (float)height};}
void page::setTitle(const char* newTitle){
	title = newTitle;
}
