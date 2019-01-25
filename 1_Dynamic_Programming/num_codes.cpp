#include<bits/stdc++.h>

using namespace std;

int num_codes(int *input, int size)
{
	if(size == 1)
		return 1;

	if(size == 0)
		return 1; //empty string

	int output = num_codes(input,size-1);

	if(input[size-2]*10 + input[size-1] <= 26)
		output += num_codes(input,size-2); //this we don't have to do always!

	return output;
}


int num_codes2(int *input, int size, int *arr)
{
	if(size == 1)
		return 1;

	if(size == 0)
		return 1; //empty string

	if(arr[size] > 0)
		return arr[size];

	int output = num_codes2(input,size-1,arr);

	if(input[size-2]*10 + input[size-1] <= 26)
		output += num_codes2(input,size-2,arr); //this we don't have to do always!

	arr[size] = output;

	return output;
}


int num_codes_iter(int *input, int size)
{
	int *output = new int[size+1];
	output[0] = 1;
	output[1] = 1;

	for(int i=2;i<=size;i++) 
	{
		output[i] += output[i-1];
		if(( input[i-2]*10 + input[i-1]) <= 26)
			output[i] += output[i-2];
	}

	int ans = output[size];
	delete [] output;

	return ans;

}


int main()
{
	int input[50];

	for(int i=0;i<50;i++)
	{
		if(i%2 == 0)
			input[i] = 1;
		else
			input[i] = 2;
	}

	int size = sizeof(input)/sizeof(int);
	int *arr = new int[size+1];

	for(int i=0;i<=size;i++)
		arr[i] = 0;

	cout << num_codes2(input, size,arr) << endl;


	return 0 ; 

}

