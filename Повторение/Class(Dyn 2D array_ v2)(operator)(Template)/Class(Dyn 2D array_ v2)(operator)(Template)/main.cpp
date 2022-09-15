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
- Rotate90() - метод, который поворачивает матрицу на 90 градусов

Операторы:
- operator(x, y) - чтение значения по координатам (геттер)
- operator(...) - принимает неопределённое количество параметров и заменяет все эти числа в массиве на 0
пример: matrix(1, 2, 3, 4) - заменяет в массиве числа 1, 2, 3, 4 на 0
- operator== - сравнение с Matrix
- operator!=   сравнение по сумме элементов
- operator>= - сравнение по сумме элементов
- operator<= - сравнение по сумме элементов
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
Пример:
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