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

stack<int> s;

void DFS_1(vector<int> *edges, int source, bool *visited)
{
	visited[source] = true;

	for(int i=0;i<edges[source].size();i++)
	{
		if( visited[ edges[source][i] ] == false)
			DFS_1(edges, edges[source][i], visited);
	}

	s.push(source);
}

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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n,e; // n is number of vertics and e is number of edges

	cin >> n >> e;

	vector<int> *edges = new vector<int>[n+1];
	vector<int> *edgesT = new vector<int>[n+1]; //stores the Transposed graph!

	for(int i=0;i<e;i++)
	{
		int x,y; //edge from x to y(Directed Graph)
		cin >> x >> y;

		edges[x].pb(y);
		edgesT[y].pb(x);
	}

	bool *visited = new bool[n+1];
	for(int i=1;i<=n;i++)
		visited[i] = false;

	for(int i=1;i<=n;i++)
		if(!visited[i])
			DFS_1(edges,i,visited);

	for(int i=1;i<=n;i++)
		visited[i] = false;

	vector<vector <int> > allComponents;

	while(!s.empty())
	{
		int top = s.top();
		s.pop();

		if( !visited[top] )
		{
			vector<int> component = BFS(edgesT, top, visited);
			allComponents.pb(component);
		}
	}

	//I will get all the Strong Components!
	int flag = 0;
	int index = -1;

	for(int i=0;i<allComponents.size();i++)
	{
		int possible = allComponents[i][0];
		for(int j=0;i<allComponents.size();i++)

	}

	return 0 ; 

}


/*  

INPUT DATA

10 12
1 2
2 3
3 4
4 1
4 5
5 6
6 7
7 5
8 7
8 9
9 8
10 9 

 */




