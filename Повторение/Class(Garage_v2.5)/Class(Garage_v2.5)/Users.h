#pragma once
class Application;

class Users
{
	char* Login;
	char* Password;
public:
	Users(const char* login, const char* password);
	virtual ~Users();
	virtual char* GetLogin();
	virtual char* GetPassword();
	virtual int GetFlag();
	virtual void Menu(Application* app); // �������� �� 2 ������.
	void Print();
	bool CheckLogin(const char* login, const char* password);
};