#include "Graph.h"
#include <list>

using namespace std;

Graph::Graph(const string _title)
{
	title = _title;

	//��������� ������ ��� ������� ������
	vertices = new unordered_map<string, Vertex*>();
}

Graph::~Graph()
{
	// ������� ������ � �������� ������ �������
	unordered_map<string, Vertex*>::iterator pos = vertices->begin();
	while (pos != vertices->end())
	{
		//��������� �� ������� �������
		Vertex* currentVertex = pos->second;

		//����������� ��������� �� ����. �������
		pos++;

		//������� ������� �������
		delete currentVertex;
	}
	//�������� ������
	delete vertices;
}

// ����� ������� �� ��������
Vertex* Graph::FindVertex(const string _title)
{
	auto pos = vertices->find(_title);
	if (pos != vertices->end())
		return pos->second;

		return nullptr;
}

// ���������� �������
unsigned int Graph::AddVertex(const string title, unsigned int weight)
{
	if (FindVertex(title) == 0)
	{
		Vertex* vertex = new Vertex(vertexId++, title, weight);
		if (vertex != nullptr)
		{
			//���������� ������� � ������ ������
			vertices->insert(make_pair(title, vertex));

			//��������� ���-�� ������ �� 1
			vertexCount++;

			//���������� Id ��������� ������
			return vertexId - 1;
		}
	}
	return -1;
}

unsigned int Graph::AddLink(const string from, const string to, const string title, unsigned int weight)
{
	//�������� ��������� �� ������� �� �� ���������
	Vertex* vertexFrom = FindVertex(from);
	Vertex* vertexTo = FindVertex(to);

	if (vertexFrom != nullptr && vertexTo != nullptr)
	{
		//�������� ������� �����
		Link* link = new Link(linkId++, title, weight, vertexFrom, vertexTo);
		if (link != nullptr)
		{
			//���������� ���������� �� ��������� ����� � ������ ���� ������ �������
			vertexFrom->links.push_back(link);
			vertexTo->links.push_back(link);
			//����. ���-�� ���� �� 1
			linkCount++;

			//���������� Id ���������� �����
			return linkId - 1;
		}
	}
	return -1;
}

//�������� ������� �� id
bool Graph::RemoveVertex(unsigned int vertexId)
{
	unordered_map<string, Vertex*>::iterator pos;
	for (pos = vertices->begin(); pos != vertices->end(); pos ++)
	{
		Vertex* currentVertex = pos->second;

		//���� ������� ������ �������
		if (currentVertex->id == vertexId)
		{
			//�� ������ ���-�� ���� ����� ������� ���-�� ���� ���������� � ��������� �������
			linkCount -= currentVertex->GetLinksCount();

			//��������� ���-�� ������ �� 1
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
	
	//��������� ������ ������ � ���������� ��
	unordered_map<string, Vertex*>::iterator pos = vertices->begin();
	while (pos != vertices->end())
	{
		pos->second->Print();
		pos++;
	}
}

// �������� ���. ��� ������������� �����
void Graph::GetRoute(string from, string to)
{
	//�������� ����. ���������
	FoundVertices.clear();

	//������ ������� ������������� ������, �������������� �� ������� ��������
	list<Vertex*> oldFront;

	//������ ������� ���������� ������, �������������� �� ����. ��������
	list<Vertex*> newFront;

	//���������� ����� (����� ��������)
	int t = 0;

	Vertex* vertexFrom = FindVertex(from);
	Vertex* vertexTo = FindVertex(to);

	//���� ������� ����
	if (vertexFrom != nullptr && vertexTo != nullptr)
	{
		//�������� ��� ������� ��� ������������
		for (auto it = vertices->begin(); it != vertices->end(); it++)
		{
			it->second->label = -1;
		}

		//�������� ��������� ��� ����������
		vertexFrom->label = 0;
		oldFront.push_back(vertexFrom);

		//���� �� ����������� ���������� ������� � ��������������� ��������
		while (oldFront.size() > 0)
		{
			//��������� ��� ��������� ������� � �����. ��������
			for (Vertex* vertex : oldFront)
			{
				//��� ������� ������� ��������� ��������� �������� ������
				for (Link* link: vertex->links)
				{
					Vertex* current = FindVertex(link->to->title);

					//���� ������� ������� ��������� �������
					if (current == vertexTo)
					{
						current->label = t + 1;
						Vertex* reverse = current;

						//���� �� �������� ��� �������� �����
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

						return; // �����
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

// �������� ������� ��� ���������� ������
void Graph::GetRouteDijkstra(string from, string to)
{
	//�������� ����. ���������
	FoundVertices.clear();

	Vertex* vertexFrom = FindVertex(from);
	Vertex* vertexTo = FindVertex(to);

	// ���� ��� ������� �������
	if (vertexFrom != nullptr && vertexTo != nullptr)
	{
		// ��������� ��������� ������ � �������� �� ��� ������������, ������� ���������� �� ������ - �������������
		for (auto vertex = vertices->begin(); vertex != vertices->end(); vertex++)
		{
			vertex->second->label = 0;
			vertex->second->distance = 1000000;
			vertex->second->prev = nullptr;
		}

		//�������� ��������� ������� ��� ����������, ���������� �� �� ����� 0
		vertexFrom->distance = 0;

		while (true)
		{
			// ������� � ����������� ����������� �� �������
			Vertex* minVertex = nullptr;

			//��������� ��������� �������� ������ ��� ������� � ���. �����������
			for (auto vertex = vertices->begin(); vertex != vertices->end(); vertex++)
			{
				if (minVertex == nullptr && vertex->second->label == 0) minVertex = vertex->second;
				if(minVertex != nullptr && vertex->second->label == 0 && minVertex->distance > vertex->second->distance) minVertex = vertex->second;
			}

			//���� ��������� �� ������� � ����������� ����������� ����� ������������� - ������� ���
			if (minVertex == nullptr || minVertex->distance == 1000000)
				return; // ������� ���

			//���� ������� � ��� ����������� �������� �������
			if (minVertex == vertexTo)
			{
				// ��������� �� �������� � �������� ����������� � ��������� �� �������� � ������ ���������
				Vertex* v = minVertex;
				while (v != nullptr)
				{
					FoundVertices.push_back(v);
					v = v->prev;
				}

				//������
				FoundVertices.reverse();

				cout << "Way found!" << endl;
				for (auto it = FoundVertices.begin(); it != FoundVertices.end(); it++)
				{
					cout << (*it)->title << " ";
				}

				return;
			}

			minVertex->label = 1;

			// ��� ����������� ������� ��������� �������� �������� ������
			for (Link* link : minVertex->links)
			{
				Vertex* currentVertex = (link->from == minVertex) ? link->to : link->from;

				// ���� �������� ������� �� �������� � ���������� ��������� �� �� ������ ��������� �� ����������� ������� + ��� ���������� �����
				if (currentVertex->label == 0 && currentVertex->distance > (minVertex->distance + link->weight))
				{
					// �������� ��������� � �������� �������
					currentVertex->distance = minVertex->distance + link->weight;

					// ������� ����������� ������� ��� ���������� �� ���� � ��������
					currentVertex->prev = minVertex;
				}
			}
		}
	}
}