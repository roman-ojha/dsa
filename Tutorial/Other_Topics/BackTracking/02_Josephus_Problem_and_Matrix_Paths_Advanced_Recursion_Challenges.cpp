/*
    1) Find the number of ways in n*m matrix 
        => path from 0*0 to n*m
        => you can only to right and left
    2) josepjus problem
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int nWays(int n, int m)
{
    // Base case n=1 or m=1, therefore  ans = 1
    if (n == 1 || m == 1)
        return 1;
    else
        return nWays(n - 1, m) + nWays(n, m - 1);
}

int josephus(int n, int k)
{
    if (n == 1) // Base case
        return 0;
    else
        return (josephus(n - 1, k) + k) % n;
    /*
        josephus(5,3)
        (josephus(4,3)+3)%5
        (josephus(3,3)+3)%4
        (josephus(2,3)+3)%3
        (josephus(1,3)+3)%2
    */
}

int main()
{
    cout << "No. of way to reach out to the destination is: " << nWays(4, 3) << endl;
    cout << "Josephus problem: " << josephus(5, 3) << endl;
    return 0;
}