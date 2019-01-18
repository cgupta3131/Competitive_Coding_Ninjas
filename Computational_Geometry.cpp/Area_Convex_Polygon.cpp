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
double area(int *x, int *y, int n)
{
	double fArea = 0;

	for(int i=1;i<n-1;i++)
	{
		int x1 = x[i]-x[0];
		int y1 = y[i] - y[0];

		int x2 = x[i+1]-x[0];
		int y2 = y[i+1] - y[0];

		int cross = x1*y2 - x2*y1;
		//cout << cross << endl;

		fArea += (double)cross/2;
	}

	return abs(fArea);

}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;
	cin >> n;

	int *x = new int[n];
	int *y = new int[n];

	for(int i=0;i<n;i++)
		cin >> x[i];
	for(int i=0;i<n;i++)
		cin >> y[i];
	
	cout << setprecision(20) << area(x,y,n) << endl;
	return 0 ; 

}



