#pragma once
class MyMatrix
{
	int** Matrix;
	int Width;
	int Height;

public:

	MyMatrix();
	MyMatrix(const int width, const int height);
	MyMatrix(MyMatrix& matrix2);
	void Set(const int x, const int y, const int value);
	int Get(const int x, const int  y);
	int Min();
	bool Save(const char* file_name);
	bool Load(const char* file_name);
	~MyMatrix();
	void Print();
	bool Contains(const char* str);
};
