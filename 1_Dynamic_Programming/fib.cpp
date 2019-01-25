#include<bits/stdc++.h>

using namespace std;

int fib1(int n)
{
	if(n == 0 || n == 1)
		return 1;

	return fib1(n-1) + fib1(n-2); 
}

/*  Here we are maintainging an array arr which in initiazed with 0, and then 
whenever we are getting an answer for any fibonaaci number we are just 
storing it's value in arr[i]. Now if we require fib(i), again we won't
compute it but just take the value from the array! Hence saving a hell
lot of time! So total complexity would be reduced to O(n) as '2n' calls
would be made!  */

int fib2(int n, int *arr) //fibonacci with Dynamic Programming
{
	if(n==0 || n ==1)
		return 1;

	if(arr[n] > 0)
		return arr[n];

	int output = fib2(n-1,arr) + fib2(n-2,arr);
	arr[n] = output;

	return output;

}


int fib_Iter(int n)
{
	int *arr = new int[n+1];
	arr[0] = 1;
	arr[1] = 1;

	for(int i=2;i<=n;i++)
		arr[i] = arr[i-1] + arr[i-2];

	int temp = arr[n];

	delete [] arr;
	return temp;

}

int main()
{	
	int n;
	cin >> n;

	int *arr = new int[n+1]; 
	for(int i=0;i<=n;i++)
		arr[i] = 0;

	cout << fib2(n,arr) << endl;

	return 0 ; 

}

