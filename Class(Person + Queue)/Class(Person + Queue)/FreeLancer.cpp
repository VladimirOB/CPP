#include "FreeLancer.h"
#include "pch.h"

FreeLancer::FreeLancer(unsigned hourCost, unsigned numbOfHourst) : Person("V", "B", "D", 28)
{
	HourCost = hourCost;
	NumberOfHours = numbOfHourst;
}

FreeLancer::~FreeLancer()
{
	cout << "FreeLancer" << endl;
}

void FreeLancer::Print()
{
	Person::Print();
	cout << "HourCost: " << HourCost << endl;
	cout << "NumberOfHours: " << NumberOfHours << endl;
}

void FreeLancer::SetHourCost(unsigned new_HourCost)
{
	HourCost = new_HourCost;
}

int FreeLancer::GetHourCost()
{
	return HourCost;
}

double FreeLancer:: GetS()
{
	return HourCost * NumberOfHours*30;
}