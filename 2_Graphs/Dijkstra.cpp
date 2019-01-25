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
class Edge{
public:
	int source;
	int destination;
	int weight;
};

bool compare(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}

int main()
{
	int V, E;
	cin >>	V >> E;

	//Adjacency Matrix
	int edge[V][V];

	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			edge[i][j] = -1;

	Edge *input = new Edge[E];
	Edge *output = new Edge[V-1];

	for(int i=0;i<E;i++)
	{
		cin >> input[i].source;
		cin >> input[i].destination;
		cin >> input[i].weight;
		//Updating the adjaceny matrix
		edge[input[i].source][input[i].destination] = input[i].weight;
		edge[input[i].destination][input[i].source] = input[i].weight;
	}

	bool visited[V];
	int distances[V];

	for(int i=0;i<V;i++)
	{
		visited[i] = false;
		distances[i] = INT_MAX;
	}

	distances[0] = 0;

	for(int i=0;i<V;i++)
	{
		int minVertex;
		int min_value = INT_MAX;

		for(int j=0;j<V;j++)
		{
			if(!visited[j] && min_value > distances[j])
			{
				minVertex = j;
				min_value = distances[j];
			}
		}

		visited[minVertex] = true;

		for(int j=0;j<V;j++)
		{
			if(edge[minVertex][j] > 0 && !visited[j] )	
				if(distances[j] > distances[minVertex] + edge[minVertex][j])
					distances[j] = distances[minVertex] + edge[minVertex][j];
		}
	}

	for(int i=0;i<V;i++)
		cout << i << " " << distances[i] << endl;

	return 0 ; 

}



