#include "Stack.h"
#include <iostream>

using namespace std;


Stack::Stack()
{
	cout << "Constr" << endl;
	
	MaxSize = 100;
	CurrentSize = 0;
	Numbers = new int[MaxSize];
	P = &Numbers[0];
}


Stack::Stack(unsigned max_size)
{
	cout << "Constr with params" << endl;
	
	MaxSize = max_size;
	CurrentSize = 0;
	Numbers = new int[MaxSize];
	P = &Numbers[0];
}


Stack::~Stack()
{
	cout << "Destr" << endl;

	delete[] Numbers;
}


bool Stack::Push(int num)
{
	if (CurrentSize + 1 <= MaxSize) 
	{
		CurrentSize++;

		if (CurrentSize == 1)
			*P = num;
		else
			*++P = num;

		return true;
	}
	else
		return false;
	
}


int Stack::Pop()
{
	if (CurrentSize > 0)
	{
		CurrentSize--;
		
		return *P--;
	}
	else
		throw exception();
}


int Stack::Show() 
{
	return *P;
}


void Stack::Print() 
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		cout << *(Numbers + i) << endl;
	}
}

void Stack::Clear()
{
	CurrentSize = 0;
}







/*bool Stack::Push(int num)
{
	if (CurrentSize + 1 <= MaxSize)
	{
		CurrentSize++;

		*(Numbers + (CurrentSize - 1)) = num;

		return true;
	}
	else
		return false;
}*/