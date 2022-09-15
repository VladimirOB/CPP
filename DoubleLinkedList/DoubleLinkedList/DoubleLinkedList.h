#pragma once
#include "pch.h"
struct Element
{
	char* Str; // ���������!!
	Element* next; // ���������. �������� 4 �����.
	Element* prev; // ���������. �������� 4 �����.
public:

	Element(const char* str, Element* prev, Element* next);
	~Element();
};

class DoubleLinkedList
{
	Element* First;
	Element* Last;
	unsigned count;
	typedef bool (*comparator)(char* a, char* b);
	comparator Comp;
public:
	DoubleLinkedList();
	DoubleLinkedList(comparator comp);
	DoubleLinkedList(const DoubleLinkedList& source);
	~DoubleLinkedList();
	void Add(const char* str);
	void Print();
	void PrintBack();
	size_t GetSize();
	bool Contains(const char* str);
	size_t GetCount(const char* str);
	bool Insert(size_t position,const char* str);
	bool EqualsReverse(const DoubleLinkedList& list2);
	friend ostream& operator << (ostream& os, const DoubleLinkedList& lst);
	char*& operator[] (unsigned index);
	DoubleLinkedList& operator= (const DoubleLinkedList& source);
	bool operator==	(const DoubleLinkedList& source); //(���������� 2 ������ �����������)
	DoubleLinkedList& operator+=(const char* str);
	friend DoubleLinkedList operator+(const DoubleLinkedList& first, const DoubleLinkedList& second);
	void ReplaceAll(const char* str, const char* str2);
	bool Remove(unsigned index);
	bool RemoveAll(const char* str); // �������� �� ������ ���� ���������, ���������� ��������� ������
	bool operator- (const char* str);
	DoubleLinkedList& operator -= (const DoubleLinkedList& source); // ������� ��������� ������ ����� � ������.
	void Reverse();
	void Sort();
	void InsertionSort();
};
