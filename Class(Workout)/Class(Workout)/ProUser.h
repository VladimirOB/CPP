#pragma once
#include "Users.h"
class ProUser :public Users
{
	unsigned CurrentSize;
public:
	ProUser(const char* login, const char* password);
	~ProUser();
	int GetFlag();
	void SetFlag(unsigned flag);

};
