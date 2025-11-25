#pragma once

#include<iostream>
#include<vector>
#include<memory>
#include"raylib.h"

class pageContent{
    public: 
        pageContent();
        ~pageContent();
        void getContent();
        void drawContent();

};

class email{
	public: 
		email();
		~email();
		void getRec();

	private:
		int width;
		int height;
};

class emailContent : public pageContent{
    public: 
		emailContent();
		~emailContent();
        void getContent();
        void drawContent();

    private:
        const char* emailFile = "emails.json";
		std::vector<std::unique_ptr<email>> emails;
};

class serverContent : public pageContent{
	public: 
		serverContent();
		~serverContent();
		void getContent();
		void drawContent();
		bool getServerUp();

	private:
		bool serverUp = false;
};
