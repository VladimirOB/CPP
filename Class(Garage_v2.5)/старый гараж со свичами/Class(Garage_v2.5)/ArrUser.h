#pragma once
#include "Users.h"
class ArrUser
{
	Users** User;
	size_t CurrentSize;
	size_t MaxSize;
public:
	ArrUser(const size_t maxSize);
	~ArrUser();
	void AddUser(Users* user);
	ArrUser& DeleteUser(const char* login);
	virtual int CheckUser(const char* login, const char* password);
	bool CheckLogin(const char* login);
	void Print();
	void SimpleUserMenu();
	void AdminMenu();
	bool SaveUsers();
	bool LoadUsers();
};

