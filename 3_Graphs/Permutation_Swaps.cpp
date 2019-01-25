#include<bits/stdc++.h>
using namespace std;

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer	

vector<int> BFS(int **edges, int source, bool *visited, int n)
{
	visited[source] = true;

	vector<int> output; /*  = new vector<int>;  */
	queue<int> q;
	q.push(source);

	while(!q.empty())
	{
		int front = q.front();
		output.push_back(front);
		q.pop();

		for(int i=1;i<=n;i++)
		{
			if(edges[front][i] && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}

	return output;

}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int n,m;
		cin >> n >> m;

		int *input = new int[n];
		int *output = new int[n];

		for(int i=0;i<n;i++)
			cin >> input[i];

		for(int i=0;i<n;i++)
			cin >> output[i];

		//Rather than Adjanceny Matrix, construct an adjancecy list!
		int **edges = new int*[n+1];
		
		for(int i=0;i<=n;i++)
			edges[i] = new int[n+1];

		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				edges[i][j] = 0;
		
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin >> x >> y;

			edges[x][y] = 1;
			edges[y][x] = 1;
		}

		bool *visited = new bool[n+1];

		for(int i=0;i<n+1;i++)
			visited[i] = false;
		visited[0] = true;

		vector< vector<int> > allComponents;
		for(int i=1;i<=n;i++)
		{
			if(visited[i] == false)
			{
				vector<int> component = BFS(edges,i,visited,n);
				allComponents.push_back(component);
			}
		}

		delete [] visited;


		int flag = 0;
		for(int i=0;i<allComponents.size();i++)
		{
			vector<int> v1;
			vector<int> v2;

			for(int j=0;j<allComponents[i].size();j++)
			{	
				int index = allComponents[i][j] - 1;
				v1.push_back(input[ index ]);
				v2.push_back(output[ index ]);
			}

			sort(v1.begin(),v1.end());
			sort(v2.begin(),v2.end());

			if(v1 != v2)
			{
				flag = 1;
				break;
			}
		}

		if(flag == 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

		delete [] input;
		delete [] output;
 
 		for(int i=0;i<=n;i++)
 			delete [] edges[i];
 		delete [] edges;
		



	}
	
	return 0 ; 

}



