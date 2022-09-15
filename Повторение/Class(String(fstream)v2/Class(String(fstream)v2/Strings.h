#pragma once
#include <fstream>
#include <iostream>
using namespace std;
/*- char** str - массив строк
- MaxRows - максимальное количество строк
- CurrentRows - текущее количество строк

Методы класса:
- конструкторы (без параметров, принимающий начальное количество строк, копирования)
- деструктор

- Print() - печать строки
- Add(char*) - добавление строки
- Remove(size_t index) - удаление строки по индексу (по позиции)
- Strings operator+ (char*) - добавление строки
- Strings operator+ (const Strings& source) - объединение двух контейнеров со строками (Strings)

- Strings& operator-= (char* str) - удаляет все вхождения строки в контейнере
- Strings& operator-= (const Strings& source) - удаляет все строки, которые есть во втором контейнере sourse
- bool operator == (const Strings& source) - построчно сравнивает 2 контейнера
- RemoveDuplicates() - удаление повторяющихся строк в контейнере
- Sort() - сортировка строк в контейнере в алфавитном порядке*/

class Strings
{
	char** Str;
	size_t CurrentRows;
	size_t MaxRows;
public:
	Strings();
	Strings(size_t size);
	Strings(const Strings& source);
	void Print();
	void Add(const char* str);
	bool Remove(size_t index);
	Strings& operator+(const char* str);
	Strings& operator+(const Strings& source);
	Strings& operator -=(const char* str);
	Strings& operator -=(const Strings& source);
	bool operator==(const Strings& source);
	void RemoveDuplicates();
	void Sort();
	bool Save(const char* file_name);
	bool Load(const char* file_name);
	friend ostream& operator << (ostream& os, const Strings& str);
	friend istream& operator >> (istream& is, Strings& str);
	friend Strings operator+ (const Strings& str, const char* new_str);
	friend Strings operator+ (Strings& first, Strings& second);
};

