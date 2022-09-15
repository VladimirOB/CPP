#include "Person.h"
#include "Worker.h"
#include "FreeLancer.h"
#include "Staff.h"
#include <iostream>
using namespace std;
Staff::Staff(size_t size)
{
	MaxSize = size;
	CurrentSize = 0;
	staff = new Person * [MaxSize];
}

Staff::~Staff()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		delete[] staff[i];
	}
	delete[] staff;
}

bool Staff::Add(Person* employee)
{
	if (CurrentSize < MaxSize)
	{
		staff[CurrentSize++] = employee;
		return true;
	}
	else
	{
		cout << "Error" << endl;
		return false;
	}
}

void Staff::Print()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		//полиморфный вызов метода Print() у правильного наследника.
		staff[i]->Print();
	}
}

double Staff::GetS()
{
	double result = 0;

	for (size_t i = 0; i < CurrentSize; i++)
	{
		result += staff[i]->GetS();
	}
	return result;
}

