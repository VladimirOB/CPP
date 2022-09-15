#pragma once
#include "pch.h"

//предварительное объявление класса приложения
class Application;

// объявление типа данных "указатель на метод класса Application"
typedef void (Application::* menuitem_handler)();

struct MenuItem
{
	//название пункта меню
	char* title;

	//буква пункта меню
	char letter;

	//указатель на метод-обработчик выбора пункта меню
	menuitem_handler handler;

	MenuItem(char letter, const char* title, menuitem_handler handler);
	~MenuItem();
	void Print();
};
