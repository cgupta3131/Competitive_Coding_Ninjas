#include<bits/stdc++.h>

using namespace std;

int count_set_bits(int n, int x)
{
	int num = 0;

	for(int i=0;i<n;i++)
		if( (x&(1<<i)) != 0) //means that ith bit is set
			num++;

	return num;
}

int solve(int n, int **input)
{	
	//Here (1,1,1) means that we don't have to assign any candies and
	//hence ways of doing it would be 1

	//(0,0,0) mask means that number of ways of assigning candies to all the
	//three persons!
	
	int size = pow(2,n);
	int *dp = new int[size];

	for(int i=0;i<size;i++)
		dp[i] = 0;
	
	dp[size-1] = 1;

	for(int mask = size-2;mask>=0;mask--)
	{
		int y = count_set_bits(n,mask);

		for(int i=0;i<n;i++)
		{
			if(input[y][i] == 1 && (mask&(1<<i)) == 0)
				dp[mask] += dp[mask| (1<<i)];
		}
	}

	return dp[0];
}

int main()
{
	int n;
	cin >> n;

	int **input = new int*[n];

	for(int i=0;i<n;i++)
		input[i] = new int[n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> input[i][j];

	cout << solve(n,input) << endl;


	return 0 ; 

}

