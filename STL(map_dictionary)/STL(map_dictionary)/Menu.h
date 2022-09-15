#pragma once
#include <iostream>
#include <list>
#include "MenuItem.h"

using namespace std;

class Menu
{
protected:

	// ������ ������� ����
	list<MenuItem*> items;

	// ��������� �� ����������
	Application* app;

public:
	Menu(Application* app);
	~Menu();

	// ���������� ������ ����
	void Add(char letter, const char* title, menuitem_handler handler);

	// ������ ���� ��������� ������
	void Print();

	// ���� ������ � ��������� ����
	void Run();
};

