/*  A cube free number is a number who’s none of the divisor is a cube number 
(A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). 
So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 
etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. 
So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3
and position of 10 is 9. Given a positive number you have to say if its a cube free 
number and if yes then tell its position among cube free numbers.
  */


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

class Pair{
public:
	bool first;
	long long int second;

};


Pair *arr_max(long int n)
{
	long int x = int( cbrt(n) );
	vector<long int> *output = Primes_till_N(x);

	Pair *arr = new Pair[n+1];
	for(long int i=0;i<=n;i++)
		arr[i].first = true; // true implies that it is Cube-Free-Number

	for(long int i=0;i<output->size();i++)
	{
		long int div = pow(output->at(i),3);		
		long int temp = div;

		while(div <= n)
		{	
			if(arr[div].first == true)
				arr[div].first =  false; // Not a cube-Free-Number

			div += temp;
		}
	}

	int count = 0;
	for(long int i=1;i<n+1;i++)
	{
		long int position = i;

		if(arr[i].first == true)
			arr[i].second = position - count;
		else
		{
			count++;
			arr[i].second = -1; //No position can be assigned
		}
	}

	return arr;

}


int main()
{
	long int t;
	cin >> t;
	int max = INT_MIN;
	vector<long int> testcases;
	for(long int i=0;i<t;i++)
	{	
		long int n;
		cin >> n;
		testcases.push_back(n);

		if(n > max)
			max = n;
	}

	Pair *arr = arr_max(max);
	for(long int i=0;i<t;i++)
	{
		cout << "Case " << i+1 << ": ";
		int x = testcases.at(i);

		if(arr[x].first == false)
			cout << "Not Cube Free" << endl;
		else
			cout << arr[x].second << endl;
	}


	return 0 ; 

}

