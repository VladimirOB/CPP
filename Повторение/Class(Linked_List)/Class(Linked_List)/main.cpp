#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LinkedList.h"
using namespace std;


/*
	��������
	size_t GetSize() - �������� ���-�� ����� ������. ����� ������� � ���������� � �������
	bool Contains(char* str) - ���������� true, ���� ������� ����������� ���� 1 ���. (�� / ���)
	size_t GetCount(char* str) - ���������� ���������� ��������� �������� � ������.
	void Insert(size_t position, char* str) - ��������� ������ � ������ ����� ��������� � ������� position
	operator << - ����� ������ �� �����
*/

/*- ����������� ����������� (LinkedList lst2 = lst)
- operator= (LinkedList lst2; lst2 = lst;)
- operator== (���������� 2 ������ �����������)
- operator+= (��������� ������� � ����� ������)
- operator+ (���������� 2 ������ � ������, ����������� � ���� ������������� �������)
- bool ReplaceAll(const char* str, const char* str2) - ������ ���� ��������� ������ str � ������ �� ������ str2
- bool Remove(unsigned index) - �������� �������� �� �������, ����������� ��� ������
- bool RemoveAll(char* str) - �������� �� ������ ���� ���������, ���������� ��������� ������
- operator- (const char* str) - �������� �� ������ ���� ��������� ���������� ��������� ������
- operator -= (const LinkedList& source) // ������� ��� ������, ������� ���� �� 2�
*/

int main()
{
	LinkedList lst;
	lst.Add("Hello");
	lst.Add("World");
	lst.Insert(1, "qwer");
	cout << lst ;
	return 0;
}