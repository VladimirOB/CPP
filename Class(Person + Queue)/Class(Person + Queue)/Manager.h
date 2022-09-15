#pragma once
#include "Person.h"

/*����������� ����� Manager, ����������� �� Person, ������� ��������� ����:
- Salary - ������ ��
- Bonuses - ������ �������� �������
- RoomNumber - ����� ������� ��������
- CarNumber - ����� ���������� ����������

������:
- ������
- �����
- Print()
- �������
- �������*/


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



