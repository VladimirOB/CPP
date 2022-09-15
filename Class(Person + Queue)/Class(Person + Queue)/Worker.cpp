#include "Worker.h"
#include "pch.h"

Worker::Worker(unsigned salary, unsigned lockerNumber) : Person("V", "B", "D", 28)
{
	Salary = salary;
	LockerNumber = lockerNumber;
}

Worker::~Worker()
{
	cout << "Destr Worker" << endl;
}

void Worker::Print()
{	
	Person::Print();
	cout << "Salary: " << Salary << endl;
	cout << "LockerNumber: " << LockerNumber << endl;
}

void Worker::SetSalary(unsigned new_sal)
{
	Salary = new_sal;
}

int Worker::GetSalary()
{
	return Salary;
}

double Worker::GetS()
{
	return Salary;
}