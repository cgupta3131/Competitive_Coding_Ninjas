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

	
	ll n,M;
	ll a,b;

	cin >> n >> M;
	cin >> a >>b;

	ll num = pow(2,32);

	ll *x = new ll[n+1];
	ll *c = new ll[n+1];

	x[0] = 0;

	for(int i=1;i<=n;i++)
	{
		x[i] = ( ( (x[i-1]%M)*a ) + b ) % num;
		c[i] = x[i]/256;
	}

	/*  c[6] = 7;
	c[7] = 14;
	c[8] = 21;
	c[9] = 8;

	for(int i=1;i<=n;i++)
		cout << c[i] << " ";
	cout << "\n";  */


	ll profit = 0;
	ll cur = -1 * c[1];

	for(int i=2;i<n;i++)
	{
		if( c[i] > c[i+1])
		{
			profit += c[i] - abs(cur);
			cur = -1 * c[i+1];
			continue;
		}

		if(i == n-1) //means that last element is larger than the second last element
			profit += c[n] - abs(cur);
		

	}

	cout << profit << "\n";
 

	return 0 ; 

}



