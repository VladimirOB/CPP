#pragma once
#include "Person.h"

/*Разработать класс Manager, наследующий от Person, имеющий следующие поля:
- Salary - размер ЗП
- Bonuses - размер денежных бонусов
- RoomNumber - номер личного кабинета
- CarNumber - номер служебного автомобиля

Методы:
- констр
- дестр
- Print()
- сеттеры
- геттеры*/


class Manager : public Person
{
	unsigned Salary; 
	unsigned Bonuses;
	unsigned RoomNumber;
	unsigned CarNumber;

public:
	Manager(unsigned salary, unsigned bonuses, unsigned roomNumber, unsigned carNumber);
	~Manager();
	void Print();
	void SetSalary(unsigned new_sal);
	int GetSalary();
	double GetS();
};



