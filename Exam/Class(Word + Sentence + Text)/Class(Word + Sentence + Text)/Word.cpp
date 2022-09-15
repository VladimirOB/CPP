#include "Word.h"
#include "pch.h"

/*Задача 1 (7 баллов)
Разработать класс Word, который хранит одно слово, содержащий следующие члены класса:
·	конструктор по умолчанию
·	конструктор, принимающий строку (char* или string) и заносящий её в класс (если передаётся несколько слов в строке, хранится только первое слово)
·	конструктор копирования
·	operator =
·	деструктор
·	print - печатает слово на экран
·	length - возвращает количество символов в слове
·	set(char* или string) - заносит новое слово в класс (меняет старое слово на новое)
·	char* get() - возвращает слово
·	operator[] (int pos) - получает доступ к символу в слове для чтения и записи
*/

Word::Word()
{
	word += "Hello";
}

Word::Word(const char* str)
{
	stringstream ss(str);
	ss >> word;
	word = std::regex_replace(word, std::regex("[,.!? ]"), "");
}

Word::Word(const Word& source, Word& second)
{
	second = source;
}

void Word::operator = (const string& source)
{
	word = source;
}

Word::~Word()
{
	
}

void Word::Print()
{
	cout << word << endl;
}

int Word::Length()
{
	return word.length();
}

void Word::Set(string str)
{
	stringstream ss(str);
	ss >> word;
	word = std::regex_replace(word, std::regex("[,.!? ]"), "");
}

string Word::get()
{
	return word;
}

char& Word::operator[] (int pos)
{
	if (pos <= word.length())
	{
		return word[pos];
	}
}