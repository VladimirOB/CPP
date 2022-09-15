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
	//перебор всех рёбер входящих в удаляемую вершину
	list<Link*>::iterator pos = links.begin();
	while (pos != links.end())
	{
		//указатель на текущее ребро
		Link* currentLink = *(pos);

		pos++;

		//удаление текущего ребра
		delete currentLink;
	}

	// очистить список всех рёбер вершины
	//links.clear();
}

//удаление ребра по id у вершины без удаления их в соседней вершине
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

// вернуть количество рёбер, входящих в вершину
unsigned int Vertex::GetLinksCount()
{
	return links.size();
}

// возвратить Id вершины
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

	// перебрать все входящие рёбра и вызвать у них метод принт
	list<Link*>::iterator pos;
	for (pos = links.begin(); pos != links.end(); pos++)
	{
		(*pos)->Print();
	}
	cout << endl;
}