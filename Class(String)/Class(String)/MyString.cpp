#include "pch.h"
#include "MyString.h"

	


	// constructor

	MyString::MyString() // default
	{
		MaxSize = 39;
		Str = new char[MaxSize];
		strcpy(Str, "Hello my big big world");
	}

	MyString::MyString(const char* str, unsigned int maxSize) // with param.
	{
		if (str != NULL && maxSize > 0)
		{
			MaxSize = maxSize;
			Str = new char[maxSize];
			strcpy(Str, str);
		}
		else
		{
			MaxSize = 39;
			Str = new char[MaxSize];
			strcpy(Str, "Good bye my big big world");
		}
	}

	// Destructor

	MyString::~MyString()
	{
		puts("End.");
		delete[] Str;
 	}

	void MyString::Set(const char* str)  //change string with class
	{	// +1 если заканчивать нулём.(не len, а str[i]!=0)
		int size = strlen(str);
		 
		if (size >= MaxSize)
		{
			char* new_str = new char[size + 1];

			strcpy(new_str, str);
			
			delete[] Str;

			Str = new_str;

			MaxSize = size;
		}
		else
		{
			strcpy(Str, str);
		}
	}

	char* MyString::Get() //return string from a class
	{
		return Str;
	}

	int MyString::GetLength() //get current row size
	{
		return strlen(Str);
	}

	int MyString::GetVowelsCount(int vow) // Get number of vowels (A,E,I,O,U,Y)
	{
		for (int i = 0; i < Str[i]!=0; i++)
		{
			if (Str[i] == 'a' or Str[i] == 'e' or Str[i] == 'i' or Str[i] == 'o' or Str[i] == 'u' or Str[i] == 'y'
			or  Str[i] == 'A' or Str[i] == 'E' or Str[i] == 'I' or Str[i] == 'O' or Str[i] == 'U' or Str[i] == 'Y')
			{
				vow++;
			}
		}
		return vow;
	}

	void MyString::ToUpper() //convert string to uppercase
	{
		for (int i = 0; i < Str[i]!=0; i++)
		{
			if (Str[i]-0 >= 97 && Str[i] <= 122)
				Str[i] -= 32;
		}
	}

	void MyString::ToLower()	//convert string to lowercase
	{
		for (int i = 0; i < Str[i] != 0; i++)
		{
			if (Str[i] - 0 >= 65 and Str[i] - 0 <= 90)
				Str[i] += 32;
		}
	}

	void MyString::RemoveDigits() //Remove all digits from string
	{
		char* new_str = new char[MaxSize]; // можно и без него.
		int size = 0;
		for (int i = 0; i < Str[i] != 0; i++)
		{
			if (!isdigit(Str[i]))
			{
				new_str[size++] = Str[i];
			}
		}
		delete[]Str;
		Str = new_str;
		MaxSize = size;
	}

	bool MyString::SaveToFile()
	{
		FILE* file_w = fopen("t.txt", "w");
		if (file_w != NULL)
		{
			for (int i = 0; i < Str[i] != 0; i++)
			{
				fprintf(file_w, "%c", Str[i]);
			}
			puts("Save S.");
			fclose(file_w);
			return true;
		}
		else
			return false;
	}

	bool MyString::LoadFromFile()
	{
		FILE* file_r = fopen("t2.txt", "r");
		if (file_r != NULL)
		{
			fseek(file_r, 0, SEEK_END);
			long file_size = ftell(file_r);
			fseek(file_r, 0, SEEK_SET);

			if (MaxSize != file_size)
			{
				delete[] Str;
				Str = new char[file_size];
				MaxSize = file_size;
			}
			fread(Str, sizeof(char), MaxSize, file_r);
			fclose(file_r);
			puts("Load S.");
			return true;
		}
		else return false;
	}
	//Добавить в класс MyString метод Contains(const char* str) и проверяет, содержит ли строка в классе MyString переданную строку
	bool MyString::Contains(const char* str)
	{
		int cnt = 0;
		for (int i = 0, t = 0; i < Str[i] != 0; i++)
		{
			if (str[t] == Str[i])
			{
				for (size_t k = i; k < strlen(str)+i; k++)
				{
					if (str[t] == Str[k])
					{
						t++;
						cnt++;
					}
				}

				if (cnt == strlen(str))
					return true;
				else
					cnt = 0, t = 0;
			}
		}
			return false;
	}

	void MyString::Print()
	{
		for (int i = 0; i < Str[i] != 0; i++)
		{
			cout << Str[i];
		}
		cout << endl;
	}
