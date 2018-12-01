#include<bits/stdc++.h>

using namespace std;

int Number_of_Changes(int n, int k, int *den) // Non-DP way
{
	if(n == 0)
		return 1;
	if(n < 1 || k == 0)
		return 0;

	int first = Number_of_Changes(n-den[k-1],k,den); 
	//If we choose den[k-1] once

	int second = Number_of_Changes(n,k-1,den);
	//If we don't choose den[k-1] at all

	return first + second;
}

int Number_of_Changes_DP(int n, int k, int *den, int **output) // DP way
{
	if(n == 0)
		return 1;
	if(n < 1 || k == 0)
		return 0;

	if(output[n][k] != -1)
		return output[n][k];

	int first = Number_of_Changes_DP(n-den[k-1],k,den,output);
	int second = Number_of_Changes_DP(n,k-1,den,output);

	output[n][k] = first+second;
	return first + second;

}




int main()
{
	int n;
	cin >> n;
	int k; //number of denominations
	cin >> k;

	int *den = new int[k];
	for(int i=0;i<k;i++)
		cin >> den[i];

	int **output = new int*[n+1]; //n+1 rows;

	for(int i=0;i<=n;i++)
		output[i] = new int[k+1]; //k+1 columns

	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
			output[i][j] = -1;

	//cout << Number_of_Changes(n,k,den) << endl;
	cout << Number_of_Changes_DP(n, k, den,output) << endl;

	return 0 ; 

}

