#pragma once
#include "Person.h"
class Worker : public Person
{
	unsigned Salary;
	unsigned LockerNumber;
public:
	Worker(unsigned salary, unsigned lockerNumber);
	void Print();
	double GetS();
};

