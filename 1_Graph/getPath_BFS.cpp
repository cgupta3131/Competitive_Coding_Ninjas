#include<iostream>
#include<string>
#include<string>
#include<queue>
#include<vector>
#include<map>

using namespace std;



bool hasPath(int **edges, int n, int *visited, int v1, int v2)
{

	queue<int> pendingVertices;

	pendingVertices.push(v1);
	visited[v1] = 1;

	while(pendingVertices.empty() ==  false)
	{
		int front = pendingVertices.front();

		if(front == v2)
			return true;
		
		pendingVertices.pop();

		for(int i=0;i<n;i++)
		{	
			if(edges[front][i] == 1 && visited[i] == false)
			{
				visited[i] = 1;
				pendingVertices.push(i);	
			}
			
		}
		
	}

	return false;
}

//hasPath(int **edges, int n, int *visited, int v1, int v2)

void getPath2(int **edges, int n, int *visited, int v1, int v2)
{
	map <int,int> parent;

	queue<int> pendingVertices;
	pendingVertices.push(v1);
	visited[v1] = 1;
	int flag = 0;


	while( pendingVertices.empty() == false)
	{
		int front = pendingVertices.front();
		pendingVertices.pop();

		for(int i=0;i<n;i++)
		{	
			if(edges[front][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				pendingVertices.push(i);
				parent[i] = front;

				if(i == v2)
				{
					flag = 1;
					break;
				}

			}
		}
	}

	if(flag == 0)
		return;

	cout << v2 << " ";
	int x = v2;

	while(x != v1)
	{
		cout << parent.at(x) << " ";
		x = parent.at(x);
	}


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

	int v1, v2;

	cin >> v1 >> v2;

	int *visited = new int[n];
	for(int i=0;i<n;i++)
		visited[i] = 0;


	getPath2(edges,n,visited, v1,v2);

	/*  if(output == NULL)
		return 0;

	int index = output->size();
	for(int i=0;i<output->size();i++)
		cout << output->at(index-1-i) << " ";
	cout << endl;  */

}

