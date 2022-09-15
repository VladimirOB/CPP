#include "pch.h"
#include "Person.h"
#include "Student.h"
#include "Stack.h"

int main(void)
{
	/*Person person("Vova","Balaban", "Earth", 28);
	person.SetFirstName("Vodoley");
	Student student;
	student.Print();
	cout << endl;
	student.SetAddress("China");
	student.SetRoomNumber(65535);
	student.Print();*/

	Stack stack(5);
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Print();
	int pop = stack.Pop();
	cout << "pop = " << pop << endl;
	int show = stack.Show();
	cout << "show = " << show << endl;
	stack.Print();
}