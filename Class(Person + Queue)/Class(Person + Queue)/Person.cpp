#include "Person.h"
#include "pch.h"

Person::Person(const char* first, const char* last, const char* adr, unsigned age)
{
	FirstName = new char[strlen(first) + 1];
	strcpy(FirstName, first);
	LastName = new char[strlen(last) + 1];
	strcpy(LastName, last);
	Address = new char[strlen(adr) + 1];
	strcpy(Address, adr);
	Age = age;
}

Person::~Person()
{
	cout << "Destr Person" << endl;
	delete[] FirstName;
	delete[] LastName;
	delete[] Address;
}

void Person::Print()
{
	cout << "First Name: " << FirstName << endl;
	cout << "Last Name: " << LastName << endl;
	cout << "Address: " << Address << endl;
	cout << "Age: " << Age << endl;
}

void Person::SetFirstName(const char* str)
{
	if (strlen(FirstName) >= strlen(str))
	{
		strcpy(FirstName, str);
	}
	else
		delete[] FirstName;
	FirstName = new char[strlen(str) + 1];
	strcpy(FirstName, str);
}

char* Person::GetFirstName()
{
	return FirstName;
}

double Person::GetS()
{
	return 0;
}