#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
	cout << "Constr" << endl;

	CurrentSize = 0;
	DeleteSize = 0;
	MaxSize = 100;
	Numbers = new int[MaxSize];
	P_Start = Numbers;
	P_End = Numbers;
}


Queue::Queue(unsigned max_size)
{
	cout << "Constr with params" << endl;

	CurrentSize = 0;
	DeleteSize = 0;
	MaxSize = max_size;
	Numbers = new int[MaxSize];
	P_Start = Numbers;
	P_End = Numbers;
}


Queue::~Queue()
{
	cout << "Destr" << endl;
	
	delete[] Numbers;
}


bool Queue::Enqueue(int num)
{
	if (CurrentSize + DeleteSize < MaxSize)
	{	
		CurrentSize++;
		*P_End++ = num;
		return true;
	}
	else if (DeleteSize > 0)
	{
		int* p_del;
		p_del = Numbers;

		for (size_t i = 0; i < CurrentSize; i++)
		{
			*p_del++ = *P_Start++;
			if (i + 1 < CurrentSize)
				P_End--;
		}

		P_Start = Numbers;

		DeleteSize = 0;
		CurrentSize++;
		*P_End++ = num;
		return true;
	}
	else
	{
		cout << "No space!" << endl;
		return false;
	}
}


int Queue::Dequeue()
{
	if (P_Start != P_End) 
	{
		DeleteSize++;
		CurrentSize--;
		return *P_Start++;
	}
	else
		cout << "No data!" << endl;
}


int Queue::Show()
{
	return *P_Start;
}


void Queue::Clear()
{
	CurrentSize = 0;
	P_Start = Numbers;
	P_End = Numbers;
}


void Queue::Print()
{
	int* temp;
	
	temp = P_Start;
	
	if (CurrentSize > 0)
	{
		cout << "Queue: " << endl;

		for (size_t i = 0; i < CurrentSize; i++)
		{
			cout << *temp++ << endl;
		}
		cout << endl;
	}
	else
		cout << "Error. No data!" << endl;
	
}