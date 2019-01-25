#include<bits/stdc++.h>

using namespace std;

bool check_all_negative(int *arr, int n)
{	
	for(int i=0;i<n;i++)
		if(arr[i] > 0)
			return false;

	return true;	

}

//Finds the maximum subarray sum in an array!
int kadane(int *arr, int n)
{
	if(check_all_negative(arr,n) == true)
	{	
		int max = INT_MIN;
		for(int i=0;i<n;i++)
			if(arr[i] > max)
				max = arr[i];
		return max;
	}


	int current_sum = 0;
	int best_sum = 0;

	for(int i=0;i<n;i++)
	{
		if(current_sum < 0)
			current_sum = 0;
	
		current_sum += arr[i];
		if(current_sum > best_sum)
			best_sum = current_sum;
	}

	return best_sum;
}



int main()
{
	int R,C;
	cin >> R >> C;

	int arr[R][C];

	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			cin >> arr[i][j];

	//Best Sum could be negative also!
	int best_sum = INT_MIN;	

	for(int left=0;left<C;left++)
	{
		int *temp = new int[R];
		for(int i=0;i<R;i++)
			temp[i] = 0;

		for(int right=left;right<C;right++)
		{
			for(int i=0;i<R;i++)
				temp[i] += arr[i][right];

			int sum = kadane(temp,R);

			if(sum > best_sum)
				best_sum = sum;
		}

		delete []temp;

	}

	cout << best_sum << endl;



	return 0 ; 

}

