#pragma once

#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include "raylib.h"
#include "pageContent.hpp"


class page{
	public:
		page(int width=50, int height=25, Color color=BLACK);
		~page();

		int getWidth();
		int getHeight();
		int getX();
		int getY();
		int getIndex();
		void setIndex(int index);
		Color getColor();
		const char* getTitle();
		Rectangle getRec();
		void setTitle(const char* newTitle);
		void setColor(Color newColor);
		void setX(int newX);
		void setY(int newY);
		//void drawPageTab();
		//void drawPage();

	private:
		int x, y;
		int width;
		int height;
		int index;
		Color color;
		const char* title;
		pageContent content;
};

class pageBar{
	public:
		pageBar(int width=500, int height=50, Color color=BROWN);
		int getWidth();
		int getHeight();
		int getNextFree();
		void addPage(const char* pageName);
		bool removePage(const char* pageName);
		void drawPageBar();
		void activatePage(int pageIndex);
		void update(Vector2 mousePos);
		~pageBar();
		
		
	private:
		int width;
		int height;
		int nextFree;
		Color color;
		int activePage = 0;
		std::vector<std::unique_ptr<page>> pages;
};

class widget{
	public:
		widget(int width=500, int height=500, const char*title="Jammy");
		int getWidth();
		int getHeight();
		void setPage(const char* title);
		void addPage(const char* title);
		void setPColor(Color newColor);
		void setSColor(Color newColor);
		void runJammyDodger();
		void update();
		~widget();

	private:
		int width;
		int height;
		const char* title;
		Color pColor;
		Color sColor;
		std::unique_ptr<pageBar> jammyBar;
};


