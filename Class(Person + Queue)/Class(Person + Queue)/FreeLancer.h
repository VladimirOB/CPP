#pragma once
#include "Person.h"

/*Разработать класс Freelancer, наследующий от Person, имеющий следующие поля:
- HourCost - стоимость часа работы
- NumberOfHours - количество отработанных часов

Методы:
- констр
- дестр
- Print()
- сеттеры
- геттеры*/

class FreeLancer : public Person
{
	unsigned HourCost;
	unsigned NumberOfHours;
	
public:
	FreeLancer(unsigned hourCost, unsigned numbOfHourst);
	~FreeLancer();
	void Print();
	void SetHourCost(unsigned new_HourCost);
	int GetHourCost();
	double GetS();
};

