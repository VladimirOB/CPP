#pragma once
#include "Users.h"
#include "MenuItem.h"

class Admin : public Users
{
	Application* app; // ��������� �� ����������. (���������� ������ � MI.h
public:
	Admin(const char* login, const char* password);
	~Admin();
	int GetFlag();
	void Menu(Application* app);
	
};

