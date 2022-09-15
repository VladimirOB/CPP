#include "Graph.h"
#include <list>

using namespace std;

Graph::Graph(const string _title)
{
	title = _title;

	//выделение памяти под словарь вершин
	vertices = new unordered_map<string, Vertex*>();
}

Graph::~Graph()
{
	// перебор списка и удаление каждой вершины
	unordered_map<string, Vertex*>::iterator pos = vertices->begin();
	while (pos != vertices->end())
	{
		//указатель на текущую вершину
		Vertex* currentVertex = pos->second;

		//переместить указатель на след. вершину
		pos++;

		//удалить текущую вершину
		delete currentVertex;
	}
	//удаление списка
	delete vertices;
}

// поиск вершины по названию
Vertex* Graph::FindVertex(const string _title)
{
	auto pos = vertices->find(_title);
	if (pos != vertices->end())
		return pos->second;

		return nullptr;
}

// добавление вершины
unsigned int Graph::AddVertex(const string title, unsigned int weight)
{
	if (FindVertex(title) == 0)
	{
		Vertex* vertex = new Vertex(vertexId++, title, weight);
		if (vertex != nullptr)
		{
			//добавление вершины в список вершин
			vertices->insert(make_pair(title, vertex));

			//увеличить кол-во вершин на 1
			vertexCount++;

			//возвратить Id созданной вершин
			return vertexId - 1;
		}
	}
	return -1;
}

unsigned int Graph::AddLink(const string from, const string to, const string title, unsigned int weight)
{
	//получить указатели на вершины по их названиям
	Vertex* vertexFrom = FindVertex(from);
	Vertex* vertexTo = FindVertex(to);

	if (vertexFrom != nullptr && vertexTo != nullptr)
	{
		//создание объекта ребра
		Link* link = new Link(linkId++, title, weight, vertexFrom, vertexTo);
		if (link != nullptr)
		{
			//добавление указателей на созданное ребро в списки рёбер каждой вершины
			vertexFrom->links.push_back(link);
			vertexTo->links.push_back(link);
			//увел. кол-во рёбер на 1
			linkCount++;

			//возвратить Id созданного ребра
			return linkId - 1;
		}
	}
	return -1;
}

//удаление вершины по id
bool Graph::RemoveVertex(unsigned int vertexId)
{
	unordered_map<string, Vertex*>::iterator pos;
	for (pos = vertices->begin(); pos != vertices->end(); pos ++)
	{
		Vertex* currentVertex = pos->second;

		//если найдена нужная вершина
		if (currentVertex->id == vertexId)
		{
			//из общего кол-ва рёбер графа вычесть кол-во рёбер подходящее к удаляемой вершине
			linkCount -= currentVertex->GetLinksCount();

			//уменьшить кол-во вершин на 1
			vertexCount--;

			delete currentVertex;

			vertices->erase(pos);

			return true;
		}
	}
	return false;
}

void Graph::Print()
{
	cout << "Graph: " << title << endl;
	cout << "Vertices: " << vertexCount << "Links: " << linkCount << endl << endl;
	
	//перебрать список вершин и напечатать их
	unordered_map<string, Vertex*>::iterator pos = vertices->begin();
	while (pos != vertices->end())
	{
		pos->second->Print();
		pos++;
	}
}

// волновой алг. для невзвешенного графа
void Graph::GetRoute(string from, string to)
{
	//очистить пред. результат
	FoundVertices.clear();

	//Список текущих просмотренных вершин, обрабатываемых на текущей итерации
	list<Vertex*> oldFront;

	//Список текущих помеченных вершин, обрабатываемых на след. итерации
	list<Vertex*> newFront;

	//Дискретное время (номер итерации)
	int t = 0;

	Vertex* vertexFrom = FindVertex(from);
	Vertex* vertexTo = FindVertex(to);

	//если вершины есть
	if (vertexFrom != nullptr && vertexTo != nullptr)
	{
		//Пометить все вершины как непосещённые
		for (auto it = vertices->begin(); it != vertices->end(); it++)
		{
			it->second->label = -1;
		}

		//Пометить начальную как посещённую
		vertexFrom->label = 0;
		oldFront.push_back(vertexFrom);

		//пока не закончились помеченные вершины с необработанными соседями
		while (oldFront.size() > 0)
		{
			//Перебрать все помеченые вершины с необр. соседями
			for (Vertex* vertex : oldFront)
			{
				//для текущей вершины перебрать множество соседних вершин
				for (Link* link: vertex->links)
				{
					Vertex* current = FindVertex(link->to->title);

					//если текущая вершина оказалась искомой
					if (current == vertexTo)
					{
						current->label = t + 1;
						Vertex* reverse = current;

						//цикл по вершинам для возврата назад
						while (reverse->label > 0)
						{
							FoundVertices.push_back(reverse);

							for (Link* link : reverse->links)
							{
								if (link->from->label == reverse->label - 1)
								{
									reverse = link->from;
									break;
								}
							}
						}
						FoundVertices.push_back(vertexFrom);
						FoundVertices.reverse();
						cout << "Way found!" << endl;
						for (auto it = FoundVertices.begin(); it != FoundVertices.end(); it++)
						{
							cout << (*it)->title << " ";
						}

						return; // конец
					}

					if (current->label == -1)
					{
						current->label = t + 1;
						newFront.push_back(current);
					}
				}
			}

			oldFront.clear();
			copy(newFront.begin(), newFront.end(), back_inserter(oldFront));
			newFront.clear();
			t++;

		}
		cout << "Way not found!" << endl;
	}
}

// алгоритм Дейстры для взвешенных графов
void Graph::GetRouteDijkstra(string from, string to)
{
	//очистить пред. результат
	FoundVertices.clear();

	Vertex* vertexFrom = FindVertex(from);
	Vertex* vertexTo = FindVertex(to);

	// Если обе вершины нашлись
	if (vertexFrom != nullptr && vertexTo != nullptr)
	{
		// Перебрать множество вершин и пометить их как непосещённые, текущее расстояние до вершмн - бесконечность
		for (auto vertex = vertices->begin(); vertex != vertices->end(); vertex++)
		{
			vertex->second->label = 0;
			vertex->second->distance = 1000000;
			vertex->second->prev = nullptr;
		}

		//пометить стартовую вершину как посещённую, расстояние до неё равно 0
		vertexFrom->distance = 0;

		while (true)
		{
			// Вершина с минимальный расстоянием от текущей
			Vertex* minVertex = nullptr;

			//перебрать множество соседних вершин для вершины с мин. расстоянием
			for (auto vertex = vertices->begin(); vertex != vertices->end(); vertex++)
			{
				if (minVertex == nullptr && vertex->second->label == 0) minVertex = vertex->second;
				if(minVertex != nullptr && vertex->second->label == 0 && minVertex->distance > vertex->second->distance) minVertex = vertex->second;
			}

			//Если дистанция до вершины с минимальным расстоянием равна бесконечности - решения нет
			if (minVertex == nullptr || minVertex->distance == 1000000)
				return; // решения нет

			//Если вершина с мин расстоянием является искомой
			if (minVertex == vertexTo)
			{
				// Двигаться по вершинам в обратном направлении и добавлять их названия в массив результов
				Vertex* v = minVertex;
				while (v != nullptr)
				{
					FoundVertices.push_back(v);
					v = v->prev;
				}

				//реверс
				FoundVertices.reverse();

				cout << "Way found!" << endl;
				for (auto it = FoundVertices.begin(); it != FoundVertices.end(); it++)
				{
					cout << (*it)->title << " ";
				}

				return;
			}

			minVertex->label = 1;

			// для минимальной вершины перебрать можество соседних вершин
			for (Link* link : minVertex->links)
			{
				Vertex* currentVertex = (link->from == minVertex) ? link->to : link->from;

				// Если соседняя вершина не посещена и отмеченная дистанция до неё больше дистанции до минимальной вершины + вес связующего ребра
				if (currentVertex->label == 0 && currentVertex->distance > (minVertex->distance + link->weight))
				{
					// Поменять дистанцию к соседней вершине
					currentVertex->distance = minVertex->distance + link->weight;

					// Указать минимальную вершину как предыдущую на пути к соседней
					currentVertex->prev = minVertex;
				}
			}
		}
	}
}