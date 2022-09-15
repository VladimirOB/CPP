#include "Group.h"
#include "Person.h"
#include "pch.h"

Group::Group()
{
	MaxMembers = 3;
	CurrentMember = 0;
	Peoples = new Person * [MaxMembers];
}

Group::Group(size_t maxMembers)
{
	MaxMembers = maxMembers;
	CurrentMember = 0;
	Peoples = new Person * [MaxMembers];
}

Group::Group(const Group& source)
{
	//cout << "Copy Group" << endl;				// copy 

	MaxMembers = source.MaxMembers;
	CurrentMember = 0;

	Peoples = new Person * [MaxMembers];

	for (size_t i = 0; i < source.CurrentMember; i++)
	{
		Person* person = new Person(*source.Peoples[i]);
		Add(person);
	}
}

Group::~Group()
{
	//cout << "Group destructor" << endl;
	for (size_t i = 0; i < CurrentMember; i++)
	{
		delete Peoples[i];
	}
	delete[] Peoples;
}

void Group::Add(Person* person)
{
	if (CurrentMember < MaxMembers)
	{
		Peoples[CurrentMember++] = person;
	}
	else
	{
		size_t new_size = MaxMembers + 3;
		cout << "Group resize. Old size: " << MaxMembers << ". New size: " << new_size << endl;

		//выделить память под новую группу
		Person** new_peoples = new Person * [new_size];
		size_t i = 0;
		// перебрать всех людей в исходном массиве
		for (; i < CurrentMember; i++)
		{
			//добавить человека в новый массив
			new_peoples[i] = Peoples[i];
		}

		// добавить ногово человека в новый массив людей
		new_peoples[i] = person;

		// изменить размеры с учётом нового человека
		MaxMembers = new_size;
		CurrentMember++;

		// удаляем старый массив указателей 
		delete[] Peoples;

		// сохраняем новый массив с персонами в поле класса Peoples
		Peoples = new_peoples;
	}
		
}

void Group::Del(Person* person)
{
	size_t new_size = MaxMembers - 1;
	
	cout << "Group resize. Old size: " << MaxMembers << ". New size: " << new_size << endl;

	//выделить память под новую группу
	Person** new_peoples = new Person * [new_size];
	size_t i = 0, cnt=0;
	// перебрать всех людей в исходном массиве
	for (; i < CurrentMember; i++)
	{
		//добавить человека в новый массив
		if (*Peoples[i] == *person)
		{
			cout << "no" << endl;
		}
		else
		{	
			new_peoples[cnt] = Peoples[i]; 
			cnt++;
		}
	}

	MaxMembers = new_size;
	CurrentMember--;

	// удаляем старый массив указателей 
	delete[] Peoples;

	// сохраняем новый массив с персонами в поле класса Peoples
	Peoples = new_peoples;
	
}

void Group::Print()
{
	for (size_t i = 0; i < CurrentMember; i++)
	{
		Peoples[i]->Print();
	}
	cout << endl;
}

//bool Group::Save(const char* fileName)
//{
//	FILE* file_w = fopen(fileName, "w");
//	if (file_w != NULL)
//	{	
//		fprintf(file_w, "%d\n", CurrentMember);
//
//		for (size_t i = 0; i < CurrentMember; i++)
//		{
//			if (!Peoples[i]->Save(file_w))
//			{
//				cout << "Error saving peoples!" << endl;
//				fclose(file_w);
//				return false;
//			}
//		}
//		fclose(file_w);
//		return true;
//	}
//	else
//	{
//		cout << "Error opening file!!!" << endl;
//		return false;
//	}
//	
//}

bool Group::Save(const char* fileName)
{
	FILE* file_w = fopen(fileName, "w");
	if (file_w != NULL)
	{
		fprintf(file_w, "%d\n", CurrentMember);

		for (size_t i = 0; i < CurrentMember; i++)
		{
			fprintf(file_w, "%s %s %d\n", Peoples[i]->GetFirstName(), Peoples[i]->GetLastName(), Peoples[i]->GetAge());
		}
		fclose(file_w);
		return true;
	}
	else
	{
		cout << "Error opening file!!!" << endl;
		return false;
	}

}

//bool Group::Load(const char* fileName) // not done.
//{
//	FILE* file_r = fopen(fileName, "r"); 
//	if (file_r != NULL)
//	{	
//		//удаляем существующих людей в группе
//		for (size_t i = 0; i < CurrentMember; i++)
//		{
//			delete[] Peoples[i];
//		}
//
//		//int c = fscanf(file_r, "%d", &CurrentMember);
//		CurrentMember = 0;
//		while (!feof(file_r)) // цикл работает пока не закончится файл.
//		{
//			char firstName[200] = "";
//			char lastName[200] = "";
//			unsigned age = 0;
//
//			int res = fscanf(file_r, "%s %s %d", firstName, lastName, &age);
//			if (strlen(firstName) > 0 and strlen(lastName) > 0)
//			{
//				Person* person = new Person(firstName, lastName, age);
//				Add(person);
//			}
//		}
//		fclose(file_r);
//		return true;
//	}
//	else
//	{
//		cout << "Error oppening file!" << endl;
//		return false;
//	}
//} // Load D.E.

bool Group::Load(const char* fileName) 
{
	FILE* file_r = fopen(fileName, "r");
	if (file_r != NULL)
	{
		//удаляем существующих людей в группе
		for (size_t i = 0; i < CurrentMember; i++)
		{
			delete Peoples[i]; // [] 
		}
		unsigned current=0;
		int cm = fscanf(file_r, "%d", &current);

		for (size_t i = 0; i < current; i++)
		{
			char firstName[200];
			char lastName[200];
			unsigned age = 0;
			int res = fscanf(file_r, "%s %s %d", firstName, lastName, &age);

			Person* person = new Person(firstName, lastName, age);
			Add(person);
			
		}
		fclose(file_r);
		return true;
	}
	else
	{
		cout << "Error oppening file!" << endl;
		return false;
	}
}

Group Group::Remove(Person* person)
{
	Group result = *this;
	result.Del(person);
	*this = result;
	return result;
}

Group& Group::Remove_Index(int index)
{
	Group result = *this;
	
	for (size_t i = 0; i < CurrentMember; i++)
	{
		if (i == index)
		{
			Person* person = new Person(*Peoples[i]);
			result.Del(person);
		}
	}
	*this = result;
	return result;
}

bool Group::operator==(Group& source) 
{
	int cnt = 0;
	if (MaxMembers != source.MaxMembers)
		return false;
	for (size_t i = 0; i < CurrentMember; i++)
	{
		if (*Peoples[i] == *source.Peoples[i])
			cnt++;
	}
	if (cnt == CurrentMember)
		return true;
	else return false;
}

Group& Group::operator=(const Group& source)
{
	if (MaxMembers != source.MaxMembers)
	{
		for (size_t i = 0; i < CurrentMember; i++)
			delete Peoples[i];
		delete[] Peoples;

		MaxMembers = source.MaxMembers;
		CurrentMember = 0;

		Peoples = new Person * [MaxMembers];

		for (size_t i = 0; i < source.CurrentMember; i++)
		{
			Person* person = new Person(*source.Peoples[i]);
			Add(person);
		}
	}
	else
	{
		CurrentMember = 0;
		for (size_t i = 0; i < source.CurrentMember; i++)
		{
			Person* person = new Person(*source.Peoples[i]);
			Add(person);
		}
	}
	
	return *this;
}

Group Group::operator+(Person* person)
{
	Group result = *this;
	result.Add(person);
	return result;
	
}

//Group Group::operator+ (const Group& source) // не мой.
//{	// посмотреть на конструктор копирования. // new Peoples[i] = new Person[Peoples[i]] что то такое.
//	//Group result = //конструктор с парам; // В новую группу закинуть всё
//	if (MaxMembers < CurrentMember + source.CurrentMember)
//	{
//		size_t new_size = MaxMembers + source.MaxMembers;
//
//		int new_curr = source.CurrentMember + CurrentMember;
//
//		Person** new_people = new Person * [new_size];
//
//		size_t i = 0;
//		for (; i < CurrentMember; i++)
//		{
//			new_people[i] = Peoples[i];
//		}
//
//		for (size_t j = 0; j < new_curr; j++, i++)
//		{
//			new_people[i] = source.Peoples[j];
//		}
//		MaxMembers = new_size;
//		CurrentMember = new_curr;
//
//		delete[] Peoples;
//
//		Peoples = new_people;
//	}
//	else
//	{
//	unsigned new_curr = CurrentMember + source.CurrentMember;
//
//
//	for (size_t i = CurrentMember, k = 0; i < new_curr; i++, k++)
//	{
//		Add(source.Peoples[k]);
//	}
//	CurrentMember = new_curr;
//	}
//	return *this;
//}

Group Group::operator+ (const Group& source)
{
	Group result(MaxMembers + source.MaxMembers +3);
	result.CurrentMember = 0;

	for (size_t i = 0; i < CurrentMember; i++)
	{
		Person* result_person = new Person(*Peoples[i]);
		result.Add(result_person);
	}

	for (size_t i = 0; i < source.CurrentMember; i++)
	{
		Person* result_person = new Person(*source.Peoples[i]);
		result.Add(result_person);
	}
	return result;
}


void Group::operator+=(Person* person)
{
	
	if (CurrentMember < MaxMembers)
	{
		Peoples[CurrentMember++] = person;
	}
	else
	{
		size_t new_size = MaxMembers + 3;
		cout << "Group resize. Old size: " << MaxMembers << ". New size: " << new_size << endl;

		//выделить память под новую группу
		Person** new_peoples = new Person * [new_size];
		size_t i = 0;
		// перебрать всех людей в исходном массиве
		for (; i < CurrentMember; i++)
		{
			//добавить человека в новый массив
			new_peoples[i] = Peoples[i];
		}

		// добавить ногово человека в новый массив людей
		new_peoples[i] = person;

		// изменить размеры с учётом нового человека
		MaxMembers = new_size;
		CurrentMember++;

		// удаляем старый массив указателей 
		delete[] Peoples;

		// сохраняем новый массив с персонами в поле класса Peoples
		Peoples = new_peoples;
	}
}

Group& Group::operator-=(Person* person) //удаление по значению
{
	//Peoples[CurrentMember--] = person;
	Group result = *this;
	result.Del(person);
	*this = result;
	return result;
	
}

Group Group::operator-(Person* person) //удаление по значению с возвратом новой группы
{
	Group result = *this;
	result.Del(person);
	*this = result;
	return result;
}