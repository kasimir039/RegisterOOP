#include "registration.hpp"

void Register::Login()
{
	std::string userId;
	std::string userPassword;

	clearConsole();
	std::cout << "\t\t\t Please enter the username and password" << std::endl;
	std::cout << "\t\t\t USERNAME: ";
	std::cin >> userId;
	std::cout << "\t\t\t PASSWORD: ";
	std::cin >> userPassword;

	std::ifstream input("records.txt");

	std::string loginCheckId;
	std::string loginCheckPassword;
	bool loginSuccessful = false;

	while (input >> loginCheckId >> loginCheckPassword)
	{
		if (loginCheckId == userId && loginCheckPassword == userPassword)
		{
			loginSuccessful = true;
			break;
		}
	}
	input.close();

	if (loginSuccessful)
	{
		clearConsole();
		std::cout << userId << "\n Your LOGIN is successfull \n Thanks for loggin in \n";
		Menu();
	}
	else
	{
		std::cout << "\n LOGIN ERROR \n Please check your username and password \n";
		Menu();
	}
}

void Register::Registration()
{
	std::string registerId;
	std::string registerPassword;

	clearConsole();

	std::cout << "\t\t\t Enter the username: ";
	std::cin >> registerId;
	std::cout << "\t\t\t Enter the password: ";
	std::cin >> registerPassword;

	std::ofstream outputFile("records.txt", std::ios::app);
	if (outputFile.is_open())
	{
		outputFile << registerId << " " << registerPassword << std::endl;
		outputFile.close();
		clearConsole();
		std::cout << "\n\t\t\t Registration is successfull \n";
		Menu();
	}
	else
	{
		std::cout << "Error: Unable to open file for registration." << std::endl;
		Menu();
	}
}

void Register::Forgot()
{
	int option = 0;
	clearConsole();
	std::cout << "\t\t\t You forgot the password? \n";
	std::cout << "Press 1 to search your id by username " << std::endl;
	std::cout << "Press 2 to go back to the main menu " << std::endl;
	std::cout << "\t\t\t Enter your choice: ";
	std::cin >> option;

	switch (option)
	{
	case 1:
	{
		std::string searchUserId;
		std::cout << "\n\t\t Enter the username which you remembered: ";
		std::cin >> searchUserId;

		std::ifstream inputFile("records.txt");
		std::string searchId;
		std::string searchPassword;
		bool accountFound = false;

		while (inputFile >> searchId >> searchPassword)
		{
			if (searchId == searchUserId)
			{
				accountFound = true;
				break;
			}
		}
		inputFile.close();

		if (accountFound)
		{
			std::cout << "\n\n Your account is found \n";
			std::cout << "\n\n Your password is: " << searchPassword << "\n";
			Menu();
		}
		else
		{
			std::cout << "\n\t Sorry your account is not found \n";
			Menu();
		}
		break;

	}
	case 2:
	{
		Menu();
		break;
	}
	default:
		std::cout << "\t\t\t Wrong choice Please try again " << std::endl;
		Forgot();
		break;
	}
}

const void Register::Menu()
{
	int choice = 0;
	std::cout << "\t\t\t---------------------------------------------\n\n\n";
	std::cout << "\t\t		Welcome to the login page			 \n\n\n";
	std::cout << "\t\t\______________		MENU		______________\n\n";
	std::cout << "													   \n\n";
	std::cout << "\t Press 1 to LOGIN: " << std::endl;
	std::cout << "\t Press 2 to REGISTER: " << std::endl;
	std::cout << "\t Press 3 if you forgot your PASSWORD: " << std::endl;
	std::cout << "\t Press 4 to EXIT: " << std::endl;
	std::cout << "\n\t\t\t Please enter your choice: ";

	std::cin >> choice;
	std::cout << std::endl;

	switch (choice)
	{
	case LOGIN:
		Login();
		break;
	case REGISTRATION:
		Registration();
		break;
	case FORGOT:
		Forgot();
		break;
	case EXIT:
		std::cout << "\t\t\t Thank you \n\n";
		break;
	default:
		clearConsole();
		std::cout << "\t\t\t Please select from the option given above \n" << std::endl;
		Menu();
		break;
	}
}

const void Register::clearConsole()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
