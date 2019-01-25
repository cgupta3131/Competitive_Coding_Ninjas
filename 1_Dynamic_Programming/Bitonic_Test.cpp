 	
#include<bits/stdc++.h>

using namespace std;

class forArray
{
public:
	int data;
	int index;

};

forArray* Length_Incr_SubSeq(int *input, int len)
{
	forArray *output = new forArray[len];
	output[0].data = 1;
	output[0].index = 0;
 
	for(int i=1;i<len;i++)
	{	
		output[i].data = 1;
		output[i].index = i;
 		for(int j=i-1;j>=0;j--)
		{
			if(input[j] >= input[i])
				continue;
			else
				if(output[i].data < (output[j].data + 1) )
				{
					output[i].data = output[j].data + 1;
					output[i].index = output[j].index;
				}
		}

	}

	return output;

}


forArray* Length_Decr_SubSeq(int *input, int len)
{
	forArray *output = new forArray[len];
	output[0].data = 1;
	output[0].index = 0;
 
	for(int i=1;i<len;i++)
	{	
		output[i].data = 1;
		output[i].index = i;
 		for(int j=i-1;j>=0;j--)
		{
			if(input[j] <= input[i])
				continue;
			else
				if(output[i].data < (output[j].data + 1) )
				{
					output[i].data = output[j].data + 1;
					output[i].index = output[j].index;
				}
		}

	}

	return output;

}


int final_Answer(forArray *increasing, forArray *decreasing,int  size)
{	
	int best = 1;

	for(int i=0;i<size;i++)	
	{
		for(int j=i+1;j<size;j++)
		{
			if(decreasing[j].index == i)
			{
				if( (increasing[i].data+decreasing[j].data-1) > best     )
					best = increasing[i].data+decreasing[j].data-1;
			}


		}
	}

	int best_inc = 0;

	for(int i=0;i<size;i++)
		if(best < increasing[i].data)
			best = increasing[i].data;

	int best_dec = 0;

	for(int i=0;i<size;i++)
		if(best < decreasing[i].data)
			best = decreasing[i].data;

	int temp = 0;
	for(int i=0;i<size;i++)
		if( (increasing[i].data+decreasing[i].data-1) > temp   )
					temp = increasing[i].data+decreasing[i].data-1;

	return temp;

	return max(best,max(best_inc,best_dec));


}


int longestBitonicSubarray(int *input, int n) 
{
 	forArray *output1 = Length_Incr_SubSeq(input,n);
	forArray *output2 = Length_Decr_SubSeq(input,n); 
  
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

	/*  for(int i=0;i<size;i++)
		cout << output1[i].data << " " << output1[i].index << endl;
	cout << endl << endl;
	for(int i=0;i<size;i++)
		cout << output2[i].data << " " << output2[i].index << endl;  */




	return 0 ; 

}

