#include<bits/stdc++.h>

using namespace std;


int Modular_Exp_Rec(int a, int b)
{
	int m = pow(10,9) +7;
	if(b == 0)
		return 1;
	if(b == 1)
		return a;

	if(b % 2 == 0) // i.e b is even number
		return  ( ( Modular_Exp_Rec( (a*a)%m ,  b/2) % m ) + m) % m;
	else
		return ((((a%m)* ( Modular_Exp_Rec((a*a)%m , (b-1)/2) % m ) ) % m ) + m ) % m ;
}

int Modular_Exp_Iter(int a, int b)
{
	int result = 1;
	int m = pow(10,9) +7;

	while(b > 0)
	{
		if(b % 2 == 1) //if b is odd
		{
			result *= a; 
			result = result % m;
		}

		b = b/2;
		a = (a*a) % m;

	}

	return (result+m)%m;

}


int main()
{

	int a,b;
	cin >> a >> b;
	cout << Modular_Exp_Rec(a,b) << endl;
	cout << Modular_Exp_Iter(a,b) << endl;
	return 0 ; 

}

