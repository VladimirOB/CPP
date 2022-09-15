#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <list>
using namespace std;

// ����� ������� �����
class Vertex
{
	friend class Graph;
	friend class Link;

	//�������� �������
	string title;

	//����� �������
	unsigned int id;

	// ��� ������� �����
	int weight;

	//����, ���������� � ������ �������
	list<Link*> links;

	//�������� ����� ������ � ������ �������
	bool RemoveLink(unsigned int linkId);

	//����� �������, ����� ��� ������ ���������� ������(�������� � �������)
	int label;

	//���. ���������� �� ������� � ���. ��������
	unsigned int distance;

	// ���������� ������� ��� �������� �� ����������� ����
	Vertex* prev;

public:
	Vertex(unsigned int id, const string title, int weight);
	~Vertex();

	//������� ���
	string GetTitle();

	//������� ����
	unsigned int GetId();

	//������� ���-�� ����
	unsigned int GetLinksCount();

	void Print();
};

