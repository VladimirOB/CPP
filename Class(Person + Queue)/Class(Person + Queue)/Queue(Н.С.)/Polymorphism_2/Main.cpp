#include <iostream>
#include "Queue.h"

using namespace std;

// 2. Разработать класс Queue, имеющий следующие поля:
// - int* numbers - массив, на основе которого создаётся стек
// - CurrentSize - текущий размер стека
// - MaxSize - максимальный размер стека
//
// Методы :
// - констр
// - дестр
// - bool Enqueue(int num) - поместить в очередь
// - int Dequeue() - вытащить из очереди и вернуть
// - int Show() - показать крайнее число в стеке, но не вынимать из стека
// - Clear() - полностью очистить стек(удалить все элементы)
// - Print() - показать содержимое стека

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