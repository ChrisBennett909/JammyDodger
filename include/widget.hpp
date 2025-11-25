#pragma

#include<iostream>
#include<vector>
#include<memory>
#include "raylib.h"


class page{
	public:
		page(int width=50, int height=25, Color color=BLACK);
		~page();

		int getWidth();
		int getHeight();
		int getX();
		int getY();
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
		Color color;
		const char* title;
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
		void activatePage(const char* title);
		~pageBar();
		
		std::vector<std::unique_ptr<page>> pages;
		
	private:
		int width;
		int height;
		int nextFree;
		Color color;
		const char* activePage;
};

class widget{
	public:
		widget(int width=500, int height=500, const char*title="Jammy");
		int getWidth();
		int getHeight();
		void setPage(const char*pageName);
		void setPColor(Color newColor);
		void setSColor(Color newColor);
		void runJammyDodger();
		void update();
		~widget();

		std::unique_ptr<pageBar> jammyBar;

	private:
		int width;
		int height;
		const char* title;
		Color pColor;
		Color sColor;
};


