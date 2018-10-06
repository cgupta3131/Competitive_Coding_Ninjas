#include<bits/stdc++.h>

using namespace std;


int Length_Incr_SubSeq(int *input, int len)
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

	int best = 0;

	for(int i=0;i<len;i++)
		if(best < output[i])
			best = output[i];

	delete [] output;
	return best;

}




int main()
{
	int input[] = {2,1,3,4};

	int size = sizeof(input)/sizeof(input[0]);


	return 0 ; 

}

