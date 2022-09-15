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
- Rotate90() - �����, ������� ������������ ������� �� 90 ��������

���������:
- operator(x, y) - ������ �������� �� ����������� (������)
- operator(...) - ��������� ������������� ���������� ���������� � �������� ��� ��� ����� � ������� �� 0
������: matrix(1, 2, 3, 4) - �������� � ������� ����� 1, 2, 3, 4 �� 0
- operator== - ��������� � Matrix
- operator!=   ��������� �� ����� ���������
- operator>= - ��������� �� ����� ���������
- operator<= - ��������� �� ����� ���������
 - operator int() - works like sum();
-operator double() - works like avg();
-operator++
- operator++(int)
-operator--
- operator--(int)
-operator+=
-operator-=
-operator new - writes to.log file
- operator delete - writes to.log file
������:
Matrix matrix(4, 5);
matrix.Set(3, 4, 23);
cout << matrix(1, 2) << endl;

matrix.Save("file.dat");
matrix.Load("file.dat");*/

int main()
{
	/*Matrix<int> m;
	Matrix<int> m2 = m;
	m.Print();
	m.operator()(1, 2, 3, 4, 0);
	m.operator--();
	m += 5;
	m.Print();*/

	Matrix<int>* m = new Matrix<int>;
	m->Print();
	delete m;

	Matrix<int>* a = new Matrix<int>[3];
	for (size_t i = 0; i < 3; i++)
	{
		a[i].Print();
	}
	delete[] a;
	return 0;
}