#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Matrix.h"

/*2. ����������� ����� Matrix, ������� ��������� ����:
- int** matrix
- Width - ����� �������
- Height - ������ �������

������:
- ������������ (��� ����������, �����������, � ���������)
- ����������
- void Print() - ������ �������
- void Set(x, y, value) - ������ ��������
- int Get(x, y) - ������ ��������
- int Min()
- bool Save(char* filename)
- bool Load(char* filename)

������:

Matrix matrix(4, 5);
matrix.Set(3, 4, 23);
cout << matrix(1, 2) << endl;

matrix.Save("file.dat");
matrix.Load("file.dat");*/

int main()
{
	Matrix m;
	m.Load("1.txt");
	cout << m << endl;
	return 0;
}