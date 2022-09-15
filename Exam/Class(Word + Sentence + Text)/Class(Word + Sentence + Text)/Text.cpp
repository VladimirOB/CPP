#include "Text.h"
#include "pch.h"

Text::Text()
{
	string str = { "hello world! Oh hi. How are you?" };
	string temp;
	string temp2;
	str = std::regex_replace(str, std::regex("[.!?]"), ".");
	stringstream ss(str);
	size_t found;
	while (!ss.eof())
	{
		ss >> temp;
		found = temp.find(".");
		if (found != string::npos)
		{
			temp2 += temp;
			Sentence.push_back(temp2);
			temp2.clear();
		}
		else
		{
			temp += " ";
			temp2 += temp;
		}
		temp.clear();
	}
}

Text::Text(string str)
{
	string temp;
	string temp2;
	str = std::regex_replace(str, std::regex("[.!?]"), ".");
	stringstream ss(str);
	size_t found;
	while (!ss.eof())
	{
		ss >> temp;
		found = temp.find(".");
		if (found != string::npos)
		{
			temp2 += temp;
			Sentence.push_back(temp2);
			temp2.clear();
		}
		else
		{
			temp += " ";
			temp2 += temp;
		}
		temp.clear();
	}
}

Text::Text(const Text& source, Text& second)
{
	second = source;
}

void Text::operator = (const string& source)
{

}

ostream& operator << (ostream& os, Text& str)
{

	for (size_t i = 0; i < str.Sentence.size(); i++)
	{
		os << str.Sentence[i] << endl;
	}
	return os;
}

int Text::Length()
{
	int cnt = 0;
	for (size_t i = 0; i < Sentence.size(); i++)
		cnt++;

	return cnt;
}

void Text::Set(string str)
{
	Sentence.clear();
	string temp;
	string temp2;
	str = std::regex_replace(str, std::regex("[.!?]"), ".");
	stringstream ss(str);
	size_t found;
	while (!ss.eof())
	{
		ss >> temp;
		found = temp.find(".");
		if (found != string::npos)
		{
			temp2 += temp;
			Sentence.push_back(temp2);
			temp2.clear();
		}
		else
		{
			temp += " ";
			temp2 += temp;
		}
		temp.clear();
	}
}

//char* Text::get()
//{
//	string buffer;
//	for (size_t i = 0; i < Sentence.size(); i++)
//	{
//		
//	}
//}

void Text::Add(string word)
{
	word = std::regex_replace(word, std::regex("[.!?]"), ".");
	stringstream ss(word);
	string temp;
	string temp2;
	size_t found;
	while (!ss.eof())
	{
		ss >> temp;
		found = temp.find(".");
		if (found != string::npos)
		{
			temp2 += temp;
			Sentence.push_back(temp2);
			temp2.clear();
			break;
		}
		else
		{
			temp += " ";
			temp2 += temp;
		}
		temp.clear();
	}
}

bool Text::Remove(unsigned index)
{
	if (index < Sentence.size())
	{
		int cnt = 0;
		for (auto it = Sentence.begin(); it != Sentence.end(); it++)
		{
			if (cnt == index)
			{
				Sentence.erase(it);
				return true;
			}
			cnt++;
		}
	}
	else
	{
		cout << "Wrong index!" << endl;
		return false;
	}
}

void Text::operator += (string word)
{
	Add(word);
}

string& Text::operator[] (int pos)
{
	if (pos < Sentence.size())
	{
		int cnt = 0;
		for (auto it = Sentence.begin(); it != Sentence.end(); it++)
		{
			if (cnt == pos)
			{
				return *it;
			}
			cnt++;
		}
	}
	else
	{
		string buff;
		cout << "Error pos!" << endl;
		return buff;
	}
}

bool Text::Load(const char* filename)
{
	string str;
	string buffer;
	ifstream file(filename, ios::in);
	if (!file.fail())
	{
		while (!file.eof())
		{
			file >> buffer;
			buffer += " ";
			str += buffer;
		}
	}
	else
	{
		cout << "Error opening file!" << endl;
		return false;
	}
	file.close();

	Sentence.clear();
	string temp;
	string temp2;
	str = std::regex_replace(str, std::regex("[.!?]"), ".");
	stringstream ss(str);
	size_t found;
	while (!ss.eof())
	{
		ss >> temp;
		found = temp.find(".");
		if (found != string::npos)
		{
			temp2 += temp;
			Sentence.push_back(temp2);
			temp2.clear();
		}
		else
		{
			temp += " ";
			temp2 += temp;
		}
		temp.clear();
	}
	return true;
}

bool Text::Save(const char* filename)
{
	ofstream file(filename, ios::out);
	if (!file.fail())
	{
		for (size_t i = 0; i < Sentence.size(); i++)
		{
			file << Sentence[i] << endl;
		}
		file.close();
		return true;
	}
	else
	{
		cout << "Error opening file!" << endl;
		file.close();
		return false;
	}
}

bool Text::saveWords(const char* filename)
{
	string str;
	string temp;
	set<string> m;
	for (size_t i = 0; i < Sentence.size(); i++)
	{
		str += Sentence[i];
		str += " ";
	}
	str = std::regex_replace(str, std::regex("[.!?]"), "");
	stringstream ss(str);
	while (!ss.eof())
	{
		ss >> temp;
		m.insert(temp);
	}
	//sort(m.begin(), m.end());

	ofstream file(filename, ios::out);
	if (!file.fail())
	{
		for (auto it = m.begin(); it != m.end(); it++)
		{
			file << *it << endl;
		}
		file.close();
		return true;
	}
	else
	{
		cout << "Error opening file!" << endl;
		file.close();
		return false;
	}
}