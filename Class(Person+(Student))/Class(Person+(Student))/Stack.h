#pragma once

/*Методы:
- констр
- дестр
- bool Push(int num) - поместить в стек
- int Pop() - вытащить из стека и вернуть
- int Show() - показать крайнее число в стеке, но не вынимать из стека
- Clear() - полностью очистить стек (удалить все элементы)
- Print() - показать содержимое стека*/

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
	int Pop();  //вытащить из стека и вернуть
	int Show();
	void Clear();
	void Print();
};

