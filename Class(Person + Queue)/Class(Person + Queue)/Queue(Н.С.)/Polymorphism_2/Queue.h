#pragma once

class Queue
{
	int* Numbers;
	int* P_Start;
	int* P_End;
	unsigned CurrentSize;
	unsigned MaxSize;
	unsigned DeleteSize;

public:
	
	Queue();
	Queue(unsigned max_size);
	~Queue();

	bool Enqueue(int num);
	int Dequeue();
	int Show();
	void Clear();
	void Print();

};