#include<bits/stdc++.h>
typedef long long int ll;

using namespace std;


ll gcd(ll a, ll b) //assuming a>b
{
	if(b == 0)
		return a;

	return gcd(b,a%b);

}


void Solve_LCM_SUM(ll n)
{
	ll sum = n;

	for(ll i=2;i<=n;i++)
	{
		ll product = n*i;
		sum += product/gcd(n,i);
	}

	cout << sum << endl;

}



int main()
{
	ll n;
	cin >> n; 

	Solve_LCM_SUM(n);


	return 0 ; 

}

