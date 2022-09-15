#pragma once
#include "pch.h"

class Word
{
	string word;
public:
	Word();
	~Word();
	Word(string str);
	Word (const Word& source, Word& second);
	Word operator = (const Word& source);
	void Print();
	friend ostream& operator<< (ostream& os, Word& str);
	int Length();
	void Set(string);
	const string Get();
	char& operator[] (int pos);
};