#pragma once
#include "Users.h"
#include "MenuItem.h"
class SimpleUser : public Users
{
protected:
	//указатель на приложение
	Application* app; // Application будет в MenuItem.h

public:
	SimpleUser(const char* login, const char* password);
	~SimpleUser();
	int GetFlag();
	void PrintMenu();
	void Menu(Application* app);
};