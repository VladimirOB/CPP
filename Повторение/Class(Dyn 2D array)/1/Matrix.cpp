#define _CRT_SECURE_NO_WARNINGS
#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix()
{
	Height = 3;
	Width = 4;
	matrix = new int* [Height];
	for (size_t i = 0; i < Height; i++)
	{
		matrix[i] = new int[Width];
		for (size_t k = 0; k < Width; k++)
		{
			matrix[i][k] = rand()%9;
		}
	}

}
Matrix::Matrix(unsigned height, unsigned width)
{
	Height = height;
	Width = width;
	matrix = new int* [Height];
	for (size_t i = 0; i < Height; i++)
	{
		matrix[i] = new int[Width];
		for (size_t k = 0; k < Width; k++)
		{
			matrix[i][k] = rand() % 9;
		}
	}
}

Matrix::Matrix(const Matrix& source)
{
	Height = source.Height;
	Width = source.Width;
	matrix = new int*[Height];
	for (size_t i = 0; i < Height; i++)
	{
		matrix[i] = new int[Width];
		for (size_t k = 0; k < Width; k++)
		{
			matrix[i][k] = source.matrix[i][k];
		}
	}
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < Height; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::Print()
{
	for (size_t i = 0; i < Height; i++)
	{
		for (size_t k = 0; k < Width; k++)
		{
			cout << matrix[i][k] << " ";
		}
		cout << endl;
	}
}

ostream& operator << (ostream& os, Matrix& m)
{
	for (size_t i = 0; i < m.Height; i++)
	{
		for (size_t k = 0; k < m.Width; k++)
		{
			os << m.matrix[i][k] << " ";
		}
		cout << endl;
	}
	return os;
}

void Matrix::Set(int x, int y, int value)
{
	if (x < Height && y < Width)
	{
		matrix[x][y] = value;
	}
	else
		throw exception("Error");
}

int Matrix::Get(int x, int y)
{
	return matrix[x][y];
}

int Matrix::Min()
{
	int min = matrix[0][0];
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

bool Matrix::Save(const char* file_name)
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
		printf("Error opening file");
		return false;
	}
}

bool Matrix::Load(const char* file_name)
{
	FILE* file = fopen(file_name, "r");
	if (file != nullptr)
	{
		int rows, cols;
		int res = fscanf(file, "%d %d", &rows, &cols);

		if (rows > Height || cols > Width)
		{
			for (size_t i = 0; i < Height; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		Height = rows;
		Width = cols;
		matrix = new int* [Height];
		for (size_t i = 0; i < Height; i++)
		{
			matrix[i] = new int[Width];
		}

		for (size_t i = 0; i < Height; i++)
		{
			for (size_t k = 0; k < Width; k++)
			{
				int res = fscanf(file, "%d", &matrix[i][k]);
			}
		}


		fclose(file);
		return true;
	}
	else
	{
		printf("Error opening file\n");
		return false;
	}
}