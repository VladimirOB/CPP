#include "LinkedList.h"
#include <iostream>
using namespace std;

Element::Element(const char* str, Element* next)
{
	Str = new char[strlen(str) + 1];
	strcpy(Str, str);
	Next = next;
}

Element::~Element()
{
	delete[] Str;
}

LinkedList::LinkedList()
{
	First = Last = nullptr;
	Count = 0;
}

LinkedList::~LinkedList()
{
	Element* current = First;

	while (current != nullptr)
	{
		Element* tmp = current;
		current = current->Next;
		delete tmp;
	}
}

LinkedList::LinkedList(const LinkedList& source)
{
	Count = 0;
	if (source.First == nullptr)
	{
		First = Last = nullptr;
		return;
	}
	Element* temp = source.First;
	while (temp != nullptr)
	{
		Add(temp->Str);
		temp = temp->Next;
	}
}

void LinkedList::Add(const char* str)
{
	Element* elem = new Element(str, nullptr);
	if (First == nullptr)
	{
		First = Last = elem;
	}
	else
	{
		Last->Next = elem;
		Last = elem;
	}
	Count++;
}

size_t LinkedList::GetSize()
{
	return Count;
}

bool LinkedList::Contains(const char* str)
{
	Element* current = First;
	while (current != nullptr)
	{
		if (strcmp(current->Str, str) == 0)
			return true;
		current = current->Next;
	}
	return false;
}

size_t LinkedList::GetCount(const char* str)
{
	Element* current = First;
	size_t cnt = 0;
	while (current != nullptr)
	{
		if (strcmp(current->Str, str) == 0)
			cnt++;
		current = current->Next;
	}
	return cnt;
}

void LinkedList::Insert(size_t position, const char* str)
{
	if (First == nullptr)
	{
		Add(str);
		return;
	}

	Element* new_elem = new Element(str, nullptr);

	if (position == 0)
	{
		new_elem->Next = First;
		First = new_elem;
		Count++;
		return;
	}
	else
	{
		Element* current = First;
		Element* prev = nullptr;
		unsigned current_index = 0;
		while (current != nullptr)
		{
			if (position == current_index)
			{
				prev->Next = new_elem;
				new_elem->Next = current;
				Count++;
				return;
			}
			prev = current;
			current_index++;
			current = current->Next;
		}
	}
}

bool LinkedList::ReplaceAll(const char* str, const char* str2)
{
	Element* current = First;
	while (current != nullptr)
	{
		if (strcmp(current->Str, str) == 0)
		{
			if(strlen(str2) <= strlen(str))
			strcpy(current->Str, str2);
			else
			{
				delete[] current->Str;
				current->Str = new char[strlen(str2) + 1];
				strcpy(current->Str, str2);
			}
		}
		current = current->Next;
	}
}

bool LinkedList::Remove(unsigned index)
{
	if (First == nullptr)
		return false;
	if (index < Count)
	{
		if (index == 0)
		{
			Element* temp = First;
			First = First->Next;
			delete temp;
			Count--;
			return true;
		}
		else
		{
			Element* current = First;
			Element* prev = First;
			unsigned current_index = 0;
			while (current != nullptr)
			{
				if (index == current_index)
				{
					Count--;
					break;
				}
				else
				{

					prev = current;
					current = current->Next;
					current_index++;
				
				}
			}
			prev->Next = current->Next;
			Last = prev;
			delete current;
			return true;
		}
		
	}
	else
	{
		cout << "Cant' remove. No match found." << endl;
		return false;
	}
}

bool LinkedList::RemoveAll(const char* str)
{
	Element* current = First;
	Element* prev = current;
	unsigned current_index = 0;

	while (current != 0)
	{
		if (strcmp(str, First->Str) == 0)
		{
			Element* temp = First->Next;
			current = current->Next;
			delete temp;
			Count--;
			current_index++;
		}
		else if (strcmp(str, current->Str) == 0)
		{
			prev->Next = current->Next;

			delete current;
			current = prev->Next;
			Count--;
			current_index++;
		}
		else
		{
			prev = current;
			Last = prev;
			current = current->Next;
		}
	}
	if (current_index > 0)
		return true;
	else
		return false;
}

LinkedList& LinkedList::operator= (const LinkedList& source)
{
	if (source.First == nullptr)
	{
		First = Last = nullptr;
		return *this;
	}
	else
	{
		if (First != nullptr)
		{
			Element* current = First;
			while (current != nullptr)
			{
				Element* tmp = current;
				current = current->Next;
				delete tmp;
			}
			Count = 0;
			First = Last = nullptr;
		}

		Element* current = source.First;
		while (current != nullptr)
		{
			Add(current->Str);
			current = current->Next;
		}
	}
}




void LinkedList::Print()
{
	Element* current = First;
	while (current != nullptr)
	{
		cout << current->Str << " ";
		current = current->Next;
	}
	cout << endl;
}

ostream& operator << (ostream& os, LinkedList& lst)
{
	Element* current = lst.First;
	while (current != nullptr)
	{
		os << current->Str << " ";
		current = current->Next;
	}
	os << endl;
	return os;
}