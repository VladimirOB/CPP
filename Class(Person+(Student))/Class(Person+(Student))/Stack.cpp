#include "Stack.h"
#include "pch.h"
Stack::Stack()
{
	CurrSize = 0;
	MaxSize = 10;
	Numbers = new int[MaxSize];
}

Stack::Stack(size_t maxSize)
{
	CurrSize = 0;
	MaxSize = maxSize;
	Numbers = new int[MaxSize];
}

Stack::~Stack()
{
	delete[] Numbers;
}

bool Stack::Push(int num)
{
	if (CurrSize < MaxSize)
		Numbers[CurrSize++] = num;
	else 
		return false;
	
}

int Stack::Pop()
{	if(CurrSize > 0)
	{		
	return Numbers[CurrSize--];
	}
	else
	throw exception();
}

int Stack::Show()
{
	return Numbers[CurrSize];
}

void Stack::Clear()
{
	CurrSize = 0;
}

void Stack::Print()
{
	for (size_t i = 0; i < CurrSize; i++)
	{
		cout << Numbers[i] << endl;
	}
}