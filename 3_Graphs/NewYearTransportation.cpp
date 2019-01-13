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

bool BFS(vector<int> *edges, int source, int n, int dest)
{
	bool *visited = new bool[n+1];
	for(int i=1;i<=n;i++)
		visited[i] = false;

	queue<int> q;
	q.push(source);
	visited[source] = true;

	int flag = 0;

	while(!q.empty())
	{	
		int front = q.front();
		if(front == dest)
			return true;
		
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

	return false;

}	

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, t;
	cin >> n >> t;

	int *input = new int[n];

	for(int i=1;i<n;i++)
		cin >> input[i];

	vector<int> *edges = new vector<int>[n+1];

	for(int i=1;i<n;i++) //portal connects (i) and (input[i] + i) in unidirection
		edges[i].pb(input[i] + i);

	if( BFS(edges,1,n,t ) )
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0 ; 

}



