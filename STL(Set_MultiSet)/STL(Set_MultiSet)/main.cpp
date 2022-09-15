#include "pch.h"
void Task_1()
{//1. Пользователь вводит имя файла, программа удаляет из него повторяющиеся слова и результат сохраняет в другой файл

	char file_name_first[] = "DB/Task_1.txt", file_name_result[] = "DB/Task_1_Result.txt";
	set <string> s;
	string buffer;
	set <string>::iterator p;
	ifstream file_first(file_name_first, ios::in);
	ofstream file_second(file_name_result, ios::out);

	if (!file_first.fail())
	{
		while (!file_first.eof())
		{
			file_first >> buffer;
			s.insert(buffer);
		}
	}

	if (!file_second.fail())
	{
		for (p = s.begin(); p != s.end(); p++)
		{
			cout << *p << endl;
			file_second << *p << " ";
		}
	}
	file_first.close();
	file_second.close();
}

void Task_2()
{
	/*2. Пользователь вводит имя файла, программа подсчитывает сколько раз в файле встречается каждая буква из текста. Результат сохраняется в файл
в виде отчёта: а - 12 б - 34 в - 54 (в столбик). Буквы в файле отчёта идут в алфавитном порядке*/
	char file_name_first[] = "DB/Task_2.txt", file_name_result[] = "DB/Task_2_Result.txt";
	multiset <char> s;
	set <char> s2;
	char buffer;
	multiset <char>::iterator p;
	ifstream file_first(file_name_first, ios::in);
	ofstream file_second(file_name_result, ios::out);

	if (!file_first.fail())
	{
		while (!file_first.eof())
		{
			file_first >> buffer;
			s.insert(buffer);
			s2.insert(buffer);
		}
	}

	if (!file_second.fail())
	{
		for (p = s2.begin(); p != s2.end(); p++)
		{
			
			cout << *p << endl;
			file_second << *p << " - " << s.count(*p) << endl;
		}
	}
	file_first.close();
	file_second.close();
}

void Task_3()
{
	/*
	 3. Пользователь вводит имя файла, содержащего код на языке С++. Программа подсчитывает в коде количество использованных операторов if.
	 В результирующий файл записывается количество и координаты каждого обнаруженного оператора.*/


	char file_name_first[] = "DB/small.cpp", file_name_result[] = "DB/Task_3_Result.txt";
	char file_name_first2[] = "DB/long.cpp", file_name_result2[] = "DB/Task_3_Result(long).txt";

	vector <string> v;

	string buffer;
	char buff[200];

	ifstream file_first(file_name_first2, ios::in);
	ofstream file_second(file_name_result2, ios::out);
	int str = 1;
	int countIf = 0;
	int pos = 0;
	if (!file_first.fail())
	{
		while (!file_first.eof())
		{
			file_first.getline(buff, 199);
			buffer = buff;
			v.push_back(buffer);
		}
	}
	if (!file_second.fail())
	{
		file_second << "Word search." << endl;
		file_second << "____________________________" << endl;
		file_second << "| Word | String | Position |" << endl;
		file_second << "____________________________" << endl;
		size_t found;
		for (size_t i = 0; i < v.size(); i++)
		{
			//cout << v[i] << endl;
			found = v[i].find("if");
			if (found != string::npos) // npos -1, но по факту бесконечное положительное число.
			{
				buffer = v[i];
				for (int i = 0; i < buffer.size(); i++)
				{
					//if ((buffer[i] == '\t' || buffer[i] == ' ' || buffer[i] == ')') && (buffer[i+1] == 'i' && buffer[i + 2] == 'f' &&(buffer[i+3]== ' ' || buffer[i+3] == '(')))
					if (buffer[i] == 'i' && buffer[i + 1] == 'f')
					{
						pos = i;
						if (pos < 10)
						{
							if (str < 100)
								file_second << "|  If  | " << str << "     | " << pos << "        |" << endl;
							else
								file_second << "|  If  | " << str << "    | " << pos << "        |" << endl;
						}
						else
						{
							if (str < 100)
								file_second << "|  If  | " << str << "     | " << pos << "       |" << endl;
							else
								file_second << "|  If  | " << str << "    | " << pos << "       |" << endl;
						}
						
						cout << "If = " << str << "  .  " << pos << endl;
					}
				}
				
				countIf++;
			}
			str++;
		}
		file_second << "____________________________" << endl;
		file_second << "Count of word = " << countIf << endl;
	}
	
	file_first.close();
	file_second.close();
}

int main(void)
{
	//Task_1();
	//Task_2();
	//Task_3();
	// 
	//Подсчитать частотный словарь символов в файле с использованием класса map
	/*typedef map <char, int> MyMap;
	map <char, int> m;

	char buffer[200];
	ifstream file("1.txt");

	if (!file.fail())
	{
		while (!file.eof())
		{
			file.getline(buffer, 200);

			for (size_t i = 0; buffer[i] != 0; i++)
			{
				if (m.find(buffer[i]) != m.end())
					m[buffer[i]] += 1;
				else
				{
					m[buffer[i]] = 0;
				}
			}
		}

		file.close();
	}
	else cout << "Error opening files!" << endl;

	map <char, int>::iterator pos;
	ofstream file2("1_Result.txt");

	if (!file2.fail())
	{
		for (pos = m.begin(); pos != m.end(); pos++)
		{
			pos->second *= 2;
			file2 << pos->first << " " << "-" << " " << pos->second << endl;
		}

		file2.close();
	}
	else cout << "Error opening files!" << endl;*/

}