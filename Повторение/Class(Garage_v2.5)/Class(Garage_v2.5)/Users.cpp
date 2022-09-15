#define _CRT_SECURE_NO_WARNINGS
#include "Users.h"
#include <iostream>
using namespace std;

Users::Users(const char* login, const char* password)
{
	Login = new char[strlen(login) + 1];
	strcpy(Login, login);
	Password = new char[strlen(password) + 1];
	strcpy(Password, password);
}

Users::~Users()
{
	delete[] Login, Password;
}

char* Users::GetLogin()
{
	return Login;
}

char* Users::GetPassword()
{
	return Password;
}

int Users::GetFlag()
{
	return 0;
}

bool Users::CheckLogin(const char* login, const char* password)
{
	if (!strcmp(Login, login) && !strcmp(Password, password))
		return true;
	else
		return false;
}

void Users::Print()
{
	cout << "Login: " << Login << endl;

	for (size_t i = 0; i < strlen(Password); i+=2)
	{
		if (i + 1 == strlen(Password))
		{
			cout << Password[i];
		}
		else
			cout << Password[i] << "*";
	}
	cout << endl;
}

void Users::Menu(Application* app) {}
