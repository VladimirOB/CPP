#pragma once
#include "pch.h"
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
	vector<string> Sentence;

public:
	Text();
	Text(string str);
	Text(const Text& source, Text& second);
	void operator = (const string& source);
	friend ostream& operator<< (ostream& os, Text& str);
	int Length();
	void Set(string);
	char* get();
	void Add(string word);
	bool Remove(unsigned index);
	void operator += (string word);
	string& operator[] (int pos);
	bool Load(const char* filename);
	bool Save(const char* filename);
	bool saveWords(const char* filename);
};

