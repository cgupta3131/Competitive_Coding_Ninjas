#include<bits/stdc++.h>

using namespace std;



long long int modular = pow(10,9) + 7;


void multiply(long long int A[2][2], long long int M[2][2])
{	
	A[0][0] %= (modular - 1);
	A[0][1] %= (modular - 1);
	A[1][0] %= (modular - 1);
	A[1][1] %= (modular - 1);

	M[0][0] %= (modular - 1);
	M[0][1] %= (modular - 1);
	M[1][0] %= (modular - 1);
	M[1][1] %= (modular - 1);


	long long int first = ( A[0][0] * M[0][0] )% (modular - 1)  + ( A[0][1] * M[1][0] ) % (modular - 1); 	
	long long int second = ( A[0][0] * M[0][1] ) % (modular - 1) + ( A[0][1] * M[1][1] ) % (modular - 1); 
	long long int third = ( A[1][0] * M[0][0] ) % (modular - 1)+  ( A[1][1] * M[1][0] ) % (modular - 1); 
	long long int fourth = ( A[1][0] * M[0][1] ) % (modular - 1)  + ( A[1][1] * M[1][1] ) % (modular - 1); 

	A[0][0] = first % (modular - 1);
	A[0][1] = second % (modular - 1);
	A[1][0] = third % (modular - 1);
	A[1][1] = fourth % (modular - 1);
}


void power(long long int A[2][2] , long long int n)
{
	if(n <= 1)
		return;

	power(A,n/2);

	multiply(A,A);

	if(n%2 == 1) // if n is odd
	{
		long long int M[2][2] =  { {1,1},{1,0} };
		multiply(A,M);
	}
}

long long int fib_modulus(long long int n)
{
	long long int A[2][2] =  { {1,1},{1,0} };

	if(n == 0 )
		return 0;

	power(A,n-1);
	return A[0][0];
}

long long int Modular_Exp_Rec(long long int a, long long int b)
{
	if(b == 0)
		return 1;
	if(b == 1)
		return a% (modular);

	if(b%2 == 0) //if b is an even number
		return Modular_Exp_Rec( (a*a)% (modular) , (b/2) % (modular) ) % (modular);
	else
		return  ( ( a% (modular) ) * Modular_Exp_Rec( (a*a)% (modular) , (b/2) % (modular) ) ) % (modular) ;
}


long long int solve(long long int f0, long long int f1 , long long int n)
{
	//gn = fn + 1;
	long long int a = f0+1;
	long long int b = f1+1;

	long long int first = fib_modulus(n-1);
	long long int second = fib_modulus(n);

	long long int first_product = Modular_Exp_Rec(a,first)% (modular);
	long long int second_product = Modular_Exp_Rec(b,second)% (modular);

	return ( (first_product * second_product)% (modular) ) - 1;
}



int main()
{
	long long int t;
	cin >> t;

	while(t--)
	{
		long long int f0,f1,n;
		cin >> f0 >> f1 >> n;

		if(n == 0)
		{
			cout << f0 << endl;
			continue;
		}
		if(n == 1)
		{
			cout << f1 << endl;
			continue;
		}

		cout << solve(f0,f1,n) << endl; 

	}


	return 0 ; 

}

