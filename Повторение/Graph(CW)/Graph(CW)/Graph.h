#pragma once
#include "Vertex.h"
#include "Link.h"
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Graph
{
	// название графа
	string title;

	// номер следующей вершины, которая будет создана.
	unsigned int vertexId = 0;

	// кол-во вершин 
	unsigned int vertexCount = 0;

	// номер след. ребра, который будет создан
	unsigned int linkId = 0;

	// кол-во рёбер
	unsigned int linkCount = 0;

	// указатель на список вершин графа
	unordered_map<string, Vertex*>* vertices;

public:

	// Результирующий список вершин
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

