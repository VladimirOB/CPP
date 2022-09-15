#pragma once
#include "Person.h"

class Group
{
	Person** People;
	size_t CurrentSize;
	size_t MaxSize;
public:
	Group();
	Group(const Group& source);
	~Group();
	void Print();
	bool Add(Person* person);
	Group& Remove(unsigned index);
	Group Remove(Person* person);
	void Delete(Person* person);
	bool operator ==(const Group& source);
	bool Save(const char* fileName);
	bool Load(const char* fileName);
};
