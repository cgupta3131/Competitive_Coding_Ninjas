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


		int a=1;

		while(1)
		{
			if(R-1-a == 0 && C-1-a == 0)
				break;

			for(int k=R-1-a;k>=0;k--)
			{
				int right = helper[k][C-a];
				int down = helper[k+1][C-1-a];

				int minimum = min(right,down);
				helper[k][C-1-a] = minimum - arr[k][C-1-a];

				if(helper[k][C-1-a] <= 0)
					helper[k][C-1-a] = 1;
			}


			for(int k=C-1-a;k>=0;k--)
			{
				int right = helper[R-1-a][k+1];
				int down = helper[R-a][C-1-a];

				int minimum = min(right,down);
				helper[R-1-a][k] = minimum - arr[R-a-1][k];

				if(helper[R-1-a][k] <= 0)
					helper[R-1-a][k] = 1;
			}

			
			if(R-1-a == 0 || C-1-a == 0)
				break;
			a++;
		}
		
		cout << min(helper[0][1],helper[1][0]) << endl;
		
	}

	return 0;

}

