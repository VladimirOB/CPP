#include "Student.h"
#include "pch.h"

/*Разработать класс Student, наследующий от Person, имеющий следующие поля:
- № студенческого билета
- Stipend - размер стипендии
- RoomNumber - номер комнаты

Методы:
- констр
- дестр
- Print()
- сеттеры
- геттеры*/

Student::Student()
{
	StudentTicket = 777;
	Stipend = 1234;
	RoomNumber = 99;
}

Student::Student(unsigned studTick, unsigned stipend, unsigned roomNumb)
{
	StudentTicket = studTick;
	Stipend = stipend;
	RoomNumber = roomNumb;
}

Student::~Student()
{

}

void Student::Print()
{
	Person::Print();
	cout << "StudentTicket = " << StudentTicket << endl;
	cout << "Stipend = " << Stipend << endl;
	cout << "RoomNumber = " << RoomNumber << endl;
}

void Student::SetStudTicket(unsigned studTick)
{
	StudentTicket = studTick;
}

void Student::SetStipend(unsigned stipend)
{
	Stipend = stipend;
}

void Student::SetRoomNumber(unsigned roomNumb)
{
	RoomNumber = roomNumb;
}

int Student::GetStudTicket()
{
	return StudentTicket;
}

int Student::GetStipend()
{
	return Stipend;
}

int Student::GetRoomNumber()
{
	return RoomNumber;
}