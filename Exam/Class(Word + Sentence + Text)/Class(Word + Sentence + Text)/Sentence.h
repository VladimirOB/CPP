#pragma once
#include "pch.h"
//����������� ����� Sentence, ����������� ������� ���� �����������, ��������� �� ����, ����� ����� ��������� ����� :
//�	��������� ���� ���� Word
//�	����������� �� ���������
//�	�����������, ����������� ������(char* ��� string) � ��������� � � �����(������ �������������� ������� �� �����, ����������� - ������� � ���������)
//�	����������� �����������
//�	operator =
//�	����������
//�	print - �������� ����������� �� �����
//�	length - ���������� ���������� ���� � �����������
//�	set(char* ��� string) - ������� ����� ����������� � �����
//�	char* get() - ���������� ��� ������ � ������������
//�	void Add(Word word) � ��������� ����� ����� � �����������
//�	bool Remove(unsigned index) � ������� ����� �� �����������
//�	operator += (Word word) � ��������� ����� ����� � �����������
//�	operator[] (int pos) - �������� ������ � ����� � ����������� ��� ������ � ������

class Sentence
{
	vector<string> Word;

public:
	Sentence();
	Sentence(string);
	Sentence(const Sentence&, Sentence&);
	void operator = (const string&);
	~Sentence();
	void Print();
	int Length();
	void set(string);
	void Add(string word);
	bool Remove(unsigned index);
	void operator += (string word);
	string& operator[] (int pos);

};

