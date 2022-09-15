#pragma once
#include "pch.h"
#include "Sentence.h"
/*����������� ����� Text, ����������� ������� �����, ��������� �� �����������, ����� ����� ��������� �����:
�	��������� ����������� ���� Sentence
�	����������� �� ���������
�	�����������, ����������� ������ (char* ��� string) � ��������� � � ����� (������ �������������� ������� �� �����������, ����������� - [.!?])
�	����������� �����������
�	operator =
�	����������
�	operator << �������� ����� �� �����, ������ ����������� �� ����� ������
�	length - ���������� ���������� ����������� � ������
�	set(char* ��� string) - ������� ����� ����� � �����
�	char* get() - ���������� ������ � �������, ���������� ��� ���������� ���� ����������� (����������� - . (�����))
�	void Add(Sentense word) � ��������� ����� ����������� � �����
�	bool Remove(unsigned index) � ������� ����������� �� ������
�	operator += (Word word) � ��������� ����� ����������� � �����
�	operator[] (int pos) - �������� ������ � ����������� � ������ ��� ������ � ������
�	load(char* filename) - �������� ������ �� ����� � ��������� �� �����������, ����������� - [.!?])
�	save(char* filename) - ���������� ������ � ����, ������ ����������� �� ��������� ������, ����������� - . (�����)
�	saveWords(char* filename) - ���������� ������ ���� ���� ������ ��� ���������� � �������
*/
class Text
{
	vector<Sentence> text;

public:
	Text();
	Text(string str);
	Text(const Text& source, Text& second);
	Text operator = (const string& source);
	friend ostream& operator<< (ostream& os, Text& str);
	int Length();
	void Set(string);
	string Get();
	void Add(Sentence word);
	bool Remove(unsigned index);
	void operator += (Sentence word);
	Sentence& operator[] (int pos);
	bool Load(const char* filename);
	bool Save(const char* filename);
	bool saveWords(const char* filename);
};

