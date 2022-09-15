#pragma once
#include <iostream>
using namespace std;
/*- ������������ (��� ����������, �����������, � ���������)
- ����������
- void Print() - ������ �������
- void Set(x, y, value) - ������ ��������
- int Get(x, y) - ������ ��������
- int Min()
- bool Save(char* filename)
- bool Load(char* filename)*/
class Matrix
{
	int** matrix;
	unsigned Height; // ������ ������� (rows)
	unsigned Width; // ����� ������� (cols)
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

