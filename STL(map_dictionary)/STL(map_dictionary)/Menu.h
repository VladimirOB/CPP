#pragma once
#include <iostream>
#include <list>
#include "MenuItem.h"

using namespace std;

class Menu
{
protected:

	// список пунктов меню
	list<MenuItem*> items;

	// указатель на приложение
	Application* app;

public:
	Menu(Application* app);
	~Menu();

	// добавление пункта меню
	void Add(char letter, const char* title, menuitem_handler handler);

	// печать всех элементов списка
	void Print();

	// цикл показа и обработки меню
	void Run();
};

