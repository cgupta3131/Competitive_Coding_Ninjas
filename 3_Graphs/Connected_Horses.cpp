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

void addEdges(int **arr, int i, int j, vector<int> *edges, int n, int m)
{
   int num = arr[i][j];

   if(i+1 <= n && j+2 <= m && arr[i+1][j+2] != -1)
      edges[num].pb(arr[i+1][j+2]);

   if(i+2 <= n && j+1 <= m && arr[i+2][j+1] != -1)
      edges[num].pb(arr[i+2][j+1]);

   if(i+2 <= n && j-1>0 && arr[i+2][j-1] != -1)
      edges[num].pb(arr[i+2][j-1]);
    
   if(i+1 <= n && j-2>0 && arr[i+1][j-2] != -1)
      edges[num].pb(arr[i+1][j-2]);

   if(i-1>0 && j-2>0 && arr[i-1][j-2] != -1)
      edges[num].pb(arr[i-1][j-2]);

   if(i-2>0 && j-1>0 && arr[i-2][j-1] != -1)
      edges[num].pb(arr[i-2][j-1]);

   if(i-2>0 && j+1 <= m && arr[i-2][j+1] != -1)
      edges[num].pb(arr[i-2][j+1]);

   if(i-1>0 && j+2 <= m && arr[i-1][j+2] != -1)
      edges[num].pb(arr[i-1][j+2]);
}


int BFS(vector<int> *edges, int source, bool *visited)
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

   return output.size();

}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t;
	cin >> t;

   ll factorial[1000007];
      factorial[0] = 1;

   for(ll i = 1; i <= 1e6+5; i++)
      factorial[i] = (factorial[i - 1] * i) % MOD;

	while(t--)
	{

		int n,m,q;

		cin >> n >> m >> q;

		int **arr = new int*[n+1];
		for (int i = 0 ; i <= n ; i++)
   			arr[i] = new int[m+1];


		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= m ; j++)
				arr[i][j] = -1;

		for(int i=1;i<=q;i++)
		{
			int x,y;
			cin >> x >> y;

			arr[x][y] = i;
		}

		vector<int> *edges = new vector<int>[q+1];

		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
            if(arr[i][j] != -1)
               addEdges(arr,i,j,edges,n,m);
			}
		}

     /*   for(int i=1;i<=q;i++)
      {
         cout << i << " : ";
         for(int j=0;j<edges[i].size();j++)
            cout << edges[i][j] << " ";
         cout << endl;
      }  */

      bool *visited = new bool[q+1];

      for(int i=1;i<=q;i++)
         visited[i] = false;


      ll final_ans = 1;
      for(int i=1;i<=q;i++)
      {
         if(!visited[i])
         {
            ll temp = BFS(edges, i, visited);
            final_ans *= factorial[temp];
            final_ans %= MOD;
         }
      }

      for (int i=0;i<=n;i++)
         delete [] arr[i];
      delete [] arr;

      delete [] visited;
      delete [] edges;

      cout << final_ans << endl;


	}


	return 0 ; 

}



