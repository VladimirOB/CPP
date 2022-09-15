#pragma once
#include "Person.h"

/*Разработать класс Worker, наследующий от Person, имеющий следующие поля:
- Salary - размер ЗП
- LockerNumber - номер личного шкафчика

Методы:
- констр
- дестр
- Print()
- сеттеры
- геттеры*/

class Worker : public Person
{
	unsigned Salary;
	unsigned LockerNumber;
	
public:

	Worker(unsigned salary, unsigned lockerNumber);
	~Worker();
	void Print();
	void SetSalary(unsigned new_sal);
	int GetSalary();
	double GetS();

};

