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

Word::Word(string str)
{
	stringstream ss(str);
	ss >> word;
	word = std::regex_replace(word, std::regex("[,.!? \t]"), "");
}

Word::Word(const Word& source, Word& second)
{
	second = source;
}

Word Word::operator=(const Word& second)
{
	word = second.word;
	return *this;
}

Word::~Word()
{
	
}


void Word::Print()
{
	cout << word << endl;
}

ostream& operator<< (ostream& os, Word& str)
{
	for (size_t i = 0; i < str.word.size(); i++)
	{
		os << str[i];
	}
	return os;
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

const string Word::Get()
{
	return word;
}

char& Word::operator[] (int pos)
{
	if (pos < word.length())
	{
		return word[pos];
	}
}