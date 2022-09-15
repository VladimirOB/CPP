#pragma once
#include "pch.h"

//��������������� ���������� ������ ����������
class Application;

// ���������� ���� ������ "��������� �� ����� ������ Application"
typedef void (Application::* menuitem_handler)();

struct MenuItem
{
	//�������� ������ ����
	char* title;

	//����� ������ ����
	char letter;

	//��������� �� �����-���������� ������ ������ ����
	menuitem_handler handler;

	MenuItem(char letter, const char* title, menuitem_handler handler);
	~MenuItem();
	void Print();
};
