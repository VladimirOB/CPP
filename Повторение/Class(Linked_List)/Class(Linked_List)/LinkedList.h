#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct Element
{
	char* Str; // указатель.
	Element* Next; // указатель. «анимает 4 байта.
public:
	Element(const char* str, Element* next);
	~Element();
};

class LinkedList
{
	Element* First;
	Element* Last;
	unsigned Count;
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& source);
	void Add(const char* str);
	size_t GetSize();
	bool Contains(const char* str);
	size_t GetCount(const char* str);
	void Insert(size_t position, const char* str);
	bool ReplaceAll(const char* str, const char* str2);
	bool Remove(unsigned index);
	bool RemoveAll(const char* str);
	LinkedList& operator = (const LinkedList& source);
	void Print();
	friend ostream& operator << (ostream& os, LinkedList&);
};

