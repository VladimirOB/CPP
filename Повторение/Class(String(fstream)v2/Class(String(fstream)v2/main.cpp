#include <iostream>
using namespace std;
#include "Strings.h"
/*1. ����������� ����� Strings, ����������� ������� ������ ����� � ������� ��������� ����:
- char** str - ������ �����
- MaxRows - ������������ ���������� �����
- CurrentRows - ������� ���������� �����

������ ������:
- ������������ (��� ����������, ����������� ��������� ���������� �����, �����������)
- ����������

- Print() - ������ ������
- Add(char*) - ���������� ������
- Remove(size_t index) - �������� ������ �� ������� (�� �������)
- Strings operator+ (char*) - ���������� ������
- Strings operator+ (const Strings& source) - ����������� ���� ����������� �� �������� (Strings)

- Strings& operator-= (char* str) - ������� ��� ��������� ������ � ����������
- Strings& operator-= (const Strings& source) - ������� ��� ������, ������� ���� �� ������ ���������� sourse
- bool operator == (const Strings& source) - ��������� ���������� 2 ����������
- RemoveDuplicates() - �������� ������������� ����� � ����������
- Sort() - ���������� ����� � ���������� � ���������� �������
������:
Strigs str(5);
str.Add("Hello");
str.Add("world");
str.Add("!!!");

Strigs str2(5);
str2.Add("world");
str2.Add("!!!");

str-=str2;
str.Print(); // Hello

- Save(char* filename) - ���������� � ���� ���������� C++
- Load(char* filename) - �������� �� ����� ���������� C++*/

/*char cnt1[] = "1";
char cnt2[] = "2";
if (strcmp(cnt1, cnt2) == 1)
	cout << "cnt1 > cnt2" << endl;
else
	cout << "cnt1 < cnt2" << endl;*/



	/*2. ��� ������ Strings �������� ��������� ������:
	- istream& operator >> - ��������� ���� 7 ����� � ����������
	- ostream& operator << - ��������� ����� ���� ����� �� �������
	- ifstream& operator >> - ��������� ���� 7 ����� �� ��������� ������
	- ofstream& operator << - ��������� ����� ���� ����� � �������� �������� �����
	- Strings operator+ (Strings&, char*) - ���������� ����� ������ � ����� (� ������������� ������ ���������� �����)
	- Strings operator+ (Strings&, Strings&) - ����������� 2 ����������� ����� (� ������������� ������ ���������� �����)

	��� ��������� ������������� ��� ������� ������� � �������� �������� ������ Strings.*/

int main()
{
	Strings str;
	//str.Add("ALOHA");
	//str.Add("Hello world");
	//str.Add("Okey Jimmy");
	//str.Add("ALOHA");
	//str.Add("Qwerty");
	//str.Add("Hello world");
	//str.RemoveDuplicates();
	//str.Sort();
	//str.Save("1.txt");
	str.Load("1.txt");
	cout << str << endl;

	return 0;
}