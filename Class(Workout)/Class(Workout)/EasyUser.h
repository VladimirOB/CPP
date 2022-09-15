#pragma once
#include "Users.h"
class EasyUser :public Users
{
	unsigned Flag;
public:
	EasyUser(const char* login, const char* password);
	~EasyUser();
	int GetFlag();
	void SetFlag(unsigned flag);
};

