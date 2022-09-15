#pragma once
#include "pch.h"
#include "Word.h"
//–азработать класс Sentence, позвол€ющий хранить одно предложение, состо€щее из слов, класс имеет следующие члены :
//Ј	коллекци€ слов типа Word
//Ј	конструктор по умолчанию
//Ј	конструктор, принимающий строку(char* или string) и занос€щий еЄ в класс(строка предварительно делитс€ на слова, разделители - пробелы и табул€ции)
//Ј	конструктор копировани€
//Ј	operator =
//Ј	деструктор
//Ј	print - печатает предложение на экран
//Ј	length - возвращает количество слов в предложении
//Ј	set(char* или string) - заносит новое предложение в класс
//Ј	char* get() - возвращает всю строку с предложением
//Ј	void Add(Word word) Ц добавл€ет новое слово в предложение
//Ј	bool Remove(unsigned index) Ц удал€ет слово из предложени€
//Ј	operator += (Word word) Ц добавл€ет новое слово в предложение
//Ј	operator[] (int pos) - получает доступ к слову в предложении дл€ чтени€ и записи

class Sentence
{
	vector<Word> Sent;

public:
	Sentence();
	Sentence(string);
	Sentence(const Sentence&, Sentence&);
	Sentence operator = (const Sentence&);
	~Sentence();
	void Print();
	friend ostream& operator<< (ostream& os, Sentence& str);
	int Length();
	void Set(string);
	string Get();
	void Add(Word word);
	bool Remove(unsigned index);
	void operator += (Word word);
	Word& operator[] (int pos);
};

