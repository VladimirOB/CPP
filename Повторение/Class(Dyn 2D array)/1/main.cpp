#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Matrix.h"

/*2. Разработать класс Matrix, имеющий следующие поля:
- int** matrix
- Width - длина массива
- Height - высота массива

Методы:
- конструкторы (без параметров, копирования, с размерами)
- деструктор
- void Print() - печать массива
- void Set(x, y, value) - сеттер значения
- int Get(x, y) - геттер значения
- int Min()
- bool Save(char* filename)
- bool Load(char* filename)

Пример:

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