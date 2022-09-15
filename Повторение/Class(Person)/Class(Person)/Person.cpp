#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(const char* fName, const char* lName, unsigned age)
{
	FirstName = new char[strlen(fName) + 1];
	strcpy(FirstName, fName);
	LastName = new char[strlen(lName) + 1];
	strcpy(LastName, lName);
	Age = age;

}

Person::~Person()
{
	delete[] FirstName, LastName;
}

void Person::Print()
{
	cout << "First Name: " << FirstName << endl;
	cout << "Last Name: " << LastName << endl;
	cout << "Age: " << Age << endl;
}

void Person::SetFirstName(const char* nName)
{
	if (strlen(nName) > strlen(FirstName))
	{
		delete[] FirstName;
		FirstName = new char[strlen(nName) + 1];
		strcpy(FirstName, nName);
	}
	else
		strcpy(FirstName, nName);
}

char* Person::GetFirstName()
{
	return FirstName;
}

char* Person::GetLastName()
{
	return LastName;
}

unsigned Person::GetAge()
{
	return Age;
}

bool Person::operator==(const Person& source)
{
	if (strcmp(FirstName, source.FirstName) != 0 || strcmp(LastName, source.LastName) != 0 || Age != source.Age)
		return false;
	return true;
}