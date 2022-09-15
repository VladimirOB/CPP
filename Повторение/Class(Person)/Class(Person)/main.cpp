#include <iostream>
#include "Person.h"
#include "Group.h"
using namespace std;

/*1. ����������� ����� Person, ������� ��������� ����:
- char* FirstName
- char* Lastname
- unsigned Age;

- ������������ (��� ����������, �����������, � ���������)
- ����������
- void Print() - ������ ������

- ������� / �������

2. ����������� ����� Group, ������� ��������� ����:
- Person** people
- MaxLength - ������������ ����� ������
- CurrentLength - ������� ������ ������

������:
- ������������ (��� ����������, �����������, � ���������)
- ����������
- void Print() - ������ ������
- Add(Person*)
- Remove(unsigned index) - �������� �� �������
- Remove(Person*) - �������� �� ��������
- bool Save(char* filename)
- bool Load(char* filename)

���������:
- operator== - ��������� ����� ���� � ������
- operator= - �������� ������������

- operator+ (Person*)
- operator+ (const Group&) - ����������� �����
- operator+= (Person*)
- operator -= (Person*) - �������� �� ��������
- operator- (Person*) - �������� �� �������� � ��������� ����� ������

������:

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