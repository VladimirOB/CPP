#include "pch.h"
#include "Person.h"


Person::Person()
{
	//puts("Constr");

	FirstName = new char[40];
	strcpy(FirstName, "Vladimir");
	LastName = new char[40];
	strcpy(LastName, "Balaban");
	Age = 27;
}

Person::Person(const char* firstName, const char* lastName, const unsigned age)
{
	//puts("Constr with params");

	FirstName = new char[strlen(firstName) + 1];
	strcpy(FirstName, firstName);
	LastName = new char[strlen(lastName) + 1];
	strcpy(LastName, lastName);
	Age = age;
}

Person::Person(const Person& source)
{
	//cout << "Copy constructor" << endl;

	FirstName = new char[strlen(source.FirstName) + 1];
	strcpy(FirstName, source.FirstName);
	LastName = new char[strlen(source.LastName) + 1];
	strcpy(LastName, source.LastName);
	Age = source.Age;
}



Person::~Person()
{
	//puts("Person destr");
	delete[] FirstName;
	delete[] LastName;
}

void Person::SetFirstName(const char* str)
{
	int size = strlen(str);
	if (size < 40)
	{
		strcpy(FirstName, str);
	}
	else
		cout << "Error. Too big size str!" << endl;
}
void Person::SetLastName(const char* str)
{
	int size = strlen(str);
	if (size < 40)
	{
		strcpy(LastName, str);
	}
	else
		cout << "Error. Too big size str!" << endl;
}
void Person::SetAge(unsigned int n)
{
	Age = n;
}

char* Person::GetFirstName()
{
	return FirstName;
}
char* Person::GetLastName()
{
	return LastName;
}
int Person::GetAge()
{
	return Age;
}

Person Person::operator=(Person& source)
{
	if (FirstName != NULL)
		delete[] FirstName;
	if (LastName != NULL)
		delete[] LastName;
	FirstName = new char[strlen(source.FirstName) + 1];
	strcpy(FirstName, source.FirstName);
	LastName = new char[strlen(source.LastName) + 1];
	strcpy(LastName, source.LastName);
	Age = source.Age;
	
	return *this;
}

bool Person::operator==(Person& source)
{
	if ((strcmp(FirstName, source.FirstName) != 0) or (strcmp(LastName, source.LastName) != 0) or (Age != source.Age))
		return false;
	else
		return true;
}

void Person::Print()
{
	cout << "FirstName: " << FirstName << endl;
	cout << "LastName: " << LastName << endl;
	cout << "Age: " << Age << endl << endl;
}

bool Person::Save(FILE* file_w)
{
	if (file_w != NULL)
	{
		fprintf(file_w, "%s %s %d\n", FirstName, LastName, Age);
		return true;
	}
	else
	{
		cout << "Cannot open file!" << endl;
		return false;
	}
}
