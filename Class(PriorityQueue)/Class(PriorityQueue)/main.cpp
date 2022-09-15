#include "pch.h"
#include "PriorityQueue.h"
#include "ArithmeticalException.h"
/*3. Реализовать класс PriorityQueue, который позволяет хранить значения и извлекать их из очереди в соответствии с их приоритетом
Класс имеет следующие члены класса:
- int* buffer;
- size_t MaxSize;

Методы:
- констр
- дестр
- EnQueue() - поместить в очередь
- DeQueue() - вытащить из очереди
- Show() - показать элемент с краю
- Print() - показать всю очередь
- Clear() - очистить всю очередь

Доп. задание: использовать для очереди компаратор (передать в конструктор)*/

bool ascend(int a, int b)
{
	return a < b;
}

bool descend(int a, int b)
{
	return a > b;
}

bool comp(int a, int b)
{
	if (a < 0 && b < 0)
		return a > b;

	if (a >= 0 && b >= 0)
		return a < b;

	if (a >= 0 && b < 0)
		return false;

	if (a < 0 && b >= 0)
		return true;
}

int main(void)
{
	PriorityQueue queue(descend);
	queue.Run(10); // передаём размер

	/*queue.EnQueue(9);
	queue.EnQueue(8);
	queue.EnQueue(3);
	queue.EnQueue(7);
	queue.EnQueue(6);
	queue.EnQueue(5);
	queue.EnQueue(4);
	queue.EnQueue(5);
	queue.EnQueue(6);
	queue.EnQueue(0);*/
	queue.Print();

	try 
	{
		cout << "DeQueue = " << queue.DeQueue() << endl;
		//cout << "DeQueue = " << queue.DeQueue() << endl;
	}
	catch(ArithmeticalException* ex)
	{
		ex->Print();
		delete ex;
	}

	queue.Print();
	cout << "Show = " << queue.Show() << endl;


}