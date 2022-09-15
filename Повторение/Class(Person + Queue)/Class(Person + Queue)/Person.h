#pragma once
class Person
{
	char* FirstName;
	char* LastName;
	char* Address;
	unsigned Age;

public:
	Person(const char* fName, const char* lName, const char* adr, unsigned age);
	virtual ~Person();
	void virtual Print();
	double virtual GetS();

};

