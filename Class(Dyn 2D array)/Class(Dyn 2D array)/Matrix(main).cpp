#include "pch.h"
#include "MyMatrix.h"
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

int main(void)
{
	srand(time(NULL));
	MyMatrix matrix(3,4);
	MyMatrix matrix2 = matrix;
	matrix.Print();
	matrix2.Print();
	cout << "Get(0,0) = " << matrix.Get(0, 0) << endl << endl;

	int min = matrix.Min();
	cout << "Min = " << min << endl;

	matrix.Save("Matrix_Save.txt");

	matrix.Load("Matrix_Load.txt");
	matrix.Print();

	matrix.Set(2, 3, 7);
	matrix.Print();
}