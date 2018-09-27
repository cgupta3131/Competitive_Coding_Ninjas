#include<bits/stdc++.h>

using namespace std;


int gcd(int a, int b) // assuming a>b
{
	if(b == 0)
		return a;

	return gcd(b,a%b); //Applying Euclid's Algorithm!
}


int main()
{
	int a,b;
	cin >> a >> b;


	int x = max(a,b);
	int y = min(a,b);
	cout << gcd(x,y) << endl;
	return 0 ; 

}

