#include "Admin.h"
#include "Users.h"
#include "pch.h"

Admin::Admin(const char* login, const char* password) : Users(login, password)
{
	Login = new char[strlen(login) + 1];
	strcpy(Login, login);
	Password = new char[strlen(password) + 1];
	strcpy(Password, password);
	Flag = 1;
}

Admin::~Admin()
{
	delete[] Login;
	delete[] Password;
}

char* Admin::GetLogin()
{
	return Login;
}
char* Admin::GetPassword()
{
	return Password;
}

int Admin::GetFlag()
{
	return Flag;
}

void Admin::Print()
{
	cout << "(A)Login: " << Login << endl;
	for (size_t i = 0; i < strlen(Password); i += 2)
	{
		cout << Password[i] << "*";
	}
	cout << endl;
	//cout << "Password: " << Password << endl << endl;
}