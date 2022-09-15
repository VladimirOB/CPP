#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(const char* fName, const char* lName, const char* adr, unsigned age)
{
	FirstName = new char[strlen(fName) + 1];
	strcpy(FirstName, fName);
	LastName = new char[strlen(lName) + 1];
	strcpy(LastName, lName);
	Address = new char[strlen(adr) + 1];
	strcpy(Address, adr);
	Age = age;
}

Person::~Person()
{
	delete[] FirstName, LastName, Address;
}

void Person::Print()
{
	cout << "First Name: " << FirstName << endl;
	cout << "Last Name: " << LastName << endl;
	cout << "Address: " << Address << endl;
	cout << "Age: " << Age << endl;
}

double Person::GetS()
{
	return 0;
}