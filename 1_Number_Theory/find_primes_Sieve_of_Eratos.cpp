#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin >> n;

	bool *arr = new bool[n+1];

	for(int i=0;i<=n;i++)
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

	int count = 0;
	for(int i=2;i<=n;i++)
		if(arr[i] == true)
			count++;

	cout << count << endl;


	return 0 ; 

}

