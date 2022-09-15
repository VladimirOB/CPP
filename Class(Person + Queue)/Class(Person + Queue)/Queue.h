#pragma once

/*2. Разработать класс Queue, имеющий следующие поля:
- int* numbers - массив, на основе которого создаётся стек
- CurrentSize - текущий размер стека
- MaxSize - максимальный размер стека

Методы:
- констр
- дестр
- bool Enqueue(int num) - поместить в очередь
- int Dequeue() - вытащить из очереди и вернуть
- int Show() - показать крайнее число в стеке, но не вынимать из стека
- Clear() - полностью очистить стек (удалить все элементы)
- Print() - показать содержимое стека*/

class Queue
{
	int* Numbers;
	size_t MaxSize;
	size_t CurrentSize;

public:
	Queue();
	Queue(size_t size);
	~Queue();
	bool Enqueue(int num); //поместить в очередь
	int Dequeue(); //вытащить из очереди и вернуть
	int Show();
	void Clear();
	void Print();
};

