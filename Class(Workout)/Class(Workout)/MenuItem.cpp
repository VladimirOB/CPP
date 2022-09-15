#include "MenuItem.h"

MenuItem::MenuItem(char letter, const char* title, menuitem_handler handler)
{
	this->letter = letter;
	this->handler = handler;

	// копирование названия пункта меню
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}

MenuItem::~MenuItem()
{
	delete[] title;
}

void MenuItem::Print()
{
	cout << letter << ". " << title << endl;
}