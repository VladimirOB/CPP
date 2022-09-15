#include "Strings.h"
#include "pch.h"

Strings::Strings()
{
	//cout << "Str constr" << endl;
	MaxRows = 6;
	CurrentRows = 0;
	Str = new char* [MaxRows];
}

Strings::Strings(unsigned mRows)
{
	//cout << "Str constr with param" << endl;
	MaxRows = mRows;
	CurrentRows = 0;
	Str = new char*[MaxRows];
}

Strings::Strings(const Strings& source)
{
	//cout << "copy constr" << endl;
	MaxRows = source.MaxRows;
	CurrentRows = source.CurrentRows;
	Str = new char* [MaxRows];
	
	for (size_t i = 0; i < source.CurrentRows; i++)
	{
		Str[i] = new char[strlen(source.Str[i])+1]; 
		strcpy(Str[i], source.Str[i]);
	}
}

Strings::~Strings()
{
	//cout << "Str destr" << endl;
	for (size_t i = 0; i < CurrentRows; i++)
	{
		delete[] Str[i];
	}
	delete[] Str;
}

void Strings::Print()
{
	for (size_t i = 0; i < CurrentRows; i++)
	{
		cout << Str[i] << endl;
	}
}

void Strings::Add(const char* row)
{
	if (CurrentRows < MaxRows)
	{
		Str[CurrentRows] = new char[strlen(row) + 1];
		strcpy(Str[CurrentRows++], row);
	}
	else
	{
		unsigned new_size = MaxRows + 3;
		cout << "Strings resize. New size: " << new_size << endl;

		// выделить память под новые строки
		char** new_str = new char* [new_size];
		
		for (size_t i = 0; i < CurrentRows; i++)
		{
			new_str[i] = new char[strlen(Str[i]) + 1];
			new_str[i] = Str[i]; // скопировали адреса существующих строк
		}

		delete[] Str; // старый массив строк.
		Str = new_str;
		MaxRows = new_size;
		Add(row);
	}
}

void Strings::Remove(size_t index)  // удаление строки по индексу(по позиции)
{
	if (index >= 0 and index < CurrentRows)
	{
		delete Str[index];

		for (size_t i = index; i < CurrentRows; i++)
		{
			Str[i] = Str[i + 1];
		}
		CurrentRows--;
	}
	else throw exception ("Wrong index.");
	
}

Strings Strings::operator=(const Strings& source)
{
	MaxRows = source.MaxRows;
	CurrentRows = source.CurrentRows;
	Str = new char* [MaxRows];

	for (size_t i = 0; i < source.CurrentRows; i++)
	{
		Str[i] = new char[strlen(source.Str[i])+1];
		strcpy(Str[i], source.Str[i]);
	}
	return *this;
}

//Strings Strings::operator+(char* str) //добавление строки
//{
//	Add(str);
//	return *this;
//}
//
//Strings Strings:: operator+ (const Strings& source) //объединение двух контейнеров со строками(Strings)
//{
//	Strings result(CurrentRows + source.CurrentRows + 3);
//	
//	for (size_t i = 0; i < CurrentRows; i++)
//	{
//		result.Add(Str[i]);
//	}
//
//	for (size_t i = 0; i < source.CurrentRows; i++)
//	{
//		result.Add(source.Str[i]);
//	}
//	return result;
//}

void Strings::operator-=(char* str)
{
	for (size_t i = 0; i < CurrentRows; i++)
	{
		if (strcmp(Str[i], str)==0)
		{
			Remove(i--);
		}
	}
	//return *this; если сделать не void, можно использовать каскад (str2 -= a -= b)
}

Strings& Strings::operator-= (const Strings& source) //удаляет все строки, которые есть во втором контейнере sourse
{
	for (size_t i = 0; i < CurrentRows; i++)
	{
		for (size_t k = 0; k < source.CurrentRows; k++) // поправить
		{
			if (strcmp(Str[i],source.Str[k]) == 0)
			{
				Remove(i--);
				break;
			}
		}
	}
	return *this;

	/*for (size_t i = 0; i < CurrentRows; i++)
	{
		for (size_t j = 0; j < source.CurrentRows; j++)
		{
			if (strcmp(Str[i], source.Str[j]) == 0)
			{
				Remove(i);
				if (i > 0)
					i--;
			}

		}
	}

	return *this;*/
}

bool Strings::operator== (const Strings& source)  //построчно сравнивает 2 контейнера
{
	if (CurrentRows != source.CurrentRows)
		return false;
	int cnt = 0;
	for (size_t i = 0; i < CurrentRows; i++)
	{
		if (*Str[i] == *source.Str[i])
		{
			cnt++;
		}
	}
	if (CurrentRows == cnt)
		return true;
	else
		return false;
}

void Strings::RemoveDuplicates()  // удаление повторяющихся строк в контейнере
{
	for (size_t i = 0; i < CurrentRows; i++)
	{
		for (size_t k = i+1; k < CurrentRows; k++)
		{
			if (*Str[i] == *Str[k])
			{
				Remove(k--);
			}
		}
	}
}

//void Strings::Sort() // сортировка строк в контейнере в алфавитном порядке
//{
//	for (size_t i = 0; i < CurrentRows; i++)
//	{
//		for (size_t k = i+1; k < CurrentRows; k++)
//		{
//			if (strcmp(Str[i], Str[k]) == 1)
//			{
//				swap(Str[i], Str[k]);
//			}
//		}
//	}
//}

//void Strings::Sort() // сортировка строк в контейнере в алфавитном порядке
//{
//	for (size_t i = 0; i < CurrentRows; i++)
//	{
//		for (size_t k = i+1; k < CurrentRows; k++)
//		{
//			if (strcmp(Str[i], (Str[k])) == 1)
//			{
//				char* t = Str[i];
//				Str[i] = Str[k];
//				Str[k] = t;
//			}
//		}
//	}
//}

void Strings::Sort() // сортировка строк в контейнере в алфавитном порядке
{
	int j = 0, code_row = 0, code_source_row = 0;
	char** buffer = new char* [CurrentRows];
	for (size_t i = 0; i < CurrentRows; i++)
	{
		buffer[i] = new char[strlen(Str[i])+1];
		strcpy(buffer[i], Str[i]);
	}
	
	for (size_t i = 0; i < CurrentRows; i++)
	{
		for (size_t k = 0; k < strlen(Str[i])+1; k++)
		{
			if (buffer[i][k] >= 65 && buffer[i][k] <= 90)
				buffer[i][k] = buffer[i][k] + 32;
		}
	}
	for (size_t i = 0; i < CurrentRows; i++)
	{
		for (size_t k = i + 1; k < CurrentRows; k++)
		{
			if (strcmp(buffer[i], buffer[k]) == 1)
			{
				swap(buffer[i], buffer[k]);
				char* t = Str[i];
				Str[i] = Str[k];
				Str[k] = t;
			}
		}
	}
	
	//for (size_t i = 0; i < CurrentRows; i++)
	//{
	//	code_row = Str[i][j]; // присвоение кода 1му символу 1й строки

	//	for (size_t k = i + 1; k < CurrentRows; k++)
	//	{
	//		code_source_row = Str[k][j]; // присвоение кода 1му символу 2й строки

	//		if (code_source_row > 96 and (code_source_row - 32) < code_row)
	//		{
	//			char* t = Str[i];
	//			Str[i] = Str[k];
	//			Str[k] = t;
	//			break;
	//		}
	//	}
	//}
	//for (size_t i = 0; i < CurrentRows; i++)
	//{
	//	code_row = Str[i][j]; // присвоение кода 1му символу 1й строки
	//	for (size_t k = 0; k < CurrentRows; k++)
	//	{
	//		code_source_row = Str[k][j]; // присвоение кода 1му символу 2й строки
	//		if (code_source_row > 96 or code_row > 96)
	//			break;
	//		else if (code_source_row < 97 or code_row <97)
	//		{
	//			if (strcmp(Str[i], Str[k]) == -1)
	//			{
	//				swap(Str[i], Str[k]);
	//			}
	//		}
	//	}
	//}

	for (size_t i = 0; i < CurrentRows; i++)
		delete[] buffer[i];
	delete[] buffer;
}


//void Strings::Sort() // сортировка строк в контейнере в алфавитном порядке
//{   //A = 65 a = 97
//
//	int j = 0, code_row=0, code_source_row=0;
//	for (size_t i = 0; i < CurrentRows; i++)
//	{
//		code_row = Str[i][j]; // присвоение кода 1му символу 1й строки
//
//		for (size_t k = i + 1; k < CurrentRows; k++)
//		{
//			code_source_row = Str[k][j]; // присвоение кода 1му символу 2й строки
//
//			if (Str[i][j] - '0' == Str[k][j] - '0') // проверка на одинаковые буквы.
//			{
//				while (Str[i][j] - '0' == Str[k][j] - '0') // добавляем символ, пока они равны.
//				{
//					j++;
//					code_row = Str[i][j];
//					code_source_row = Str[k][j];
//				}
//			}
//			if (code_row < 97 and code_source_row < 97)
//			{
//				if (Str[i][j] - '0' > Str[k][j] - '0')
//				{
//					char* t = Str[i];
//					Str[i] = Str[k];
//					Str[k] = t;
//					i = -1;
//					break;
//				}
//			}
//
//			if (code_row > 96 and code_source_row > 96)
//			{
//				if (Str[i][j] - '0' > Str[k][j] - '0')
//				{
//					char* t = Str[i];
//					Str[i] = Str[k];
//					Str[k] = t;
//					i = -1;
//					break;
//				}
//			}
//
//			if (code_row < 97 and code_source_row > 96)
//			{
//				if ((code_row+32) > (code_source_row))
//				{
//					if (Str[i][j] - '0' > Str[k][j] - '0')
//					{
//						char* t = Str[i];
//						Str[i] = Str[k];
//						Str[k] = t;
//						i = -1;
//						break;
//					}
//				}
//			}
//			j = 0;
//		}
//	}
//}

void Strings::Save(const char* file_name)  //сохранение в файл средствами C++
{
	
	for (size_t i = 0; i < CurrentRows; i++)
	{
		if(i == CurrentRows-1)
		file_w << Str[i];
		else
		file_w << Str[i] << endl;
	}
	file_w.close();
}

Strings Strings::Load(const char* file_name)  //сохранение в файл средствами C++
{
	fstream file_r(file_name, ios::in);
	if (!file_r.fail())
	{
		char** new_str = new char* [10];
		for (size_t i = 0; i < 10; i++)
		{
			new_str[i] = new char[200];
		}

		while (!file_r.eof())
		{
			file_r.getline(new_str[CurrentRows++], 200);
		}
		file_r.close();
		MaxRows = CurrentRows;
		Str = new_str;
		return *this;
	}
	else cout << "Error opening file" << endl;
}



ostream &operator <<(ostream& os, const Strings& string)
{
	for (size_t i = 0; i < string.CurrentRows; i++)
	{
		os << string.Str[i] << endl;
	}
	return os;
}


istream& operator >> (istream& is, Strings& string)
{	
	char buffer[100];
	is.getline(buffer, 99);
	string.Add(buffer);
	
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

