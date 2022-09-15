#include "Worker.h"
#include <iostream>
using namespace std;

Worker::Worker(unsigned salary, unsigned lockerNumber) : Person("V", "B", "D", 28)
{
	Salary = salary;
	LockerNumber = lockerNumber;
}

void Worker::Print()
{
	Person::Print();
	cout << "Salary: " << Salary << endl;
	cout << "Locker Number: " << LockerNumber << endl;
}

double Worker::GetS()
{
	return Salary;
}