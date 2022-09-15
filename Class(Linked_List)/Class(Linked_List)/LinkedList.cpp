#include "LinkedList.h"
#include "pch.h"

Element::Element(const char* str, Element* next)
{
	Str = new char[strlen(str) + 1];
	strcpy(Str, str);
	this->next = next;
}


Element::~Element()
{
	delete[] Str;
}

LinkedList::LinkedList()
{
	First = Last = nullptr;
	count = 0;
}

LinkedList::LinkedList(const LinkedList& source)
{
	this->count = 0;
	if (source.First == nullptr)
	{
		First = Last = nullptr;
		return;
	}
	Element* temp = source.First;

	while (temp != nullptr)
	{
		Add(temp->Str);
		temp = temp->next;
	}
}


LinkedList::~LinkedList()
{
	Element* current = First;
	while (current != nullptr)
	{
		Element* tmp = current;

		current = current->next; // ѕереместить указатель на след. €ч. списка

		delete tmp;
	}
}

void LinkedList::Add(const char* str)
{
	Element* elem = new Element(str, nullptr);

	if (First == nullptr) // ≈сли список пустой.
	{
		First = Last = elem;
	}
	else
	{
		Last->next = elem; // ƒобавить вновь созданную €чейку списка в конец списка.

		Last = elem; // »справить указатель на последнюю €чейку.(ѕереместить в него адрес вновь созданной посл. €чейки).
	}
	count++;
}

void LinkedList::Print()
{
	Element* current = First;
	while (current != nullptr)
	{
		cout << current->Str << " ";

		current = current->next; // ѕереместить указатель на след. €ч. списка
	}
	cout << endl;
}

size_t LinkedList::GetSize()
{
	return count;
}

bool LinkedList::Contains(const char* str)
{
	Element* current = First;
	while (current != nullptr)
	{
		if (strcmp(str, current->Str) == 0)
			return true;
		current = current->next; // ѕереместить указатель на след. €ч. списка
		
	}
	return false;
}

size_t LinkedList::GetCount(const char* str)
{
	Element* current = First;
	size_t cnt = 0; 
	while (current != nullptr)
	{
		if (strcmp(str, current->Str) == 0)
			cnt++;
		current = current->next; // ѕереместить указатель на след. €ч. списка

	}
	return cnt;
}


bool LinkedList::Insert(size_t position,const char* str) 
{
	if (First == nullptr)
	{
		Add(str);
		return true;
	}
	else
	{
		Element* new_elem = new Element(str, NULL);

		if (position == 0)
		{
			//First = new_elem;
			//First->next = current;
			new_elem->next = First;
			First = new_elem;
			count++;
			return true;
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
					prev->next = new_elem;
					new_elem->next = current;
					count++;
					return true;
				}
				prev = current;
				current = current->next;
				current_index++;
			}
			return false;
		}
		
	}
}

ostream& operator << (ostream& os, const LinkedList& lst)
{
	Element* current = lst.First;
	while (current != nullptr)
	{
		cout << current->Str << " ";

		current = current->next; // ѕереместить указатель на след. €ч. списка
	}
	cout << endl;
	
	return os;
}

char*& LinkedList::operator[] (unsigned index)
{
	Element* current = First;
	unsigned current_index = 0;
	while (current != nullptr)
	{
		if (index == current_index)
		{

			return current->Str;
		}
		current = current->next;
		current_index++;
	}
	throw std::out_of_range("Error");
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
				current = current->next;
				delete tmp;
				this->count = 0;
			}
			First = Last = nullptr;
		}

		Element* current = source.First;

		while (current != nullptr)
		{
			Add(current->Str);
			current = current->next;
		}
	}
	
}

bool LinkedList::operator==	(const LinkedList& source) //(сравнивает 2 списка поэлементно)
{
	if (count != source.count)
		return false;

	Element* current = First;
	Element* source_current = source.First;
	while (current != nullptr)
	{
		if(strcmp(current->Str,source_current->Str) !=0)
			return false;
		current = current->next;
		source_current = source_current->next;
	}
	return true;
}

LinkedList& LinkedList::operator+=(const char* str)
{
	Add(str);
	return *this;
}

LinkedList operator+(LinkedList& first, LinkedList& second)
{
	LinkedList new_lst;

	Element* current_first = first.First;
	Element* current_second = second.First;

	while (current_first != nullptr)
	{
		new_lst.Add(current_first->Str);
		current_first = current_first->next;
	}

	while (current_second != nullptr)
	{
		new_lst.Add(current_second->Str);
		current_second = current_second->next;
	}
	return new_lst;
}

void LinkedList::ReplaceAll(const char* str, const char* str2)
{//замена всех вхождений строки str в списке на строку str2

	Element* current = First;
	while (current != nullptr)
	{
		if (strcmp(str, current->Str) == 0)
		{
			if (strlen(str) >= strlen(str2))
				strcpy(current->Str, str2);
			else
				delete[] current->Str;
			current->Str = new char[strlen(str2) + 1];
			strcpy(current->Str, str2);
		}
		current = current->next; // ѕереместить указатель на след. €ч. списка
	}
}

bool LinkedList::Remove(unsigned index)
{
	if (First == nullptr)
	{
		cout << "First = 0" << endl;
		return false;
	}
	if(index < count)
	{
		if (index == 0)
		{
			Element* tmp = First;
			First = First->next;
			delete tmp;
			count--;
			return true;
		}
		else
		{
			Element* current = First;
			Element* prev = current;
			unsigned current_index = 0;
			while (current != nullptr)
			{
				if (index == current_index)
				{
					count--;
					break;
				}
				else
				{
					prev = current; // сохранка
					current = current->next;
					current_index++;
				}
			}
			prev->next = current->next; 
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


bool LinkedList::RemoveAll(const char* str) // удаление из списка всех элементов, содержащих указанную строку
{
	Element* current = First;
	Element* prev = current;
	unsigned cnt_index = 0;

	while (current != 0)
	{
		if (strcmp(str, First->Str) == 0)
		{
			Element* temp = First->next;
			current = current->next;
			delete First;
			First = temp;

			count--;
			cnt_index++;

		}
		else if (strcmp(str, current->Str) == 0)
		{
			prev->next = current->next;

			delete current;
			current = prev->next;

			count--;
			cnt_index++;
		}
		else
		{
			prev = current;
			Last = prev;
			// текущий элемент сдвигаетс€ на следующий
			current = current->next;
		}
	}
	if (cnt_index > 0)
		return true;
	else
		return false;
}


LinkedList& LinkedList::operator- (const char* str)
{
	if (First == nullptr)
	{
		cout << "First is empty" << endl;
		return *this;
	}
	else
	{
		Element* current = First;
		Element* prev = nullptr;

		while (current != nullptr)
		{
			if (strcmp(current->Str, str) == 0)
			{
				prev = current->next;
				RemoveAll(current->Str);
				current = prev;
			}
			else
			{
				current = current->next;
			}
		}
		return *this;
	}
}

LinkedList& LinkedList::operator -= (const LinkedList& source) // удал€ет вхождени€ одного листа в другом.
{
	Element* current = First;
	Element* source_current = source.First;
	Element* temp = nullptr;

	while (source_current != nullptr)
	{
		if (strcmp(current->Str, source_current->Str) == 0)
		{
			temp = current->next;// присвоить текущего темпу, переместить текущий на следующий, удалить темп.
			RemoveAll(current->Str);
			current = temp;
			source_current = source_current->next;
			continue;
		}
		current = current->next;

		if (current == nullptr)
		{
			if(First == nullptr)
				return *this;

			current = First;
			source_current = source_current->next;
		}
	}
	return *this;
}
