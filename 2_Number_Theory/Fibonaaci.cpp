#include<bits/stdc++.h>

using namespace std;


void multiply(int A[2][2], int M[2][2])
{
	int first = A[0][0] * M[0][0] + A[0][1] * M[1][0]; 	
	int second = A[0][0] * M[0][1] + A[0][1] * M[1][1]; 
	int third = A[1][0] * M[0][0] + A[1][1] * M[1][0]; 
	int fourth = A[1][0] * M[0][1] + A[1][1] * M[1][1]; 

	A[0][0] = first;
	A[0][1] = second;
	A[1][0] = third;
	A[1][1] = fourth;
}


void power(int A[2][2] , int n)
{
	if(n <= 1)
		return;

	power(A,n/2);

	multiply(A,A);

	if(n%2 == 1) // if n is odd
	{
		int M[2][2] =  { {1,1},{1,0} };
		multiply(A,M);
	}



}

int fib(int n)
{
	int A[2][2] =  { {1,1},{1,0} };

	if(n == 0 )
		return 0;

	power(A,n-1);
	return A[0][0];
}


int main()
{

	int n;
	cin >> n;
	cout << fib(n) << endl;

	return 0 ; 

}

