#pragma once
#include "pch.h"
/*–азработать класс Text, позвол€ющий хранить текст, состо€щий из предложений, класс имеет следующие члены:
Ј	коллекци€ предложений типа Sentence
Ј	конструктор по умолчанию
Ј	конструктор, принимающий строку (char* или string) и занос€щий еЄ в класс (строка предварительно делитс€ на предложени€, разделители - [.!?])
Ј	конструктор копировани€
Ј	operator =
Ј	деструктор
Ј	operator << печатает текст на экран, каждое предложение на новой строке
Ј	length - возвращает количество предложений в тексте
Ј	set(char* или string) - заносит новый текст в класс
Ј	char* get() - возвращает строку с текстом, полученным при соединении всех предложений (соединитель - . (точка))
Ј	void Add(Sentense word) Ц добавл€ет новое предложение в текст
Ј	bool Remove(unsigned index) Ц удал€ет предложение из текста
Ј	operator += (Word word) Ц добавл€ет новое предложение в текст
Ј	operator[] (int pos) - получает доступ к предложению в тексте дл€ чтени€ и записи
Ј	load(char* filename) - загрузка текста из файла и разбиение на предложени€, разделители - [.!?])
Ј	save(char* filename) - сохранение текста в файл, каждое предложение на отдельной строке, соединитель - . (точка)
Ј	saveWords(char* filename) - сохранение списка всех слов текста без повторений в столбик
*/
class Text
{
	vector<string> Sentence;

public:
	Text();
	Text(string str);
	Text(const Text& source, Text& second);
	void operator = (const string& source);
	friend ostream& operator<< (ostream& os, Text& str);
	int Length();
	void Set(string);
	char* get();
	void Add(string word);
	bool Remove(unsigned index);
	void operator += (string word);
	string& operator[] (int pos);
	bool Load(const char* filename);
	bool Save(const char* filename);
	bool saveWords(const char* filename);
};

