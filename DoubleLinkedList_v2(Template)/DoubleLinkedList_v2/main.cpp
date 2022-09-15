#include "pch.h"
#include "DoubleLinkedList.h"

/*2. В класс DoubleLinkedList добавить следующие методы:
- size_t GetSize() - получить количество ячеек списка +++
- bool Contains(char* str) - возвращает true, если элемент встречается хотя бы раз в списке +++
- size_t GetCount(char* str) - возвращает количество вхождений элемента в список +++
- void Insert(size_t position, char* str) - вставляет строку в список ПЕРЕД элементом с номером position +++
- operator << - вывод списка на экран

- конструктор копирования (DoubleLinkedList lst2 = lst) +++
- operator= (DoubleLinkedList lst2; lst2 = lst;) +++
- operator== (сравнивает 2 списка поэлементно) +++
- operator+= (добавляет элемент в конец списка) +++
- operator+ (объединяет 2 списка в третий, реализовать в виде дружественной функции)
- bool ReplaceAll(const char* str, const char* str2) - замена всех вхождений строки str в списке на строку str2
- bool Remove(insigned index) - удаление элемента по индексу, рассмотреть все случаи
- bool RemoveAll(char* str) - удаление из списка всех элементов, содержащих указанную строку

- void Reverse() - переворот списка
- Sort() - сортировка списка (любым методом, как можно быстрее, передавать компаратор)*/


bool ascend(char* a, char* b)
{
	if (strcmp(a, b) == 1)
		return true;
	else
		return false;
}

bool descend(char* a,char* b)
{
	if (strcmp(a, b) == -1)
		return true;
	else
		return false;
}

int main(void)
{
	DoubleLinkedList <char> list, list2, list3;
	/*list.Add(a);
	list.Add(a);
	list.Add(a);
	list.Insert(0,a);*/

	list.Add("Hello");
	list.Add("World");
	list.RemoveAll("Hello");
	/*list.Add("big");
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
	list.Add("point");*/

	//for (size_t i = 0; i < 2000; i++)
	//{
	//	list.Add("gapsoiubgoasfwgjhj");
	//	list.Add("baapsoiubgodafasdfgsg");
	//}

	//list.Sort(); // в режиме отладки с зажатой клавишей F11 весь метод длился 2 минуты 24сек
	cout << "Time = " << (clock() / 10000.0) << endl;
	cout << list << endl;
}