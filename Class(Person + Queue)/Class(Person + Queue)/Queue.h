#pragma once

/*2. ����������� ����� Queue, ������� ��������� ����:
- int* numbers - ������, �� ������ �������� �������� ����
- CurrentSize - ������� ������ �����
- MaxSize - ������������ ������ �����

������:
- ������
- �����
- bool Enqueue(int num) - ��������� � �������
- int Dequeue() - �������� �� ������� � �������
- int Show() - �������� ������� ����� � �����, �� �� �������� �� �����
- Clear() - ��������� �������� ���� (������� ��� ��������)
- Print() - �������� ���������� �����*/

class Queue
{
	int* Numbers;
	size_t MaxSize;
	size_t CurrentSize;

public:
	Queue();
	Queue(size_t size);
	~Queue();
	bool Enqueue(int num); //��������� � �������
	int Dequeue(); //�������� �� ������� � �������
	int Show();
	void Clear();
	void Print();
};

