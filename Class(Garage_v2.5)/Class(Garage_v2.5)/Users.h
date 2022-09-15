#pragma once
class Application;

class Users
{
protected:
	char* Login;
	char* Password;
public:
	Users(const char* login, const char* password); 
	virtual ~Users();
	virtual char* GetLogin();
	virtual char* GetPassword();
	virtual int GetFlag();
	void Print();
	virtual void Menu(Application* app);
	bool CheckLogin(const char* login, const char* password);


};

