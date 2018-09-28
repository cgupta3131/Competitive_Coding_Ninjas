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


int main()
{

	Triplet myAns = Extended_Euclid(12,5);
	cout << myAns.gcd << endl;
	cout << myAns.x << endl;
	cout << myAns.y << endl;

	return 0 ; 

}

