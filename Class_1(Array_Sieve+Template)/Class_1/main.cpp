#include "pch.h"
#include "MyArray.h"

int main()
{
	int a[10];
	for (size_t i = 0; i < 10; i++)
	{
		a[i] = i;
	}

	//создание экземпляра шаблонного класса
	MyArray<float, 10> arr;
	cout << "Sum = " << arr.Sum() << endl;
	arr.Print();
	arr.set(0, 777);
	cout << arr.Get(0) << endl;
	
	
	float min = 0, max = 0;
	arr.MinMax(min, max);
	cout << "Min = " << min << endl << "Max = " << max << endl;
	arr.Print();

	arr.LoadFromFile("test.txt");
	arr.Print();

}