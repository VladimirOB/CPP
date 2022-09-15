#pragma once
#include "Person.h"
class FreeLancer : public Person
{
	unsigned HourCost;
	unsigned NumberOfHours;
public:
	FreeLancer(unsigned hourCost, unsigned numberOfHours);
	void Print();
	double GetS();
};

