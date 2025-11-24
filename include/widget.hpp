#pragma

#include<iostream>
#include<vector>
#include<memory>


class widget{
	public:
		Widget(int width=500, int height=500);
		int getWidth();
		int getHeight();
		void setPage(pageName str);
		~widget();


	private:
		int width;
		int height;
		std::vector<std::unique_ptr<Page>> pages;
}
