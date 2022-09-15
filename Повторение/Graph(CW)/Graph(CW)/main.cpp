#include <iostream>
using namespace std;
#include "Graph.h"

void main()
{
	Graph gr("TEST");

	gr.AddVertex("A", 150);
	gr.AddVertex("B", 250);
	gr.AddVertex("C", 350);
	gr.AddVertex("D", 450);
	gr.AddLink("A", "B", "link#1", 8);
	gr.AddLink("B", "C", "link#1", 16);
	gr.AddLink("C", "D", "link#1", 32);
	gr.GetRouteDijkstra("A", "D");

//	gr.Print();
}