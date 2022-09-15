#include <iostream>
using namespace std;
#include "Strings.h"
/*1. Разработать класс Strings, позволяющий хранить массив строк и имеющий следующие поля:
- char** str - массив строк
- MaxRows - максимальное количество строк
- CurrentRows - текущее количество строк

Методы класса:
- конструкторы (без параметров, принимающий начальное количество строк, копирования)
- деструктор

- Print() - печать строки
- Add(char*) - добавление строки
- Remove(size_t index) - удаление строки по индексу (по позиции)
- Strings operator+ (char*) - добавление строки
- Strings operator+ (const Strings& source) - объединение двух контейнеров со строками (Strings)

- Strings& operator-= (char* str) - удаляет все вхождения строки в контейнере
- Strings& operator-= (const Strings& source) - удаляет все строки, которые есть во втором контейнере sourse
- bool operator == (const Strings& source) - построчно сравнивает 2 контейнера
- RemoveDuplicates() - удаление повторяющихся строк в контейнере
- Sort() - сортировка строк в контейнере в алфавитном порядке
пример:
Strigs str(5);
str.Add("Hello");
str.Add("world");
str.Add("!!!");

Strigs str2(5);
str2.Add("world");
str2.Add("!!!");

str-=str2;
str.Print(); // Hello

- Save(char* filename) - сохранение в файл средствами C++
- Load(char* filename) - загрузка из файла средствами C++*/

/*char cnt1[] = "1";
char cnt2[] = "2";
if (strcmp(cnt1, cnt2) == 1)
	cout << "cnt1 > cnt2" << endl;
else
	cout << "cnt1 < cnt2" << endl;*/



	/*2. Для класса Strings добавить следующие методы:
	- istream& operator >> - потоковый ввод 7 строк с клавиатуры
	- ostream& operator << - потоковый вывод всех строк на консоль
	- ifstream& operator >> - потоковый ввод 7 строк из файлового потока
	- ofstream& operator << - потоковый вывод всех строк в открытый файловый поток
	- Strings operator+ (Strings&, char*) - добавление одной строки в конец (с формированием нового контейнера строк)
	- Strings operator+ (Strings&, Strings&) - объединение 2 контейнеров строк (с формированием нового контейнера строк)

	Все операторы перегружаются как обычные функции и являются друзьями класса Strings.*/

int main()
{
	Strings str;
	//str.Add("ALOHA");
	//str.Add("Hello world");
	//str.Add("Okey Jimmy");
	//str.Add("ALOHA");
	//str.Add("Qwerty");
	//str.Add("Hello world");
	//str.RemoveDuplicates();
	//str.Sort();
	//str.Save("1.txt");
	str.Load("1.txt");
	cout << str << endl;

	return 0;
}