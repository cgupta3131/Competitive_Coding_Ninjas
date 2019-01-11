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

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t;
	cin >> t;

	while(t--)
	{
		int n,m,q;

		cin >> n >> m;

		int **arr = new int*[n];
		for (int i = 0 ; i < n ; i++)
   			arr[i] = new int[m];

   		for (int i = 0 ; i < n ; i++)
   			for (int j = 0 ; j < n ; j++)
   				arr[i][j] = -1;

   		for(int i=1;i<=q;i++)
   		{
   			int x,y;
   			cin >> x >> y;

   			arr[x][y] = i;
   		}

   		vector<int> *edges = new vector<int>[q+1];

	}


	return 0 ; 

}



