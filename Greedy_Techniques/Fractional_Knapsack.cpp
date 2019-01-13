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
class item{

public:
	int value,weight;
};

bool compare(item a, item b)
{
	double value1 = 1.0*(a.value)/(a.weight);
	double value2 = 1.0*(b.value)/(b.weight);

	return value1 > value2;
}

double fKnapsack(item arr[], int W, int n)
{
	sort(arr,arr+n,compare);

	int currW = 0;
	double fValue = 0;

	for(int i=0;i<n;i++)
	{
		if(currW + arr[i].weight <= W)
		{
			currW += arr[i].weight;
			fValue += arr[i].value;
		}

		else
		{
			int remainingW = W - currW;
			fValue = arr[i].value * (1.0*remainingW/arr[i].weight);
			break;
		}
	}

	return fValue;

}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int W = 70;

    item arr[] = { {60,20} , {70,15} , {80,40} };

    cout << fKnapsack(arr,W,3) << "\n";


	
	return 0 ; 

}



