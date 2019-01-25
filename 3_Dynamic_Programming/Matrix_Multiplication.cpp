#include<bits/stdc++.h>

using namespace std;

int matrixMultiply(int*arr, int **dp, int i, int j)
{
	if(i == j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int minCost = INT_MAX;
	for(int k=i;k<j;k++)
	{
		int possibleAns = matrixMultiply(arr,dp,i,k) + matrixMultiply(arr,dp,k+1,j) + 
							arr[i-1]*arr[k]*arr[j];

		if(possibleAns < minCost)
			minCost = possibleAns;
	}

	dp[i][j] = minCost;
	return minCost;
}

int main()
{
	int n;
	cin >> n;

	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int **dp = new int*[n];

	for (int i = 0; i <n; i++)
		dp[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = -1;

	int cost = matrixMultiply(arr,dp,1,n-1);

	cout << cost << endl;

	return 0 ; 

}

