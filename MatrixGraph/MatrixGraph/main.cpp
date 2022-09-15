#include "pch.h"
#include "Graph.h"
/*1. ��� ������ Graph �������� ��������� ������:
- RenameVertex(string oldName, string newName) - �������������� �������
- PrintLinks(string title) - ������� �������� � ���� ��������� � �������� ������
- Print() - ������� ��� ������� � ����� ����� ����
- DeleteLink(string vertex1, string vertex2) - �������� ����� ����� ���������
- DeleteVertex(string title) - �������� ������� �� ����� �������
- MinWeight() - ���������� ������������ ���� ����� ����
- VertexConnection(string vertex1, string vertex2) - ��������� ������� �� �������*/

/*2. ��� ���������� ������ Graph �������� ��������� ������:
- ����������� �����������
- operator =
- operator == (��� ��������� ���� ������)
- Save(string filename) - ���������� ����� � ����
- Load(string filename) - �������� ����� �� �����
- GetRoute(string from, string to) - ���������� ����������� ���� �� ����� �� ��������� ���������*/

int main(void)
{
	Graph graph(100);

	graph.AddVertex("One");
	graph.AddVertex("Two");
	graph.AddVertex("Three");
	graph.AddVertex("Four");
	graph.AddVertex("Five");
	graph.AddVertex("Six");

	graph.AddLink("One", "Two", 7);
	graph.AddLink("One", "Three", 9);
	graph.AddLink("One", "Six", 14);
	graph.AddLink("Two", "Three", 10);
	graph.AddLink("Three", "Six", 2);
	graph.AddLink("Three", "Four", 11);
	graph.AddLink("Four", "Five", 6);
	graph.AddLink("Six", "Five", 6);
	graph.GetRouteDijkstra("One", "Six");

	//graph.AddVertex("A");
	//graph.AddVertex("B");
	//graph.AddVertex("C");
	//graph.AddVertex("D");
	//graph.AddVertex("E");

	//graph.AddLink("A", "B", 1);
	//graph.AddLink("A", "C", 2);
	//graph.AddLink("B", "C", 1.5);
	//graph.AddLink("C", "D", 3);
	//graph.AddLink("C", "E", 4.5);
	//graph.AddLink("E", "D", 3.1415926535897932383626433832);

	////graph.Print();
	//graph.GetRoute("A", "D");

	//graph.GetRoute("One", "Four");

}