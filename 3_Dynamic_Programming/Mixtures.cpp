#include<bits/stdc++.h>

using namespace std;


int minSmoke(int *arr, int **dp, int i, int j)
{
	if(i == j)
		return 0;

	if(dp[i][j] != -1)
	{
		//cout << "Overlapping" << endl;
		return dp[i][j];
	}

	int min_smoke = INT_MAX;
	int left_sum = 0;
	int right_sum = 0;

	for(int k=i;k<j;k++)
	{
		right_sum += arr[k];
		right_sum %= 100;
	}

	left_sum += arr[i-1];
	//cout << left_sum << " " << right_sum << endl;

	for(int k=i;k<j;k++)
	{
		int possible_ans =  minSmoke(arr,dp,i,k) + minSmoke(arr,dp,k+1,j) + 
							left_sum*right_sum;

		left_sum += arr[k];
		left_sum %= 100;

		right_sum -= arr[k];
		right_sum %= 100;					
		
		if(right_sum < 0)
			right_sum += 100;	
		//cout << left_sum << " " << right_sum << endl;				
		//cout << i << " " << j << " " << possible_ans << endl;		
		if(min_smoke > possible_ans)
			min_smoke = possible_ans;
	}		

	dp[i][j] = min_smoke;
	return min_smoke;
}


int main()
{
	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];

	int **dp = new int*[n+1];

	for (int i = 0; i <=n; i++)
		dp[i] = new int[n+1];

	for (int i = 0; i <=n; i++)
		for (int j = 0; j <=n; j++)
			dp[i][j] = -1;

	cout << minSmoke(arr,dp,1,n) << endl;


	return 0 ; 

}

