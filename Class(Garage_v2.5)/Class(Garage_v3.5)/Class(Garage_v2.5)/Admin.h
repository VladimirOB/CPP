#pragma once
#include "Users.h"
#include "MenuItem.h"

class Admin : public Users
{
protected:
	
	//��������� �� ����������
	Application* app; // Application ����� � MenuItem.h

public:
	Admin(const char* login, const char* password);
	~Admin();
	int GetFlag();
	
	void Menu(Application* app);
};








































































































































































#define _ cout << "Creator: Balaban Vladimir." << endl;