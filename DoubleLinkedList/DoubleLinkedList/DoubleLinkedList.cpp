#include "DoubleLinkedList.h"
#include "pch.h"

bool asc(char* a, char* b)
{
	return strcmp(a, b) == -1;
	
}

Element::Element(const char* str, Element* prev, Element* next)
{
	Str = new char[strlen(str) + 1];
	strcpy(Str, str);
	this->next = next;
	this->prev = prev;
}

Element::~Element()
{
	delete[] Str;
}

DoubleLinkedList::DoubleLinkedList()
{
	First = Last = nullptr;
	count = 0;
	Comp = asc;
}

DoubleLinkedList::DoubleLinkedList(comparator comp)
{
	First = Last = nullptr;
	count = 0;
	Comp = comp;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& source)
{
	this->count = 0;
	if (source.First == nullptr)
	{
		First = Last = nullptr;
		Comp = 0;
		return;
	}

	First = Last = nullptr;

	Element* temp = source.First;

	while (temp != nullptr)
	{
		Add(temp->Str);
		temp = temp->next;
	}
	Comp = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
	Element* current = First;
	while (current != nullptr)
	{
		Element* tmp = current;

		current = current->next; // ѕереместить указатель на след. €ч. списка

		delete tmp;
	}
}

void DoubleLinkedList::Add(const char* str)
{
	Element* elem = new Element(str, nullptr, nullptr);

	if (First == nullptr) // ≈сли список пустой.
	{
		First = Last = elem;
	}
	else
	{
		Last->next = elem; // ƒобавить вновь созданную €чейку списка в конец списка.

		// добавить в новую €чейку адрес предыдущего элемента (пока он последний)
		elem->prev = Last;


		Last = elem; // »справить указатель на последнюю €чейку.(ѕереместить в него адрес вновь созданной посл. €чейки).
	}
	count++;
}

void DoubleLinkedList::Print()
{
	Element* current = First;
	while (current != nullptr)
	{
		cout << current->Str << " ";
		current = current->next; // ѕереместить указатель на след. €ч. списка
	}
	cout << endl;
}

void DoubleLinkedList::PrintBack()
{
	Element* current = Last;
	while (current != nullptr)
	{
		cout << current->Str << " ";

		// переместить текущий указатель на следующую €чейку списка
		current = current->prev;
	}
	cout << endl;
}

size_t DoubleLinkedList::GetSize()
{
	return count;
}

bool DoubleLinkedList::Contains(const char* str)
{
	Element* current_start = First;
	Element* current_end = Last;
	while (current_start != nullptr || current_end != nullptr)
	{
		if (current_start != nullptr)
			if (strcmp(str, current_start->Str) == 0)
				return true;
		if (strcmp(str, current_end->Str) == 0)
			return true;
		if (current_start != nullptr)
			current_start = current_start->next; // ѕереместить указатель на след. €ч. списка
		current_end = current_end->prev;
	}
	return false;
}

size_t DoubleLinkedList::GetCount(const char* str)
{
	Element* current_start = First;
	Element* current_end = Last;
	unsigned index_current = 0, count_temp = 0;
	if (count % 2 == 0)
		count_temp = count / 2;
	else
		count_temp = (count / 2) + 1;
	size_t cnt = 0;
	while (current_start != nullptr || current_end != nullptr)
	{
		if (index_current >= count_temp)
			return cnt;
		if (current_start != nullptr) // ?
			if (index_current < count_temp && strcmp(str, current_start->Str) == 0)
				cnt++;
		if (index_current < count_temp && strcmp(str, current_end->Str) == 0)
			cnt++;
		index_current++;
		if (current_start != nullptr)// ?
			current_start = current_start->next; // ѕереместить указатель на след. €ч. списка
		current_end = current_end->prev;

	}
	return cnt;
}


bool DoubleLinkedList::Insert(size_t position, const char* str)
{
	if (First == nullptr)
	{
		Add(str);
		return true;
	}
	else
	{
		Element* element = new Element(str, nullptr, nullptr);

		if (position == 0)
		{
			element->next = First;
			First->prev = element;
			First = element;
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
				{	// прив€зать новый элемент к предыдущему (prev)
					prev->next = element;

					// прив€зать предыдущий элемент к указателю prev ноаого элемента
					element->prev = prev;

					// прив€зать новый элемент к последующему (current)
					element->next = current;

					// св€зать указатель prev следующего элемента с вновь созданным
					current->prev = element;

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

bool DoubleLinkedList::EqualsReverse(const DoubleLinkedList& list2)
{
	if (count == list2.count)
	{
		Element* current = First;
		Element* lst2Current = list2.Last;
		while (current)
		{
			if (strcmp(current->Str, lst2Current->Str) != 0)
				return false;

			current = current->next;
			lst2Current = lst2Current->prev;
		}
	}
	else return false;

	return true;
}


ostream& operator << (ostream& os, const DoubleLinkedList& lst)
{
	Element* current = lst.First;
	while (current != nullptr)
	{
		os << current->Str << " ";

		current = current->next; // ѕереместить указатель на след. €ч. списка
	}
	os << endl;

	return os;
}

char*& DoubleLinkedList::operator[] (unsigned index)
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
	throw std::out_of_range("error");
}


DoubleLinkedList& DoubleLinkedList::operator= (const DoubleLinkedList& source)
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
		return *this;
	}
}

bool DoubleLinkedList::operator==	(const DoubleLinkedList& source) //(сравнивает 2 списка поэлементно)
{
	if (count != source.count)
		return false;

	Element* current = First;
	Element* source_current = source.First;
	while (current != nullptr)
	{
		if (strcmp(current->Str, source_current->Str) != 0)
			return false;
		current = current->next;
		source_current = source_current->next;
	}
	return true;
}

DoubleLinkedList& DoubleLinkedList::operator+=(const char* str)
{
	Add(str);
	return *this;
}

DoubleLinkedList operator+(const DoubleLinkedList& first, const DoubleLinkedList& second)
{
	DoubleLinkedList new_lst;

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

void DoubleLinkedList::ReplaceAll(const char* str, const char* str2)
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

bool DoubleLinkedList::Remove(unsigned index)
{
	if (First == nullptr)
	{
		cout << "First = 0" << endl;
		return false;
	}
	if (index < count)
	{
		if (index == 0) // если нужно удалить первый.
		{
			Element* tmp = First;
			First = First->next;
			First->prev = nullptr;
			delete tmp;
			count--;
			return true;
		}
		else
		{
			Element* current = First;
			Element* prev = current;
			Element* next = nullptr;
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
					next = current->next;
				}
			}
			if (index == count) // если нужно удалить последний
			{

				delete current;
				current = prev;
				current->next = nullptr;
				Last = current;
			}
			else
			{
				delete current;
				current = prev;
				current->next = next;
				if (next != nullptr) // ?
					next->prev = current;
			}
			return true;
		}

	}
	else
	{
		cout << "Cant' remove. No match found." << endl;
		return false;
	}
}


bool DoubleLinkedList::RemoveAll(const char* str) // удаление из списка всех элементов, содержащих указанную строку
{
	Element* current = First;
	Element* prev = current;
	Element* next = current->next;
	unsigned cnt_index = 0;

	while (current != 0)
	{
		if (strcmp(str, First->Str) == 0)
		{
			Element* temp = First->next;
			current = current->next;
			delete First;
			First = temp;
			if (First != nullptr)
				First->prev = nullptr;
			count--;
			cnt_index++;

		}
		else if (strcmp(str, current->Str) == 0)
		{
			delete current;
			current = prev;
			current->next = next;
			if (next != nullptr)
				next->prev = current;
			count--;
			cnt_index++;
		}
		else
		{
			prev = current;
			Last = prev;
			current = current->next;
			if (current != nullptr)
				next = current->next;
		}
	}
	if (cnt_index > 0)
	{
		cout << "Successful removed " << cnt_index << " Element's!" << endl;
		return true;
	}

	else
		return false;
}


bool DoubleLinkedList::operator- (const char* str)
{
	Element* current = First;
	Element* prev = current;
	Element* next = current->next;
	unsigned cnt_index = 0;

	while (current != 0)
	{
		if (strcmp(str, First->Str) == 0)
		{
			Element* temp = First->next;
			current = current->next;
			delete First;
			First = temp;
			if (First != nullptr)
				First->prev = nullptr;
			count--;
			cnt_index++;

		}
		else if (strcmp(str, current->Str) == 0)
		{
			delete current;
			current = prev;
			current->next = next;
			if (next != nullptr)
				next->prev = current;
			count--;
			cnt_index++;
		}
		else
		{
			prev = current;
			Last = prev;
			current = current->next;
			if (current != nullptr)
				next = current->next;
		}
	}
	if (cnt_index > 0)
	{
		cout << "Successful removed " << cnt_index << " Element's!" << endl;
		return true;
	}

	else
		return false;
}

DoubleLinkedList& DoubleLinkedList::operator -= (const DoubleLinkedList& source) // удал€ет вхождени€ одного листа в другом.
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
			if (First == nullptr)
				return *this;

			current = First;
			source_current = source_current->next;
		}
	}
	return *this;
}

void DoubleLinkedList::Reverse()
{
	Element* current = First;
	swap(First, Last);
	while (current != nullptr)
	{
		swap(current->next, current->prev);
		current = current->prev;
	}
}

void DoubleLinkedList::Sort()
{
	if (First == nullptr)
		return;
	Element* current = First;
	Element* tmp = nullptr;
	unsigned cnt = 0;
	while (current->next != nullptr)
	{
		if (current != nullptr && strcmp(current->Str, current->next->Str)==1)
		{
			swap(current->Str, current->next->Str);
			cnt++;
		}
		current = current->next;
	}
	if (cnt != 0)
		Sort();
}

void DoubleLinkedList::InsertionSort()
{
	// if list is empty
	if (First == nullptr)
		return;

	Element* current = First;
	Element* temp = nullptr;
	while (current != nullptr)
	{
		temp = current->next; // получил след эл.

		// заходит сюда если temp не 0, и перед темп не 0, и тем < || > предыдущего.
		while (temp != nullptr && temp->prev != nullptr && Comp(temp->Str, temp->prev->Str))
		{
			swap(temp->Str, temp->prev->Str); // помен€ли указатели на стр местами

			temp = temp->prev; // бежим слева направо
		}
		// иначе просто бежим по списку
		current = current->next;
	}
}