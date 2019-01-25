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

bool compare(pii a, pii b)
{
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin >> n;

    pii *arr = new pii[n];

    for(int i=0;i<n;i++)
    {
    	cin >> arr[i].first >> arr[i].second;
    }

    sort(arr,arr+n,compare);

    int count = 1;
    int cur_finish = arr[0].second;

    for(int i=1;i<n;i++)
    {
    	if(arr[i].first >= cur_finish)
    	{
    		count++;
    		cur_finish = arr[i].second;
    	}

    }

    cout << count << "\n";

   
	
	return 0 ; 

}



