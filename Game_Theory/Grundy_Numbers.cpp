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
int Mex(int a1, int a2, int a3)
{
  int pos = 0;
  while(1)
  {
    if(pos != a1 && pos != a2 && pos != a3)
    	break;
    pos++;
  }
  
  return pos;
  
}

int grundy(int n)
{
  	if(n == 0)
      	return 0;
  	if(n == 1)
    	return 1;
  
  int a1 = grundy(n/2);
  int a2 = grundy(n/3);
  int a3 = grundy(n/6);
  
  return Mex(a1,a2,a3);
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


  	int n;
  	cin >> n;
  
 	cout << grundy(n) << endl;

	
	return 0 ; 

}



