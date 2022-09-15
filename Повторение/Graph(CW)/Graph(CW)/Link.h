#pragma once
#include "Vertex.h"

// класс ребра графа
class Link
{
	friend class Graph;
	friend class Vertex;

	// указатель на вершину, из которой идёт ребро
	Vertex* from;

	//указатель на вершину, в которую идёт ребро
	Vertex* to;

	//название ребра 
	string title;

	//номер ребра
	unsigned int id;

	// вес 
	int weight;
public:
	Link(unsigned int id, const string title, int weight, Vertex* from, Vertex* to);
	~Link();

	//получить номер ребра
	unsigned int GetId();

	//получить имя ребра
	string GetTitle();
	void Print();

};

