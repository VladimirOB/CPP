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

Word::Word(string str)
{
	stringstream ss(str);
	ss >> word;
	word = std::regex_replace(word, std::regex("[,.!? \t]"), "");
}

Word::Word(const Word& source, Word& second)
{
	second = source;
}

Word Word::operator=(const Word& second)
{
	word = second.word;
	return *this;
}

Word::~Word()
{
	
}


void Word::Print()
{
	cout << word << endl;
}

ostream& operator<< (ostream& os, Word& str)
{
	for (size_t i = 0; i < str.word.size(); i++)
	{
		os << str[i];
	}
	return os;
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

const string Word::Get()
{
	return word;
}

char& Word::operator[] (int pos)
{
	if (pos < word.length())
	{
		return word[pos];
	}
}