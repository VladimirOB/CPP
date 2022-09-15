#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdarg.h> 
#include <cstdarg>
#include <conio.h>
using namespace std;

template <class T>

class Matrix
{
	T** matrix;
	unsigned Height;
	unsigned Width;
public:
	Matrix()
	{
		srand(static_cast <unsigned> (time(0)));
		Height = 3;
		Width = 4;
		matrix = new T * [Height];
		for (size_t i = 0; i < Height; i++)
		{
			matrix[i] = new T[Width];
			for (size_t k = 0; k < Width; k++)
			{
				float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 10.0));
				matrix[i][k] = r2;
			}
		}
	}

	Matrix(unsigned height, unsigned width)
	{
		Height = height;
		Width = width;
		matrix = new T * [Height];
		for (size_t i = 0; i < Height; i++)
		{
			matrix[i] = new T[Width];
			for (size_t k = 0; k < Width; k++)
			{
				matrix[i][k] = rand() % 9;
			}
		}
	}

	Matrix(const Matrix& source)
	{
		Height = source.Height;
		Width = source.Width;

		matrix = new T * [Height];
		for (size_t i = 0; i < Height; i++)
		{
			matrix[i] = new T[Width];
			for (size_t k = 0; k < Width; k++)
			{
				matrix[i][k] = source.matrix[i][k];
			}
		}
	}

	Matrix operator = (const Matrix& source)
	{
		if (matrix != NULL)
		{
			for (size_t i = 0; i < Height; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		Height = source.Height;
		Width = source.Width;
		matrix = new T * [Height];
		for (size_t i = 0; i < Height; i++)
		{
			matrix[i] = new T[Width];
			for (size_t k = 0; k < Width; k++)
			{
				matrix[i][k] = source.matrix[i][k];
			}
		}

		return *this;
	}

	~Matrix()
	{
		for (size_t i = 0; i < Height; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	void Print()
	{
		for (size_t i = 0; i < Height; i++)
		{
			for (size_t k = 0; k < Width; k++)
			{
				cout << matrix[i][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	void Set(int x, int y, T value)
	{
		matrix[x][y] = value;
	}

	int Get(int x, int y)
	{
		return matrix[x][y];
	}

	int Min()
	{
		T min = matrix[0][0];
		for (size_t i = 0; i < Height; i++)
		{
			for (size_t k = 0; k < Width; k++)
			{
				if (matrix[i][k] < min)
					min = matrix[i][k];
			}
		}
		return min;
	}

	bool Save(const char* file_name)
	{
		FILE* file = fopen(file_name, "w");

		if (file != nullptr)
		{
			fprintf(file, "%d %d%s", Height, Width, "\n");

			for (size_t i = 0; i < Height; i++)
			{
				for (size_t k = 0; k < Width; k++)
				{
					fprintf(file, "%d ", matrix[i][k]);
				}
				fprintf(file, "%s", "\n");
			}
			fclose(file);
			return true;
		}
		else
		{
			printf("Error opening file.\n");
			return false;
		}
	}

	bool Load(const char* file_name)
	{
		FILE* file = fopen(file_name, "r");

		if (file != nullptr)
		{
			int rows, cols;
			fscanf(file, "%d %d", &rows, &cols);
			if (rows > Height || cols > Width)
			{
				for (size_t i = 0; i < Height; i++)
				{
					delete[]matrix[i];
				}
				delete[] matrix;

				Height = rows;
				Width = cols;
				matrix = new T * [Height];
				for (size_t i = 0; i < Height; i++)
				{
					matrix[i] = new T[Width];
				}

				for (size_t i = 0; i < Height; i++)
				{
					for (size_t k = 0; k < Width; k++)
					{
						int res = fscanf(file, "%d ", &matrix[i][k]);
					}
				}
			}
			else
			{
				Height = rows;
				Width = cols;
				for (size_t i = 0; i < Height; i++)
				{
					for (size_t k = 0; k < Width; k++)
					{
						int res = fscanf(file, "%d ", &matrix[i][k]);
					}
				}
			}
			fclose(file);
			return true;
		}
		else
		{
			printf("Error opening file! \n");
			return false;
		}
	}

	void Rotate90()
	{
		if (Height == Width)
		{
			int tmp;
			for (size_t i = 0; i < Height; i++)
			{
				for (size_t k = i; k < Height - 1 - i; k++)
				{
					tmp = matrix[i][k];
					matrix[i][k] = matrix[Height - k - 1][i]; // задаём 1 числу 1 строки, 1е число 2-й строки.
					matrix[Height - k - 1][i] = matrix[Height - i - 1][Height - k - 1]; // 1му числу 2й строки задаём предпоследнее число предп
					matrix[Height - i - 1][Height - k - 1] = matrix[k][Height - i - 1];
					matrix[k][Height - i - 1] = tmp;
				}
			}
		}
		else
		{
			T** new_matrix = new T * [Width];
			for (size_t i = 0; i < Width; i++)
			{
				new_matrix[i] = new T[Height];
			}

			for (size_t i = 0; i < Height; i++)
			{
				for (size_t k = 0; k < Width; k++)
				{
					new_matrix[k][Height - i - 1] = matrix[i][k];
				}
			}
			for (size_t i = 0; i < Height; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;

			matrix = new T * [Width];
			for (size_t i = 0; i < Width; i++)
			{
				matrix[i] = new T[Height];
			}
			matrix = new_matrix;
			int t = Height;
			Height = Width;
			Width = t;

		}
	}

	T& operator()(int x, int y)
	{
		return matrix[x][y];
	}

	void operator()(T first, ...)
	{
		va_list lst;
		va_start(lst, first);
		for (size_t i = 0; i < Height; i++)
		{
			for (size_t k = 0; k < Width; k++)
			{
				if (matrix[i][k] == first)
					matrix[i][k] == 0;
			}
		}

		while (true)
		{
			T current = va_arg(lst, int);
			if (current == 0)
				break;
			for (int i = 0; i < Height; i++)
			{
				for (int k = 0; k < Width; k++)
				{
					if (matrix[i][k] == current)
						matrix[i][k] = 0;
				}
			}
		}
		va_end(lst); // очистка
	}

	bool operator==(Matrix& source)
	{
		if (Height != source.Height || Width != source.Width)
			return false;
		for (size_t i = 0; i < Height; i++)
		{
			for (size_t k = 0; k < Width; k++)
			{
				if (matrix[i][k] != source.matrix[i][k])
				{
					return false;
				}
			}
		}
		return true;
	}

	bool operator!=(int n)
	{
		int sum = 0;
		for (size_t i = 0; i < Height; i++)
		{
			for (size_t k = 0; k < Width; k++)
			{
				sum += matrix[i][k];
			}
		}
		if (sum != n)
			return true;
		else
			return false;
	}

	bool operator<= (int n)
	{
		int sum = 0;
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				sum += matrix[i][k];
			}
		}
		if (sum <= n)
			return true;

		else return false;
	}

	bool operator>= (int n)
	{
		int sum = 0;
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				sum += matrix[i][k];
			}
		}
		if (sum >= n)
			return true;

		else return false;
	}

	operator int()
	{
		int sum = 0;
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				sum += matrix[i][k];
			}
		}
		return sum;
	}

	operator double()
	{
		double avg = 0;
		int hw = Height * Width;
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				avg += matrix[i][k];
			}
		}
		avg /= hw;
		return avg;
	}

	Matrix operator++()
	{
		Matrix old = *this;

		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				matrix[i][k]++;
			}
		}
		return old;
	}

	Matrix operator++(int n)
	{
		Matrix old = *this;

		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				matrix[i][k] += n;
			}
		}
		return old;
	}

	Matrix operator--()
	{
		Matrix old = *this;

		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				matrix[i][k]--;
			}
		}
		return old;
	}

	Matrix operator--(T n)
	{
		Matrix old = *this;

		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				matrix[i][k] -= n;
			}
		}
		return old;
	}

	Matrix operator+=(T n)
	{
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				matrix[i][k] += n;
			}
		}
		return *this;
	}

	Matrix operator-=(T n)
	{
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				matrix[i][k] -= n;
			}
		}
		return *this;
	}

	void* operator new(size_t size)
	{
		time_t seconds = time(NULL);
		tm* tt = localtime(&seconds);
		int day = tt->tm_mday,
			month = tt->tm_mon + 1,
			year = tt->tm_year + 1900;
		int hour = tt->tm_hour,
			min = tt->tm_min,
			sec = tt->tm_sec;
		FILE* file = fopen("new.log", "a");

		if (file != nullptr)
		{
			fprintf(file, "%d.0%d.%d в %d:%d:%d была выделена память.\n", day, month, year, hour, min, sec);
			fclose(file);
		}
		void* p = malloc(size);
		return p;
	}

	void* operator new[](size_t size)
	{
		time_t seconds = time(NULL);
		tm* tt = localtime(&seconds);
		int day = tt->tm_mday, month = tt->tm_mon + 1, year = tt->tm_year + 1900;
		int hour = tt->tm_hour, min = tt->tm_min, sec = tt->tm_sec;
		FILE* file = fopen("test2.log", "a"); if (file != NULL)
		{
			fprintf(file, "%d.0%d.%d в %d:%d:%d была выделена память.\n", day, month, year, hour, min, sec);
			fclose(file);
		}
		void* p = malloc(size);
		return p;
	}

	void operator delete(void* p)
	{
		time_t seconds = time(NULL);
		tm* tt = localtime(&seconds);
		int day = tt->tm_mday, month = tt->tm_mon + 1, year = tt->tm_year + 1900;
		int hour = tt->tm_hour, min = tt->tm_min, sec = tt->tm_sec;
		FILE* file = fopen("test2.log", "a");
		if (file != NULL)
		{
			fprintf(file, "%d.0%d.%d в %d:%d:%d память очищена.\n\n", day, month, year, hour, min, sec);
			fclose(file);
		}
		free(p);
	}

};

