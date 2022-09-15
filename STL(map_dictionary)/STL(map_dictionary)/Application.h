#pragma once
#include "MenuItem.h"
#include "Menu.h"
#include "pch.h"
/*
2. ����������� ���������-�������, ������� ����� ��������� ����:
- �������� ���� ����
- ���������� ������� �����
- ������������� ����
- ������� ���� ����
- ���������� ��� ��������� ����
- ����. �������
- ����. �������

������������ ��������� map � ������*/

class Application
{
	Menu* menu = new Menu(this);
	map <string, string> m;
	map <string, string> rev_m;
	set<string> Report;
	string buffer_eng;
	string buffer_ru;

public:
	Application();
	~Application();
	void AddPair();
	void Translate();
	void TranslateString();
	void EditPair();
	void DeletePair();
	void ViewOnePair();
	void ViewAllPair();
	void ViewReport();
	void Exit();
	void ExitNoSave();
	void Run();
};

