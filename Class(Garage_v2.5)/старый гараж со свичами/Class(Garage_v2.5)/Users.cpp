#include "Users.h"
#include "pch.h"
Users::Users(const char* login, const char* password)
{
	Login = new char[strlen(login) + 1];
	strcpy(Login, login);
	Password = new char[strlen(password) + 1];
	strcpy(Password, password);
	Flag = 0;
}

Users::~Users()
{
	delete[] Login;
	delete[] Password;
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
	return Flag;
}

void Users::Print()
{
	cout << "Login: " << Login << endl;

	for (size_t i = 0; i < strlen(Password); i+=2)
	{
		cout << Password[i] << "*";
	}
	//cout << "Password: " << Password << endl << endl;
}