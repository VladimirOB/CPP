#include "PriorityQueue.h"
#include "pch.h"
#include "ArithmeticalException.h"
PriorityQueue::PriorityQueue(comparator comp)
{
	CurrSize = 0;
	MaxSize = 20;
	Buffer = new int[MaxSize];
	P = Buffer;
	Comp = comp;
}

PriorityQueue::~PriorityQueue()
{
	delete[] Buffer;

}

bool PriorityQueue::EnQueue(int num) //- поместить в очередь
{
	if (CurrSize < MaxSize)
	{	
		Buffer[CurrSize++] = num;
		return true;
	}
	else
	{
		cout << "Error." << endl;
		return false;
	}
}

int PriorityQueue::DeQueue()
{
	if (CurrSize > 0)
	{
		int num = Buffer[0], index = 0;
		
		for (size_t i = 0; i < CurrSize; i++)
		{

			if (Comp(num, Buffer[i]))
			{
				num = Buffer[i];
				index = i;
			}
		}
		CurrSize--;
		for (size_t i = index; i < CurrSize; i++)
		{
			Buffer[i] = Buffer[i + 1];
		}
		return num;
	}
	else
		throw new ArithmeticalException(2, "Current size error!");
}

int PriorityQueue::Show() //- показать элемент с краю
{
	int num = Buffer[0];
	for (size_t i = 0; i <= CurrSize; i++)
	{

		if (Comp(num, Buffer[i]))
		{
			num = Buffer[i];
		}
	}
	return num;
}

void PriorityQueue::Print() //- показать всю очередь
{
	for (size_t i = 0; i < CurrSize; i++)
	{
		cout << Buffer[i] << " ";
	}
	cout << endl;
}

void PriorityQueue::Clear() //- очистить всю очередь
{
	CurrSize = 0;
}

void PriorityQueue::Run(size_t size)
{
	srand(time(0));
	int n;
	for (size_t i = 0; i < size; i++)
	{
		n = rand() % 10;
		
		EnQueue(n);
	}
}
