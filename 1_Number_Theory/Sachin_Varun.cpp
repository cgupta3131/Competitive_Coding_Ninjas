/*  Varun and you are talking about a movie that you have recently watched while 
Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to you 
and asked him to answer his question in order to save himself from punishment. 

The question says:
Given two weights of a and b units, in how many different ways you can achieve a 
weight of d units using only the given weights? Any of the given weights can be used 
any number of times (including 0 number of times). Since Varun is not able to answer
the question, he asked you to help him otherwise he will get punished.

Note: Two ways are considered different if either the number of times a is 
used or number of times b is used is different in the two ways.  */
#include<bits/stdc++.h>

using namespace std;

class Triplet
{
public:
	long long int gcd;
	long long int x;
	long long int y;
};


Triplet Extended_Euclid(long long int a, long long int b) // assuming a>b
{
	if(b == 0)
	{
		Triplet myAns;
		myAns.gcd = a;
		myAns.x = 1;
		myAns.y = 0;

		return myAns;
	}


	Triplet smallAns = Extended_Euclid(b,a%b);

	Triplet myAns;

	myAns.gcd = smallAns.gcd;
	myAns.x = smallAns.y;
	myAns.y = smallAns.x - (a/b)*smallAns.y;

	return myAns;

}

long long int ModInverse(long long int A, long long int M)
{
	long long int myAns = Extended_Euclid(A,M).x;
	return (myAns%M + M)%M; //if myAns is negative!
	
}

long long int solve(long long int a, long long int b, long long int d) 
{

	long long int y1 = ( (d%a) * ModInverse(b,a) ) % a;
	long long int y2 = (d/b) % a;

	if(d < y1*b)
		return 0;

	long long int n = ( (d/b) - y1 ) / a;
	return n+1; 
}


int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{

		long long int A,B,D;
		cin >> A >> B >> D;

		if(D == 0)
		{
			cout << 1 << endl;
			continue;
		}
		Triplet myAns = Extended_Euclid(A,B);
		long long int g = myAns.gcd;

		if(D%g != 0)
		{
			cout << 0 << endl;
			continue;
		}

		A = A/g;
		B = B/g;
		D = D/g;

		cout << solve(A,B,D) << endl;


	}

	return 0 ; 

}



