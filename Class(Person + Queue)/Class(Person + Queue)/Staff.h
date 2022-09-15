#pragma once
#include "Person.h"

/*Разработать класс Staff (Сотрудники), имеющий следующие поля:
- Person** staff - массив сотрудников
- MaxSize - макс колво сотр
- CurrentSize - тек колво сотр

Методы:
- констр
- дестр
- Add(Person* ) - добавить сотрудника
- Print() - печать всех сотрудников
- GetSalariesSum() - посчитать общие расходы на ЗП
*/

class Staff
{
	Person** Staff_E;
	size_t MaxSize;
	size_t CurrentSize;

public:

	Staff(size_t size);
	~Staff();

	bool Add(Person* employee);
	void Print();
	double GetS();

};

