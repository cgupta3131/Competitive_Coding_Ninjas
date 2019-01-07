#include<bits/stdc++.h>

using namespace std;

void print(int **edges, int n, int starting_vertex, int *visited)
{
	cout << starting_vertex << " ";
	visited[starting_vertex] = 1;

	for(int i=0;i<n;i++)
		if(edges[i][starting_vertex] == 1 && visited[i] == 0)
			print(edges,n,i,visited);

}

int main()
{
	int n; //number ofvertices
	int e; //number of edges

	cin >> n >> e;

	int **edges = new int*[n];

	for(int i=0;i<n;i++)
	{
		edges[i] = new int[n];
		for(int j=0;j<n;j++)
			edges[i][j] = 0;
	}

	for(int i=0;i<e;i++)	
	{
		int first, second;
		cin >> first >> second;
		edges[first][second] = 1;
		edges[second][first] = 1;
	}

	int *visited = new int[n];
	for(int i=0;i<n;i++)
		visited[i] = 0;

	print(edges,n,0,visited);
	cout << endl;


	return 0 ; 

}

