#include<bits/stdc++.h>

using namespace std;

// n <= 10000

int Knapsnack(int n, int *weights, int *values, int w_max,int **dp)
{
	if(w_max<0 || n == 0)
		return 0;
		
	if(dp[n][w_max] != -1)
		return dp[n][w_max];
	int ans;

	if(w_max-weights[0] < 0)
		ans=Knapsnack(n-1,weights+1,values+1,w_max,dp);
	else
		ans=max( Knapsnack(n-1,weights+1,values+1,w_max,dp),
			values[0]+Knapsnack(n-1,weights+1,values+1,w_max-weights[0],dp) );

	dp[n][w_max] = ans;
	return ans;

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

	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++)
		dp[i] = new int[w_max+1];

	for(int i=0;i<=n;i++)
		for(int j=0;j<=w_max;j++)
			dp[i][j] = -1;

	cout << Knapsnack(n, weights, values, w_max,dp) << endl;



	return 0 ; 

}

