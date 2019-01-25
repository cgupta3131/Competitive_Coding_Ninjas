 	
#include<bits/stdc++.h>

using namespace std;

int* Length_Incr_SubSeq(int *input, int len)
{
	int *output = new int[len];
	output[0] = 1;

	for(int i=1;i<len;i++)
	{	
		output[i] = 1;
		for(int j=i-1;j>=0;j--)
		{
			if(input[j] >= input[i])
				continue;
			else
				if(output[i] < (output[j] + 1) )
					output[i] = output[j]+1;
		}

	}

	return output;

}

int * Length_Decr_SubSeq(int *input, int len)
{
	int *output = new int[len];
	for(int i=0;i<len;i++)
		output[i] = 1;

	for(int i=len-2;i>=0;i--)
	{
		for(int j = len-1;j>i;j--)
		{
			if(input[j] >= input[i])
				continue;
			else
				if(output[i] < (output[j]+1))
					output[i] = output[j]+1;
		}
	}

	return output;
}

int final_Answer(int *output1,int *output2, int n)
{

	int best = 0;
	for(int i=0;i<n;i++)
		if(  (output1[i] + output2[i] - 1) > best)
			best = (output1[i] + output2[i] - 1);

	return best;
}



int longestBitonicSubarray(int *input, int n) 
{
 	int *output1 = Length_Incr_SubSeq(input,n);
	int *output2 = Length_Decr_SubSeq(input,n); 
  
  	return final_Answer(output1,output2,n);
     	
     	
}




int main()
{
	int size;
	cin >> size;

	int *input = new int[size];

	for(int i=0;i<size;i++)
		cin >> input[i];

	cout << longestBitonicSubarray(input,size) << endl;

	return 0 ; 

}

