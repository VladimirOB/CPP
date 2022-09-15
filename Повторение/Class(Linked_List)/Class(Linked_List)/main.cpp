#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LinkedList.h"
using namespace std;


/*
	Добавить
	size_t GetSize() - получить кол-во ячеек списка. можно хранить в переменной и вернуть
	bool Contains(char* str) - возвращает true, если элемент встречается хоть 1 раз. (да / нет)
	size_t GetCount(char* str) - возвращает количество вхождений элемента в список.
	void Insert(size_t position, char* str) - вставляет строку в список ПЕРЕД элементом с номером position
	operator << - вывод списка на экран
*/

/*- конструктор копирования (LinkedList lst2 = lst)
- operator= (LinkedList lst2; lst2 = lst;)
- operator== (сравнивает 2 списка поэлементно)
- operator+= (добавляет элемент в конец списка)
- operator+ (объединяет 2 списка в третий, реализовать в виде дружественной функции)
- bool ReplaceAll(const char* str, const char* str2) - замена всех вхождений строки str в списке на строку str2
- bool Remove(unsigned index) - удаление элемента по индексу, рассмотреть все случаи
- bool RemoveAll(char* str) - удаление из списка всех элементов, содержащих указанную строку
- operator- (const char* str) - удаление из списка всех элементов содержащих указанную строку
- operator -= (const LinkedList& source) // удаляет все строки, которые есть во 2м
*/

int main()
{
	LinkedList lst;
	lst.Add("Hello");
	lst.Add("World");
	lst.Insert(1, "qwer");
	cout << lst ;
	return 0;
}