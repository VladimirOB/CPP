#include "Queue.h"
#include "pch.h"

Queue::Queue()
{
	MaxSize = 9;
	CurrentSize = 0;
	Numbers = new int[MaxSize];
}

Queue::Queue(size_t size)
{
	MaxSize = size;
	CurrentSize = 0;
	Numbers = new int[MaxSize];
}

Queue::~Queue()
{
	delete[] Numbers;
}

bool Queue::Enqueue(int num)
{
	if (CurrentSize < MaxSize)
	{
		Numbers[CurrentSize++] = num;
	}
	else
	{
		cout << "Error." << endl;
			return false;
	}
}

int Queue::Dequeue()
{
	int result = Numbers[0];
	CurrentSize--;
	for (size_t i = 0; i < CurrentSize; i++)
	{
		Numbers[i] = Numbers[i + 1];
	}
	return result;
}

int Queue::Show()
{
	return Numbers[0];
}

void Queue::Clear()
{
	CurrentSize = 0;
}

void Queue::Print()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		cout << Numbers[i] << endl;
	}
}

