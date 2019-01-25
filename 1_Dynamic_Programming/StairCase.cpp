#include<bits/stdc++.h>

using namespace std;

long Solve_Iteratively(int n)
{
	long *arr = new long[n+1];
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;


	for(int i=3;i<=n;i++)
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];

	return arr[n];
}

long Solve_Recursively(int n, long *arr)
{
	if(n == 0 || n == 1)
		return 1;
	if(n == 2)
		return 2;

	if(arr[n] != 0)
		return arr[n];

	long answer1 = Solve_Recursively(n-1,arr);
	long answer2 = Solve_Recursively(n-2,arr);
	long answer3 = Solve_Recursively(n-3,arr);
	arr[n] = answer1 + answer2 + answer3;

	return answer1 + answer2 + answer3;
}



int main()
{
	int n;
	cin >> n;

	long *arr = new long[n+1];
	for(int i=0;i<=n;i++)
		arr[i] = 0;

	//cout << Solve_Iteratively(n) << endl;
	cout << Solve_Recursively(n,arr) << endl;

	return 0 ; 

}

