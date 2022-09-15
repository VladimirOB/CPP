#pragma once
#include "pch.h"

template<class T>
class MyMatrix
{
	T** Matrix;
	int Height;
	int Width;

public:

	MyMatrix() // default
	{
		srand(static_cast <unsigned> (time(0)));
		Height = 3;
		Width = 4;
		Matrix = new T * [Height];
		for (int i = 0; i < Height; i++)
		{
			Matrix[i] = new T[Width];
		}

		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 10.0));
				Matrix[i][k] = r2;
			}
		}
	}


	MyMatrix(const int width, const int height) // with param
	{
		if (width > 0 && height > 0)
		{
			Height = width;
			Width = height;
			Matrix = new T * [Height];
			for (int i = 0; i < Height; i++)
			{
				Matrix[i] = new T[Width];
			}

			for (int i = 0; i < Height; i++)
			{
				for (int k = 0; k < Width; k++)
				{
					Matrix[i][k] = rand() % 20;
				}
			}
		}
		else
		{
			Height = 3;
			Width = 4;
			Matrix = new T * [Height];
			for (int i = 0; i < Height; i++)
			{
				Matrix[i] = new T[Width];
			}

			for (int i = 0; i < Height; i++)
			{
				for (int k = 0; k < Width; k++)
				{
					Matrix[i][k] = 1;
				}
			}
		}
	}

	MyMatrix(const MyMatrix& matrix2) // copy
	{
		Height = matrix2.Height;
		Width = matrix2.Width;
		Matrix = new  T* [matrix2.Height];
		for (int i = 0; i < Height; i++)
		{
			Matrix[i] = new T[Width];
		}

		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				Matrix[i][k] = matrix2.Matrix[i][k];
			}
		}
	}

	void Set(const int x, const int y, const int value)  //сеттер значения
	{
		if (x <= Height and y <= Width)
		{
			Height = x;
			Width = y;
			for (int i = 0; i < x; i++)
			{
				for (int k = 0; k < y; k++)
				{
					Matrix[i][k] = value;
				}
			}
		}
		else
		{	// удаляем старый массив
			for (int i = 0; i < Height; i++)
				delete[] Matrix[i];
			delete[] Matrix;
			// присваиваем новые значения
			Height = x;
			Width = y;
			// создаём новый массив
			Matrix = new T * [Height];
			for (int i = 0; i < Height; i++)
			{
				Matrix[i] = new T[Width];
			}

			for (int i = 0; i < Height; i++)
			{
				for (int k = 0; k < Width; k++)
				{
					Matrix[i][k] = value;
				}
			}
		}
	}

	T Get(const int x, const int  y)  //геттер значения
	{
		return Matrix[x][y];
	}

	T Min()
	{
		T min = Matrix[0][0];
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				if (Matrix[i][k] < min)
					min = Matrix[i][k];
			}
		}
		return min;
	}

	bool Save(const char* file_name)
	{
		FILE* file_w = fopen(file_name, "w");
		if (file_w != NULL)
		{
			fprintf(file_w, "%d %d\n", Height, Width);

			if (typeid(T) == typeid(int))
			{
				for (int i = 0; i < Height; i++)
				{
					for (int k = 0; k < Width; k++)
					{
						fprintf(file_w, "%d ", Matrix[i][k]);
					}
					fprintf(file_w, "%s", "\n");
				}
			}

			if (typeid(T) == typeid(float) || typeid(T) == typeid(double))
			{
				for (int i = 0; i < Height; i++)
				{
					for (int k = 0; k < Width; k++)
					{
						int res = fprintf(file_w, "%f ", Matrix[i][k]);
					}
					fprintf(file_w, "%s", "\n");
				}
			}

			
			puts("Save S.");
			fclose(file_w);
			return true;
		}
		else
			puts("Save F.");
		return false;
	}

	bool Load(const char* file_name)
	{
		int rows = 0, cols = 0;
		FILE* file_r = fopen(file_name, "r");

		if (file_r != nullptr)
		{
			int res = fscanf(file_r, "%d %d", &rows, &cols);

			if (rows > Height || cols > Width)
			{
				for (int i = 0; i < Height; i++)
					delete[] Matrix[i];
				delete[] Matrix;

				Height = rows;
				Width = cols;

				Matrix = new T * [Height];
				for (int i = 0; i < Height; i++)
				{
					Matrix[i] = new T[Width];
				}

				if (typeid(T) == typeid(int))
				{
					for (int i = 0; i < Height; i++)
					{
						for (int k = 0; k < Width; k++)
						{
							fscanf(file_r, "%d", &Matrix[i][k]);
						}
					}
				}

				if (typeid(T) == typeid(float) || typeid(T) == typeid(double))
				{
					for (int i = 0; i < Height; i++)
					{
						for (int k = 0; k < Width; k++)
						{
							fscanf(file_r, "%f", &Matrix[i][k]);
						}
					}
				}
				cout << "Load Matrix (" << Height << "," << Width << ") Successful" << endl;
			}
			else
			{
				Height = rows;
				Width = cols;
				if (typeid(T) == typeid(int))
				{
					for (int i = 0; i < Height; i++)
					{
						for (int k = 0; k < Width; k++)
						{
							fscanf(file_r, "%d", &Matrix[i][k]);
						}
					}
				}

				if (typeid(T) == typeid(float) || typeid(T) == typeid(double))
				{
					for (int i = 0; i < Height; i++)
					{
						for (int k = 0; k < Width; k++)
						{
							fscanf(file_r, "%f", &Matrix[i][k]);
						}
					}
				}
				cout << "Load Matrix (" << Height << "," << Width << ") Successful." << endl;
			}
			fclose(file_r);
			return true;
		}
		else
		{
			cout << "Error opening file!" << endl;
			return false;
		}
			
	}

	T& operator()(int& x, int& y)
	{
		return Matrix[x][y];
	}

	void operator()(T first, ...)
	{
		va_list lst; // lst - указатель для перемещ. по стеку.
		va_start(lst, first); // кидаем lst в начало.
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				if (Matrix[i][k] == first)
					Matrix[i][k] = 0;
			}
		}
		while (true)
		{
			T current = va_arg(lst, int); // получаем текущий пар. из стека
			if (current == 0)
				break;
			for (int i = 0; i < Height; i++)
			{
				for (int k = 0; k < Width; k++)
				{
					if (Matrix[i][k] == current)
						Matrix[i][k] = 0;
				}
			}
		}
		va_end(lst); // очистка
	}

	bool operator== (MyMatrix& matrix2)
	{
		if (Height != matrix2.Height or Width != matrix2.Width)
		{
			return false;
		}

		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				if (Matrix[i][k] != matrix2.Matrix[i][k])
					return false;
			}
		}
		return true;
	}

	bool operator!= (int n)
	{
		int sum = 0;
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				sum += Matrix[i][k];
			}
		}
		if (sum != n)
			return true;

		else return false;
	}

	bool operator<= (int n)
	{
		int sum = 0;
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				sum += Matrix[i][k];
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
				sum += Matrix[i][k];
			}
		}
		if (sum >= n)
			return true;

		else return false;
	}

	void Rotate90()
	{
		if (Height == Width)
		{

			int tmp;
			for (int i = 0; i < Height; i++)
			{
				for (int j = i; j < Height - 1 - i; j++)
				{
					tmp = Matrix[i][j];
					Matrix[i][j] = Matrix[Height - j - 1][i];
					Matrix[Height - j - 1][i] = Matrix[Height - i - 1][Height - j - 1];
					Matrix[Height - i - 1][Height - j - 1] = Matrix[j][Height - i - 1];
					Matrix[j][Height - i - 1] = tmp;
				}
			}
		}
		else
		{
			T** new_m = new T* [Width];
			for (int i = 0; i < Width; i++)
			{
				new_m[i] = new T[Height];
			}

			for (int i = 0; i < Height; i++)
			{
				for (int j = 0; j < Width; j++)
				{
					new_m[j][Height - i - 1] = Matrix[i][j];
				}
			}


			for (int i = 0; i < Height; i++)
				delete[] Matrix[i];
			delete[] Matrix;

			Matrix = new T* [Width];
			for (int i = 0; i < Width; i++)
			{
				Matrix[i] = new T[Height];
			}

			Matrix = new_m;
			int temp = Height;
			Height = Width;
			Width = temp;
		}
	}

	MyMatrix operator= (const MyMatrix& source)
	{
		// удаление старого массива
		if (Matrix != NULL)
		{
			for (int i = 0; i < Height; i++)
			{
				delete[] Matrix[i];
			}
			delete[] Matrix;
		}

		// скопировать размер массива
		Height = source.Height;
		Width = source.Width;
		// выделить память под новый массив

		Matrix = new T* [Height];
		for (int i = 0; i < Height; i++)
		{
			Matrix[i] = new T[Width];
		}


		// скопировать сами значения
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				Matrix[i][k] = source.Matrix[i][k];
			}

		}

		return *this;
	}

	MyMatrix operator+ (T n) // const copy +1
	{
		MyMatrix result = *this; // const copy +1

		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				result.Matrix[i][k] += n;
			}
		}
		return result;
	}

	MyMatrix operator+ (MyMatrix& source) // const copy +1
	{
		MyMatrix result = *this; // const copy +1
		if (result.Height <= source.Height && result.Width <= source.Width)
		{
			for (int i = 0; i < result.Height; i++)
			{
				for (int k = 0; k < result.Width; k++)
				{
					result.Matrix[i][k] += source.Matrix[i][k];
				}
			}
		}
		else
		{
			for (int i = 0; i < source.Height; i++)
			{
				for (int k = 0; k < source.Width; k++)
				{
					result.Matrix[i][k] += source.Matrix[i][k];
				}
			}
		}
		return result;
	}

	MyMatrix operator- (T n) // const copy +1
	{
		MyMatrix result = *this; // const copy +1

		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				result.Matrix[i][k] -= n;
			}
		}
		return result;
	}

	MyMatrix operator- (MyMatrix& source) // const copy +1
	{
		MyMatrix result = *this; // const copy +1
		if (result.Height <= source.Height && result.Width <= source.Width)
		{
			for (int i = 0; i < result.Height; i++)
			{
				for (int k = 0; k < result.Width; k++)
				{
					result.Matrix[i][k] -= source.Matrix[i][k];
				}
			}
		}
		else
		{
			for (int i = 0; i < source.Height; i++)
			{
				for (int k = 0; k < source.Width; k++)
				{
					result.Matrix[i][k] -= source.Matrix[i][k];
				}
			}
		}
		return result;
	}

	MyMatrix& operator+=(T n)
	{
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				Matrix[i][k] += n;
			}
		}
		return *this;
	}

	MyMatrix& operator-=(int n) // <<<<<<
	{
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				Matrix[i][k] -= n;
			}
		}
		return *this;
	}

	MyMatrix& operator++()
	{
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				Matrix[i][k]++;
			}
		}
		return *this;
	}

	MyMatrix operator++(int)
	{
		MyMatrix old = *this;
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				Matrix[i][k]++;
			}
		}
		return old;
	}

	MyMatrix& operator--()
	{
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				Matrix[i][k]--;
			}
		}
		return *this;
	}

	MyMatrix operator--(int)
	{
		MyMatrix old = *this;
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				Matrix[i][k]--;
			}
		}
		return old;
	}

	operator int()
	{
		int sum = 0;
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				sum += Matrix[i][k];
			}
		}
		return sum;
	}

	operator double()
	{
		double avg = 0;
		int del = Height * Width;
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				avg += Matrix[i][k];
			}
		}
		avg /= del; // если сюда закинуть Width * Height предупреждает о переполнении.
		return avg;
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
		FILE* w = fopen("test2.log", "a");
		if (w != NULL)
		{
			//fprintf(w, "%s %d %s", "Было выделено памяти:", size, asctime(tt));

			fprintf(w, "%d.0%d.%d в %d:%d:%d была выделена память.\n", day, month, year, hour, min, sec);
			fclose(w);
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
		FILE* w = fopen("test2.log", "a");
		if (w != NULL)
		{
			fprintf(w, "%d.0%d.%d в %d:%d:%d память очищена.\n\n", day, month, year, hour, min, sec);
			fclose(w);
		}
		free(p);

	}

	void* operator new[](size_t size)
	{	
		time_t seconds = time(NULL);
		tm* tt = localtime(&seconds);
		int day = tt->tm_mday, month = tt->tm_mon + 1, year = tt->tm_year + 1900;
		int hour = tt->tm_hour, min = tt->tm_min, sec = tt->tm_sec;
		FILE* w = fopen("test2.log", "a"); if (w != NULL)
		{
		fprintf(w, "%d.0%d.%d в %d:%d:%d была выделена память.\n", day, month, year, hour, min, sec);
		fclose(w);
		}
		void* p = malloc(size);
		return p;
	}

	void operator delete[](void* p)
	{
		time_t seconds = time(NULL);
		tm* tt = localtime(&seconds);
		int day = tt->tm_mday, month = tt->tm_mon + 1, year = tt->tm_year + 1900;
		int hour = tt->tm_hour, min = tt->tm_min, sec = tt->tm_sec;
		FILE* w = fopen("test2.log", "a");
		if (w != NULL)
		{
			fprintf(w, "%d.0%d.%d в %d:%d:%d память очищена.\n\n", day, month, year, hour, min, sec);
			fclose(w);
		}
		free(p);

	}

	~MyMatrix()
	{
		for (int i = 0; i < Height; i++)
			delete[] Matrix[i];
		delete[] Matrix;
	}

	void Print()
	{
		for (int i = 0; i < Height; i++)
		{
			for (int k = 0; k < Width; k++)
			{
				cout << Matrix[i][k] << " ";
			}
			cout << endl;
		}
		cout << endl;

	}
};

