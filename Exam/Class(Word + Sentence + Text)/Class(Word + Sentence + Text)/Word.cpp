#include "Word.h"
#include "pch.h"

/*������ 1 (7 ������)
����������� ����� Word, ������� ������ ���� �����, ���������� ��������� ����� ������:
�	����������� �� ���������
�	�����������, ����������� ������ (char* ��� string) � ��������� � � ����� (���� ��������� ��������� ���� � ������, �������� ������ ������ �����)
�	����������� �����������
�	operator =
�	����������
�	print - �������� ����� �� �����
�	length - ���������� ���������� �������� � �����
�	set(char* ��� string) - ������� ����� ����� � ����� (������ ������ ����� �� �����)
�	char* get() - ���������� �����
�	operator[] (int pos) - �������� ������ � ������� � ����� ��� ������ � ������
*/

Word::Word()
{
	word += "Hello";
}

Word::Word(const char* str)
{
	stringstream ss(str);
	ss >> word;
	word = std::regex_replace(word, std::regex("[,.!? ]"), "");
}

Word::Word(const Word& source, Word& second)
{
	second = source;
}

void Word::operator = (const string& source)
{
	word = source;
}

Word::~Word()
{
	
}

void Word::Print()
{
	cout << word << endl;
}

int Word::Length()
{
	return word.length();
}

void Word::Set(string str)
{
	stringstream ss(str);
	ss >> word;
	word = std::regex_replace(word, std::regex("[,.!? ]"), "");
}

string Word::get()
{
	return word;
}

char& Word::operator[] (int pos)
{
	if (pos <= word.length())
	{
		return word[pos];
	}
}