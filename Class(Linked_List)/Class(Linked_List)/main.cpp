#include "pch.h"
#include "LinkedList.h"
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

int main(void)
{
	LinkedList list, list2;
	list.Add("123");
	list.Remove(0);
	list.Add("qwe");
	list += "2";
	cout << list << endl;
	/*list.Add("One");
	list.Add("Two");
	list.Add("Three");
	list.Add("Four");

	list2.Add("Ten");
	list2 = list;
	list2.Add("Odno Slovo");

	list2 -= list;
	cout << "list:" << endl << list << endl;
	
	cout << "list2:" << endl << list2 << endl;
	
	system("pause");
	system("cls");

	LinkedList list3 = list;

	if (list == list2) 
		cout << "list == list2" << endl;
	else cout << "list != list2" << endl;

	list += "Ten";
	LinkedList list4 = list + list2;

	list.ReplaceAll("Two", "Million");
	list.Remove(1);
	list.RemoveAll("Three");
	list - "Four";
	list.RemoveAll("One");
	list.Add("One");
	cout << "list:" << endl << list << endl;
	cout << "list2:" << endl << list2 << endl;
	cout << "list3:" << endl << list3 << endl;
	cout << "list4:" << endl << list4 << endl;*/
	/*cout << "Contains (1 - yes, 0 - no) =  " << lst.Contains("Two") << endl;
	cout << "Count Contains = " << lst.GetCount("Two") << endl;
	cout <<"GetSize = " << lst.GetSize() << endl;*/
}