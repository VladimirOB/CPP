#pragma once
#include "pch.h"
struct Element
{
	char* Str; // УКАЗАТЕЛЬ!!
	Element* next; // указатель. Занимает 4 байта.
	Element* prev; // указатель. Занимает 4 байта.
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
	bool operator==	(const DoubleLinkedList& source); //(сравнивает 2 списка поэлементно)
	DoubleLinkedList& operator+=(const char* str);
	friend DoubleLinkedList operator+(const DoubleLinkedList& first, const DoubleLinkedList& second);
	void ReplaceAll(const char* str, const char* str2);
	bool Remove(unsigned index);
	bool RemoveAll(const char* str); // удаление из списка всех элементов, содержащих указанную строку
	bool operator- (const char* str);
	DoubleLinkedList& operator -= (const DoubleLinkedList& source); // удаляет вхождения одного листа в другом.
	void Reverse();
	void Sort();
	void InsertionSort();
};
