#include <iostream>
#include <vector>
using namespace std;

/*
    // Next Diagonal element of board[i][j] is board[i+1][j+1]

    EX:
        -> Possible solution
            |__|__|Q3|__|
            |Q1|__|__|__|
            |__|__|__|Q4|
            |__|Q2|__|__|

            |__|Q2|__|__|
            |__|__|__|Q4|
            |Q1|__|__|__|
            |__|__|Q3|__|
        -> Output:
            [[".Q..","...Q","Q...","..Q."],
            ["..Q.","Q...","...Q",".Q.."]]


*/

// Store board of all the possible solution
vector<vector<string>> allBoard;

// 'isSafe' function will check does it will safe to place Queen in the given place
int safe(int row, int col, vector<string> &board)
{
    // Checking horizontal line
}

// Recursive function to solve nQueens problem
void rec(vector<string> board, int col)
{
    // Base condition:
    // if column is at the end of column
    // col == size of column in board
    // in that case we will put the board that get solved in the 'allBoard' that contain all the possible solution
    if (col == board.size())
    {
        allBoard.push_back(board);
        return;
    }

    // Now we will put queen into the row 0 on possible column
    for (int row = 0; row < board.size(); row++)
    {
        // before placing the Queen first we have to check does the current place is safe or not
        if (isSafe(row, col, board))
        {
            // if it will safe then we will place the queen
            board[row][col] = 'Q';
            // after placing the Queen for this column we will place the queen for another column
            rec(board, col + 1);

            // After placing other Queen if the current placing queen get placed in wrong place then we also have to remove it
            board[row][col] = '.';
        }
    }
    return;
}

// Return:
// [[".Q..","...Q","Q...","..Q."],
// ["..Q.","Q...","...Q",".Q.."]]
vector<vector<string>> solveNQueens(int n)
{
    // Initializing new board
    string s;
    for (int i = 0; i < n; i++)
        s += '.';
    // vector of string will make our board which is
    // initially all empty
    vector<string> board(n, s);
    rec(board, 0);
    return allBoard;
}

int main()
{
    // int n;
    // cout << "Enter N no. of Queens you want to place: ";
    // cin >> n;
    // Dynamically create n*n size of array
    // string *board = new string[n * n];
    // board[i][j] = board[i*n+j]

    // NOTE: rather we will chose 4*4 size of board for simplicity
    // string board[4][4];

    return 0;
}