#pragma once
#include "Person.h"

/*����������� ����� Worker, ����������� �� Person, ������� ��������� ����:
- Salary - ������ ��
- LockerNumber - ����� ������� ��������

������:
- ������
- �����
- Print()
- �������
- �������*/

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

