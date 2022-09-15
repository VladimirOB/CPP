#include "Manager.h"
#include "pch.h"

Manager::Manager(unsigned salary, unsigned bonuses, unsigned roomNumber, unsigned carNumber) : Person("V", "B", "D", 28)
{
	Salary = salary;
	Bonuses = bonuses;
	RoomNumber = roomNumber;
	CarNumber = carNumber;
}

Manager::~Manager()
{
	cout << "Destr Manager" << endl;
}

void Manager::Print()
{
	Person::Print();
	cout << "Salary: " << Salary << endl;
	cout << "Bonuses: " << Bonuses << endl;
	cout << "RoomNumber: " << RoomNumber << endl;
	cout << "CarNumber: " << CarNumber << endl;
}

void Manager::SetSalary(unsigned new_sal)
{
	Salary = new_sal;
}

int Manager::GetSalary()
{
	return Salary;
}

double Manager::GetS()
{
	return Salary + Bonuses;
}