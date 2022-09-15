#pragma once
#include "pch.h"

class Word
{
	string word;
public:
	Word();
	~Word();
	Word(const char* str);
	Word (const Word& source, Word& second);
	void operator = (const string& source);
	void Print();
	int Length();
	void Set(string);
	string get();
	char& operator[] (int pos);
};