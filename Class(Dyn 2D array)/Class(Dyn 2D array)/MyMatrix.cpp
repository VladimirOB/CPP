#include "pch.h"
#include "MyMatrix.h"
MyMatrix::MyMatrix() // default
{
	Width = 3;
	Height = 4;
	Matrix = new int* [Width];
	for (int i = 0; i < Width; i++)
	{
		Matrix[i] = new int[Height];
	}

	for (int i = 0; i < Width; i++)
	{
		for (int k = 0; k < Height; k++)
		{
			Matrix[i][k] = 1;
		}
	}

}

MyMatrix::MyMatrix(const int width, const int height) // with param
{
	if (width > 0 && height > 0)
	{
		Width = width;
		Height = height;
		Matrix = new int* [Width];
		for (int i = 0; i < Width; i++)
		{
			Matrix[i] = new int[Height];
		}

		for (int i = 0; i < Width; i++)
		{
			for (int k = 0; k < Height; k++)
			{
				Matrix[i][k] = rand() % 100;
			}
		}
	}
	else
	{
		Width = 3;
		Height = 4;
		Matrix = new int* [Width];
		for (int i = 0; i < Width; i++)
		{
			Matrix[i] = new int[Height];
		}

		for (int i = 0; i < Width; i++)
		{
			for (int k = 0; k < Height; k++)
			{
				Matrix[i][k] = 1;
			}
		}
	}
}

MyMatrix::MyMatrix(MyMatrix& matrix2) // copy
{
	cout << "Copy C." << endl;
	Width = matrix2.Width;
	Height = matrix2.Height;
	Matrix = new int* [matrix2.Width];
	for (int i = 0; i < Width; i++)
	{
		Matrix[i] = new int[matrix2.Height];
	}

	for (int i = 0; i < Width; i++)
	{
		for (int k = 0; k < Height; k++)
		{
			Matrix[i][k] = matrix2.Matrix[i][k];
		}
	}

}

void MyMatrix::Set(const int x, const int y, const int value)  //сеттер значения
{
	if (x <= Width and y <= Height)
	{
		Width = x;
		Height = y;
		for (int i = 0; i < x; i++)
		{
			for (int k = 0; k < y; k++)
			{
				Matrix[i][k] = value;
			}
		}
	}
	else
	{	// удаляем старый массив
		for (int i = 0; i < Width; i++)
			delete[] Matrix[i];
		delete[] Matrix;
		// присваиваем новые значения
		Width = x;
		Height = y;
		// создаём новый массив
		Matrix = new int* [Width];
		for (int i = 0; i < Width; i++)
		{
			Matrix[i] = new int[Height];
		}

		for (int i = 0; i < Width; i++)
		{
			for (int k = 0; k < Height; k++)
			{
				Matrix[i][k] = value;
			}
		}
	}
}

int MyMatrix::Get(const int x, const int  y)  //геттер значения
{
	return Matrix[x][y];
}

int MyMatrix::Min()
{
	int min = Matrix[0][0];
	for (int i = 0; i < Width; i++)
	{
		for (int k = 0; k < Height; k++)
		{
			if (Matrix[i][k] < min)
				min = Matrix[i][k];
		}
	}
	return min;
}

bool MyMatrix::Save(const char* file_name)
{
	FILE* file_w = fopen(file_name, "w");
	if (file_w != NULL)
	{
		fprintf(file_w, "%d %d\n", Width, Height);
		for (int i = 0; i < Width; i++)
		{
			for (int k = 0; k < Height; k++)
			{
				fprintf(file_w, "%d ", Matrix[i][k]);
			}
			fprintf(file_w, "%s", "\n");
		}
		puts("Save S.");
		fclose(file_w);
		return true;
	}
	else
		puts("Save F.");
	return false;
}

bool MyMatrix::Load(const char* file_name)
{
	int rows=0, cols=0;
	FILE* file_r = fopen(file_name, "r");
	if (file_r != NULL)
	{
		fscanf(file_r, "%d %d", &rows, &cols);
		/*char str[4]; 
		fgets(str, 4, file_r);
		rows = str[0] - 48;
		cols = str[2] - 48;*/
		if (rows > Width || cols > Height)
		{
			for (int i = 0; i < Width; i++)
				delete[] Matrix[i];
			delete[] Matrix;

			Width = rows;
			Height = cols;

			Matrix = new int* [Width];
			for (int i = 0; i < Width; i++)
			{
				Matrix[i] = new int[Height];
			}

			for (int i = 0; i < Width; i++)
			{
				for (int k = 0; k < Height; k++)
				{
					fscanf(file_r, "%d", &Matrix[i][k]);
				}
			}
			cout << "Load Matrix (" << Width << "," << Height << ") S." << endl;
		}
		else
		{
			Width = rows;
			Height = cols;
			for (int i = 0; i < Width; i++)
			{
				for (int k = 0; k < Height; k++)
				{
					fscanf(file_r, "%d", &Matrix[i][k]);
				}
			}
			cout << "Load Matrix (" << Width << "," << Height << ") S." << endl;
		}
		fclose(file_r);
		return true;
	}
	else return false;
}

MyMatrix::~MyMatrix()
{

	for (int i = 0; i < Width; i++)
		delete[] Matrix[i];
	delete[] Matrix;
	puts("Destr");
}


void MyMatrix::Print()
{
	for (int i = 0; i < Width; i++)
	{
		for (int k = 0; k < Height; k++)
		{
			cout << Matrix[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//bool MyMatrix::Contains(const char* str)
//{
//	char* P = Str;
//	const char* p = str;
//	int i = 0;
//	for (; *P; P++)
//	{
//		if (*p == 0)
//			break;
//		if (*P == *p)
//			p++;
//		else
//			p = &str[0];
//	}
//	if (*p == 0)
//		return true;
//	else
//		return false;
//}