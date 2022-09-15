#include "pch.h"
#include "Application.h"
void Task_1()
{
	map <string, int> m;

	string buffer;
	ifstream file("1.txt");
	ofstream file_result("1_result.txt");
	if (!file.fail())
	{
		while (!file.eof())
		{
			file >> buffer;
			if (m.find(buffer) != m.end())
			{
				m[buffer] += 1;
			}
			else
			{
				m[buffer] = 1;
			}
		}
		file.close();
	}
	else cout << "Error opening files!" << endl;

	

	multimap<int, string> m2; // меняем местами ключ и значение
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		int key = it->second;
		string str = (*it).first;
		m2.insert(pair<int, string>(key, str)); // заполняем значениями 1-го map

		//m2.insert(make_pair(it->second, it->first));
	}

	if (!file_result.fail())
	{
		for (auto it = m2.begin(); it != m2.end(); it++)
		{
			file_result << it->second << " " << "-" << " " << it->first << endl;
		}
		cout << "Ok!" << endl;
	}
	else cout << "Error opening files!" << endl;
	file.close();
	file_result.close();
}

int main(void)
{
	//Task_1();
	Application app;
	app.Run();
}