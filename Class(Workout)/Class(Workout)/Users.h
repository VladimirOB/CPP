#pragma once
#include "MenuItem.h"

class Users
{
protected:
	char* Login;
	char* Password;
	unsigned Flag;
public: 
	Users(const char* login, const char* password);
	virtual ~Users();
	virtual char* GetLogin();
	virtual char* GetPassword();
	virtual int GetFlag();
	void Print();
	bool CheckLogin(const char* login, const char* password);
	virtual void SetFlag(unsigned flag);
	
};

