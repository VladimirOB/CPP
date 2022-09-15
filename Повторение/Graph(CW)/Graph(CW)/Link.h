#pragma once
#include "Vertex.h"

// ����� ����� �����
class Link
{
	friend class Graph;
	friend class Vertex;

	// ��������� �� �������, �� ������� ��� �����
	Vertex* from;

	//��������� �� �������, � ������� ��� �����
	Vertex* to;

	//�������� ����� 
	string title;

	//����� �����
	unsigned int id;

	// ��� 
	int weight;
public:
	Link(unsigned int id, const string title, int weight, Vertex* from, Vertex* to);
	~Link();

	//�������� ����� �����
	unsigned int GetId();

	//�������� ��� �����
	string GetTitle();
	void Print();

};

