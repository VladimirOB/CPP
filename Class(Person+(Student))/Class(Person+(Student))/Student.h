#pragma once
#include "Person.h"
class Student : public Person
{
	unsigned StudentTicket;	//� ������������� ������
	unsigned Stipend;        //- ������ ���������
	unsigned RoomNumber;    //- ����� �������

public:

	Student();
	Student(unsigned studTick, unsigned stipend, unsigned roomNumb);
	~Student();
	void Print();
	void SetStudTicket(unsigned studTick);
	void SetStipend(unsigned stipend);
	void SetRoomNumber(unsigned roomNumb);
	int GetStudTicket();
	int GetStipend();
	int GetRoomNumber();

};

