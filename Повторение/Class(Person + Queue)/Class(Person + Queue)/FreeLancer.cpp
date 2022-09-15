#include "FreeLancer.h"
#include <iostream>
using namespace std;

FreeLancer::FreeLancer(unsigned hourCost, unsigned numberOfHours) : Person("V", "B", "D", 28)
{
	HourCost = hourCost;
	NumberOfHours = numberOfHours;
}

void FreeLancer::Print()
{
	Person::Print();
	cout << "HourCost: " << HourCost << endl;
	cout << "Number Of Hours: " << NumberOfHours << endl;
}

double FreeLancer::GetS()
{
	double result;
	result = HourCost * NumberOfHours;
	return result;
}