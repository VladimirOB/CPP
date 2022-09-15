#pragma once
#include "Vertex.h"
#include "Link.h"
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Graph
{
	// �������� �����
	string title;

	// ����� ��������� �������, ������� ����� �������.
	unsigned int vertexId = 0;

	// ���-�� ������ 
	unsigned int vertexCount = 0;

	// ����� ����. �����, ������� ����� ������
	unsigned int linkId = 0;

	// ���-�� ����
	unsigned int linkCount = 0;

	// ��������� �� ������ ������ �����
	unordered_map<string, Vertex*>* vertices;

public:

	// �������������� ������ ������
	list<Vertex*> FoundVertices;

	Graph(const string _title);
	~Graph();
	Vertex* FindVertex(const string title);
	unsigned int AddVertex(const string title, unsigned int weight);
	unsigned int AddLink(const string from, const string to, const string title, unsigned int weight);
	bool RemoveVertex(unsigned int vertexId);
	void Print();
	void GetRoute(string from, string to);
	void GetRouteDijkstra(string from, string to);
};

