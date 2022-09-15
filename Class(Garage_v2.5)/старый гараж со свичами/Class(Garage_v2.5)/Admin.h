#pragma once
#include "Users.h"
class Admin : public Users
{
	char* Login;
	char* Password;
	int Flag;
public:
	Admin(const char* login, const char* password);
	~Admin();
	char* GetLogin();
	char* GetPassword();
	int GetFlag();
	void Print();
};

