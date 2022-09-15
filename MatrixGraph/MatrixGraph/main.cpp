#include "pch.h"
#include "Graph.h"
/*1. Для класса Graph добавить следующие методы:
- RenameVertex(string oldName, string newName) - переименование вершины
- PrintLinks(string title) - выводит названия и веса связанных с заданной вершин
- Print() - выводит все вершины и связи между ними
- DeleteLink(string vertex1, string vertex2) - удаление ребра между вершинами
- DeleteVertex(string title) - удаление вершины со всеми связями
- MinWeight() - нахождение минимального веса среди всех
- VertexConnection(string vertex1, string vertex2) - проверить связаны ли вершины*/

/*2. Для матричного класса Graph добавить следующие методы:
- конструктор копирования
- operator =
- operator == (для сравнения двух графов)
- Save(string filename) - сохранение графа в файл
- Load(string filename) - загрузка графа из файла
- GetRoute(string from, string to) - нахождение кратчайшего пути на графе по волновому алгоритму*/

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