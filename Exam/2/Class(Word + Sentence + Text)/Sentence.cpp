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
		Sent.push_back(temp);
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
		Sent.push_back(temp);
		temp.clear();
	}
}

Sentence::Sentence(const Sentence& source, Sentence& second)
{
	second = source;
}

Sentence Sentence::operator= (const Sentence& source)
{
	Sent.clear();
	/*string temp;
	stringstream ss(source);
	while (!ss.eof())
	{
		ss >> temp;
		if (temp != "")
		Sent.push_back(temp);
		temp.clear();
	}*/
	for (auto i = source.Sent.begin(); i != source.Sent.end(); i++)
	{
		Sent.push_back(*i);
	}
	return *this;
}

Sentence::~Sentence()
{

}

void Sentence::Print()
{
	for (size_t i = 0; i < Sent.size(); i++)
	{
		cout << Sent[i] <<  " ";
	}
	cout << endl;
}

ostream& operator<< (ostream& os, Sentence& str)
{
	for (int i = 0; i < str.Sent.size(); i++)
	{
		os << str[i] << " ";
	}
	return os;
}

int Sentence::Length()
{
	int cnt = 0;
	for (size_t i = 0; i < Sent.size(); i++)
	cnt++;
	return cnt;
}

void Sentence::Set(string str)
{
	Sent.clear();
	string temp;
	str = std::regex_replace(str, std::regex("[ \t]"), " ");
	stringstream ss(str);
	while (!ss.eof())
	{
		ss >> temp;
		if(temp != "")
		Sent.push_back(temp);
		temp.clear();
	}
}

string Sentence::Get()
{
	string temp;
	string buffer;
	for (auto it = Sent.begin(); it != Sent.end(); it++)
	{
		temp = it->Get();
		buffer += temp;
		buffer += " ";
	}
	return buffer;
}

void Sentence::Add(Word word)
{
	Sent.push_back(word);
}

void Sentence::operator += (Word word)
{
	Add(word);
}

bool Sentence::Remove(unsigned index)
{
	if (index < Sent.size())
	{
		int cnt = 0;
		for (auto it = Sent.begin(); it != Sent.end(); it++)
		{
			if (cnt == index)
			{
				Sent.erase(it);
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



Word& Sentence::operator[] (int pos)
{
	if (pos < Sent.size())
	{
		int cnt = 0;
		for (auto it = Sent.begin(); it != Sent.end(); it++)
		{
			if (cnt == pos)
			{
				return *it;
			}
			cnt++;
		}
	}
}