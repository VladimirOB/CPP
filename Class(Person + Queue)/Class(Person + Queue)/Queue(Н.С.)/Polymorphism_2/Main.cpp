#include <iostream>
#include "Queue.h"

using namespace std;

// 2. ����������� ����� Queue, ������� ��������� ����:
// - int* numbers - ������, �� ������ �������� �������� ����
// - CurrentSize - ������� ������ �����
// - MaxSize - ������������ ������ �����
//
// ������ :
// - ������
// - �����
// - bool Enqueue(int num) - ��������� � �������
// - int Dequeue() - �������� �� ������� � �������
// - int Show() - �������� ������� ����� � �����, �� �� �������� �� �����
// - Clear() - ��������� �������� ����(������� ��� ��������)
// - Print() - �������� ���������� �����

int main() {

	Queue q(5);

	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);

	q.Print();

	q.Dequeue();
	q.Dequeue();

	q.Print();

	q.Enqueue(5);
	q.Enqueue(6);
	q.Enqueue(7);

	q.Print();

	int value = q.Show();
	cout << "Value: " << value << endl;

	q.Print();

	q.Clear();

	q.Print();

	return 0;
}