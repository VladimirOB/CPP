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
	// ����������, �������� ���������� �� ����� �����
	_finddata_t c_file;

	// ����� ������ ��������� ������
	double hFile;

	// ����� ����� �� ����� � ������� ����� ������ ��������� ������ � ���������� � ������ �����
	char mask[] = "\\*.*";
	char path_mask[200];
	char new_name[200];
	sprintf(path_mask, "%s%s", path, mask);
	hFile = _findfirst(path_mask, &c_file);
	
	
	// ���� ���� �������� ������
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
	// ���� ��� ��������� ���������� �� ��������� ��������� ������
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
				Task_1(new_path); // ��������
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
	// ���������� ������ �� ������ ��������� ������
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
				if (buffer[one] == '�' && buffer[one-1] == '�' || buffer[one] == '�' && buffer[one-1] == '�' || buffer[one] == '�' && buffer[one-1] == '�' && buffer[one-2] == '�' || buffer[one] == '�' && buffer[one-1] == '�' || buffer[one] == '�' && buffer[one-1] == '�' || buffer[one] == '�' && buffer[one-1] == '�' && buffer[one-2] == '�' && buffer[one-3] == '�' || buffer[one] == '�' && buffer[one-1] == '�' && buffer[one-2] == '�' || buffer[one] == '�' && buffer[one-1] == '�' && buffer[one-2] == '�' || buffer[one] == '�' && buffer[one-1] == '�' && buffer[one-2] == '�')
				{
					verb.insert(buffer);
				}
				if (buffer[one] == '�' && buffer[one-1] == '�' || buffer[one] == '�' && buffer[one-1] == '�' && buffer[one-2] == '�' || buffer[one] == '�' && buffer[one-1] == '�' && buffer[one-2] == '�' || buffer[one] == '�' && buffer[one-1] == '�' || buffer[one] == '�' && buffer[one-1] == '�' && buffer[one-2] == '�' || buffer[one] == '�' && buffer[one-1] == '�' && buffer[one-2] == '�' || buffer[one] == '�' && buffer[one-1] == '�' || buffer[one] == '�' && buffer[one-1] == '�')
				{
					adjective.insert(buffer);
				}
				if (buffer[one] == '�' && buffer[one-1] == '�')
				{
					noun.insert(buffer);
				}
			}
		}
		file.close();
	}
	
}

void Prog2() // ������� � ����������.
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
				if (buffer[one] == '�' && buffer[one - 1] == '�' || buffer[one] == '�' && buffer[one - 1] == '�' || buffer[one] == '�' && buffer[one - 1] == '�' && buffer[one - 2] == '�' || buffer[one] == '�' && buffer[one - 1] == '�' || buffer[one] == '�' && buffer[one - 1] == '�' || buffer[one] == '�' && buffer[one - 1] == '�' && buffer[one - 2] == '�' && buffer[one - 3] == '�' || buffer[one] == '�' && buffer[one - 1] == '�' && buffer[one - 2] == '�' || buffer[one] == '�' && buffer[one - 1] == '�' && buffer[one - 2] == '�' || buffer[one] == '�' && buffer[one - 1] == '�' && buffer[one - 2] == '�')
				{
					if (two == 0)
					{
						if (next[two] == '�' || next[two] == '�' || next[two] == '�' || next[two] == '�')
						{
							sprintf(buffer, "%s%s%s", buffer, " ", next);
							verb.insert(buffer);
						}
							
					}
					else if (two == 1)
					{
						if (next[two] == '�' && next[two - 1] == '�' ||
							next[two] == '�' && next[two - 1] == '�' ||
							next[two] == '�' && next[two - 1] == '�' ||
							next[two] == '�' && next[two - 1] == '�' ||
							next[two] == '�' && next[two - 1] == '�' ||
							next[two] == '�' && next[two - 1] == '�' ||
							next[two] == '�' && next[two - 1] == '�' ||
							next[two] == '�' && next[two - 1] == '�' ||
							next[two] == '�' && next[two - 1] == '�')
							{
								sprintf(buffer, "%s%s%s", buffer, " ", next);
								verb.insert(buffer);
							}
							
					}
					else if (two > 1 && two < 5)
					{
						if (next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' && next[two - 4] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' && next[two - 4] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '-' && next[two - 3] == '�' && next[two - 4] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' && next[two - 4] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' && next[two - 4] == '�')
							{
								sprintf(buffer, "%s%s%s", buffer, " ", next);
								verb.insert(buffer);
							}
							
					}
					else if (two > 4)
					{
						if (next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' && next[two - 4] == '�' && next[two - 5] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' && next[two - 4] == '�' && next[two - 5] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '-' && next[two - 4] == '�' && next[two - 5] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' && next[two - 4] == '�' && next[two - 5] == '�' ||
							next[two] == '�' && next[two - 1] == '�' && next[two - 2] == '�' && next[two - 3] == '�' && next[two - 4] == '�' && next[two - 5] == '�')
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
	// runtime 33.8 -> 29(1� list ������� �� set). -> 20(set) -> 18 -> ������ ���� -> 17
	unsigned int start_time = clock(); // ��������� �����
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char path[] = "V:\\MyDocuments\\TextFiles\\ANSI";
	Task_1(path);


	Prog2(); // 15 ���
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
	//unsigned int end_time = clock(); // �������� �����
	//unsigned int search_time = end_time - start_time; // ������� �����
	//cout << "runtime = " << search_time / 1000.0 << endl;
	cout << "runtime = " << clock() / 1000.0 << endl;
	return 0;
}