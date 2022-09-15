#pragma once
class PriorityQueue
{
	int* Buffer;
	int* P;
	size_t CurrSize;
	size_t MaxSize;
	typedef bool (*comparator)(int a, int b);
	comparator Comp;
public:
	PriorityQueue(comparator comp);
	~PriorityQueue();
	bool EnQueue(int num); //- поместить в очередь
	int DeQueue(); //- вытащить из очереди
	int Show(); //- показать элемент с краю
	void Print(); //- показать всю очередь
	void Clear(); //- очистить всю очередь
	void Run(size_t size);

};

