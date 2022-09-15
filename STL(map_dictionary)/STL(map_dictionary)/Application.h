#pragma once
#include "MenuItem.h"
#include "Menu.h"
#include "pch.h"
/*
2. Разработать программу-словарь, которая имеет следующее меню:
- Добавить пару слов
- Посмотреть перевод слова
- Редактировать пару
- Удалить пару слов
- Посмотреть все словарные пары
- Сохр. словарь
- Загр. словарь

Использовать коллекции map и другие*/

class Application
{
	Menu* menu = new Menu(this);
	map <string, string> m;
	map <string, string> rev_m;
	set<string> Report;
	string buffer_eng;
	string buffer_ru;

public:
	Application();
	~Application();
	void AddPair();
	void Translate();
	void TranslateString();
	void EditPair();
	void DeletePair();
	void ViewOnePair();
	void ViewAllPair();
	void ViewReport();
	void Exit();
	void ExitNoSave();
	void Run();
};

