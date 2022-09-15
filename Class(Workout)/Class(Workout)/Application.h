#pragma once
#include "Menu.h"
#include "Users.h"
#include "Stat.h"
class Application
{
	Menu* menu = new Menu(this);
	Users** User;
	Stat** StatUser;
	size_t CurrentSize;
	size_t MaxSize;
	size_t CurrentSizeStat;
	size_t MaxSizeStat;
	char login[40] = "";
	char password[40] = "";
	char Current_Login[40] = "";
	char letter;
	unsigned IndexCurrentLogin;

public:
	Application();
	~Application();
	void AddUser(Users* user);
	void AddStat(Stat* userStat);
	void Run();
	void NewMember();
	void P_DelHistory();
	void DelHistory(const char* log);
	bool DelUser(unsigned index);
	void StartTraining();
	void PrintStat();
	void PrintUsers();
	void SetTraining();
	void Logout();
	void Exit();
	bool LoadUsers(FILE* file);
	bool SaveUsers();
	bool LoadStatUsers(FILE* file);
	bool SaveStatUsers();
};

