#pragma once
#include "Users.h"
class MediumUser :public Users
{
	unsigned Flag;
public:
	MediumUser(const char* login, const char* password);
	~MediumUser();
	int GetFlag();
	void SetFlag(unsigned flag);
	
};

