#include "Menu.h"
#include "pch.h"

Menu::Menu(Application* app)
{
	this->app = app; // назначили полю app указатель на Applic..
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
	// создать новый пункт меню
	MenuItem* item = new MenuItem(letter, title, handler);

	//добавить новый пункт меню в конец списка пунктов
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

void Menu::Run() // цикл показа и обработки меню
{
	while (1)
	{
		system("cls");
		Print();

		char letter = _getch(); // ввод 1 символа с клавы.

		// пробежать по всем пунктам меню
		for (size_t i = 0; i < CurrentSize; i++)
		{
			// если нажатая буква совпадает с буквой текущ пункта
			if (Items[i]->letter == letter)
			{
				// обработчик нажатия текущего пункта меню
				menuitem_handler handler = Items[i]->handler;

				// запуск метода класса Application, на который указывает handler
				(app->*handler)();

			}
		}

	}

}