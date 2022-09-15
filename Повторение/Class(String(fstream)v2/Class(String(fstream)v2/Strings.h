#pragma once
#include <fstream>
#include <iostream>
using namespace std;
/*- char** str - ������ �����
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
- Sort() - ���������� ����� � ���������� � ���������� �������*/

class Strings
{
	char** Str;
	size_t CurrentRows;
	size_t MaxRows;
public:
	Strings();
	Strings(size_t size);
	Strings(const Strings& source);
	void Print();
	void Add(const char* str);
	bool Remove(size_t index);
	Strings& operator+(const char* str);
	Strings& operator+(const Strings& source);
	Strings& operator -=(const char* str);
	Strings& operator -=(const Strings& source);
	bool operator==(const Strings& source);
	void RemoveDuplicates();
	void Sort();
	bool Save(const char* file_name);
	bool Load(const char* file_name);
	friend ostream& operator << (ostream& os, const Strings& str);
	friend istream& operator >> (istream& is, Strings& str);
	friend Strings operator+ (const Strings& str, const char* new_str);
	friend Strings operator+ (Strings& first, Strings& second);
};

