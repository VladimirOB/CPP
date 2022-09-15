#define _CRT_SECURE_NO_WARNINGS
#include "MenuItem.h"
#include <iostream>
using namespace std;
MenuItem::MenuItem(char letter, const char* title, menuitem_handler handler)
{
	this->letter = letter;
	this->handler = handler;

	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}

MenuItem::~MenuItem()
{
	delete[] title;
}

void MenuItem::print()
{
	cout << letter << ". " << title << endl;
}