#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;	
typedef set<int> seti;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007

/*  1 is my maximizer and 2 is my minimizer!! */

/*  Will return a vector of pair<int,int> denoting the possible moves possible wrt
the current status of board for player  */
int **makeAMove(int **board, int &x, int &y, int player, bool isCheck);

vector<pii *> *possibleMoves(int **board , int player)
{
	vector<pii *> *output = new vector<pii *>();

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(board[i][j] == 0)
			{
				if(makeAMove(board,i,j,player,true))
				{
					pair<int, int> *p = new pair<int,int>(i,j);
					output->pb(p);
				}
			}
		}
	}

	return output;

}

int evaluateBoard(int **board, bool& completed)
{
	if(possibleMoves(board,1)->size() != 0 || possibleMoves(board,2)->size() != 0)
	{
		completed = false;
		return 0;
	}

	completed = true;
	int count[3] = {};
	/*  0 represents no othello is placed
	1 represents white othello is placed
	2 represents black othello is placed  */

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			count[board[i][j]]++;

	return count[1] - count[2];
}

/*  If isCheck = true, that this function won't make changes to the board and will
just check if a move can be made
else, it will return the new board after making the move at (x,y) position on the board
and will return the new board  */

int **makeAMove(int **board, int &x, int &y, int player, bool isCheck)
{
	int **newBoard;

	if(isCheck == true)
		newBoard = board;
	else
	{
		newBoard = new int*[4];
		for(int i=0;i<4;i++)
		{
			newBoard[i] = new int[4];
			for(int j=0;j<4;j++)
				newBoard[i][j] = board[i][j];
		}

	}

	if(x<0 || x>=4 || y<0 | y>=4 || board[x][y] != 0)
		return NULL;

	int xDir[] = {-1,-1,0,1,1, 1, 0,-1};
	int yDir[] = { 0, 1,1,1,0,-1,-1,-1};

	bool movePossible = false;	
	for(int i=0;i<8;i++)
	{
		int xStep = xDir[i];
		int yStep = yDir[i];
		int currentX = x + xStep;
		int currentY = y + yStep;
		int count = 0;

		while(currentX >=0 && currentX<4 && currentY >=0 && currentY <4)
		{
			if(newBoard[currentX][currentY] == 0)
				break;
			else if(newBoard[currentX][currentY] != player)
			{
				currentX += xStep;
				currentY += yStep;
				count++;
			}
			else
			{
				if(count > 0)
				{
					movePossible = true;
					if(isCheck == true)
						return newBoard;

					int convertX = currentX - xStep;
					int convertY = currentY - yStep;

					while(convertX != x || convertY != y)
					{
						newBoard[convertX][convertY] = player;
						convertX -=  xStep;
						convertY -=  yStep;
					}

					newBoard[x][y] = player;
				}

				break;
			}
		}
	}

	if(movePossible == true)
		return newBoard;
	else
		return NULL;
}

void printBoard(int** board) {
	for (int i = 0 ; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}


int findNextStep(int **board, bool maximizerTurn, int &x, int &y)
{
	bool completed;
	int score = evaluateBoard(board,completed);
	//printBoard(board);
	if(completed == true)
		return score;

	int player = maximizerTurn? 1 : 2;

	vector<pii *> *options = possibleMoves(board,player);

	if(options->size() == 0) //He can't move anywhere
	{
		x = -1;
		y = -1;
		int dummyX, dummyY;
		return findNextStep(board, !maximizerTurn, dummyX, dummyY);

	}

	int best =  maximizerTurn? INT_MIN : INT_MAX;

	for(int i=0;i<options->size();i++)
	{
		int currentMoveX = options->at(i)->first;
		int currentMoveY = options->at(i)->second;

		int **newBoard = makeAMove(board, currentMoveX, currentMoveY, player, false);

		int dummyX, dummyY;
		int score = findNextStep(newBoard, !maximizerTurn, dummyX, dummyY);

		best = maximizerTurn? max(best,score) : min(best,score);

		if(best == score)
		{
			x = currentMoveX;
			y = currentMoveY;
		}

		for(int i=0;i<4;i++)
			delete [] newBoard[i];
		delete [] newBoard;
	}


	return best;

}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int **a = new int*[4];

    for(int i=0;i<4;i++)
    {
    	a[i] = new int[4];
    	for(int j=0;j<4;j++)
    		a[i][j] = 0;
    }

    a[1][1] = 1;
    a[2][2] = 1;
    a[1][2] = 2;
    a[2][1] = 2; 

    int x,y;

    cout << findNextStep(a,true,x,y) <<endl;
    cout << x << " " << y << endl;

	
	return 0 ; 

}



