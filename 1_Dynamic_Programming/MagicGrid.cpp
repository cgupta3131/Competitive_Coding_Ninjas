#include<bits/stdc++.h>

using namespace std;


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int R,C;
		cin >> R >> C;

		int **arr = new int*[R];
        for(int i = 0; i < R; i++)
        {
            arr[i] = new int[C];
            for(int j = 0; j < C; j++) 
            	cin >> arr[i][j];
        }

        int **helper = new int*[R];
        for(int i = 0; i < R; i++)
            helper[i] = new int[C];

		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				helper[i][j] = 0;

		helper[R-1][C-1] = 1;	

		for(int k=R-2;k>=0;k--)
		{
			helper[k][C-1] = helper[k+1][C-1] - arr[k][C-1];

			if(helper[k][C-1] <= 0)
				helper[k][C-1] = 1;
		}

		for(int k=C-2;k>=0;k--)
		{
			helper[R-1][k] = helper[R-1][k+1] - arr[R-1][k];

			if(helper[R-1][k] <= 0)
				helper[R-1][k] = 1;
		}

		for(int i = R-2; i >= 0; i--)
        {
            for(int j = C-2; j >= 0; j--)
            {
            	int currOutput = min(helper[i+1][j],helper[i][j+1]);

            	helper[i][j] = currOutput - arr[i][j];

            	if(helper[i][j] <=0 )
            		helper[i][j] = 1;
            }
        }

		cout << helper[0][0] << endl;
	}

	return 0;
}

