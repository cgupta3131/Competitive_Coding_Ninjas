#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;


int main()
{
	ll n;
	cin >> n;

	bool *arr = new bool[n+1];

	for(ll i=0;i<=n;i++)
		arr[i] = true;

	arr[0] = false;
	arr[1] = false;

	ll x = int( sqrt(n) );

	for(ll i=2;i<=x;i++)
	{
		if(arr[i] == false)
			continue;
		else
			for(ll j=i*i ; j<=n ; j += i)
				arr[j] = false;
	}

	ll count = 0;
	for(ll i=2;i<=n;i++)
		if(arr[i] == true)
			count++;

	cout << count << endl;


	return 0 ; 

}

