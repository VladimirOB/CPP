#pragma once
#include "pch.h"
class Person
{
	char* FirstName;
	char* LastName;
	unsigned Age;

public:
	Person();
	Person(const char* firstName, const char* lastName, const unsigned age);
	Person(const Person& source);
	~Person();
	void SetFirstName(const char* str);
	void SetLastName(const char* str);
	void SetAge(unsigned int str);
	char* GetFirstName();
	char* GetLastName();
	int GetAge();
	Person operator=(Person& source);
	bool operator==(Person& source);
	void Print();
	bool Save(FILE* file_w);
};
