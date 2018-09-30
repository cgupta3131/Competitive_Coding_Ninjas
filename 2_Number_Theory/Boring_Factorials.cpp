	/* Sameer and Arpit want to overcome their fear of Maths and so they have been
	recently practicing Maths problems a lot. Aman, their friend has been helping 
	them out. But as it goes, Sameer and Arpit have got bored of problems involving 
	factorials. Reason being, the factorials are too easy to calculate in problems 
	as they only require the residue modulo some prime and that is easy to calculate 
	in linear time. So to make things interesting for them, Aman - The Mathemagician,
	gives them an interesting task. He gives them a prime number P and an integer N 
	close to P, and asks them to find N! modulo P. He asks T such queries.  */



	#include<bits/stdc++.h>

	using namespace std;
		

	long long int product(long long int n, long long int p)
	{
		long long int answer = 1;
		long long int number = p-n-1;

		for(int i=0;i<number;i++)
		{
			long long int current_value = ( n + 1 + i );
			answer *= current_value%p;
			answer %= p;
		}

		return answer;
	}	

	long long int power(long long int x, long long int k, long long int m)
	{	
		if(k == 0)
			return 1;
		if(k == 1)
			return x;
		if(k%2 == 0) //if k is an even number!
			return power( (x*x) % m , k/2 , m  ) % m;
		else
			return ( (x%m) * power( (x*x) % m , k/2 , m  )%m ) %m;
	}

		


	int main()
	{
		int t;
		cin >> t;

		while(t--)
		{
			long long int n,p;
			cin >> n >> p;

			if(n >= p)
				cout << 0 << endl;
			else
			{
				if(n == p-1)
					cout << p-1 << endl;
				else
				{
					long long int x = product(n,p);
					long long int y = power(x,p-2,p); 

					cout << ( -1 * y ) + p << endl;
				}
			}

		}


		return 0 ; 

	}

