#pragma once
#include "pch.h"
#include "MenuItem.h"

class Menu
{
protected:
	MenuItem** Items; // список пунктов меню.
	unsigned MaxSize;
	unsigned CurrentSize;

	//указатель на приложение
	Application* app; // Application будет в MenuItem.h

public:
	Menu(Application* app);
	~Menu();

	//добавление пункта меню
	void Add(char letter, const char* title, menuitem_handler handler);

	void Print(); // печать всех элементов списка

	void Run(); // цикл показа и обработки меню

};

