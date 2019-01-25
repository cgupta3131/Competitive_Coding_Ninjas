#include<bits/stdc++.h>

using namespace std;

int Subset_Sum(int n, int *input, int *values, int k)
{
	int *output = new int[k+1];
	int *helper = new int[k+1];

	for(int i=0;i<=k;i++)
		output[i] = 0;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(j - input[i-1] >= 0)
				helper[j] = max(output[j], values[i-1] + output[j - input[i-1]] );
			else
				helper[j] = output[j];		
		}

		for(int j=0;j<=k;j++)
			output[j] = helper[j];
	}

	return output[k];
}


int main()
{
	int n;
	cin >> n;

	int *input = new int[n];
	int *helper_array = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
		helper_array[i] = input[i];
	}

	int k;
	cin >> k;


	if( Subset_Sum(n, input, helper_array, k) == k )
		cout << "Yes" << endl;
	else
		cout << "No" << endl;	

	return 0 ; 

}

