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

int solve(int xy, int pq, int ab, int R, int S, int starting, int ending)
{
	//xy is time for hostel
	//pq is the time he wakes up
	//ab is opening of shop time

	int diff1 = ab-pq;
	int diff2 = diff1 - R;
	int val = -1;

	if(diff2 >= 0)
		val = 0;
	if(diff2 < 0 && diff2 > -R)
		val = -1*diff2;

	if(diff2 < 0 && diff2 <= -R)
		val = R;

	if(starting > max(ab,pq) + R + S + val )
	{
		if(max(ab,pq) + R + S + val < xy)
			return max(ab,pq) + R + S + val;
		else
			return -1;
	}
	else 
	{

		if(ending >= ab) //He gets the slippers after the shop opens
		{
			if(max(ending,pq) + 2*R + S < xy)
				return max(ending,pq)+2*R+S;
			else
				return -1;
		}

		else //he gets the slippers before the shop opens!
		{
			if(pq <= ab) //means that he wakes up before shop opens
			{
				if(max(ending,pq)+R <= ab)
				{
					if(ab+S+R < xy) //he will go before the shop open and stand there
						return ab+R+S;
					else
						return -1;
				}

				else
				{
					if(max(ending,pq) + 2*R + S < xy)
						return max(ending,pq)+2*R+S;
					else
						return -1;
				}
			}

			else
			{

				if(pq+2*R+S <= xy)
					return pq+2*R+S;
				else
					return -1;
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t;
	cin >> t;

	for(int k=1;k<=t;k++)
	{
		int n;
		cin >> n;
		string close_hostel;
		string wake;
		string open_shop;

		cin >> close_hostel;
		cin >> wake;
		cin >> open_shop;

		int R,S;
		cin >> R >> S;

		int xy = 0; //closing hostel time
		int pq = 0; //waking up time;
		int ab = 0; //shopp opening time;



		int h=0;
		int m=0;

		h = ( (int)close_hostel[0] - 48 )*10 + ( (int)close_hostel[1] - 48 );
		xy += h*60;
		m = ( (int)close_hostel[3] - 48 )*10 + ( (int)close_hostel[4] - 48 );
		xy += m;

		h = ( (int)wake[0] - 48 )*10 + ( (int)wake[1] - 48 );
		pq += h*60;
		m = ( (int)wake[3] - 48 )*10 + ( (int)wake[4] - 48 );
		pq += m;

		h = ( (int)open_shop[0] - 48 )*10 + ( (int)open_shop[1] - 48 );
		ab += h*60;
		m = ( (int)open_shop[3] - 48 )*10 + ( (int)open_shop[4] - 48 );
		ab += m;

		int flag = 0;
		if(pq >= xy || ab >= xy)
		{
			cout << "Case " << k << ": " << -1 << "\n";
			flag = 1;
		}

		int min = INT_MAX;
		int index = -1;
		for(int i=1;i<=n;i++)
		{
			string time1;
			string time2;

			cin >> time1;
			cin >> time2;

			//cout << time1 << " " << time2 << "\n"; 

			if(flag == 0)
			{
				int h,m;
				int starting = 0;
				int ending = 0;

				h = ( (int)time1[0] - 48 )*10 + ( (int)time1[1] - 48 );
				starting += h*60;
				m = ( (int)time1[3] - 48 )*10 + ( (int)time1[4] - 48 );
				starting += m;

				h = ( (int)time2[0] - 48 )*10 + ( (int)time2[1] - 48 );
				ending += h*60;
				m = ( (int)time2[3] - 48 )*10 + ( (int)time2[4] - 48 );
				ending += m;

				int pos = solve(xy,pq,ab,R,S,starting,ending);
				
				/*  if(pos != -1)
					cout << time1 << " " << time2 << "\n";  */
				//cout << i << " " << pos << "\n";

			
					
				if(pos < min && pos != -1)
				{
					min = pos;
					index = i;
				}
			}
		}

		if(flag == 0 )
			cout << "Case " << k << ": " << index << "\n";
	}


	return 0 ; 
	
}



