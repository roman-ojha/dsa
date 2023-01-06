#include <iostream>
using namespace std;

int isSafeToPlace(string **board, int r, int c, int n)
{
    for (int i = 0; i < n; i++)
    {
        // Get Diagonally element
        string curr = board[r + i][c + i];
        if ((curr == "Q1") || (curr == "Q2") || (curr == "Q3") || (curr == "Q4"))
        {
            return false;
        }

        // Get horizontal element
        curr = board[r][c + i];
        if ((curr == "Q1") || (curr == "Q2") || (curr == "Q3") || (curr == "Q4"))
        {
            return false;
        }

        // Get vertical element
        curr = board[r + i][c];
        if ((curr == "Q1") || (curr == "Q2") || (curr == "Q3") || (curr == "Q4"))
        {
            return false;
        }
    }

    // Now it is safe
    return true;
}

void nQueens(string **board, int i, int j, int n)
{
    // Next Diagonal element of board[i][j] is board[i+1][j+1]
}

int main()
{
    int n;
    cout << "Enter N no. of Queens you want to place: ";
    cin >> n;
    // Dynamically create n*n size of array
    // string *board = new string[n * n];
    // board[i][j] = board[i*n+j]

    // NOTE: rather we will chose 4*4 size of board for simplicity
    string board[4][4];

    return 0;
}