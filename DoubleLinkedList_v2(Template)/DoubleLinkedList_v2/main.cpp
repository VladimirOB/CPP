#include "pch.h"
#include "DoubleLinkedList.h"

/*2. � ����� DoubleLinkedList �������� ��������� ������:
- size_t GetSize() - �������� ���������� ����� ������ +++
- bool Contains(char* str) - ���������� true, ���� ������� ����������� ���� �� ��� � ������ +++
- size_t GetCount(char* str) - ���������� ���������� ��������� �������� � ������ +++
- void Insert(size_t position, char* str) - ��������� ������ � ������ ����� ��������� � ������� position +++
- operator << - ����� ������ �� �����

- ����������� ����������� (DoubleLinkedList lst2 = lst) +++
- operator= (DoubleLinkedList lst2; lst2 = lst;) +++
- operator== (���������� 2 ������ �����������) +++
- operator+= (��������� ������� � ����� ������) +++
- operator+ (���������� 2 ������ � ������, ����������� � ���� ������������� �������)
- bool ReplaceAll(const char* str, const char* str2) - ������ ���� ��������� ������ str � ������ �� ������ str2
- bool Remove(insigned index) - �������� �������� �� �������, ����������� ��� ������
- bool RemoveAll(char* str) - �������� �� ������ ���� ���������, ���������� ��������� ������

- void Reverse() - ��������� ������
- Sort() - ���������� ������ (����� �������, ��� ����� �������, ���������� ����������)*/


bool ascend(char* a, char* b)
{
	if (strcmp(a, b) == 1)
		return true;
	else
		return false;
}

bool descend(char* a,char* b)
{
	if (strcmp(a, b) == -1)
		return true;
	else
		return false;
}

int main(void)
{
	DoubleLinkedList <char> list, list2, list3;
	/*list.Add(a);
	list.Add(a);
	list.Add(a);
	list.Insert(0,a);*/

	list.Add("Hello");
	list.Add("World");
	list.RemoveAll("Hello");
	/*list.Add("big");
	list.Add("debug");
	list.Add("lector");
	list.Add("hour");
	list.Add("queue");
	list.Add("aloha");
	list.Add("integral");
	list.Add("zero");
	list.Add("keep");
	list.Add("joba");
	list.Add("apple");
	list.Add("sorting");
	list.Add("wow");
	list.Add("going");
	list.Add("end");
	list.Add("point");*/

	//for (size_t i = 0; i < 2000; i++)
	//{
	//	list.Add("gapsoiubgoasfwgjhj");
	//	list.Add("baapsoiubgodafasdfgsg");
	//}

	//list.Sort(); // � ������ ������� � ������� �������� F11 ���� ����� ������ 2 ������ 24���
	cout << "Time = " << (clock() / 10000.0) << endl;
	cout << list << endl;
}