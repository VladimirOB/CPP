#pragma once
#include "Person.h"

class Group
{
	Person** Peoples;
	size_t  MaxMembers;
	size_t CurrentMember;

public:
	Group();
	Group(size_t maxMembers);
	Group(const Group& source); // copy
	~Group();

	void Add(Person* person);
	void Del(Person* person);
	void Print();

	bool Save(const char* fileName);
	bool Load(const char* fileName);

	Group Remove(Person* person);
	Group& Remove_Index(int index);
	bool operator==(Group& source);
	Group& operator=(const Group& source);
	Group operator+(Person* person); 
	Group operator+ (const Group& source);
	void operator+=(Person*); // add
	Group& operator-=(Person* person);
	Group operator-(Person* person);
	
};