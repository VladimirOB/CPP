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
	Person(const char* first, const char* last, const char* adr, unsigned age);
	~Person();
	Person(const Person& source);
	void Print();
	void SetFirstName(const char* str);
	void SetLastName(const char* str);
	void SetAddress(const char* str);
	void SetAge(unsigned age);
	char* GetFirstName();
	char* GetLastName();
	char* GetAddress();
	int GetAge();
};

