#pragma once
#include "pch.h"

class Strings
{
	char** Str;          // -массив строк
	unsigned MaxRows;	 // -максимальное количество строк
	unsigned CurrentRows;// -текущее количество строк
	
public:
	Strings();
	Strings(unsigned mRows);
	Strings(const Strings& source);
	~Strings();
	void Print();
	void Add(const char* row);
	void Remove(size_t index);
	Strings operator=(const Strings& source);
	//Strings operator+(char* str);
	//Strings operator+ (const Strings& source);
	void operator-=(char* str);
	Strings& operator-= (const Strings& source);
	bool operator== (const Strings& source);
	void RemoveDuplicates();
	void Sort();
	
	void Save(const char* filename);
	Strings Load(const char* filename);

	friend ostream& operator <<(ostream& os, const Strings& string); // +
	//friend ofstream& operator << (ofstream& os, const Strings& string);// +

	//friend ifstream& operator >>(ifstream& is, Strings& string);// +
	friend istream& operator >> (istream& is, Strings& string);

	friend Strings operator+ (const Strings&,const char*);// +
	friend Strings operator+ (Strings& first, Strings& second); // +

	
};

