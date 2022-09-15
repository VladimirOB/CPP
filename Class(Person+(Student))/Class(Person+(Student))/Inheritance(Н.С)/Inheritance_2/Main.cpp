#include <iostream>
#include "Stack.h"

using namespace std;

//2. Разработать класс Stack, имеющий следующие поля:
// - int* numbers - массив, на основе которого создаётся стек
// - CurrentSize - текущий размер стека
// - MaxSize - максимальный размер стека
//
// Методы :
// - констр
// - дестр
// - bool Push(int num) - поместить в стек
// - int Pop() - вытащить из стека и вернуть
// - int Show() - показать крайнее число в стеке, но не вынимать из стека
// - Clear() - полностью очистить стек(удалить все элементы)
// - Print() - показать содержимое стека

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