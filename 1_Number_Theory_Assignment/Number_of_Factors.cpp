/*A number is called n-factorful if it has exactly n distinct prime factors.
Given positive integers a, b, and n, your task is to find the number of 
integers between a and b, inclusive, that are n-factorful. We consider 1
to be 0-factorful.  */


#include<bits/stdc++.h>

using namespace std;

vector<long int> *Primes_till_N(long int n)
{
	bool *arr = new bool[n+1];

	for(long int i=0;i<=n;i++)
		arr[i] = true;

	arr[0] = false;
	arr[1] = false;

	long int x = int( sqrt(n) );

	for(long int i=2;i<=x;i++)
	{
		if(arr[i] == false)
			continue;
		else
			for(long int j=i*i ; j<=n ; j += i)
				arr[j] = false;
	}

	vector<long int> *output = new vector<long int>;
	for(long int i=2;i<=n;i++)
		if(arr[i] == true)
			output->push_back(i);
	
	delete []arr;

	return output;
}


long int *PreComputation_Array()
{
	long int *preComp_arr = new long int[1000001];
	for(long int i=0;i<1000001;i++)
		preComp_arr[i] = 0;

	vector<long int> *primes = Primes_till_N(pow(10,6));

	for(long int i=0;i<primes->size();i++)
	{
		int current_prime = primes->at(i);
		int temp = current_prime;

		while( temp <= pow(10,6) )
		{
			preComp_arr[temp]++;
			temp += current_prime;
		}
	}
	

	return preComp_arr;
}


int main()
{
	long int t;
	cin >> t;

	long int *preComp_arr = PreComputation_Array();
	while(t--)
	{
		long int a,b,n;
		cin >> a >> b >> n;

		long int count = 0;
		for(long int i=a;i<=b;i++)
			if(preComp_arr[i] == n)
				count++;
		cout << count << endl;
	}


	return 0 ; 

}

