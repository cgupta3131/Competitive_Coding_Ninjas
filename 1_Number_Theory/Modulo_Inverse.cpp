#include<bits/stdc++.h>

using namespace std;

class Triplet
{
public:
	int gcd;
	int x;
	int y;
};


Triplet Extended_Euclid(int a, int b) // assuming a>b
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

void ModInverse(int A, int M)
{
	Triplet myAns = Extended_Euclid(A,M);
	cout << "Multiplicative Modulo Inverse of " << A << " is : " << myAns.x << endl; 
}


int main()
{
	int A,M;
	cin >> A >> M;
	ModInverse(A,M);


	return 0 ; 

}

