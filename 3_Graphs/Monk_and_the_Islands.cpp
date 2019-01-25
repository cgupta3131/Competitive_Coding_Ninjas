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

int BFS(vector<int> *edges, int source, bool *visited, int v)
{
	queue<int> q;
	q.push(source);
	visited[source] = true;

	int flag = 0;

	int *dist = new int[v+1];
	for(int i=0;i<=v;i++)
		dist[i] = -1;

	dist[source] = 0;

	while( !q.empty() )
	{	
		int front = q.front();
		q.pop();

		for(int i=0;i<edges[front].size();i++)
		{	
			//cout << "Front : " << front <<  " Back : " << edges[front][i] << endl;
			//edge between front and edges[front][i]
			if(!visited[ edges[front][i] ] )
			{

				dist[ edges[front][i] ] = dist[front] + 1;
				q.push(edges[front][i]);
				visited[edges[front][i]] = true;

				if(edges[front][i] == v)
				{
					flag = 1;
					break;	
				}
			}

		}

		if(flag == 1)
			break;
	}

	return dist[v];
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
		int n; //vertics
		int m; //edges;

		cin >> n >> m;

		int v = n;
		int e = m;

		vector<int> *edges = new vector<int>[v+1];
		for(int i=0;i<e;i++)
		{
			int x,y;
			cin >> x >> y;

			edges[x].pb(y);
			edges[y].pb(x);
		}

		bool *visited = new bool[v+1];
		for(int i=0;i<=v;i++)
			visited[i] = false;
		
		cout << BFS(edges,1,visited,v) << endl;
	}


	return 0 ; 

}



