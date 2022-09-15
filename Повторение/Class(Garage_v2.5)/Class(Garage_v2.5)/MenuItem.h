#pragma once

class Application; // предварительное объявление класса приложения

//объявление типа данных "указатель на метод класса Application"
typedef void(Application::* menuitem_handler)();

struct MenuItem
{
	//буква пункта меню
	char letter;

	//название пункта меню
	char* title;

	//указатель на метод-обработчик выбора пункта меню
	menuitem_handler handler;

	MenuItem(char letter, const char* title, menuitem_handler handler);
	~MenuItem();
	void print();
};

