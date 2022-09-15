#include "pch.h"
#include "DoubleLinkedList.h"

int main(void)
{
	DoubleLinkedList list;
	list.Add("big");
	list.Add("debug");
	list.Add("lector");
	list.Add("hour");
	list.Add("queue");
	list.Add("aloha");
	list.Add("integral");
	list.Add("zero");
	list.Add("keep");
	list.Add("joba");
	list.Add("apple");
	list.Add("sorting");
	list.Add("wow");
	list.Add("going");
	list.Add("end");
	list.Add("point");
	

	//list.Sort(); // в режиме отладки с зажатой клавишей F11 весь метод длился 2 минуты 24сек
	list.InsertionSort(); // в режиме отладки с зажатой клавишей F11 весь метод длился 23.8сек
	cout << list << endl;
	cout << "Time = " << (clock() / 10000.0) << endl;

}

