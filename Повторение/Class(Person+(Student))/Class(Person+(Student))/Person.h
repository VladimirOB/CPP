#pragma once
class Person
{
protected:
	char* FirstName;
	char* LastName;
	char* Address;
	unsigned Age;
public:
	Person();
	Person(const char* fName, const char* lName, const char* adr, unsigned age);
	~Person();
	Person(const Person& source);
	void Print();
	void SetFirstName(const char* fName);
	char* GetFirstName();
};

