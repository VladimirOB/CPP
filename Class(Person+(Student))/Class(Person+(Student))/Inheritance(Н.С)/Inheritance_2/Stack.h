#pragma once
class Stack
{
	int* Numbers;
	int* P;
	unsigned CurrentSize;
	unsigned MaxSize;

public:
	Stack();
	Stack(unsigned max_size);
	~Stack();

	bool Push(int num);
	int Pop();
	int Show();
	void Print();
	void Clear();
};



