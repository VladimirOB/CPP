#include "Link.h"

Link::Link(unsigned int id, const string title, int weight, Vertex* from, Vertex* to)
{
	this->id = id;
	this->weight = weight;
	this->from = from;
	this->to = to;
	this->title = title;
}

Link::~Link()
{
	//������� ��������� �� ��������� ����� � ������� ��������
	from->RemoveLink(id);
	to->RemoveLink(id);
}

//�������� ����� �����
unsigned int Link::GetId()
{
	return this->id;
}

//�������� ��� �����
string Link::GetTitle()
{
	return this->title;
}

void Link::Print()
{
	cout << "Link: " << title << ", From: " << from->GetTitle() << ", To: " << to->GetTitle() << endl;
}