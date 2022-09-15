#pragma once
#include <iostream>
using namespace std;
/*- конструкторы (без параметров, копирования, с размерами)
- деструктор
- void Print() - печать массива
- void Set(x, y, value) - сеттер значения
- int Get(x, y) - геттер значения
- int Min()
- bool Save(char* filename)
- bool Load(char* filename)*/
class Matrix
{
	int** matrix;
	unsigned Height; // высота массива (rows)
	unsigned Width; // длина массива (cols)
public:
	Matrix();
	Matrix(unsigned height, unsigned width);
	Matrix(const Matrix& source);
	~Matrix();
	void Print();
	friend ostream& operator << (ostream& os, Matrix& m);
	void Set(int x, int y, int value);
	int Get(int x, int y);
	int Min();
	bool Save(const char* file_name);
	bool Load(const char* file_name);
};

