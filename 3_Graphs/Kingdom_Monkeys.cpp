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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
    	int n,m;

    	cin >> n >> m;

    	vector<int> *edges = new vector<int>[n+1];

    	for(int i=0;i<m;i++)
    	{
    		int x,y;
    		cin >> x >> y;

    		edges[x].pb(y);
    		edges[y].pb(x);
    	}

    	vector< vector<int> > allComponents;

    	bool *visited = new bool[n+1];
		for(int i=1;i<=n;i++)
			visited[i] = false;

		for(int i=1;i<=n;i++)
		{
			if(visited[i] == false)
			{
				vector<int> component = BFS(edges, i, visited);
				allComponents.pb(component);
			}
		}

		delete [] edges;
		delete [] visited;

		ll max = -1;
		ll *arr = new ll[n+1];

		for(int i=1;i<=n;i++)
			cin >> arr[i];

		for(int i=0;i<allComponents.size();i++)
		{
			ll temp_sum = 0;
			for(int j=0;j<allComponents[i].size();j++)
				temp_sum += arr[ allComponents[i][j] ];

			if(temp_sum > max)
				max = temp_sum;
		}

		delete [] arr;

		cout << max << "\n";

    }

	
	return 0 ; 

}



