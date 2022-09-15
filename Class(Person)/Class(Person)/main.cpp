#include "pch.h"
#include "Person.h"
#include "Group.h"
/*1. Разработать класс Person, имеющий следующие поля:
- char* FirstName
- char* Lastname
- unsigned Age;

- конструкторы (без параметров, копирования, с размерами)
- деструктор
- void Print() - печать группы

- сеттеры / геттеры

2. Разработать класс Group, имеющий следующие поля:
- Person** people
- MaxLength - максимальная длина группы
- CurrentLength - текущий размер группы

Методы:
- конструкторы (без параметров, копирования, с размерами)
- деструктор
- void Print() - печать группы
- Add(Person*)
- Remove(unsigned index) - удаление по позиции
- Remove(Person*) - удаление по значению
- bool Save(char* filename)
- bool Load(char* filename)

Операторы:
- operator== - сравнение групп друг с другом
- operator= - оператор присваивания

- operator+ (Person*)
- operator+ (const Group&) - объединение групп
- operator+= (Person*)
- operator -= (Person*) - удаление по значению
- operator- (Person*) - удаление по значению с возвратом новой группы

Пример:

Group group(5);
group.Add(new Person(....));

group+=(new Person(....));

group.Save("file.dat");
group.Load("file.dat");

*/

int main(void)
{
	Group group(2); Group group2(3); Group group3(3); // создание групп.

	group.Add(new Person("Tolya", "Samosval", 82));
	/*group.Add(new Person("Jeka", "Vishnya", 27));
	group +=(new Person("Valentin", "Ochkov", 21));
	group += (new Person("Oleg", "Shurupov", 12));
	group -= (new Person("Jeka", "Vishnya", 27));
	group.Add(new Person("Jeka", "Vishnya", 27));
	group.Remove(new Person("Jeka", "Vishnya", 27));
	group += (new Person("Jeka", "Vishnya", 27));
	group.Remove_Index(3);
	group += (new Person("Jeka", "Vishnya", 27));

	cout << "Group(1): " << endl;
	group.Print();
	group.Save("group.txt");

	group2 = group - (new Person("Jeka", "Vishnya", 27));
	cout << "Group(2): " << endl;
	group2.Print();
	
	group3.Load("group.txt");
	cout << "Group(3): " << endl;
	group3.Print();


	cout << "G = G + G2" << endl;
	group = group + group2;
	group.Print();*/
	
}