#pragma once
#include "Person.h"

/*����������� ����� Freelancer, ����������� �� Person, ������� ��������� ����:
- HourCost - ��������� ���� ������
- NumberOfHours - ���������� ������������ �����

������:
- ������
- �����
- Print()
- �������
- �������*/

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

