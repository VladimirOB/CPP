#include "Person.h"
#include "pch.h"

Person::Person()
{
	char first[] = "Vladimir";
	char last[] = "Balaban";
	char adr[] = "Earth";
	FirstName = new char[strlen(first)+1]; 
	LastName = new char[strlen(last)+1];
	Address = new char[strlen(adr)+1];
	strcpy(FirstName, first);
	strcpy(LastName, last);
	strcpy(Address, adr);
	Age = 28;
}

Person::Person(const char* first, const char* last, const char* adr, unsigned age)
{
	FirstName = new char[strlen(first)+1]; 
	LastName = new char[strlen(last)+1];
	Address = new char[strlen(adr)+1];
	strcpy(FirstName, first);
	strcpy(LastName, last);
	strcpy(Address, adr);
	Age = 28;
}

Person::Person(const Person& source)
{
	FirstName = new char[strlen(source.FirstName) + 1];
	strcpy(FirstName, source.FirstName);
	LastName = new char[strlen(source.LastName) + 1];
	strcpy(LastName, source.LastName);
	Address = new char[strlen(source.Address) + 1];
	strcpy(Address, source.Address);
	Age = source.Age;
}

Person::~Person()
{
	delete[] FirstName;
	delete[] LastName;
	delete[] Address;
}

void Person::Print()
{
	cout << "First Name: " << FirstName << endl;
	cout << "Last NAme: " << LastName << endl;
	cout << "Address: " << Address << endl;
	cout << "Age: " << Age << endl;
}

void Person::SetFirstName(const char* str)
{
	int len = strlen(str)+1;
	if (len > strlen(FirstName))
	{
		delete[] FirstName;
		FirstName = new char[len];
		strcpy(FirstName, str);
	}
	else
	{
		strcpy(FirstName, str);
	}
}

void Person::SetLastName(const char* str)
{
	int len = strlen(str) + 1;
	if (len > strlen(LastName))
	{
		delete[] LastName;
		LastName = new char[len];
		strcpy(LastName, str);
	}
	else
	{
		strcpy(LastName, str);
	}
}

void Person::SetAddress(const char* str)
{
	int len = strlen(str) + 1;
	if (len > strlen(Address))
	{
		delete[] Address;
		Address = new char[len];
		strcpy(Address, str);
	}
	else
	{
		strcpy(Address, str);
	}
}

void Person::SetAge(unsigned age)
{
	Age = age;
}

char* Person::GetFirstName()
{
	return FirstName;
}

char* Person::GetLastName()
{
	return LastName;
}

char* Person::GetAddress()
{
	return Address;
}

int Person::GetAge()
{
	return Age;
}