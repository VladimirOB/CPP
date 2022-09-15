#include "Menu.h"
#include <conio.h>

Menu::Menu(Application* app)
{
	this->app = app;
}

Menu::~Menu()
{
	// ��������� �� ������� ������� ������
	list<MenuItem*>::iterator current = items.begin();

	// ��������� ��� ������ ����
	while (current != items.end())
	{
		// ��������� ����� ��������� ������ �� ��������� ���������
		list<MenuItem*>::iterator tmp = current;
		current++;

		// �������� ������ ����
		delete* tmp;
	}
}

void Menu::Add(char letter, const char* title, menuitem_handler handler)
{
	// ������� ����� ����� ����
	MenuItem* item = new MenuItem(letter, title, handler);

	// �������� ����� ����� ���� � ����� ������ �������
	items.push_back(item);
}

// ������ ���� ��������� ������
void Menu::Print()
{
	// ��������� �� ������� ������� ������
	list<MenuItem*>::iterator current;
	for (current = items.begin(); current != items.end(); current++)
	{
		(*current)->Print();
	}
}

// ���� ������ � ��������� ����
void Menu::Run()
{
	// ����������� ���� ����
	while (true)
	{
		// ������� ������
		system("cls||clear");

		// ����� ������� ���� �� �����
		Print();

		// ���� ����� ���� � ����������
		char letter = _getch();

		// ��������� �� ������� ������� ������
		list<MenuItem*>::iterator current;

		// ��������� �� ���� ������� ����
		for (current = items.begin(); current != items.end(); current++)
		{
			// ���� ������� ����� ��������� � ������ �������� ������ ����
			if ((*current)->letter == letter)
			{
				// ���������� ������� �������� ������ ����
				menuitem_handler handler = (*current)->handler;

				// ������ ������ ������ Application, �� ������� ��������� ��������� handler
				(app->*handler)();
			}
		}
	}
}