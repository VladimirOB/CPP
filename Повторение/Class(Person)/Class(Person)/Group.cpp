#include "Group.h"
#include <iostream>
using namespace std;

Group::Group()
{
	MaxSize = 10;
	CurrentSize = 0;
	People = new Person * [MaxSize];
}

Group::Group(const Group& source)
{
	CurrentSize = 0;
	MaxSize = source.MaxSize;
	People = new Person * [MaxSize];
	for (size_t i = 0; i < source.CurrentSize; i++)
	{
		Person* person = new Person(*source.People[i]);
		Add(person);
	}
}

Group::~Group()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		delete People[i];
	}
	delete[] People;
}

void Group::Print()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		 People[i]->Print();
	}
}

bool Group::Add(Person* person)
{
	if (CurrentSize < MaxSize)
	{
		People[CurrentSize++] = person;
		return true;
	}
	else
	{
		unsigned new_size = MaxSize + 3;
		Person** new_people = new Person * [new_size];
		size_t i = 0;
		for ( ; i < CurrentSize; i++)
		{
			new_people[i] = People[i];
		}
		new_people[i] = person;
		delete[] People;
		MaxSize = new_size;
		People = new_people;
		CurrentSize++;
	}
}

Group& Group::Remove(unsigned index)
{
	if (index < CurrentSize)
	{
		Group result = *this;
		for (size_t i = 0; i < CurrentSize; i++)
		{
			if (i == index)
			{
				Person* person = new Person(*People[i]);
				result.Delete(person);
			}
		}

		*this = result;
		return result;
	}
}

void Group::Delete(Person* person)
{
	Person** new_peoples = new Person * [--MaxSize];
	size_t i = 0, cnt = 0;

	for (; i < CurrentSize; i++)
	{
		if (*People[i] == *person)
			continue;
		else
			new_peoples[cnt++] = People[i];
	}
	CurrentSize--;
	delete[] People;
	People = new_peoples;
}

Group Group::Remove(Person* person)
{
	Group result;
	return result;
}

bool Group::operator ==(const Group& source)
{
	if (CurrentSize != source.CurrentSize || MaxSize != source.MaxSize)
		return false;
	for (size_t i = 0; i < CurrentSize; i++)
	{
		if (strcmp(People[i]->GetFirstName(), source.People[i]->GetFirstName()) != 0 && strcmp(People[i]->GetLastName(), source.People[i]->GetLastName()) != 0 && People[i]->GetAge() != source.People[i]->GetAge())
			return false;
	}
	return true;

}

bool Group::Save(const char* fileName)
{
	return false;
}

bool Group::Load(const char* fileName)
{
	return false;
}