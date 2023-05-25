#ifndef __REGISTRATION_HPP__
#define __REGISTRATION_HPP__

#include <iostream>
#include <fstream>
#include <string.h>

class Register
{
public:
	void Login();
	void Registration();
	void Forgot();
	const void clearConsole();
	const void Menu();

	enum ChoiceMenu
	{
		LOGIN = 1,
		REGISTRATION,
		FORGOT,
		MENU,
		EXIT
	};

};



#endif