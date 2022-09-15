#pragma once
#include "pch.h"
#include "MenuItem.h"

class Menu
{
protected:
	MenuItem** Items; // ������ ������� ����.
	unsigned MaxSize;
	unsigned CurrentSize;

	//��������� �� ����������
	Application* app; // Application ����� � MenuItem.h

public:
	Menu(Application* app);
	~Menu();

	//���������� ������ ����
	void Add(char letter, const char* title, menuitem_handler handler);

	void Print(); // ������ ���� ��������� ������

	void Run(); // ���� ������ � ��������� ����

};

