#pragma once
#include "Person.h"
class Staff
{
	Person** staff;
	size_t CurrentSize;
	size_t MaxSize;
public:
	Staff(size_t size);
	~Staff();
	bool Add(Person* employee);
	void Print();
	double GetS();
};

