#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer	

vector<int> BFS(vector<int> *edges, int source, bool *visited)
{
	queue<int> q;
	q.push(source);
	visited[source] = true;

	vector<int> output;

	while(!q.empty())
	{	
		int front = q.front();
		output.push_back(front);
		q.pop();

		for(int i=0;i<edges[front].size();i++)
		{
			//cout << "Front : " << front <<  " Back : " << edges[front][i] << endl;
			//edge between front and edges[front][i]
			if(!visited[ edges[front][i] ])
			{
				q.push(edges[front][i]);
				visited[edges[front][i]] = true;
			}

		}

	}

	return output;

}



int main()
{
	int v,e; //Number of vertices and edges

	cin >> v >> e;
	
	vector<int> *edges = new vector<int>[v+1];

	for(int i=0;i<e;i++)
	{
		int x,y;
		cin >> x >> y;

		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	for(int i=1;i<=v;i++)
	{
		cout << i << " : ";
		for(int j=0;j<edges[i].size();j++)
			cout << edges[i][j] << " ";
		cout << endl;
	}

	bool *visited = new bool[v+1];

	for(int i=1;i<=v;i++)
		visited[i] = false;

	vector< vector<int> > allComponents;

	for(int i=1;i<=v;i++)
	{
		if(visited[i] == false)
		{
			vector<int> component = BFS(edges, i, visited);
			allComponents.push_back(component);
		}
	}


	for(int i=0;i<allComponents.size();i++)
	{
		for(int j=0;j<allComponents[i].size();j++)
			cout << allComponents[i][j] << " ";
		cout << endl;
	}


	return 0 ; 

}



