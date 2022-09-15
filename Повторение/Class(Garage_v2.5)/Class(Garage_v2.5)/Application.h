#pragma once
#include <iostream>
using namespace std;
#include "Users.h"
#include "Garage.h"
#include "MenuItem.h"
#include <fstream>
class Application
{
	Garage* garage;
	Users** User;
	size_t CurrentSize;
	size_t MaxSize;
	char login[40] = "";
	char password[40] = "";
	char Current_Login[40] = "";

	MenuItem** Items; // список пунктов меню.
	unsigned MaxSizeItems;
	unsigned CurrentSizeItems;

public:
	Application();
	~Application();
	void AddUser(Users* user);
	void GoAddUser();
	void GoAddCar();
	void GoDeleteUser();
	void GoDeleteUserCar();
	void GoLogout();
	void GoExit();
	void Menu(Application* app);
	void AddMenu(char letter, const char* title, menuitem_handler handler);
	void PrintMenu();
	bool DeleteUser();
	void DeleteCars();
	void PrintUsers();
	void PrintCars();
	void Run();
	bool LoadUsers(ifstream& file);
	bool SaveUsers();
};

