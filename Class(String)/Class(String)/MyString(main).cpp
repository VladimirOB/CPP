#include "pch.h"
#include "MyString.h"
/*1. ����������� ����� MyString, ������� ��������� ����:
- char* Str (��������� �� ������)
- MaxSize - (������������ ������ ������)

������ ������
- ������������� (�� ���������, ��� ��������� �-������)
- ����������
- void Print()
- Set("test") - ��������� ������ � ������
- char* Get() - ���������� ������ �� ������A
- int GetLength() - �������� ������� ������ ������
- int GetVowelsCount() - �������� ���������� �������
- void ToUpper() - ��������� ������ � ������� �������
- void ToLower() - ��������� ������ � ������ �������
- void RemoveDigits() - ������� ��� ����� �� ������
- void SaveToFile() - ��������� ������ � ��������� ����.
- void LoadFromFile(); - ��������� ������ �� �����.
������:
MyString str("Hello world!!!!");
str.Print();
char* tst = str.Get();
int len = str.GetLength();*/

int main(void)
{
	MyString str("Good hello world my big", 39);
	str.Print();

	str.Set("Balaban Vova 1 sa say");
	str.Print();

	//char* str_get = str.Get();

	//int len = str.GetLength();
	//cout << "String length = " << len << endl;

	//int vow = str.GetVowelsCount(0);
	//cout << "Number of vowels = " << vow << endl;

	//str.ToUpper();
	//str.Print();

	//str.ToLower();
	//str.Print();

	//str.RemoveDigits();
	//str.Print();

	//str.SaveToFile();

	//str.LoadFromFile();
	//str.Print();

	cout << str.Contains("say") << endl;
	cout << str.Contains("Nooka") << endl;
}