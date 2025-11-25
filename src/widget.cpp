#include<iostream>
#include<vector>
#include<memory>
#include "widget.hpp"
#include "raylib.h"


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

void widget::update(){
	//check if mouse is down
	//check if mouse is over a button
	//if mouse is over button use action function for that button 
	bool mousePressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

	if (mousePressed){
		Vector2 mousePos = GetMousePosition();

		for (const auto& p : jammyBar->pages){
			if (CheckCollisionPointRec(mousePos, p->getRec())){
				jammyBar->activatePage(p->getTitle());
			}
		}
	}
}

//----------------------PageBar----------------------------
pageBar::~pageBar(){}
void widget::setPage(const char* pageName){
	//use unordered_map mapping between pageName and pages vector
}


pageBar::pageBar(int width,int height,Color color){
	this->width = width;
	this->height = height;
	this->color = color;
	this->nextFree = 0;
}

void pageBar::drawPageBar(){
	DrawRectangle(0,0,width, height, color);
	int x = 0;

	for (const auto&p : pages){
		if (p->getX() == -1){p->setX(x);}
		if (p->getY() == -1){p->setY(height - p->getHeight());}

		DrawRectangle(x, height - p->getHeight(), p->getWidth(), p->getHeight(), p->getColor());
		DrawText(p->getTitle(), x+5, height-p->getHeight()+(p->getHeight() / 3), 10, GRAY);

		x = x + p->getWidth() + 10;
	}
}

void pageBar::addPage(const char* title){
	pages.push_back(std::make_unique<page>());
	pages[nextFree]->setTitle(title);
	nextFree++;
}

void pageBar::activatePage(const char* title){
	//Return tab to normal colour 
	//change colour of new active tab
	activePage = title;
	
	//Change this to use unordered_map
	for (const auto& p:pages){
		if (p->getTitle() == activePage){
			p->setColor(DARKBLUE);
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
void page::setX(int newX){x=newX;}
void page::setY(int newY){y=newY;}
void page::setColor(Color newColor){color = newColor;}
const char* page::getTitle(){return title;}
Rectangle page::getRec(){return Rectangle{(float)x, (float)y, (float)width, (float)height};}
void page::setTitle(const char* newTitle){
	title = newTitle;
}
