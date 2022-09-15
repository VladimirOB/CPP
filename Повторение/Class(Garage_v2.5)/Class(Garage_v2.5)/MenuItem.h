#pragma once

class Application; // ��������������� ���������� ������ ����������

//���������� ���� ������ "��������� �� ����� ������ Application"
typedef void(Application::* menuitem_handler)();

struct MenuItem
{
	//����� ������ ����
	char letter;

	//�������� ������ ����
	char* title;

	//��������� �� �����-���������� ������ ������ ����
	menuitem_handler handler;

	MenuItem(char letter, const char* title, menuitem_handler handler);
	~MenuItem();
	void print();
};

