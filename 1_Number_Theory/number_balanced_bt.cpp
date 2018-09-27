#include<bits/stdc++.h>

using namespace std;

int balancedBTs(int h)
{
	long int m = 1000000007;
	if(h == 1)
		return 1;
	if(h == 2)
		return 3;

	int x = balancedBTs(h-1);
	int y = balancedBTs(h-2);


	return  (  ( (x%m)*(x%m) )%m + ( 2* (x%m) * (y%m) )%m  )%m;

}


int main()
{
	int h;
	cin >> h;
	

	cout << balancedBTs(h) << endl;

	return 0 ; 

}

