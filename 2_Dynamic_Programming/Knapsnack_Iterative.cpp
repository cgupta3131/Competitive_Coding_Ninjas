#include<bits/stdc++.h>

using namespace std;

// n <= 10000
int Knapsnack(int n, int *weights, int *values, int w_max)
{
	//dp[n+1][w_max+1]
	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++)
		dp[i] = new int[w_max+1];

	for(int i=0;i<=n;i++)
		for(int j=0;j<=w_max;j++)
			dp[i][j] = -1;

	for(int i=0;i<=w_max;i++)
		dp[0][i] = 0;

	for(int i=0;i<=n;i++)
		dp[i][0] = 0;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w_max;j++)
		{
			if(j - weights[i-1] < 0)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max( dp[i-1][j] , dp[i-1][ j - weights[i-1] ] + values[i-1]);
		}
	}
	int ans = dp[n][w_max];

	for(int i=0;i<=n;i++)
		delete [] dp[i];
	delete [] dp;

	return ans;

}

// Here because n has a max value of 10^4 and w has a max value of 100, and therefore
// 2D array could not have 10^6 ! Hence we take the benefit of the fact that dp[i][j]
// is always somehow related to some element of (i-1)th row! And hence we use 
// helper and output array of size (w_max+1)
int Knapsnack2(int n, int *weights, int *values, int w_max)
{
	int *output = new int[w_max+1];
	int *helper = new int[w_max+1];

	for(int i=0;i<=w_max;i++)
		output[i] = 0;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w_max;j++)
		{
			if(j - weights[i-1] >= 0)
				helper[j] = max(output[j], values[i-1] + output[j - weights[i-1]] );
			else
				helper[j] = output[j];		
		}

		for(int j=0;j<=w_max;j++)
			output[j] = helper[j];
	}

	return output[w_max];

}

int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	for(int i=0;i<n;i++)
		cin >> weights[i];

	int *values = new int[n];
	for(int i=0;i<n;i++)
		cin >> values[i];

	int w_max;
	cin >> w_max;

	cout << Knapsnack2(n, weights, values, w_max) << endl;



	return 0 ; 

}

