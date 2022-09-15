#include <iostream>
#include "Stack.h"

using namespace std;

//2. ����������� ����� Stack, ������� ��������� ����:
// - int* numbers - ������, �� ������ �������� �������� ����
// - CurrentSize - ������� ������ �����
// - MaxSize - ������������ ������ �����
//
// ������ :
// - ������
// - �����
// - bool Push(int num) - ��������� � ����
// - int Pop() - �������� �� ����� � �������
// - int Show() - �������� ������� ����� � �����, �� �� �������� �� �����
// - Clear() - ��������� �������� ����(������� ��� ��������)
// - Print() - �������� ���������� �����

int main() {
	
	int max_size, value, value2;
	cout << "Enter max size: ";
	cin >> max_size;
	
	Stack stack(max_size);

	stack.Push(5);
	stack.Push(7);
	stack.Push(9);
	
	value = stack.Show();
	cout << "Value(show): " << value << endl;

	value2 = stack.Pop();
	cout << "Value(Pop): " << value << endl;

	value = stack.Show();
	cout << "Value(show): " << value << endl;

	stack.Print();

	stack.Clear();

	return 0;
}