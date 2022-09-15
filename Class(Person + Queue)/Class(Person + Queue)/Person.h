#pragma once
/*1. Разработать класс Person, имеющий следующие поля:
- FirstName
- LastName
- Age
- Address

Методы:
- констр
- дестр
- Print()
- сеттеры
- геттеры*/
class Person
{
	char* FirstName;
	char* LastName;
	char* Address;
	unsigned Age;

public:
	Person(const char* first, const char* last, const char* adr, unsigned age);
	virtual ~Person();
	void SetFirstName(const char* str);
	char* GetFirstName();

	void virtual Print();
	double virtual GetS();
};

