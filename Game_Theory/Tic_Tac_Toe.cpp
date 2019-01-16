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

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input 

int player = 1;
int opponent = 2;

int depth(int b[3][3], int player)
{
	int count  = 0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(b[i][j] == player)
				count++;
		}
	}

	return count;
}


int evaluate(int b[3][3])
{
	//Checking for Rows for X or O victory
	for (int row = 0; row<3; row++) 
    { 
        if (b[row][0]==b[row][1] && 
            b[row][1]==b[row][2]) 
        { 
            if (b[row][0]==player) 
            {

                return 10 - depth(b,b[row][0]); 
            }
            else if (b[row][0]==opponent) 
                return -10 + depth(b,b[row][0]) ; 
        } 
    } 
  
    // Checking for Columns for X or O victory. 
    for (int col = 0; col<3; col++) 
    { 
        if (b[0][col]==b[1][col] && 
            b[1][col]==b[2][col]) 
        { 
            if (b[0][col]==player) 
                return +10 - depth(b,b[0][col]);  
  
            else if (b[0][col]==opponent) 
                return -10 + depth(b,b[0][col]); 
        } 
    } 
  
    // Checking for Diagonals for X or O victory. 
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2]) 
    { 
        if (b[0][0]==player) 
            return +10-depth(b,b[0][0]); 
        else if (b[0][0]==opponent) 
            return -10+depth(b,b[0][0]); 
    } 
  
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0]) 
    { 
        if (b[0][2]==player) 
            return +10-depth(b,b[0][2]); 
        else if (b[0][2]==opponent) 
            return -10+depth(b,b[0][2]); 
    } 
  
    // Else if none of them have won then return 0 
    return 0;
}

bool isMovesLeft(int board[3][3]) 
{ 
    for (int i = 0; i<3; i++) 
        for (int j = 0; j<3; j++) 
            if (board[i][j]==0) 
                return true; 
    return false; 
}

int minimax(int board[3][3],bool isMax)
{
	int score = evaluate(board);

	if(score != 0)
		return score;
	if (isMovesLeft(board)==false) 
        return 0;

	if(isMax == true) //Maximizers Turn
	{
		int best = INT_MIN;
		for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                // Check if cell is empty 
                if (board[i][j]==0) 
                { 
                    // Make the move 
                    board[i][j] = player; 
  
                    // Call minimax recursively and choose 
                    // the maximum value 
                    best = max( best, minimax(board, !isMax) ); 
  
                    // Undo the move 
                    board[i][j] = 0; 
                } 
            } 
        } 
        return best; 
	}

	else //Minimizers turn!
    { 
        int best = INT_MAX; 
  
        // Traverse all cells 
        for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                // Check if cell is empty 
                if (board[i][j]==0) 
                { 
                    // Make the move 
                    board[i][j] = opponent; 
  
                    // Call minimax recursively and choose 
                    // the minimum value 
                    best = min(best, minimax(board, !isMax)); 
  
                    // Undo the move 
                    board[i][j] = 0; 
                } 
            } 
        } 
        return best; 
    }


}

pii findBestMove(int board[3][3]) 
{ 
    int bestVal = INT_MIN;  //for player 1 who is a maximizer!
    pii bestMove; 
    bestMove.first = -1; 
    bestMove.second = -1; 
  
    for (int i=0; i<3; i++) 
    { 
        for (int j=0; j<3; j++) 
        { 
            // Check if cell is empty 
            if (board[i][j]==0) 
            { 
                // Make the move 
                board[i][j] = player; 
  
                //Now it is turn of opponent!
                int moveVal = minimax(board,false); 
  
                // Undo the move 
                board[i][j] = 0; 
  
                // If the value of the current move is 
                // more than the best value, then update 
                // best/ 
                if (moveVal > bestVal) 
                { 
                    bestMove.first = i; 
                    bestMove.second = j; 
                    bestVal = moveVal; 
                } 
            } 
        } 
    } 
  
    printf("The value of the best Move is : %d\n\n", bestVal); 
    return bestMove; 
} 


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int board[3][3] = 
    { 
        { 2,1,2 }, 
        { 1,1,2 }, 
        { 0,0,0 } 
    }; 
  
    pii bestMove = findBestMove(board); 
  
   	cout << "The Optimal Move is : " << endl;
    printf("ROW: %d COL: %d\n", bestMove.first, bestMove.second ); 

	return 0 ; 

}



