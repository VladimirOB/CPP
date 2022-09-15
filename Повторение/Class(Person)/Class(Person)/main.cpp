#include <iostream>
#include "Person.h"
#include "Group.h"
using namespace std;

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

int main()
{
	Group g;

	g.Add(new Person("Vova", "Bal", 28));
	g.Add(new Person("Vova2", "Bal2", 28));
	g.Add(new Person("Vova3", "Bal3", 28));
	Group g2 = g;
	g2.Print();
	return 0;

}