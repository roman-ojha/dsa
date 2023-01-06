#include <iostream>
using namespace std;

/*
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

void nQueens(string **board, int r, int c, int n)
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