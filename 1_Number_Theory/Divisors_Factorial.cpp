#include<bits/stdc++.h>
#include<vector>

using namespace std;


vector<long long int> *Primes_till_N(long long int n)
{
	bool *arr = new bool[n+1];

	for(long long int i=0;i<=n;i++)
		arr[i] = true;

	arr[0] = false;
	arr[1] = false;

	int x = int( sqrt(n) );

	for(int i=2;i<=x;i++)
	{
		if(arr[i] == false)
			continue;
		else
			for(int j=i*i ; j<=n ; j += i)
				arr[j] = false;
	}

	vector<long long int> *output = new vector<long long int>;
	for(long long int i=2;i<=n;i++)
		if(arr[i] == true)
			output->push_back(i);
	

	return output;

}

long long int Largest_Exponent_of_P_in_N_factorial(long long int n, long long int p)
{
	long long int number = 0;
	long long int x = 1;

	while(1)
	{
		long long int denominator = pow(p,x);
		number += n/denominator;

		if( (n/denominator) == 0)
			 break;

		x++;
	}

	return number;


}


long long int Number_of_Divisors(long long int n)
{
	vector<long long int> *primes = Primes_till_N(n);
	long long int m = pow(10,9) + 7;	
	long long int count = 1;



	for(long long int i=0;i<primes->size();i++)
	{
		long long int current_prime = primes->at(i);
		count *= ( Largest_Exponent_of_P_in_N_factorial(n,current_prime) + 1) % m;
		count = count % m;
	}

	return count;


}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		if(n == 0 || n == 1)
		{
			cout << 1 << endl;
			continue;
		}

		cout << Number_of_Divisors(n) << endl;

	}

	return 0 ; 

}

