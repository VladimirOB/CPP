#pragma once
#include "pch.h"

/*1. Разработать класс Array, имеющий следующие поля:
- int* arr;
- size

методы:
- конструкторы
- деструктор
- void set(position, value) - занесение значения в массив
- int get(position)
- print() - печать массива
- int sum() - вычисление суммы массива
- int min()
- int max()
- bool save(filename) - сохрание массива в файл
- bool load(filename) - загрузка массива из файла
*/

// объявление шаблонного класса
// Т - шаблонный параметр
// size - нешаблонный параметр (константа)
template<class T, int size>
class MyArray
{
protected:
	// объявление шаблонного массива 
	T* arr;
public:
	//констр шаблонного класса.
	MyArray()
	{
		arr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 9;
		}
	}
	MyArray(T* Arr)
	{
		arr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = Arr[i];
		}
	}
	~MyArray()
	{
		delete[] arr;
	}

	void Print()
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void set(unsigned position, T value)
	{
		if (position < size)
		{
			arr[position] = value;
		}
		else throw exception("Index is out of bounds.");
	}

	int Get(int position)
	{
		return arr[position];
	}

	T MinMax(T &min, T &max)
	{
		min = arr[0];
		max = arr[0];
		for (size_t i = 0; i < 10; i++)
		{
			if (arr[i] < min)
				min = arr[i];
			if (arr[i] > max)
				max = arr[i];
		}
		return min, max;
	}

	bool SaveArray(const char* fileName)
	{
		FILE* file_w = fopen(fileName, "w");
		if (file_w != NULL)
		{
			if (typeid(T) == typeid(int))
			{
				for (int i = 0; i < size; i++)
				{
					fprintf(file_w, "%d ", arr[i]);
				}
			}

			if (typeid(T) == typeid(float) || typeid(T) == typeid(double))
			{
				for (int i = 0; i < size; i++)
				{
					fprintf(file_w, "%f ", arr[i]);
				}
			}

			puts("Save S.");
			fclose(file_w);
			return true;
		}

		else return false;
	}

	bool LoadFromFile(const char* fileName)
	{
		// пересоздать массив.
		FILE* file_r = fopen(fileName, "r");
		fseek(file_r, 0, SEEK_END);
		int fileSize = ftell(file_r);
		fseek(file_r, 0, SEEK_SET);
		if (file_r != NULL)
		{
			if (typeid(T) == typeid(int))
			{
				for (int i = 0; i < fileSize; i++)
				{
					int res = fscanf(file_r, "%d ", &arr[i]);
				}
			}
			if (typeid(T) == typeid(float) || typeid(T) == typeid(double))
			{
				for (int i = 0; i < fileSize; i++)
				{
					int res = fscanf(file_r, "%f ", &arr[i]);
				}
			}
			
			puts("Load S.");
			fclose(file_r);
			return true;
		}
		else
			return false;
	}

	T Sum();

	T& operator[](size_t index);
};

//шаблонные методы за пределами шаблонного класса
template <class T, int size>
T MyArray<T, size>::Sum()
{
	T result = 0;
	for (size_t i = 0; i < size; i++)
	{
		result += arr[i];
	}
	return result;
}

template <class T, int size>
T& MyArray<T, size>::operator[](size_t index)
{
	if (index < size)
	{
		return arr[index];
	}
	else throw exception("Index is out of bounds.");
}

