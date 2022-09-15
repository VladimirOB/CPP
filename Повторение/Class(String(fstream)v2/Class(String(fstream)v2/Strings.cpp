#define _CRT_SECURE_NO_WARNINGS
#include "Strings.h"
#include <iostream>
#include <fstream>
using namespace std;

Strings::Strings()
{
	CurrentRows = 0;
	MaxRows = 10;
	Str = new char* [MaxRows];
}

Strings::Strings(size_t size)
{
	CurrentRows = 0;
	MaxRows = size;
	Str = new char* [MaxRows];
}

Strings::Strings(const Strings& source)
{
	CurrentRows = 0;
	MaxRows = source.MaxRows;
	Str = new char* [MaxRows];
	for (size_t i = 0; i < source.CurrentRows; i++)
	{
		Add(source.Str[i]);
	}
}

void Strings::Print()
{
	for (size_t i = 0; i < CurrentRows; i++)
	{
		cout << Str[i] << endl;
	}
}

void Strings::Add(const char* str)
{
	if (CurrentRows < MaxRows)
	{
		Str[CurrentRows] = new char[strlen(str) + 1];
		strcpy(Str[CurrentRows++],str);
	}
	else
	{
		cout << "resize" << endl;
		size_t new_size = MaxRows + 3;
		char** new_str = new char* [new_size];
		size_t i = 0;
		unsigned new_current = 0;
		for (; i < CurrentRows; i++)
		{
			new_str[new_current] = new char[strlen(Str[i]) + 1];
			strcpy(new_str[new_current++], Str[i]);
		}
		new_str[new_current++] = new char[strlen(str) + 1];
		strcpy(new_str[i],str);
		CurrentRows++;
		delete[] Str;
		MaxRows = new_size;
		Str = new_str;
	}
}

bool Strings::Remove(size_t index)
{
	if (index >= 0 && index < CurrentRows)
	{
		delete[] Str[index];
		for (size_t i = index; i < CurrentRows; i++)
		{
			Str[i] = Str[i + 1];
		}
		CurrentRows--;
		return true;
	}
	else
		return false;
}

Strings& Strings::operator+(const char* str)
{
	Add(str);
	return *this;
}

Strings& Strings::operator+(const Strings& source)
{
	for (size_t i = 0; i < source.CurrentRows; i++)
	{
		Add(source.Str[i]);
	}
	return *this;
}

Strings& Strings::operator -=(const char* str)
{
	int cnt = 0;
	for (size_t i = 0; i < CurrentRows; i++)
	{
		for (size_t k = 0; k < strlen(Str[i]); k++)
		{
			if (Str[i][k] == str[k])
				cnt++;
		}
		if (cnt == strlen(Str[i]))
		{
			delete[] Str[i];
			for (size_t j = i; j < CurrentRows; j++)
			{
				Str[j] = Str[j + 1];
			}
			CurrentRows--;
			cnt = 0;
		}
	}
	return *this;
}

Strings& Strings::operator -=(const Strings& source)
{
	for (size_t i = 0; i < CurrentRows; i++)
	{
		for (size_t k = 0; k < source.CurrentRows; k++)
		{
			if (strcmp(Str[i], source.Str[k]) == 0)
			{
				delete[] Str[i];
				for (size_t j = i; j < CurrentRows; j++)
				{
					Str[j] = Str[j + 1];
				}
				CurrentRows--;
			}
		}
		
	}
	return *this;
}

bool Strings::operator==(const Strings& source)
{
	if (CurrentRows != source.CurrentRows || MaxRows != source.MaxRows)
		return false;
	for (size_t i = 0; i < CurrentRows; i++)
	{
		if (strcmp(Str[i], source.Str[i]) != 0)
			return false;
	}
	return true;
}

void Strings::RemoveDuplicates()
{
	for (size_t i = 0; i < CurrentRows; i++)
	{
		for (size_t k = i + 1; k < CurrentRows; k++)
		{
			if (strcmp(Str[i], Str[k]) == 0)
			{
				delete[] Str[i];
				for (size_t j = i; j < CurrentRows; j++)
				{
					Str[j] = Str[j + 1];
				}
				CurrentRows--;
			}
		}
	}
}

void Strings::Sort()
{
	for (size_t i = 0; i < CurrentRows; i++)
	{
		for (size_t k = i+1; k < CurrentRows; k++)
		{
			if (strcmp(Str[i], Str[k]) == 1)
			{
				swap(Str[i], Str[k]);
			}
		}
	}
}


bool Strings::Save(const char* file_name)
{
	ofstream file(file_name, ios::out);
	if (!file.fail())
	{
		for (size_t i = 0; i < CurrentRows; i++)
		{
			if (i == CurrentRows - 1)
				file << Str[i];
			else
			file << Str[i] << endl;
		}
		file.close();
		return true;
	}
	else
	{
		throw exception("Error"); // если свой метод - throw new "имя класса"(поля класса(пример:(1, Error open)))
		return false;
	}
}

bool Strings::Load(const char* file_name)
{
	if (CurrentRows != 0)
	{
		for (size_t i = 0; i < CurrentRows; i++)
		{
			delete[] Str[i];
		}
		delete[] Str;
		CurrentRows = 0;
	}
	ifstream file(file_name, ios::in);
	if (!file.fail())
	{
		char* buffer = new char[200];
		while (!file.eof())
		{
			file.getline(buffer, 199);
			Str[CurrentRows] = new char[strlen(buffer) + 1];
			strcpy(Str[CurrentRows++],buffer);
		}
		file.close();
	}
	else
	{
		cout << "Error" << endl;
		return false;
	}
}

ostream& operator << (ostream& os, const Strings& str)
{
	for (size_t i = 0; i < str.CurrentRows; i++)
	{
		os << str.Str[i] << endl;
	}
	return os;
}

istream& operator >> (istream& is, Strings& str)
{
	char buffer[100];
	is.getline(buffer, 99);
	str.Add(buffer);
	return is;
}

Strings operator+ (const Strings& str, const char* new_str)
{
	Strings result = str;
	result.Add(new_str);
	return result;
}

Strings operator+ (Strings& first, Strings& second)
{
	Strings result(first.CurrentRows + second.CurrentRows);
	for (size_t i = 0; i < first.CurrentRows; i++)
	{
		result.Add(first.Str[i]);
	}
	for (size_t i = 0; i < second.CurrentRows; i++)
	{
		result.Add(second.Str[i]);
	}
	return result;
}