#pragma once
#include "pch.h"
#include "Word.h"
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
	vector<Word> Sent;

public:
	Sentence();
	Sentence(string);
	Sentence(const Sentence&, Sentence&);
	Sentence operator = (const Sentence&);
	~Sentence();
	void Print();
	friend ostream& operator<< (ostream& os, Sentence& str);
	int Length();
	void Set(string);
	string Get();
	void Add(Word word);
	bool Remove(unsigned index);
	void operator += (Word word);
	Word& operator[] (int pos);
};

