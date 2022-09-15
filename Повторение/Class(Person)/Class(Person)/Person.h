#pragma once
class Person
{
	char* FirstName;
	char* LastName;
	unsigned Age;
public:
	Person(const char* fName, const char* lName, unsigned age);
	~Person();
	void Print();
	void SetFirstName(const char* nName);
	char* GetFirstName();
	char* GetLastName();
	unsigned GetAge();
	bool operator==(const Person& source);
};

