#pragma once
#include "Person.h"
class Student : public Person
{
	unsigned StudentTicket;
	unsigned Stipend;
	unsigned RoomNumber;
public:
	Student();
	Student(unsigned studTicket, unsigned stipend, unsigned roomNumber);
	~Student();
	void Print();
	void SetStudentTicket(unsigned studentTicket);
	int GetStudentTicket();
};

