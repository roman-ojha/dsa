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

// Print all the possible solution board
void print_board(int n)
{
    for (int i = 0; i < allBoard.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << allBoard[i][j] << endl;
        }
        cout << endl;
    }
}

// 'isSafe' function will check does it will safe to place Queen in the given place
int isSafe(int row, int col, vector<string> &board)
{
    // Checking horizontal line:
    for (int j = 0; j < board.size(); j++)
    {
        if (board[row][j] == 'Q')
            return false;
    }

    // Checking vertical lines:
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Checking diagonal lines:
    // Top right diagonal:
    // i-- & j++
    int i = row, j = col;
    while (i >= 0 && j < board.size())
    {
        // Moving on Top left diagonal element
        if (board[i--][j++] == 'Q')
            return false;
    }
    // Top left diagonal:
    // i-- & j--
    i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        // Moving on Top left diagonal element
        if (board[i--][j--] == 'Q')
            return false;
    }
    // Bottom right diagonal:
    // i++ & j++
    i = row, j = col;
    while (i < board.size() && j < board.size())
    {
        // Moving on Top left diagonal element
        if (board[i++][j++] == 'Q')
            return false;
    }
    // Bottom left diagonal:
    // i++ & j--
    i = row, j = col;
    while (i < board.size() && j >= 0)
    {
        // Moving on Top left diagonal element
        if (board[i++][j--] == 'Q')
            return false;
    }

    // now it will safe to place
    return true;
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
    solveNQueens(4);
    cout << "No. of possible solution is: " << allBoard.size() << endl;
    print_board(4);
    return 0;
}