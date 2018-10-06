#include<bits/stdc++.h>

using namespace std;


int Length_Incr_SubSeq(int *input, int len, int element)
{
	if(len == 1)
		return 1;

	//If I don't choose the last element!
	int output1 = Length_Incr_SubSeq(input,len-1,element); 

	int output2 = 0;
	// If I choose the last element but comparision was with INT_MAX
	if(element == INT_MAX && input[len-1] < element)
		output2 = Length_Incr_SubSeq(input,len,input[len-1]);

	//If I choose the last element but comparison wasn't with INT_MAX
	else  if(element != INT_MAX && input[len-2] < element)
		output2 = 1+Length_Incr_SubSeq(input,len-1,input[len-2]);

	return max(output1,output2);
}




int main()
{
	int input[] = {2,1,3,4};

	int size = sizeof(input)/sizeof(input[0]);


	return 0 ; 

}

