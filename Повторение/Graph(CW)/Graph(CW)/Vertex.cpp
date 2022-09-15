#include "Vertex.h"
#include "Link.h"
#include <iostream>

using namespace std;

Vertex::Vertex(unsigned int id, const string title, int weight)
{
	this->id = id;
	this->weight = weight;
	this->title = title;
}

Vertex::~Vertex()
{
	//������� ���� ���� �������� � ��������� �������
	list<Link*>::iterator pos = links.begin();
	while (pos != links.end())
	{
		//��������� �� ������� �����
		Link* currentLink = *(pos);

		pos++;

		//�������� �������� �����
		delete currentLink;
	}

	// �������� ������ ���� ���� �������
	//links.clear();
}

//�������� ����� �� id � ������� ��� �������� �� � �������� �������
bool Vertex::RemoveLink(unsigned int linkId)
{
	list<Link*>::iterator pos;
	for (pos = links.begin(); pos != links.end(); pos++)
	{
		if ((*pos)->id == linkId)
		{
			links.erase(pos);
			return true;
		}
	}
	return false;
}

// ������� ���������� ����, �������� � �������
unsigned int Vertex::GetLinksCount()
{
	return links.size();
}

// ���������� Id �������
unsigned int Vertex::GetId()
{
	return this->id;
}

string Vertex::GetTitle()
{
	return title;
}

void Vertex::Print()
{
	cout << "Vertex: " << title << endl;

	// ��������� ��� �������� ���� � ������� � ��� ����� �����
	list<Link*>::iterator pos;
	for (pos = links.begin(); pos != links.end(); pos++)
	{
		(*pos)->Print();
	}
	cout << endl;
}