#pragma once
#include "pch.h"

using namespace std;

class Graph
{
	size_t MaxVertexCount;
	size_t CurrentVertexCount;
	size_t DeleteIndexCount;
	double** links;
	unsigned* buffer_index;
	map<string, unsigned>* vertices;
	map<unsigned, string>* rev_vertices;
	unordered_map <string, int>* Labels;
	list<string> Links;
	list<string> FoundVertices;
public:

	Graph();
	Graph(size_t max_vertex_count);
	~Graph();
	Graph(const Graph& source);
	void operator= (const Graph& source);
	bool AddVertex(string title);
	bool AddLink(string title1, string title2, double weight);
	bool RenameVertex(string oldName, string newName);
	bool DeleteLink(string vertex1, string vertex2);
	bool DeleteVertex(string title);
	void MinWeight();
	void GetRoute(string vertex1, string vertex2);
	void FindLinks(const string title);
	unordered_map<string, int>::iterator FindVertex(const string title);
	void FindWay(unordered_map<string, int>::iterator rev);
	void GetRouteDijkstra(string from, string to);
	void PrintVertices();
	void PrintLinks(string title);
	void Print();
	bool operator== (const Graph& source);
	bool Save(string filename);
	bool Load(string filename);
};

