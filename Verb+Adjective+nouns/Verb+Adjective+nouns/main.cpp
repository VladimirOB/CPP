#include "pch.h"

set<string> verb;
unordered_set<string> adjective;
unordered_set<string> noun;
vector<string>file_names;
void Task_1(const char* path)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "RUS");
	// переменная, хранящая информацию об одном файле
	_finddata_t c_file;

	// адрес списка найденных файлов
	double hFile;

	// найти файлы по маске и вернуть адрес списка найденных файлов и информацию о первом файле
	char mask[] = "\\*.*";
	char path_mask[200];
	char new_name[200];
	sprintf(path_mask, "%s%s", path, mask);
	hFile = _findfirst(path_mask, &c_file);
	
	
	// если файл является папкой
	if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
	{
		if (c_file.attrib & _A_SUBDIR)
		{
			char new_path[200];
			strcpy(new_path, path);
			strcat(new_path, "\\");
			strcat(new_path, c_file.name);
			Task_1(new_path);
		}
		else
		{
			std::cout << c_file.name;
			for (size_t i = strlen(c_file.name); i < 40; i++)
			{
				cout << " ";
			}
			cout << c_file.size << std::endl;
			if (c_file.name[strlen(c_file.name) - 1] == 't' && c_file.name[strlen(c_file.name) - 2] == 'x' && c_file.name[strlen(c_file.name) - 3] == 't' && c_file.size > 0)
			{
				sprintf(new_name, "%s%s%s", path, "\\", c_file.name);
				file_names.push_back(new_name);
				strcpy(new_name, "");
			}
				
		}
	}
	// цикл для получения информации об остальных найденных файлах
	while (_findnext(hFile, &c_file) == 0)
	{
		if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
		{
			if (c_file.attrib & _A_SUBDIR)
			{
				std::cout << c_file.name;
				for (size_t i = strlen(c_file.name); i < 40; i++)
				{
					cout << " ";
				}
				cout << "<DIR>" << std::endl;
				char new_path[200];
				strcpy(new_path, path);
				strcat(new_path, "\\");
				strcat(new_path, c_file.name);
				Task_1(new_path); // вытянуть
			}
			else
			{
				std::cout << c_file.name;
				for (size_t i = strlen(c_file.name); i < 40; i++)
				{
					cout << " ";
				}
				cout << c_file.size << std::endl;
				if (c_file.name[strlen(c_file.name) - 1] == 't' && c_file.name[strlen(c_file.name) - 2] == 'x' && c_file.name[strlen(c_file.name) - 3] == 't' && c_file.size > 0)
				{
					sprintf(new_name, "%s%s%s", path, "\\", c_file.name);
					file_names.push_back(new_name);
					strcpy(new_name, "");
				}
			}
		}
	}
	// освободить память от списка найденных файлов
	_findclose(hFile);
}

void Prog()
{
	int one=0;
	char buffer[1000];
	for (size_t i = 0; i < file_names.size(); i++)
	{
		ifstream file(file_names[i], ios::in);
		while (!file.eof())
		{
			file >> buffer;
			one = strlen(buffer) - 1;
			if (one > 3)
			{
				if (buffer[one] == 'л' && buffer[one-1] == 'и' || buffer[one] == 'л' && buffer[one-1] == 'е' || buffer[one] == 'ь' && buffer[one-1] == 'ш' && buffer[one-2] == 'е' || buffer[one] == 'ь' && buffer[one-1] == 'с' || buffer[one] == 'я' && buffer[one-1] == 'с' || buffer[one] == 'я' && buffer[one-1] == 'с' && buffer[one-2] == 'ь' && buffer[one-3] == 'т' || buffer[one] == 'ь' && buffer[one-1] == 'т' && buffer[one-2] == 'и' || buffer[one] == 'ь' && buffer[one-1] == 'т' && buffer[one-2] == 'а' || buffer[one] == 'ь' && buffer[one-1] == 'т' && buffer[one-2] == 'я')
				{
					verb.insert(buffer);
				}
				if (buffer[one] == 'й' && buffer[one-1] == 'ы' || buffer[one] == 'о' && buffer[one-1] == 'г' && buffer[one-2] == 'о' || buffer[one] == 'у' && buffer[one-1] == 'м' && buffer[one-2] == 'о' || buffer[one] == 'й' && buffer[one-1] == 'и' || buffer[one] == 'о' && buffer[one-1] == 'г' && buffer[one-2] == 'е' || buffer[one] == 'у' && buffer[one-1] == 'м' && buffer[one-2] == 'е' || buffer[one] == 'й' && buffer[one-1] == 'о' || buffer[one] == 'м' && buffer[one-1] == 'и')
				{
					adjective.insert(buffer);
				}
				if (buffer[one] == 'я' && buffer[one-1] == 'м')
				{
					noun.insert(buffer);
				}
			}
		}
		file.close();
	}
	
}

void Prog2() // глаголы с предлогами.
{
	int one = 0, two, cnt = 0;
	char buffer[1000];
	char next[1000];
	char temp[1000];
	for (size_t i = 0; i < file_names.size(); i++)
	{
		ifstream file(file_names[i], ios::in);
		 
		while (!file.eof())
		{
			file >> buffer;
			strcpy(temp, buffer);
			strcpy(buffer, next);
			strcpy(next, temp);
			if (cnt == 0)
			{
				file >> next;
				cnt = 1;
			}
			one = strlen(buffer)-1;
			two = strlen(next)-1;
			if (one > 3)
			{
				if (buffer[one] == 'л' && buffer[one - 1] == 'и' || buffer[one] == 'л' && buffer[one - 1] == 'е' || buffer[one] == 'ь' && buffer[one - 1] == 'ш' && buffer[one - 2] == 'е' || buffer[one] == 'ь' && buffer[one - 1] == 'с' || buffer[one] == 'я' && buffer[one - 1] == 'с' || buffer[one] == 'я' && buffer[one - 1] == 'с' && buffer[one - 2] == 'ь' && buffer[one - 3] == 'т' || buffer[one] == 'ь' && buffer[one - 1] == 'т' && buffer[one - 2] == 'и' || buffer[one] == 'ь' && buffer[one - 1] == 'т' && buffer[one - 2] == 'а' || buffer[one] == 'ь' && buffer[one - 1] == 'т' && buffer[one - 2] == 'я')
				{
					if (two == 0)
					{
						if (next[two] == 'о' || next[two] == 'с' || next[two] == 'в' || next[two] == 'у')
						{
							sprintf(buffer, "%s%s%s", buffer, " ", next);
							verb.insert(buffer);
						}
							
					}
					else if (two == 1)
					{
						if (next[two] == 'о' && next[two - 1] == 'с' ||
							next[two] == 'о' && next[two - 1] == 'в' ||
							next[two] == 'б' && next[two - 1] == 'о' ||
							next[two] == 'о' && next[two - 1] == 'п' ||
							next[two] == 'о' && next[two - 1] == 'д' ||
							next[two] == 'т' && next[two - 1] == 'о' ||
							next[two] == 'а' && next[two - 1] == 'з' ||
							next[two] == 'а' && next[two - 1] == 'н' ||
							next[two] == 'з' && next[two - 1] == 'и')
							{
								sprintf(buffer, "%s%s%s", buffer, " ", next);
								verb.insert(buffer);
							}
							
					}
					else if (two > 1 && two < 5)
					{
						if (next[two] == 'д' && next[two - 1] == 'а' && next[two - 2] == 'н' ||
							next[two] == 'о' && next[two - 1] == 'т' && next[two - 2] == 'о' ||
							next[two] == 'д' && next[two - 1] == 'о' && next[two - 2] == 'п' ||
							next[two] == 'о' && next[two - 1] == 'р' && next[two - 2] == 'п' ||
							next[two] == 'о' && next[two - 1] == 'б' && next[two - 2] == 'о' ||
							next[two] == 'з' && next[two - 1] == 'е' && next[two - 2] == 'б' ||
							next[two] == 'о' && next[two - 1] == 'д' && next[two - 2] == 'а' && next[two - 3] == 'н' ||
							next[two] == 'о' && next[two - 1] == 'д' && next[two - 2] == 'о' && next[two - 3] == 'п' ||
							next[two] == 'з' && next[two - 1] == 'и' && next[two - 2] == 'л' && next[two - 3] == 'б' ||
							next[two] == 'з' && next[two - 1] == 'е' && next[two - 2] == 'р' && next[two - 3] == 'ч' ||
							next[two] == 'д' && next[two - 1] == 'е' && next[two - 2] == 'р' && next[two - 3] == 'п' ||
							next[two] == 'о' && next[two - 1] == 'л' && next[two - 2] == 'о' && next[two - 3] == 'к' && next[two - 4] == 'о' ||
							next[two] == 'з' && next[two - 1] == 'е' && next[two - 2] == 'р' && next[two - 3] == 'е' && next[two - 4] == 'ч' ||
							next[two] == 'а' && next[two - 1] == 'з' && next[two - 2] == '-' && next[two - 3] == 'з' && next[two - 4] == 'и' ||
							next[two] == 'д' && next[two - 1] == 'е' && next[two - 2] == 'р' && next[two - 3] == 'е' && next[two - 4] == 'п' ||
							next[two] == 'ь' && next[two - 1] == 'л' && next[two - 2] == 'о' && next[two - 3] == 'д' && next[two - 4] == 'в')
							{
								sprintf(buffer, "%s%s%s", buffer, " ", next);
								verb.insert(buffer);
							}
							
					}
					else if (two > 4)
					{
						if (next[two] == 'г' && next[two - 1] == 'у' && next[two - 2] == 'р' && next[two - 3] == 'к' && next[two - 4] == 'о' && next[two - 5] == 'в' ||
							next[two] == 'ь' && next[two - 1] == 'з' && next[two - 2] == 'о' && next[two - 3] == 'в' && next[two - 4] == 'к' && next[two - 5] == 'с' ||
							next[two] == 'д' && next[two - 1] == 'о' && next[two - 2] == 'п' && next[two - 3] == '-' && next[two - 4] == 'з' && next[two - 5] == 'и' ||
							next[two] == 'и' && next[two - 1] == 'з' && next[two - 2] == 'и' && next[two - 3] == 'л' && next[two - 4] == 'б' && next[two - 5] == 'в' ||
							next[two] == 'м' && next[two - 1] == 'о' && next[two - 2] == 'г' && next[two - 3] == 'у' && next[two - 4] == 'р' && next[two - 5] == 'к')
							{
								sprintf(buffer, "%s%s%s", buffer, " ", next);
								verb.insert(buffer);
							}
							
					}
				}
			}

		}
		file.close();
	}
}

int main()
{
	// runtime 33.8 -> 29(1й list изменил на set). -> 20(set) -> 18 -> удалил инты -> 17
	unsigned int start_time = clock(); // начальное время
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char path[] = "V:\\MyDocuments\\TextFiles\\ANSI";
	Task_1(path);


	Prog2(); // 15 сек
	ofstream file2_verb("verb.txt", ios::out);
	for (auto it = verb.begin(); it != verb.end(); it++)
	{
		file2_verb << *it << endl;
	}
	file2_verb.close();

	//Prog();
	//ofstream file_verb("Task2\\verb.txt", ios::out);
	//ofstream file_adjective("Task2\\adjective.txt", ios::out);
	//ofstream file_noun("Task2\\noun.txt", ios::out);
	//for (auto it = verb.begin(); it != verb.end(); it++)
	//{
	//	file_verb << *it << endl;
	//}
	//file_verb.close();
	//for (auto it = adjective.begin(); it != adjective.end(); it++)
	//{
	//	file_adjective << *it << endl;
	//}
	//file_adjective.close();
	//for (auto it = noun.begin(); it != noun.end(); it++)
	//{
	//	file_noun << *it << endl;
	//}
	//file_noun.close();
	//unsigned int end_time = clock(); // конечное время
	//unsigned int search_time = end_time - start_time; // искомое время
	//cout << "runtime = " << search_time / 1000.0 << endl;
	cout << "runtime = " << clock() / 1000.0 << endl;
	return 0;
}