#include "SimpleUser.h"
#include "Users.h"
#include "pch.h"
SimpleUser::SimpleUser(const char* login, const char* password) : Users(login,password)
{
	Login = new char[strlen(login) + 1];
	strcpy(Login, login);
	Password = new char[strlen(password) + 1];
	strcpy(Password, password);
	Flag = 0;
}

SimpleUser::~SimpleUser()
{
	delete[] Login;
	delete[] Password;
}



char* SimpleUser::GetLogin()
{
	return Login;
}
char* SimpleUser::GetPassword()
{
	return Password;
}

int SimpleUser::GetFlag()
{
	return Flag;
}

void SimpleUser::Print()
{
	cout << "(U)Login: " << Login << endl;
	for (size_t i = 0; i < strlen(Password); i += 2)
	{
		cout << Password[i] << "*";
	}
	cout << endl;
	//cout << "Password: " << Password << endl << endl;
}