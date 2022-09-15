#include "Application.h"

Application::Application()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	// добавление пунктов в меню
	menu->Add('1', "Add pair", &Application::AddPair);
	menu->Add('2', "See the translation of the word", &Application::Translate);
	menu->Add('3', "See the translation of the string", &Application::TranslateString);
	menu->Add('4', "Edit pair", &Application::EditPair);
	menu->Add('5', "Delete pair", &Application::DeletePair);
	menu->Add('6', "View pair 1 letter ", &Application::ViewOnePair);
	menu->Add('7', "View all pair", &Application::ViewAllPair);
	menu->Add('8', "View report of missing words", &Application::ViewReport);
	menu->Add('0', "Exit from program(save)", &Application::Exit);
	menu->Add('n', "Exit from program(not save)", &Application::ExitNoSave);
	ifstream file("System/db.dat");
	if (!file.fail())
	{
		while (!file.eof())
		{
			file >> buffer_eng;
			file >> buffer_ru;
			m.insert(make_pair(buffer_eng, buffer_ru));
			rev_m.insert(make_pair(buffer_ru, buffer_eng));
		}
	}
	file.close();
	ifstream file2("System/report.dat");
	if (!file2.fail())
	{
		buffer_eng.clear();
		while (!file2.eof())
		{
			file2 >> buffer_eng;
			if(buffer_eng != "")
			Report.insert(buffer_eng);
		}
	}
	file2.close();

}

Application::~Application()
{
	delete menu;
}

void Application::AddPair()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	fstream report;
	report.open("System/report.dat",ios::in);
	string tmp;
	string rep;
	char buff[40], buff2[40];
	cout << "Enter word in English: " << endl;
	cin.getline(buff,39);
	cout << "Enter word in Russian: " << endl;
	cin.getline(buff2, 39);
	for (size_t i = 0; i < strlen(buff); i++)
	{
		buff[i] = (char)tolower((unsigned char)buff[i]); // transform(m.begin(), m.end(), tolower);
	}
	for (size_t i = 0; i < strlen(buff2); i++)
	{
		buff2[i] = (char)tolower((unsigned char)buff2[i]);
	}
	buffer_eng = buff;
	buffer_ru = buff2;
	if (!report.fail()) // удаляет добавленное слово из report
	{
		size_t found,found_ru,found_set;
		set<string>::iterator pos;
		pos = Report.find(buffer_eng);
		if (pos != Report.end())
			Report.erase(*pos);
		pos = Report.find(buffer_ru);
		if (pos != Report.end())
			Report.erase(*pos);
		
		while (!report.eof())
		{
			report >> tmp; // можно было считать весь и потом rep.erase(buffer_eng) если found.
			found = buffer_eng.find(tmp);
			found_ru = buffer_ru.find(tmp);
			if (found == string::npos && found_ru == string::npos)
			{
				rep += tmp;
				rep += "\n";
			}
			tmp.clear();
		}
	}
	
	m.insert(make_pair(buffer_eng, buffer_ru));
	rev_m.insert(make_pair(buffer_ru, buffer_eng));
	report.close();
	report.open("System/report.dat", std::ios::out);
	if (!report.fail())
	{
		report << rep;
	}
	cout << "add successfully!" << endl;
	system("pause");
}

void Application::Translate()
{
	ofstream report;
	report.open("System/report.dat", std::ios::app);
	cout << "Enter word in English or Russian: " << endl;
	char buff[40];
	cin.getline(buff, 39);
	for (size_t i = 0; i < strlen(buff); i++)
	{
		buff[i] = (char)tolower((unsigned char)buff[i]);
	}
	buffer_eng = buff;
	if (buff[0] < 'A')
	{
		if (rev_m.find(buffer_eng) != rev_m.end())
		{
			cout << "----->" << rev_m[buffer_eng] << endl;
		}
		else
		{
			cout << "(" << buffer_eng << " not found!)" << endl;
			report << buffer_eng << endl;
			Report.insert(buffer_eng);
		}
	}
	else
		if (m.find(buffer_eng) != m.end())
		{
			cout << "----->" << m[buffer_eng] << endl;
		}
		else
		{
			cout << "(" << buffer_eng << " not found!)" << endl;
			report << buffer_eng << endl;
			Report.insert(buffer_eng);
		}
	report.close();
	system("pause");
}

void Application::TranslateString()
{
	ofstream report;
	report.open("System/report.dat",std::ios::app);
	cout << "Enter string in English or Russian: " << endl;
	char buff[200];
	cin.getline(buff,199);
	for (size_t i = 0; i < strlen(buff); i++)
	{
		buff[i] = (char)tolower((unsigned char)buff[i]);
	}
	buffer_eng = buff;
	string word;
	stringstream words(buffer_eng);
	while (words >> word)
	{

		if (buff[0] < 'A')
		{
			if (rev_m.find(word) != rev_m.end())
			{
				cout << rev_m[word] << " ";
			}
			else
			{
				cout << "(!" << word << ")" ;
				report << word  << endl;
				Report.insert(word);
			}
		}
		else
			if (m.find(word) != m.end())
			{
				cout <<  m[word] << " ";
			}
			else
			{
				cout << "(!" << word << ")";
				report << word  << endl;
				Report.insert(word);
			}
				
	}
	cout << endl;
	report.close();
	system("pause");
}

void Application::EditPair()
{
	cout << "Enter the word whose meaning you want to change in English: " << endl;
	getline(cin, buffer_eng);
	size_t found;
	bool flag = false;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		found = it->first.find(buffer_eng);
		if (found != string::npos)
		{
			cout << "Enter the word to replace in Russian: " << endl;
			getline(cin, buffer_ru);
			m[buffer_eng] = buffer_ru;
			buffer_eng.clear();
			buffer_ru.clear();
			flag = true;
			break;
		}
	}
	if (!flag)
		cout << "Pair not found!" << endl;
	system("pause");
}

void Application::DeletePair()
{
	cout << "Enter the word you want to delete: (eng)" << endl;
	getline(cin,buffer_eng);
	if(m.erase(buffer_eng))
	{
		cout << "Delete successfull!" << endl;
	}
	else
		cout << "Delete error! Pair not found!" << endl;
	buffer_eng.clear();
	system("pause");

}

void Application::ViewOnePair()
{
	system("cls");
	unsigned i = 1;
	string letter;
	cout << "Enter the required letter: " << endl;
	getline(cin, letter);
	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (letter[0] == it->first[0])
		{
			
			cout << i++ << ") " << it->first << " " << " - " << it->second << endl;
		}
		
	}
	system("pause");
}

void Application::ViewAllPair()
{ 
	system("cls");
	unsigned i = 1, ch = 97;
	string letter;
	cout << "a:" << endl;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		letter = it->first[0];
		if (letter[0] > ch)
		{
			cout << endl << letter[0] << ":";
			cout << endl;
			i = 1;
			ch++;
		}
		cout << i++ << ") " << it->first << " " << " - " << it->second << endl;
	}
	system("pause");
}

void Application::ViewReport()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int i = 1;
	for (set<string>::iterator it = Report.begin(); it != Report.end(); it++)
	{
		cout << i++ << ") " << *it << endl;
	}
	if (Report.empty())
	{
		cout << "Words not found." << endl;
	}
	system("pause");
}

void Application::Exit()
{
	ofstream file("System/db.dat");
	if (!file.fail())
	{
		for (auto it = m.begin(); it != m.end(); it++)
		{
			file << it->first << " " << it->second << endl;
		}
		cout << "Save successfull!" << endl;
	}
	else cout << "Error opening files!" << endl;
	file.close();
	exit(0);
}

void Application::ExitNoSave()
{
	exit(0);
}

void Application::Run()
{
	
	menu->Run();
}
