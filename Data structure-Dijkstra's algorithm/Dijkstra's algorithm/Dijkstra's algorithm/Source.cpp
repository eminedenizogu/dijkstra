#include <fstream>
#include <vector>
#include <set>
#include <iostream>

#define DIM 50010
#define INF DIM*1000

using namespace std;

vector<pair<int, int>> adjacency_list[DIM];
set<pair<int, int>> tail; 

int distances[DIM], x, y, c, no_vertices, no_edges, k;

ifstream fin("ýnput.txt");

int main()
{
	fin >> no_vertices >> no_edges;
	for (int i = 1; i <= no_edges; i++)
	{
		fin >> x >> y >> c; 
		adjacency_list[x].push_back(make_pair(y, c)); 
	}

	for (int i = 1; i <= no_vertices; i++)
	{
		distances[i] = INF; 
	}

	
	distances[1] = 0; 

	tail.insert(make_pair(0, 1)); 
								 

	while (!tail.empty()) 
	{
		int vertex = tail.begin()->second; 
										  
		tail.erase(tail.begin());            

		for (int i = 0; i < adjacency_list[vertex].size(); i++) 
		{
			int neighbour = adjacency_list[vertex][i].first; 
			int cost = adjacency_list[vertex][i].second;   

			if (distances[neighbour] > distances[vertex] + cost)  
			{                            

				tail.erase(make_pair(distances[neighbour], neighbour)); 
				distances[neighbour] = distances[vertex] + cost;      
				tail.insert(make_pair(distances[neighbour], neighbour));  

			}
		}
	}

	
	for (int i = 2; i <= no_vertices; i++) 
	{                                                                                                  
		if (distances[i] == INF) 
			cout << "0 ";        
		else
			cout << distances[i] << " ";
	}

	system("pause");
}