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


int main(void)
{
	int cnt = 0;
	srand(time(NULL));
	
	MyMatrix<double> matrix;
	MyMatrix<double> matrix2 = matrix;
	matrix.Save("Matrix.txt");
	matrix.Print();

	matrix.Load("Matrix.txt");
	matrix2.Print();

	int min = matrix.Min();
	cout << "Min = " << min << endl << endl;

	matrix.Print();
	matrix.Rotate90();
	matrix.Print();

	//matrix.Set(3, 4, 10);
	//matrix.Print();
	
	//matrix = matrix + 3;
	//matrix2.Print();
	//matrix2 = matrix2 - 5;
	//matrix2.Print();
	//cout << "matrix res(m+m2):" << endl;
	//matrix = matrix + matrix2;
	//matrix.Print();
	//cout << "matrix res(m2-m):" << endl;
	//matrix = matrix2 - matrix;
	//matrix.Print();
	//int a = 0;
	//matrix.operator()(a, a) = 77;
	//matrix.Print();
	//
	//cout << "matrix:" << endl;
	//matrix.Print();
	//
	//int sum = matrix;
	//cout << "Sum = " <<  sum << endl;
	//double avg = matrix;
	//cout << "Avg = " << avg << endl;
	//puts("(m += 2) +=2");
	//(matrix += 2) += 2; // или (matrix.operator+=(2)).operator+=(2);
	//matrix.Print();
	//puts("(m -= 2) -=2");
	//(matrix -= 2) -= 2;
	//matrix.Print();

	//puts("m2 = ++m");
	//matrix2 = ++matrix;
	//cout << "matrix:" << endl;
	//matrix.Print();
	//cout << "matrix2:" << endl;
	//matrix2.Print();
	//puts("m2 = m++");
	//matrix2 = matrix++;
	//cout << "matrix:" << endl;
	//matrix.Print();
	//cout << "matrix2:" << endl;
	//matrix2.Print();
	//puts("_____________");
	//puts("m2 = --m");
	//matrix2 = --matrix; // оба --
	//cout << "matrix:" << endl;
	//matrix.Print();
	//cout << "matrix2:" << endl;
	//matrix2.Print();
	//puts("m2 = m--");
	//matrix2 = matrix--;
	//cout << "matrix:" << endl;
	//matrix.Print();
	//cout << "matrix2:" << endl;
	//matrix2.Print();
	//puts("_____________");

	/*MyMatrix* p = new MyMatrix();
	p->Print();
	delete p;

	MyMatrix* a = new MyMatrix[3];
	for (size_t i = 0; i < 3; i++)
	{
		a[i].Print();
	}
	delete[] a;
	cout << endl;*/
	 
	
}