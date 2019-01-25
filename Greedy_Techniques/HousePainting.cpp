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

class Painter{

public:
	ll time;
	ll cost;
	ll speed;

};

bool compare(Painter a, Painter b)
{
	if(a.time == b.time)
	{
		if(a.speed == b.speed)
			return a.cost < b.cost;
		else
			return a.speed > b.speed;
	}

	return a.time < b.time;
}



int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ll n,D;
    cin >> n >> D;

    Painter *input = new Painter[n];

    for(int i=0;i<n;i++)
    	cin >> input[i].time >> input[i].cost >> input[i].speed;

    sort(input,input+n,compare);
   
    
    ll area = 0;
    ll bestSpeed = 0, cost = 0, lasTime = input[0].time;

    for(int i = 0; i < n; i++)
    {
        ll additional = bestSpeed * (input[i].time - lasTime);
        area += additional;
        	
        if(area >= D) 
        	break;
        if(input[i].speed > bestSpeed)
        {
            bestSpeed = input[i].speed;
            cost += input[i].cost;
        }

        lasTime = input[i].time;
    }

    cout << cost << "\n";
	

	return 0 ; 

}



