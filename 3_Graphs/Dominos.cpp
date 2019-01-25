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

void DFS_2(vector<int> *edges, int source, bool *visited)
{
	visited[source] = true;

	for(int i=0;i<edges[source].size();i++)
	{
		if( visited[ edges[source][i] ] == false)
			DFS_1(edges, edges[source][i], visited);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t;
	cin >> t;

	while(t--)
	{
		int n,e;

		cin >> n >> e;
		vector<int> *edges = new vector<int>[n+1];
		for(int i=0;i<e;i++)
		{
			int x,y; //edge from x to y(Directed Graph)
			cin >> x >> y;
			edges[x].pb(y);
		}

		bool *visited = new bool[n+1];
		for(int i=1;i<=n;i++)
			visited[i] = false;

		for(int i=1;i<=n;i++)
		if(!visited[i])
			DFS_1(edges,i,visited);

		int count  = 0;
		for(int i=1;i<=n;i++)
			visited[i] = false;

		while(!s.empty())
		{
			int top = s.top();
			s.pop();

			if( !visited[top] )
			{
				count++;
				DFS_2(edges,top,visited);
			}
		}

		cout << count << "\n";

		delete [] visited;
		delete [] edges;

	}


	return 0 ; 

}



