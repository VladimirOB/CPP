#include "Menu.h"
#include <conio.h>

Menu::Menu(Application* app)
{
	this->app = app;
}

Menu::~Menu()
{
	// указатель на текущий элемент списка
	list<MenuItem*>::iterator current = items.begin();

	// перебрать все пункты меню
	while (current != items.end())
	{
		// сохранить адрес удалямого пункта во временный указатель
		list<MenuItem*>::iterator tmp = current;
		current++;

		// удаление пункта меню
		delete* tmp;
	}
}

void Menu::Add(char letter, const char* title, menuitem_handler handler)
{
	// создать новый пункт меню
	MenuItem* item = new MenuItem(letter, title, handler);

	// добавить новый пункт меню в конец списка пунктов
	items.push_back(item);
}

// печать всех элементов списка
void Menu::Print()
{
	// указатель на текущий элемент списка
	list<MenuItem*>::iterator current;
	for (current = items.begin(); current != items.end(); current++)
	{
		(*current)->Print();
	}
}

// цикл показа и обработки меню
void Menu::Run()
{
	// бесконечный цикл меню
	while (true)
	{
		// очистка экрана
		system("cls||clear");

		// вывод пунктов меню на экран
		Print();

		// ввод буквы меню с клавиатуры
		char letter = _getch();

		// указатель на текущий элемент списка
		list<MenuItem*>::iterator current;

		// пробежать по всем пунктам меню
		for (current = items.begin(); current != items.end(); current++)
		{
			// если нажатая буква совпадает с буквой текущего пункта меню
			if ((*current)->letter == letter)
			{
				// обработчик нажатия текущего пункта меню
				menuitem_handler handler = (*current)->handler;

				// запуск метода класса Application, на который указывает указатель handler
				(app->*handler)();
			}
		}
	}
}