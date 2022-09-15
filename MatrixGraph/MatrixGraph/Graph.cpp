#include "Graph.h"
#include "pch.h"

using namespace std;

Graph::Graph()
{
	this->MaxVertexCount = 100;
	CurrentVertexCount = 0;
	DeleteIndexCount = 0;
	buffer_index = new unsigned[MaxVertexCount];
	for (size_t i = 0; i < MaxVertexCount; i++)
	{
		buffer_index[i] = -1;
	}
	// ������� ������ ����� (����� �������� ������� � ������� ������� � ��������� �������)
	vertices = new map<string, unsigned>;
	rev_vertices = new map<unsigned, string>;
	Labels = new unordered_map<string, int>;
	// ��������� ������ ������ ����� ���������
	links = new double* [MaxVertexCount];
	for (size_t i = 0; i < MaxVertexCount; i++)
	{
		links[i] = new double[MaxVertexCount];

		// ��� ����� ������ ����� ������ ���������
		for (size_t k = 0; k < MaxVertexCount; k++)
		{
			links[i][k] = 0;
		}
	}
}

Graph::Graph(size_t max_vertex_count)
{
	this->MaxVertexCount = max_vertex_count;
	CurrentVertexCount = 0;
	DeleteIndexCount = 0;
	buffer_index = new unsigned[MaxVertexCount];
	for (size_t i = 0; i < MaxVertexCount; i++)
	{
		buffer_index[i] = -1;
	}
	// ������� ������ ����� (����� �������� ������� � ������� ������� � ��������� �������)
	vertices = new map<string, unsigned>;
	rev_vertices = new map<unsigned, string>;
	Labels = new unordered_map<string, int>;
	// ��������� ������ ������ ����� ���������
	links = new double* [MaxVertexCount];
	for (size_t i = 0; i < MaxVertexCount; i++)
	{
		links[i] = new double[MaxVertexCount];

		// ��� ����� ������ ����� ������ ���������
		for (size_t k = 0; k < MaxVertexCount; k++)
		{
			links[i][k] = 0;
		}
	}
}

Graph::~Graph()
{
	delete vertices;
	delete rev_vertices;
	delete Labels;

	for (size_t i = 0; i < MaxVertexCount; i++)
	{
		delete[] links[i];
	}
	delete[] links;
	delete[] buffer_index;
}

Graph::Graph(const Graph& source)
{
	MaxVertexCount = source.MaxVertexCount;
	CurrentVertexCount = source.CurrentVertexCount;
	DeleteIndexCount = source.DeleteIndexCount;
	vertices = new map<string, unsigned>;
	rev_vertices = new map<unsigned, string>;
	Labels = new unordered_map<string, int>;
	for (auto it = source.vertices->begin(); it != source.vertices->end(); it++)
	{
		vertices->insert(make_pair(it->first, it->second));
		rev_vertices->insert(make_pair(it->second, it->first));
	}
	links = new double* [MaxVertexCount];
	buffer_index = new unsigned[MaxVertexCount];

	for (size_t i = 0; i < MaxVertexCount; i++)
	{
		buffer_index = new unsigned[MaxVertexCount];
		links[i] = new double[MaxVertexCount];
		for (size_t k = 0; k < MaxVertexCount; k++)
		{
			links[i][k] = source.links[i][k];
		}
	}
	for (size_t i = 0; i < MaxVertexCount; i++)
	{
		buffer_index[i] = source.buffer_index[i];
	}
}

void Graph::operator= (const Graph& source) // Labels = new unordered_map<string, int>; ?
{
	MaxVertexCount = source.MaxVertexCount;
	CurrentVertexCount = source.CurrentVertexCount;
	DeleteIndexCount = source.DeleteIndexCount;
	for (size_t i = 0; i < MaxVertexCount; i++)
	{
		delete[] links[i];
	}
	delete[] links;
	delete[] buffer_index;
	vertices->clear();
	rev_vertices->clear();
	for (auto it = source.vertices->begin(); it != source.vertices->end(); it++)
	{
		vertices->insert(make_pair(it->first, it->second));
		rev_vertices->insert(make_pair(it->second, it->first));
	}
	buffer_index = new unsigned[MaxVertexCount];
	links = new double* [MaxVertexCount];
	for (size_t i = 0; i < MaxVertexCount; i++)
	{
		
		links[i] = new double[MaxVertexCount];
		for (size_t k = 0; k < MaxVertexCount; k++)
		{
			links[i][k] = source.links[i][k];
		}
	}
	for (size_t i = 0; i < CurrentVertexCount; i++)
	{
		buffer_index[i] = source.buffer_index[i];
	}
	

	
}

bool Graph::AddVertex(string title)
{
	// ���� ������� � ����� ������ � ����� ����������
	if (vertices->find(title) == vertices->end())
	{
		
		for (size_t i = 0; i < MaxVertexCount; i++)
		{
			if (buffer_index[i] != (-1))
			{
				rev_vertices->insert(make_pair(buffer_index[i], title));
				vertices->insert(make_pair(title, buffer_index[i]));
				Labels->insert(make_pair(title, 0));
				buffer_index[i] = (-1);
				CurrentVertexCount++;
				DeleteIndexCount--;
				return true;
			}
		}
		
		{
			rev_vertices->insert(make_pair(CurrentVertexCount, title));
			vertices->insert(make_pair(title, CurrentVertexCount++));
			Labels->insert(make_pair(title, 0));
			return true;
		}
		
	}
	else
	{
		cout << "The vertex with name: '" << title << "' already exists!!!" << endl;
		return false;
	}
}

bool Graph::RenameVertex(string oldName, string newName)
{
	if (vertices->find(newName) == vertices->end() && vertices->find(oldName) != vertices->end())
	{
		unsigned vertex_index = vertices->find(oldName)->second;
		vertices->erase(oldName);
		vertices->insert(make_pair(newName, vertex_index));
		rev_vertices->find(vertex_index)->second = newName;
		return true;
	}
	else
	{
		cout << "The vertex with name: '" << oldName << "' not found!!! or vertex with name: '" << newName << " already exists! " << endl;
		return false;
	}
}



bool Graph::AddLink(string title1, string title2, double weight)
{
	// ���� ������� � ������ ������� � ����� ����������
	if (vertices->find(title1) == vertices->end() || vertices->find(title2) == vertices->end())
	{
		cout << "Wrong vertex name" << endl;
		return false;
	}

	// �������� �� �������� ������� � ������ � ������� ����
	unsigned vertex1_index = vertices->find(title1)->second;

	// �������� �� �������� ������� � ������ � ������� ����
	unsigned vertex2_index = vertices->find(title2)->second;

	links[vertex1_index][vertex2_index] = weight;
	links[vertex2_index][vertex1_index] = weight;

	return true;
}

bool Graph::DeleteLink(string vertex1, string vertex2)
{
	// ���� ������� � ������ ������� � ����� ����������
	if (vertices->find(vertex1) == vertices->end() || vertices->find(vertex2) == vertices->end())
	{
		cout << "Wrong vertex name" << endl;
		return false;
	}
	// �������� �� �������� ������� � ������ � ������� ����
	unsigned vertex1_index = vertices->find(vertex1)->second;

	// �������� �� �������� ������� � ������ � ������� ����
	unsigned vertex2_index = vertices->find(vertex2)->second;

	links[vertex1_index][vertex2_index] = 0;
	links[vertex2_index][vertex1_index] = 0;

	return true;
}

//bool Graph::DeleteVertex(string title)
//{
//	// ���� ������� � ������ ������� � ����� ����������
//	if (vertices->find(title) == vertices->end())
//	{
//		cout << "Wrong vertex name" << endl;
//		return false;
//	}
//	// �������� �� �������� ������� � ������ � ������� ����
//	unsigned vertex_index = vertices->find(title)->second;
//
//	for (size_t i = 0; i < CurrentVertexCount; i++)
//	{
//		links[vertex_index][i] = 0;
//		links[i][vertex_index] = 0;
//	}
//	for (size_t i = 0; i < CurrentVertexCount; i++)
//	{
//		if (buffer_index[i] == (-1))
//		{
//			buffer_index[i] = vertex_index;
//			break;
//		}
//	}
//	CurrentVertexCount--;
//	DeleteIndexCount++;
//	vertices->erase(title);
//	rev_vertices->erase(vertex_index);
//	
//	return true;
//}


bool Graph::DeleteVertex(string title)
{
	// ���� ������� � ����� ������ � ����� ����������

	if (vertices->find(title) != vertices->end())
	{
		unsigned vertex_index = vertices->find(title)->second;
		vertices->erase(title);
		rev_vertices->erase(vertex_index);
		for (int i1 = 0; i1 < CurrentVertexCount; i1++) {
			for (int i = vertex_index; i < CurrentVertexCount - 1; i++) {
				links[i1][i] = links[i1][i + 1];
			}
		}
		for (int i = 0; i < CurrentVertexCount; i++) {
			links[i][CurrentVertexCount - 1] = 0;
		}
		for (int i1 = vertex_index; i1 < CurrentVertexCount - 1; i1++) {
			for (int i = 0; i < CurrentVertexCount; i++) {
				links[i1][i] = links[i1 + 1][i];
			}
		}
		for (int i = 0; i < CurrentVertexCount; i++) {
			links[CurrentVertexCount - 1][i] = 0;
		}
		CurrentVertexCount--;
		for (int i = 0; i < CurrentVertexCount; i++) {
			for (size_t i1 = 0; i1 < CurrentVertexCount; i1++)
			{
				//cout << links[i][i1] << " ";

			}
			//cout << endl;
		}
		map <string, unsigned>::iterator pos;

		// ���� first - ����
		// ���� second - �������� �������� ����
		for (pos = vertices->begin(); pos != vertices->end(); pos++)
		{
			if (pos->second > vertex_index) {
				pos->second = pos->second--;
			}
		}
		map <unsigned, string>::iterator pos1;
		cout << endl;
		for (pos1 = rev_vertices->begin(); pos1 != rev_vertices->end();)
		{
			if (pos1->first > vertex_index) {
				unsigned index = pos1->first;
				string temp = pos1->second;
				pos1++;
				rev_vertices->erase(index);
				rev_vertices->insert(make_pair(index - 1, temp));
			}
			else {
				pos1++;
			}
		}
		return true;
	}
	else
	{
		cout << "The vertex with name: '" << title << "' already exists!!!" << endl;
		return false;
	}
}

void Graph::MinWeight()
{
	double min=0;
	bool flag = false;
	for (auto it = vertices->begin(); it != vertices->end(); it++)
	{
		unsigned vertex_index = vertices->find(it->first)->second;
		
		for (size_t i = 0; i < CurrentVertexCount; i++)
		{
			if (links[vertex_index][i] != 0 && flag == false)
			{
				min = links[vertex_index][i];
				flag = true;
			}
			if (links[vertex_index][i] != 0)
			{
				if (links[vertex_index][i] < min)
				min = links[vertex_index][i];
			}
		}
	}
	cout << "Min = " << min << endl;
}

/*��� ������� ���� ����� ��������� ������� ������� � ������. �������� ���� �� ������ � �������� ��. 
����� �������� ��� �������, ������� � ���. �� ��������� ���� �������� ��� �������, ������� � ����� ���������, ����� ��� ����������. 
� �. �. �� ��� ���, ���� �� ��������� ���� �� �� ������ ��������� �� ���� ����� �����. ���� �������� ��� ������� �����, �� ���� �������. 
� ��������� ������ ���� ���������, � �� ������ ��� �������� ���� �� ����������� ���������. 
���� ���� �������, �� ����� ����� �� ������� ����� ��������� ����������.*/

void Graph::GetRoute(string from, string to)
{
	setlocale(LC_ALL, "rus");
	FoundVertices.clear(); 	// �������� ���������� ���������

	unordered_map<string, int>::iterator vertexFrom = FindVertex(from);
	unordered_map<string, int>::iterator vertexTo = FindVertex(to);
	
	if (vertexFrom != Labels->end() && vertexTo != Labels->end())
	{
		// ������ ������� ������������� ������, �������������� �� ������� ��������
		list<string> oldFront;
		// ������ ������� ���������� ������, �������������� �� ��������� ��������
		list<string> newFront;
		// ���������� ����� (����� ��������)
		int t = 0;

		// ��������� ��������� ������ � �������� �� ��� ������������
		for (auto it = Labels->begin(); it != Labels->end(); it++)
		{
			it->second = -1;
		}
		// �������� ��������� ������� ��� ���������� � ��������� � ������ ��� ������� ���������
		vertexFrom->second = 0;
		oldFront.push_back(vertexFrom->first);

		// ���� �� ����������� ���������� ������� � ��������������� ��������
		while (oldFront.size() > 0)
		{

			for (list<string>::iterator vertex = oldFront.begin(); vertex != oldFront.end(); vertex++)
			{
				Links.clear();
				
				FindLinks(*vertex); // ��������� Links ������� � ��������.

				// ��� ������� ������� ��������� ��������� �������� ������
				for (auto link : Links )
				{
					auto current = FindVertex(link);

					// ���� ������� ������� ��������� �������
					if (current->first == vertexTo->first)
					{
						current->second = t + 1;
						FoundVertices.push_back(current->first);
						cout << "���������� ���� �� ������� '" << from << "' � ������� '" << to << "': " << endl;
						FindWay(current);
						for (list<string>::iterator it = FoundVertices.begin(); it != FoundVertices.end(); it++)
						{
							cout << *it << " ";
						}
						cout << endl;
						return;
					}

					if (current->second == -1)
					{
						current->second = t + 1;
						newFront.push_back(current->first);
					}
				}
			}

			oldFront.clear();
			copy(newFront.begin(), newFront.end(), back_inserter(oldFront));
			newFront.clear();
			t++;

		}
	}
	else
	{
		cout << "Vertex not found." << endl;
		return;
	}
	
}

void Graph::FindWay(unordered_map<string, int>::iterator rev)
{
	while (rev->second > 0)
	{
		Links.clear();
		unsigned vertex_index = vertices->find(rev->first)->second;

		auto pos = vertices->begin();

		for (size_t i = 0; i < CurrentVertexCount; i++)
		{
			if (links[vertex_index][i] != 0)
				Links.push_back(pos->first);
				pos++;
			
		}

		for (string link : Links)
		{
			if (Labels->find(link)->second == rev->second - 1)
			{
				rev = Labels->find(link);
				FoundVertices.push_back(rev->first);
				break;
			}
		}
	}
	FoundVertices.reverse();
}

// ����� ������� �� ��������
unordered_map<string, int>::iterator Graph::FindVertex(const string title)
{
	auto pos = Labels->find(title);
	if (pos != Labels->end())
	{
		return pos;
	}
	return Labels->end();
}

// ����� ������ ������� �� ��������
void Graph::FindLinks(const string title)
{
	if (vertices->find(title) != vertices->end())
	{
		unsigned vertex_index = vertices->find(title)->second;

		map<string, unsigned>::iterator pos = vertices->begin();

		for (size_t i = 0; i < CurrentVertexCount + DeleteIndexCount; i++)
		{
			if (links[vertex_index][i] != 0)
				if (Labels->find(pos->first)->second == -1)
					Links.push_back(pos->first);
			pos++;
		}
	}
}

/*bool Graph::GetRoute(string from, string to) // �������.
{
	map< int, string>find;
	vector<string> print;
	double** new_links = new double* [MaxVertexCount];
	for (size_t i = 0; i < CurrentVertexCount + DeleteIndexCount; i++)
	{
		new_links[i] = new double[CurrentVertexCount + DeleteIndexCount];

		for (size_t k = 0; k < CurrentVertexCount + DeleteIndexCount; k++)
		{
			new_links[i][k] = links[i][k];
		}
	}

	string Find_str = from;
	string str = from;
	double  label = -1;
	if (vertices->find(from) != vertices->end() && vertices->find(to) != vertices->end())
	{
		cout << from << " - " << to << endl;
		// �������� �� �������� ������� � ������ � ������� ����
		unsigned vertex_index = vertices->find(from)->second;

		for (size_t j = 0; j < CurrentVertexCount + DeleteIndexCount; j++)
		{
			vertex_index = vertices->find(Find_str)->second;

			for (unsigned i = 0; i < CurrentVertexCount + DeleteIndexCount; i++)
			{

				if (new_links[vertex_index][i] != 0)
				{
					new_links[vertex_index][i] = label;
					new_links[i][vertex_index] = 0;

					find.insert(make_pair(label, Find_str));
					Find_str = rev_vertices->find(i)->second;
				}

				if (rev_vertices->find(i)->second == to && new_links[vertex_index][i] != 0)
				{
					find.insert(make_pair(--label, rev_vertices->find(i)->second));
					while (label != 0)
					{
						print.push_back(find.find(label)->second);
						label++;

					}
					for (auto it = print.rbegin(); it != print.rend(); it++)
					{
						cout << *it << " ";
					}
					cout << endl;
					return true;
				}


			}
			label--;
		}
	}


	for (size_t i = 0; i < CurrentVertexCount + DeleteIndexCount; i++)
	{

		delete[] new_links[i];
	}
	delete[] new_links;
	return false;

}*/

void Graph::GetRouteDijkstra(string from, string to)
{
	setlocale(LC_ALL, "rus");

	map<string, unsigned>::iterator vertexFrom = vertices->find(from);
	map<string, unsigned>::iterator vertexTo = vertices->find(to);
	vector<string> v;
	size_t size = CurrentVertexCount + DeleteIndexCount; // ���������� ������
	
	if (vertexFrom != vertices->end() && vertexTo != vertices->end())
	{

		int indexFrom = vertexFrom->second; // ������ ���������
		int indexTo = vertexTo->second; // ������ ��������

		int infinity = 1000; // ���� �������������

		double* way = new double[size]; //������, ���������� ������� � ���� ��� ������ �������,
				       // way[i]=0 - ��� �� ������ ���������� ���� � i-� �������,
			           // way[i]=1 - ���������� ���� � i-� ������� ��� ������

		double* sum = new double[size];  //sum[i] - ����� ����������� ���� �� ������� from � i

		double* prev = new double[size];  //prev[i] - �������, �������������� i-� ������� �� ���������� ����
				   
		int current; // ������� �������
		int i; // ������� ������
		for (i = 0; i < size; i++)  // �������������� ��������� �������� ��������
		{
			sum[i] = infinity; //������� ��� ���������� ���� �� from � i ����� �������������
			way[i] = 0;  // � ��� ����������� ���� �� ��� ����� �������
		}
		prev[indexFrom] = 0;  // From - ������ ����, ������� ���� ������� ������ �� ������������
		sum[indexFrom] = 0;  // ���������� ���� �� From � From ����� 0
		way[indexFrom] = 1;  // ��� ������� From ������ ���������� ����
		current = indexFrom;  // ������ From ������� ��������

		while (true)
		{
			// ���������� ��� �������, ������� v, � ���� ��� ��� ���������� ����
			for (i = 0; i < size; i++)
			{
				if (links[current][i] == 0)continue; // ������� To � current ���������
				if (way[i] == 0 && sum[i] > sum[current] + links[current][i])//���� ��� ������� i ��� �� 
				//������ ���������� ���� � ����� ���� � i ������ ��� ������, �� 
				{
					sum[i] = sum[current] + links[current][i];//���������� ����� �������� ����� ���� �
					//������ sum �
					prev[i] = current;//����������, ��� current->i ����� ����������� 
					//���� �� from->i
				}
			}
			// ���� �� ���� ���� ������������ ����� ����� ��������
			int w = infinity;  // ��� ������ ������ ��������� ����
			current = -1;  // � ����� ������ current - �������, � ������� ����� 
						  // ������ ����� ���������� ����. ��� ������ 
						 // ������� ��������
			for ( i = 0; i < size; i++)
			{
				if (way[i] == 0 && sum[i] < w) // ���� ��� ������� �� ������ ���������� 
							  // ���� � ���� ����� ���� � ������� i ������
							  // ��� ���������, ��
				{
					current = i; // ������� �������� ���������� i-��� �������
					w = sum[i];
				}
			}
			if (current == -1)
			{
				cout << "��� ���� �� ������� " << from << " � ������� " << to << "." << endl;
				break;
			}
			if (current == indexTo) // ������ ���������� ����, ������� ���
			{        
				cout << "���������� ���� �� ������� '" << from << "' � ������� '" << to << "': " << endl;
				i = indexTo;
				while (i != indexFrom) 
				{
					//cout << " " << rev_vertices->find(i)->second;
					v.push_back(rev_vertices->find(i)->second);
					i = prev[i];
				}
				cout << from << " ";
				for (auto it = v.rbegin(); it != v.rend(); it++)
				{
					cout << *it << " ";
				}
				cout <<". ����� ���� - " << sum[indexTo];
				break;
			}
			way[current] = 1;
		}
		cout << endl;
		delete[] way;
		delete[] sum;
		delete[] prev;
	}

}

void Graph::PrintVertices()
{
	map <string, unsigned>::iterator pos;

	// ���� first - ����
	// ���� second - �������� �������� ����
	for (pos = vertices->begin(); pos != vertices->end(); pos++)
	{
		cout << pos->first << " -> " << pos->second << endl;
	}
}

void Graph::PrintLinks(string title)
{
	if (vertices->find(title) != vertices->end())
	{
		cout << title << " links: ";

		// �������� �� �������� ������� � ������ � ������� ����
		unsigned vertex_index = vertices->find(title)->second;

		for (size_t i = 0; i < CurrentVertexCount; i++)
		{
			if (links[vertex_index][i] != 0)
			{

				cout << links[vertex_index][i] << " ";
			}
			
		}
		cout << endl;
	}
}

void Graph::Print()
{
	for (auto it = vertices->begin(); it != vertices->end(); it++)
	{
		cout << it->first << " links: " << endl;
		unsigned vertex_index = vertices->find(it->first)->second;
		
		for (size_t i = 0; i < CurrentVertexCount+ DeleteIndexCount; i++)
		{
			auto it2 = rev_vertices->find(i);
			if (links[vertex_index][i] != 0)
			{
				if (it2 != rev_vertices->end())
				{
					cout << it2->second << ": ";
					cout << links[vertex_index][i] << " ";
				}
			}
		}
		cout << endl << "-------------------" << endl;
	}
}

bool Graph::operator== (const Graph& source)
{
	if (CurrentVertexCount != source.CurrentVertexCount || DeleteIndexCount != source.DeleteIndexCount)
		return false;
	map<string, unsigned>::iterator source_it = source.vertices->begin();
	for (auto it = vertices->begin(); it != vertices->end(); it++, source_it++)
	{
		if (it->first != source_it->first)
			return false;
	}
	for (size_t i = 0; i < MaxVertexCount; i++)
	{
		for (size_t k = 0; k < MaxVertexCount; k++)
		{
			if (links[i][k] != source.links[i][k])
				return false;
		}
	}

}

bool Graph::Save(string filename)
{
	ofstream file(filename, ios::out);
	if (!file.fail())
	{
		file << CurrentVertexCount << " " << DeleteIndexCount << endl;
		for (auto it = vertices->begin(); it != vertices->end(); it++)
		{
			file << it->first << " " << it->second << " ";
		}
		file << endl;
		
		for (size_t i = 0; i < CurrentVertexCount + DeleteIndexCount; i++)
		{
			for (size_t k = 0; k < CurrentVertexCount + DeleteIndexCount; k++)
			{
				file << links[i][k] << " ";
			}
			file << endl;
		}
		file.close();
		return true;
	}
	else
	{
		cout << "Error opening file!" << endl;
		return false;
	}

	
	
}

bool Graph::Load(string filename)
{
	vertices->clear();
	rev_vertices->clear();
	for (size_t i = 0; i < MaxVertexCount; i++)
	{
		delete[] links[i];
	}
	delete[] links;

	ifstream file(filename, ios::in);
	string temp;
	unsigned sec_temp;
	if (!file.fail())
	{
		file >> CurrentVertexCount >> DeleteIndexCount;
		for (size_t i = 0; i < CurrentVertexCount; i++)
		{
			file >> temp >> sec_temp;
			vertices->insert(make_pair(temp, sec_temp));
			rev_vertices->insert(make_pair(sec_temp, temp));
		}
		
		links = new double* [MaxVertexCount];
		for (size_t i = 0; i < MaxVertexCount; i++)
		{
			links[i] = new double[MaxVertexCount];
		}

		for (size_t i = 0; i < CurrentVertexCount + DeleteIndexCount; i++)
		{
			for (size_t k = 0; k < CurrentVertexCount + DeleteIndexCount; k++)
			{
				file >> links[i][k];
			}
		}
		file.close();
		return true;
	}
	else
	{
		cout << "Error opening file!" << endl;
		return false;
	}
}