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

class Job{

public:
	int start;
	int end;
	int profit;

};

bool compare(Job a, Job b)
{

	return a.end < b.end;
}


int BinarySearch(Job *arr, int limit, int si, int ei)
{
    if(si > ei)
        return -1;

    if(si == ei)
    {
        if(arr[si].end <= limit)
            return si;
        else
            return -1;
    }

    int mid = (si+ei)/2;

    if(arr[mid].end <= limit)
    {
        int ans = BinarySearch(arr,limit,mid+1,ei);
        if(ans == -1)
            return mid;
        else
            return ans;
    }
    else
        return BinarySearch(arr,limit,si,mid-1);


}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    Job *arr = new Job[n];

    for(int i=0;i<n;i++)
    {
    	cin >> arr[i].start >> arr[i].end >> arr[i].profit;
    }

    sort(arr,arr+n,compare); //sorting wrt finishing time!

    int *dp = new int[n];
    dp[0] = arr[0].profit;



    for(int i=1;i<n;i++)
    {
    	int including = arr[i].profit;
    	int id = -1;

        id = BinarySearch(arr,arr[i].start,0,i-1);
    	
        if(id != -1)
    	   including += dp[id];
    	dp[i] = max(dp[i-1],including);
    }

    cout << dp[n-1] << "\n";

	
	return 0 ; 

}



