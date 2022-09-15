#pragma once

/*������:
- ������
- �����
- bool Push(int num) - ��������� � ����
- int Pop() - �������� �� ����� � �������
- int Show() - �������� ������� ����� � �����, �� �� �������� �� �����
- Clear() - ��������� �������� ���� (������� ��� ��������)
- Print() - �������� ���������� �����*/

class Stack
{
	int* Numbers;
	unsigned CurrSize;
	unsigned MaxSize;

public:

	Stack();
	Stack(size_t maxSize);
	~Stack();
	bool Push(int num);
	int Pop();  //�������� �� ����� � �������
	int Show();
	void Clear();
	void Print();
};

