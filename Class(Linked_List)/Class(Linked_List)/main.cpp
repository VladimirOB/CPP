#include "pch.h"
#include "LinkedList.h"
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

int main(void)
{
	LinkedList list, list2;
	list.Add("123");
	list.Remove(0);
	list.Add("qwe");
	list += "2";
	cout << list << endl;
	/*list.Add("One");
	list.Add("Two");
	list.Add("Three");
	list.Add("Four");

	list2.Add("Ten");
	list2 = list;
	list2.Add("Odno Slovo");

	list2 -= list;
	cout << "list:" << endl << list << endl;
	
	cout << "list2:" << endl << list2 << endl;
	
	system("pause");
	system("cls");

	LinkedList list3 = list;

	if (list == list2) 
		cout << "list == list2" << endl;
	else cout << "list != list2" << endl;

	list += "Ten";
	LinkedList list4 = list + list2;

	list.ReplaceAll("Two", "Million");
	list.Remove(1);
	list.RemoveAll("Three");
	list - "Four";
	list.RemoveAll("One");
	list.Add("One");
	cout << "list:" << endl << list << endl;
	cout << "list2:" << endl << list2 << endl;
	cout << "list3:" << endl << list3 << endl;
	cout << "list4:" << endl << list4 << endl;*/
	/*cout << "Contains (1 - yes, 0 - no) =  " << lst.Contains("Two") << endl;
	cout << "Count Contains = " << lst.GetCount("Two") << endl;
	cout <<"GetSize = " << lst.GetSize() << endl;*/
}