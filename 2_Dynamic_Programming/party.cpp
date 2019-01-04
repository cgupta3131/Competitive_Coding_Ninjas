#include<bits/stdc++.h>

using namespace std;


void solve(int n, int *fees, int *fun, int budget)
{
	//dp[n+1][budget+1]
	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++)
		dp[i] = new int[budget+1];

	for(int i=0;i<=budget;i++)
		dp[0][i] = 0;

	for(int i=0;i<=n;i++)
		dp[i][0] = 0;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=budget;j++)
		{
			if(j - fees[i-1] < 0)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				int option1 = dp[i-1][j];
				int option2 = dp[i-1][ j - fees[i-1] ] + fun[i-1];
				dp[i][j] = max(option1, option2);

			}
		}
	}
	int ans = dp[n][budget];
	int total_money = 0;

	for(int i=0;i<=budget;i++)
	{
		if(dp[n][i] == ans)
		{
			total_money = i;
			break;
		}

	}
	

	for(int i=0;i<=n;i++)
		delete [] dp[i];
	delete [] dp;

	cout << total_money << " " << ans << endl;

}


int main()
{
	while(1)
	{
		int budget;
		int number_of_parties;

		cin >> budget >> number_of_parties;

		if(budget == 0 && number_of_parties == 0)
			return 0;

		int fees[100];
		int fun[100];

		for(int i=0;i<number_of_parties;i++)
		{
			int first, second;
			cin >> first >> second;

			fees[i] = first;
			fun[i] = second;
		}

		solve(number_of_parties,fees,fun,budget);
	}

	return 0 ; 
}