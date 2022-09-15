#pragma once
#include "Users.h"
#include "MenuItem.h"
class SimpleUser : public Users
{
	Application* app; // Application будет в MenuItem.h

public:
	SimpleUser(const char* login, const char* password);
	~SimpleUser();
	int GetFlag();
	void PrintMenu();
	void Menu(Application* app);
};

