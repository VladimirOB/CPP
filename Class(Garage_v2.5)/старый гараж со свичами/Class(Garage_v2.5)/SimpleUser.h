#pragma once
#include "Users.h"
class SimpleUser : public Users
{
	char* Login;
	char* Password;
	unsigned Flag;
public:
	SimpleUser(const char* login, const char* password);
	~SimpleUser();
	char* GetLogin();
	char* GetPassword();
	int GetFlag();
	void Print();
};

