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
	bool EnQueue(int num); //- ��������� � �������
	int DeQueue(); //- �������� �� �������
	int Show(); //- �������� ������� � ����
	void Print(); //- �������� ��� �������
	void Clear(); //- �������� ��� �������
	void Run(size_t size);

};

