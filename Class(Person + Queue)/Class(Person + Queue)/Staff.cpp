#include "pch.h"
#include "Person.h"
#include "Worker.h"
#include "Manager.h"
#include "FreeLancer.h"
#include "Staff.h"

Staff::Staff(size_t size)
{
	Staff_E = new Person * [size];
	MaxSize = size;
	CurrentSize = 0;
}

Staff::~Staff()
{
	cout << "Staff destr" << endl;
	for (size_t i = 0; i < CurrentSize; i++)
	{
		delete[] Staff_E[i];
	}
	delete[] Staff_E;
}

bool Staff::Add(Person* employee)
{
	if (CurrentSize < MaxSize)
	{
		Staff_E[CurrentSize++] = employee;
	}
	else
	{
		cout << "There is no space left for another figure!" << endl;
		return false;
	}
}

void Staff::Print()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		//полиморфный вызов метода Print() у правильного наследника.
		Staff_E[i]->Print();
	}
}

double Staff::GetS()
{
	double result = 0;
	
	for (size_t i = 0; i < CurrentSize; i++)
	{
		// полиморф. вызов метода GetSalary у прав. наследника
		result += Staff_E[i]->GetS();
	}
	return result;
}