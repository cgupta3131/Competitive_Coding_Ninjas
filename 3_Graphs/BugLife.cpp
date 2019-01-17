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

bool Bipartitie(vector<int> *edges, int source, int *visited)
{
	visited[source] = 1;
	queue<int> q;
	q.push(source);

	while( !q.empty() )
	{
		int front = q.front();
		int colour = visited[front];
		q.pop();
		//cout << front << endl;

		for(int i=0;i<edges[front].size();i++)
		{	
			int opp;
			if(colour == 1)
				opp = 2;
			else
				opp = 1;
			if(visited[ edges[front][i] ] == colour)
				return false;
			else if(visited[ edges[front][i] ] == 0)
			{
				q.push(edges[front][i]);
				visited[ edges[front][i] ] = opp;
			}
		}

	}

	return true;


}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for(int k=1;k<=t;k++)
    {
	    int n,e; // n is number of vertics and e is number of edges

		cin >> n >> e;

		vector<int> *edges = new vector<int>[n+1];
		for(int i=0;i<e;i++)
		{
			int x,y; //edge from x to y(Directed Graph)
			cin >> x >> y;
			edges[x].pb(y);
			edges[y].pb(x);
		}

		int *visited = new int[n+1];
		for(int i=1;i<=n;i++)
			visited[i] = 0;

		/*  0 means NO Color
		1 means RED Color
		2 means BLUE Color  */

		bool final = true;
		for(int i=1;i<=n;i++)
		{
			if(visited[i] == 0)
			{
				bool ans = Bipartitie(edges,i,visited);
				if(ans == false)
				{
					final = false;
					break;
				}
			}
		}



		cout << "Scenario #" << k << ":" << endl;
		if(final)
			cout << "No suspicious bugs found!" << endl;
		else
			cout << "Suspicious bugs found!" << endl;
		delete [] edges;
		delete [] visited;
	}
	
	return 0 ; 

}



