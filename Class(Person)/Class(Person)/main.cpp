#include "pch.h"
#include "Person.h"
#include "Group.h"
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

int main(void)
{
	Group group(2); Group group2(3); Group group3(3); // �������� �����.

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