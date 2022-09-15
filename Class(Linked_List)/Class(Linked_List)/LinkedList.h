#pragma once
#include "pch.h"
struct Element
{
	char* Str;
	Element* next; // указатель. Занимает 4 байта.
public:
	Element(const char* str, Element* next);
	~Element();
};


class LinkedList
{
	Element* First;
	Element* Last;
	unsigned count;
public:
	LinkedList();
	LinkedList(const LinkedList& source); // +
	~LinkedList();

	void Add(const char* str);
	void Print();
	size_t GetSize();
	bool Contains(const char* str);
	size_t GetCount(const char* str);
	bool Insert(size_t position, const char* str);
	friend ostream& operator << (ostream& os,const LinkedList& lst);
	char*& operator[] (unsigned index);


	LinkedList& operator= (const LinkedList& source);
	bool operator==	(const LinkedList& source);
	LinkedList& operator+=(const char* str);
	friend LinkedList operator+(LinkedList& first, LinkedList& second);
	void ReplaceAll(const char* str, const char* str2);
	bool Remove(unsigned index);
	bool RemoveAll(const char* str);
	
	LinkedList& operator- (const char* str);
	LinkedList& operator -= (const LinkedList& source);
};


