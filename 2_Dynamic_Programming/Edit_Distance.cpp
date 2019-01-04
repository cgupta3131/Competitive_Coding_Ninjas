#include<bits/stdc++.h>

using namespace std;


int helper(string s1, string s2, int m , int n, int **dp)
{
	if(m == 0)
		return n;
	if(n == 0)
		return m;

	int ans;

	if(dp[m][n] != -1)
		return dp[m][n];

	if(s1[0] == s2[0])
		ans = helper(s1.substr(1,m-1),s2.substr(1,n-1),m-1,n-1,dp);
	else
	{
		//Note that Insert could be easier than Replace as character could be inserted 
		//anywhere in the string and hence shifting the positions of the characters!!
		int option1 = helper(s1.substr(1,m-1),s2,m-1,n,dp); //Remove
		int option2 = helper(s1,s2.substr(1,n-1),m,n-1,dp); //Insert
		int option3 = helper(s1.substr(1,m-1),s2.substr(1,n-1),m-1,n-1,dp); //Replace

		ans = 1 + min(option1,min(option2,option3));

	}

	dp[m][n] = ans;
	return ans;
}


int editDistance(string s1, string s2)
{
	int m = s1.length();
	int n = s2.length();


	int **dp = new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		dp[i] = new int[n+1];

		for(int j=0;j<=n;j++)
			dp[i][j] = -1;
	}

	return helper(s1,s2,m,n,dp);

}



