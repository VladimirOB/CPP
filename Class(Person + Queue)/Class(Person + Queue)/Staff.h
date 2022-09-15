#pragma once
#include "Person.h"

/*����������� ����� Staff (����������), ������� ��������� ����:
- Person** staff - ������ �����������
- MaxSize - ���� ����� ����
- CurrentSize - ��� ����� ����

������:
- ������
- �����
- Add(Person* ) - �������� ����������
- Print() - ������ ���� �����������
- GetSalariesSum() - ��������� ����� ������� �� ��
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

