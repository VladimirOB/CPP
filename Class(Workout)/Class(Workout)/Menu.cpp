#include "Menu.h"
#include "pch.h"

Menu::Menu(Application* app)
{
	this->app = app; // ��������� ���� app ��������� �� Applic..
	MaxSize = 20;
	CurrentSize = 0;
	Items = new MenuItem * [MaxSize];
}

Menu::~Menu()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		delete[] Items[i];
	}
	delete[] Items;
}

void Menu::Add(char letter, const char* title, menuitem_handler handler)
{
	// ������� ����� ����� ����
	MenuItem* item = new MenuItem(letter, title, handler);

	//�������� ����� ����� ���� � ����� ������ �������
	if (CurrentSize < MaxSize)
	{
		Items[CurrentSize++] = item;
	}
}

void Menu::Print()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		Items[i]->Print();
	}
}

void Menu::Run() // ���� ������ � ��������� ����
{
	while (1)
	{
		system("cls");
		Print();

		char letter = _getch(); // ���� 1 ������� � �����.

		// ��������� �� ���� ������� ����
		for (size_t i = 0; i < CurrentSize; i++)
		{
			// ���� ������� ����� ��������� � ������ ����� ������
			if (Items[i]->letter == letter)
			{
				// ���������� ������� �������� ������ ����
				menuitem_handler handler = Items[i]->handler;

				// ������ ������ ������ Application, �� ������� ��������� handler
				(app->*handler)();

			}
		}

	}

}