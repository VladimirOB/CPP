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
			text.push_back(temp2);
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
			text.push_back(temp2);
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

Text Text::operator= (const string& source)
{
	text.clear();
	string temp;
	stringstream ss(source);
	while (!ss.eof())
	{
		ss >> temp;
		if (temp != "")
			text.push_back(temp);
		temp.clear();
	}
	return *this;
}

ostream& operator << (ostream& os, Text& str)
{

	for (size_t i = 0; i < str.text.size(); i++)
	{
		os << str.text[i] << "." << endl;
	}
	return os;
}

int Text::Length()
{
	int cnt = 0;
	for (size_t i = 0; i < text.size(); i++)
		cnt++;

	return cnt;
}

void Text::Set(string str)
{
	text.clear();
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
			text.push_back(temp2);
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

string Text::Get()
{
	string temp;
	string buffer;
	for (auto it = text.begin(); it != text.end(); it++)
	{
		temp = it->Get();
		buffer += temp;
	}
	return buffer;
}

void Text::Add(Sentence word)
{
	text.push_back(word);
}

bool Text::Remove(unsigned index)
{
	if (index < text.size())
	{
		int cnt = 0;
		for (auto it = text.begin(); it != text.end(); it++)
		{
			if (cnt == index)
			{
				text.erase(it);
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

void Text::operator += (Sentence word)
{
	Add(word);
}

Sentence& Text::operator[] (int pos)
{
	if (pos < text.size())
	{
		int cnt = 0;
		for (auto it = text.begin(); it != text.end(); it++)
		{
			if (cnt == pos)
			{
				return *it;
			}
			cnt++;
		}
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

	text.clear();
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
			text.push_back(temp2);
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
		for (size_t i = 0; i < text.size(); i++)
		{
			file << text[i] << "." <<endl;
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
	for (auto it = text.begin(); it != text.end(); it++)
	{
		str = it->Get();
		str += " ";
	}
	str = std::regex_replace(str, std::regex("[.!?]"), "");
	stringstream ss(str);
	while (!ss.eof())
	{
		ss >> temp;
		m.insert(temp);
	}

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