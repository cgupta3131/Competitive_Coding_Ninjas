#include<bits/stdc++.h>

using namespace std;

void multiply(unsigned long long A[2][2], unsigned long long M[2][2])
{
	A[0][0] %= 1000000007;
	A[0][1] %= 1000000007;
	A[1][0] %= 1000000007;
	A[1][1] %= 1000000007;

	M[0][0] %= 1000000007;
	M[0][1] %= 1000000007;
	M[1][0] %= 1000000007;
	M[1][1] %= 1000000007;

	unsigned long long first = ( A[0][0] * M[0][0] ) %1000000007  + ( A[0][1] * M[1][0] ) %1000000007; 	
	unsigned long long second = ( A[0][0] * M[0][1] ) %1000000007 + ( A[0][1] * M[1][1] ) %1000000007; 
	unsigned long long third = ( A[1][0] * M[0][0] ) %1000000007 +  ( A[1][1] * M[1][0] ) %1000000007; 
	unsigned long long fourth = ( A[1][0] * M[0][1] ) %1000000007 + ( A[1][1] * M[1][1] ) %1000000007; 

	A[0][0] = first%1000000007;
	A[0][1] = second%1000000007;
	A[1][0] = third%1000000007;
	A[1][1] = fourth%1000000007;
}

void power(unsigned long long A[2][2] , unsigned long long n)
{
	if(n <= 1)
		return;

	power(A,n/2);

	multiply(A,A);

	if(n%2 == 1) // if n is odd
	{
		unsigned long long M[2][2] =  { {1,1},{1,0} };
		multiply(A,M);
	}



}

unsigned long long fib(unsigned long long n)
{
	unsigned long long A[2][2] =  { {1,1},{1,0} };

	if(n == 0 )
		return 0;

	power(A,n-1);
	return A[0][0]%1000000007;
}


unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{

	unsigned long long first = fib(m+2);
	unsigned long long second = fib(n+1);
	return ( first - second );

}



int main()
{
	unsigned long long n,m;
	cin >> n >> m;

	cout << fiboSum(m,n) << endl; 


	return 0 ; 

}

