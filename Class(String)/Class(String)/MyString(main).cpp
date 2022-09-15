#include "pch.h"
#include "MyString.h"
/*1. Разработать класс MyString, имеющий следующие поля:
- char* Str (указатель на строку)
- MaxSize - (максимальный размер строки)

методы класса
- контструкторы (по умолчанию, или принимает С-строку)
- деструктор
- void Print()
- Set("test") - изменение строки в классе
- char* Get() - возвращает строку из классаA
- int GetLength() - получить текущий размер строки
- int GetVowelsCount() - получить количество гласных
- void ToUpper() - перевести строку в верхний регистр
- void ToLower() - перевести строку в нижний регистр
- void RemoveDigits() - удаляет все цифры из строки
- void SaveToFile() - сохраняет строку в текстовый файл.
- void LoadFromFile(); - загружает строку из файла.
Пример:
MyString str("Hello world!!!!");
str.Print();
char* tst = str.Get();
int len = str.GetLength();*/

int main(void)
{
	MyString str("Good hello world my big", 39);
	str.Print();

	str.Set("Balaban Vova 1 sa say");
	str.Print();

	//char* str_get = str.Get();

	//int len = str.GetLength();
	//cout << "String length = " << len << endl;

	//int vow = str.GetVowelsCount(0);
	//cout << "Number of vowels = " << vow << endl;

	//str.ToUpper();
	//str.Print();

	//str.ToLower();
	//str.Print();

	//str.RemoveDigits();
	//str.Print();

	//str.SaveToFile();

	//str.LoadFromFile();
	//str.Print();

	cout << str.Contains("say") << endl;
	cout << str.Contains("Nooka") << endl;
}