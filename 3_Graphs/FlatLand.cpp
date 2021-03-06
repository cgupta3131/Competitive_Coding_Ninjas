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
vector<int> final;

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
			DFS_2(edges, edges[source][i], visited);
	}

	final.pb(source);
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
		DFS_1(edgesT,1,visited);

	for(int i=1;i<=n;i++)
	{
		if(!visited[i]) //means that the graph is dis-connected!
		{
			cout << 0 << endl;
			return 0;
		}
	}

	for(int i=1;i<=n;i++)
		visited[i] = false;

	int top = s.top();
	DFS_2(edges,top,visited);

	delete [] visited;
	delete [] edges;
	delete [] edgesT;

	sort(final.begin(),final.end());

	cout << final.size() << "\n";

	for(int i=0;i<final.size();i++)
		cout << final[i] << " ";
	cout << "\n";

	return 0 ; 

}



