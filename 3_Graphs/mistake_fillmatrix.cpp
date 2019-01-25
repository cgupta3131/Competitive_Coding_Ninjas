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

bool compare(ppi a, ppi b)
{
	if(a.first.first == b.first.first)
		return a.first.second < b.first.second;
	else
		return a.first.first < b.first.first;
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
		for(int i=0;i<q;i++)
		{
			int x,y,z; //edge from x to y(Directed Graph)
			cin >> x >> y >> z;

			if(x > y)
			{
				int temp = x;
				x = y;
				y = temp;
			}

			if(x == y)
			{
				if(z != 0)
				{
					flag = 1;
					break;
				}
			}

			if(x != y)
			{
				ppi my_pair = mp(mp(x,y),z);
				store.pb(my_pair);
			}

			
		}

		if(flag == 1)
		{
			cout << "no" << endl;
			continue;
		}

		sort(store.begin(),store.end(),compare);

		int *colour = new int[n+1];
		for(int i=0;i<=n;i++)
			colour[i] = -1;

		flag =0;

		/*  for(int i=0;i<store.size();i++)
		{
			int x = store[i].first.first;
			int y = store[i].first.second;
			int z = store[i].second;

			cout << x << " " << y << " " << z << endl;
		}  */

		for(int i=0;i<store.size();i++)
		{
			int x = store[i].first.first;
			int y = store[i].first.second;
			int z = store[i].second;

			if(z == 1) //give different colors to both x and y;
			{
				if(colour[x] == -1 && colour[y] == -1)
				{
					colour[x] = 0;
					colour[y] = 1;
				}

				else if(colour[x] == -1 && colour[y] != -1)
					colour[x] = 1 - colour[y]; 
				else if(colour[x] != -1 && colour[y] == -1)
					colour[y] = 1 - colour[x]; 
				else
				{
					if(colour[x] == colour[y])
					{
						flag = 1;
						break;
					}

				}
			}

			else if(z == 0) //both x and y shold get same colors;
			{
				if(colour[x] == -1 && colour[y] == -1)
				{
					colour[x] = 0;
					colour[y] = 0;
				}

				else if(colour[x] == -1 && colour[y] != -1)
					colour[x] = colour[y]; 
				else if(colour[x] != -1 && colour[y] == -1)
					colour[y] = colour[x]; 
				else
				{
					if(colour[x] != colour[y])
					{
						flag = 1;
						break;
					}
				}

			}

		}

		if(flag == 1)
			cout << "no" << endl;

		else
			cout << "yes" << endl;

		delete [] colour;



	}
	return 0 ; 

}



