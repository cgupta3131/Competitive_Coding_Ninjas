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
typedef pair<pii,int> ppi;
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

int find(int x, int *parent)
{
	if(parent[x] == -1)
		return x;

	else
		return find(parent[x],parent);
}

void Union(int x, int y, int *parent)
{
	int x1 = find(x,parent);
	int y1 = find(y,parent);

	if(x1 != y1)
		parent[x1] = y1;
}

void coloring(int x, int *parent, int *visited, int colour)
{
	if(parent[x] == -1)
	{
		visited[x] = colour;
		return;
	}

	visited[x] = colour;
	coloring(parent[x],parent,visited,colour);
	
}

bool Bipartitie(vector<int> *edges, int source, int *visited, int *parent)
{
	coloring(source,parent,visited,1);
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
				coloring(edges[front][i],parent,visited,opp);
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

	while(t--)
	{
		int n,q;

		cin >> n >> q;
		int flag = 0;

		vector<ppi> store;

		int *parent = new int[n+1];
		for(int i=0;i<=n;i++)
			parent[i] = -1;
		
		vector<int> *edges = new vector<int>[n+1];

		for(int i=0;i<q;i++)
		{
			int x,y,z; //edge from x to y(Directed Graph)
			cin >> x >> y >> z;

			if(x == y)
			{
				if(z != 0)
				{
					flag = 1;
					break;
				}
				else
					continue;
			}

			if(z == 0) //Union of x and y
				Union(x,y,parent);
			else
			{
				edges[x].pb(y);
				edges[y].pb(x);
			}
		}

		if(flag == 1)
		{
			delete [] edges;
			delete [] parent;
			cout << "no" << endl;
			continue;
		}

		bool *visited2 = new bool[n+1];
		for(int i=1;i<=n;i++)
			visited2[i] = false;

		for(int i=1;i<=n;i++)
		{
			if(parent[i] == -1 || visited[i] == true)
			{
				visited2[i] = true;
				continue;
			}

			int temp = parent[i];
			visited2[i] = true;
			vector<int> temp;
			temp.pb(i);

			while(1)
			{
				if(parent[temp] == -1)
				{
					visited2[temp] = true;
					continue;
				}

				visited2[temp] = true;
				temp = parent[temp];
				temp.pb(temp);
			}


		}

		int *visited = new int[n+1];
		for(int i=1;i<=n;i++)
			visited[i] = 0;

		bool final = true;
		for(int i=1;i<=n;i++)
		{
			if(visited[i] == 0)
			{
				bool ans = Bipartitie(edges,i,visited,parent);
				if(ans == false)
				{
					final = false;
					break;
				}
			}
		}
		delete [] visited;
		delete [] edges;
		delete [] parent;

		if(final)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

		
	}

	return 0 ; 

}


