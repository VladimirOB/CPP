#pragma once
class Users
{
	char* Login;
	char* Password;
	char Flag;
public:
	Users(const char* login, const char* password); // ����� ������� ��� �����������?
	virtual ~Users();
	virtual char* GetLogin();
	virtual char* GetPassword();
	virtual int GetFlag();
	virtual void Print();
	//void SetPassword();
	//Logout(); // exit 
};

