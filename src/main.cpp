#include<iostream>
#include<memory>
#include "widget.hpp"


int main(){
	std::cout << "Jammy Dodger" << std::endl;

	std::unique_ptr<widget> jd = std::make_unique<widget>();
	jd->addPage("Gmail");
	jd->addPage("Server");
	jd->runJammyDodger();
}
