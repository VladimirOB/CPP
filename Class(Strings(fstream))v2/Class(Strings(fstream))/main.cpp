#include "pch.h"
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

class Point
{
	int x, y, z;

public:
	
	Point()
	{
		x = y = z = 0;
	}

	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	friend ostream& operator << (ostream& os, const Point& point);
	friend istream& operator >>(istream& is, Point& point);
};

ostream& operator << (ostream& os, const Point& point) // возвращает ссылку на объект типа ostream. первый параметр принимает ostream(можно и istream и др)
{
	os << point.x << " " << point.y << " " << point.z;
	return os;
}

istream& operator >>(istream& is, Point& point) // istream для считывания из файла.
{
	is >> point.x >> point.y >> point.z;
	return is;
	
}

int main(void)
{
	Strings str, str2, str3;
	int cnt = 0;
	ifstream ifs;
	ifs.open("test.txt", ifstream::in ); // | ios_base::skipws для чего?
	if (!ifs.is_open())
	{
		cout << "Error opening file!" << endl;
	}
	else
	{
		cout << "File is open" << endl;
		while (!ifs.eof())
		{
			cnt++;
			ifs >> str; // взять из файла.
			if (cnt == 7)
				break;
		}

	}ifs.close();


	for (size_t i = 0; i < 7; i++)
	{
		cout << "Enter string str2: " << i + 1 << "/7" << endl;
		cin >> str2;
	}
	
	ofstream ofs;
	ofs.open("new_test.txt", ofstream::out); 
	if (!ofs.is_open())
	{
		cout << "Error opening file!" << endl;
	}
	else
	{
		cout << "File is open" << endl;
		ofs << str << str2; // закинуть в файл.
		cout << "Save str + str2 Successfull!" << endl;
	}ofs.close();
	
	str3 = str + "QWERTY";
	str3 = str + str2;
	
	cout << "str: " << endl << str;
	cout << endl << "str2: " << endl << str2;
	cout << endl << "str3: " << endl << str3;

	

	/*str2 = str;
	str2.Add(d);
	cout << "\nStr: " << endl;
	str.Print();
	cout << "\nStr2: " << endl;
	str2.Print();
	if (str2 == str)
		cout << "str2 = str" << endl;
	else
		cout << "str2 != str" << endl;
	cout << endl;
	str.Sort();
	cout << "Str Sorting:" << endl;
	str.Print();
	system("pause");
	system("cls");
	str3 = str;
	str3.Add(a);
	str3.Add(a);
	cout << "str3: " << endl;
	str3.Print();
	str3 -= a;
	cout << "\nstr3 -= Hello world " << endl;
	str3.Print();
	system("pause");
	system("cls");
	cout << "str3: " << endl;
	str3.Add(a);
	str3.Add(b);
	str3.Add(d);
	str3.Add(e);
	str3.Add(c);
	str3.Print();
	cout << "\nstr: " << endl;
	str.Print();
	str3 -= str;
	cout << "\nstr3 -= str " << endl;
	cout << "str3: " << endl;
	str3.Print();
	str4.Add(a);
	str4.Add(a);
	str4.Add(b);
	str4.Add(b);
	str4.Add(e);
	cout << "\nstr4: " << endl;
	str4.Print();
	str4.RemoveDuplicates();
	cout << "\nstr4(RemoveDuplicates): " << endl;
	str4.Print();*/


	/*str.Remove(3);
	cout << "str = Hello, Good, Bad (Remove(Uf))" << endl;
	str.Print();
	system("pause");
	system("cls");
	str2 = str;
	cout << "str2 = str (Hello, Good, Bad)" << endl;
	str2.Print();
	system("pause");
	system("cls");
	str3 = str + str2;
	cout << "str3 = str + str2 (Hello, Good, Bad)x2" << endl;
	str3.Print();
	system("pause");
	system("cls");
	str2 = str + (c) + (d);
	cout << "str2 = str + Bad + Uf" << endl;
	str2.Print();
	system("pause");
	system("cls");
	cout << "Save str3 (str + str2)" << endl;
	str3.Save("test.txt");
	system("pause");
	system("cls");
	str4.Load("test.txt");
	cout << "Load str4 (str + str2)" << endl;
	system("pause");
	system("cls");
	str4.Print();*/
}