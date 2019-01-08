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

#define forr(i,a,n) for(ll i = a ; i < n ; i++)
#define forn(i,n) for(ll i = 0 ; i < n ; i++)
#define revfor(i,b,a) for(ll i = b ; i >= a ; i--)
#define revforn(i,n) for(ll i = n ; i >= 0 ; i--)
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


int main()
{
	int V, E;
	cin >>	V >> E;

	//Adjacency Matrix
	//int edge[V][V];

	int **edge = new int*[V];
	for(int i=0;i<V;i++)
	{
		edge[i] = new int[V];
		/*  for(int j=0;j<V;j++)
			edge[i][j] = 0;  */
	}

	memset(edges,-1,)


	for(int i=0;i<E;i++)
	{
		int ei, ej, w;
		cin >> ei >> ej >> w;
		//Updating the adjaceny matrix
		edge[ei][ej] = w;
		edge[ej][ei] = w;
	}

	bool visited[V];
	int parent[V];
	int weight[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		weight[i] = INT_MAX;
		parent[i] = 0;
	}

	//Source being vertex 0
	weight[0] = 0;
	parent[0] = -1;

	for(int i=0;i<V;i++)
	{
		int minVertex = -1;
		for(int j=0;j<V;j++)
		{
			if(!visited[j] && (minVertex == -1 || weight[j] < weight[minVertex]))
				minVertex = j;
		}

		visited[minVertex] = true;
		//cout << "Min-Weight-Vertex : " << minVertex << endl; 

		for(int j=0;j<V;j++)
		{
			if( edge[minVertex][j] > 0 && !visited[j] )
			{
				if(weight[j] > edge[minVertex][j])
				{
					weight[j] = edge[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}

	for(int i=1;i<V;i++)
	{
		int mini = min(i,parent[i]);
		int maxi = max(i,parent[i]);
		cout << mini << " " << maxi << " " << weight[i] << endl;
	}

	return 0 ; 
}



