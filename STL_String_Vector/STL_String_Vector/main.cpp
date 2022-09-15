#include "pch.h"
#include <iostream>

void Task_1()
{
	/*1. Пользователь вводит имя текстового файла, программа удаляет из него все слова "hello".
	Результат записывается в отдельный файл.
	Первый файл никуда не девается.*/

	char file_name1[40], file_name1_res[40];
	cout << "Enter file name:(no extension) " << endl;
	cin >> file_name1;
	strcpy(file_name1_res, file_name1);
	strcat(file_name1_res, "_result.txt");

	strcat(file_name1, ".txt");
	string str1;

	fstream file1(file_name1, ios::in);
	fstream file1_result(file_name1_res, ios::out);

	if (!file1.fail())
	{
		while (!file1.eof())
		{
			file1 >> str1;
			if (str1 != "hello")
				file1_result << str1 << " ";
		}
	}
	file1_result.close();
}

void Task_2()
{
	/*2. Пользователь вводит имя текстового файла,
	программа делит файл на слова и сохраняет их в результирующий файл в столбик, отсортированными в алфавитном порядке.
	Слова в файле разделяются пробемами, табуляцией или переходом на слудующую строку.*/

	char file_name[40], file_name_res[40];
	cout << "enter file name:(no extension) " << endl;
	cin >> file_name;
	strcpy(file_name_res, file_name);
	strcat(file_name_res, "2_result.txt");
	strcat(file_name, ".txt");

	//vector <string> str;
	////str.reserve(100);
	//string tmp;

	fstream file(file_name, ios::in);
	fstream file_result(file_name_res, ios::out);

	//if (!file.fail())
	//{
	//	while (!file.eof())
	//	{
	//		file >> tmp;
	//		str.push_back(tmp);
	//	}
	//}
	//sort(str.begin(), str.end());
	//for (size_t i = 0; i < str.size(); i++)
	//{
	//	file_result << str[i] << endl;
	//}


	//set - сортировка без повторений. multiset - сортировка с повторениями.
	string str;
	istringstream iss(str);
	multiset<string> mset((istream_iterator<string>(iss)), istream_iterator<string>());
	str.clear();
	for (auto const& val : mset)
	{
		str += (val + ' '); // закидываем в str отсортированные слова по очереди.

	}
	if (!file_result.fail())
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			file_result << str[i];
			if (str[i] == ' ')
				file_result << endl;
		}
	}

	file.close();
	file_result.close();
}

void Task_3()
{
	/*3. Пользователь вводит имена двух файлов, программа записывает в столбик слова в третий файл, только в том случае,
	если слово встречается и в первом и во втором файле.*/

	char file_name1[40], file_name2[40], file_name_result[40];
	cout << "Enter file name1:(no extension) " << endl;
	cin >> file_name1;


	strcpy(file_name2, file_name1);
	strcpy(file_name_result, file_name1);
	strcat(file_name_result, "_result.txt");
	strcat(file_name1, "(1).txt");
	strcat(file_name2, "(2).txt");
	string str1, str2;
	string tmp1, tmp2;
	string result;
	fstream file1(file_name1, ios::in);
	fstream file2(file_name2, ios::in);
	fstream file_result(file_name_result, ios::out);
	if (!file1.fail() && !file2.fail())
	{
		while (!file1.eof())
		{
			file1 >> tmp1;
			str1 += tmp1 += " ";
		}
		while (!file2.eof())
		{
			file2 >> tmp2;
			size_t found = str1.find(tmp2);
			if (found !=string::npos) // npos -1, но по факту бесконечное положительное число.
			{
				file_result << tmp2 << endl;
				str2 += tmp2 += " ";
			}

		}
	}
	else
		cout << "Error opening one or more files." << endl;

	cout << str2 << endl;
	file_result.close();
	file1.close();
	file2.close();

	/*char file_name1[40], file_name2[40], file_name_result[40];
	cout << "Enter file name1:(no extension) " << endl;
	cin >> file_name1;


	strcpy(file_name2, file_name1);
	strcpy(file_name_result, file_name1);
	strcat(file_name_result, "_result.txt");
	strcat(file_name1, "(1).txt");
	strcat(file_name2, "(2).txt");
	vector <string> str1, str2;
	string tmp1, tmp2;
	string result;
	fstream file1(file_name1, ios::in);
	fstream file2(file_name2, ios::in);
	fstream file_result(file_name_result, ios::out);
	if (!file1.fail() && !file2.fail())
	{
		while (!file1.eof())
		{
			file1 >> tmp1;
			str1.push_back(tmp1);
		}
		while (!file2.eof())
		{
			file2 >> tmp2;
			str2.push_back(tmp2);
		}

		for (size_t i = 0; i < str1.size(); i++)
		{
			for (size_t k = 0; k < str2.size(); k++)
			{
				if(str1[i] == str2[k])
				file_result << str1[i] << endl;
			}
		}
	}
	else
	cout << "Error opening one or more files." << endl;

	file_result.close();
	file1.close();
	file2.close();*/

}

int main(void)
{
	//Task_1();
	//Task_2();
	Task_3();
}