#include "Sentence.h"
#include "pch.h"

Sentence::Sentence()
{
	string str = {"		hello	 world"};
	string temp;
	str = std::regex_replace(str, std::regex("[ \t]"), " ");
	stringstream ss(str);
	while(!ss.eof())
	{
		ss >> temp;
		if (temp != "")
		Word.push_back(temp);
		temp.clear();
	}
}

Sentence::Sentence(string str)
{
	string temp;
	str = std::regex_replace(str, std::regex("[ \t]"), " ");
	stringstream ss(str);
	while (!ss.eof())
	{
		ss >> temp;
		if (temp != "")
		Word.push_back(temp);
		temp.clear();
	}
}

Sentence::Sentence(const Sentence& source, Sentence& second)
{
	second = source;
}

void Sentence::operator = (const string& source)
{
	string temp;
	stringstream ss(source);
	while (!ss.eof())
	{
		ss >> temp;
		if (temp != "")
		Word.push_back(temp);
		temp.clear();
	}
}

Sentence::~Sentence()
{

}

void Sentence::Print()
{
	for (size_t i = 0; i < Word.size(); i++)
	{
		cout << Word[i] <<  " ";
	}
	cout << endl;
}

int Sentence::Length()
{
	int cnt = 0;
	for (size_t i = 0; i < Word.size(); i++)
	cnt++;
	
	return cnt;

}

void Sentence::set(string str)
{
	Word.clear();
	string temp;
	str = std::regex_replace(str, std::regex("[ \t]"), " ");
	stringstream ss(str);
	while (!ss.eof())
	{
		ss >> temp;
		if(temp != "")
		Word.push_back(temp);
		temp.clear();
	}
}

void Sentence::Add(string word)
{
	word = std::regex_replace(word, std::regex("[ \t]"), " ");
	stringstream ss(word);
	string temp;
	ss >> temp;
	Word.push_back(temp);
}

bool Sentence::Remove(unsigned index)
{
	if (index < Word.size())
	{
		int cnt = 0;
		for (auto it = Word.begin(); it != Word.end(); it++)
		{
			if (cnt == index)
			{
				Word.erase(it);
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

void Sentence::operator += (string word)
{
	Add(word);
}

string& Sentence::operator[] (int pos)
{
	if (pos < Word.size())
	{
		int cnt = 0;
		for (auto it = Word.begin(); it != Word.end(); it++)
		{
			if (cnt == pos)
			{
				return *it;
			}
			cnt++;
		}
	}
}