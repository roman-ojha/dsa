/*
    # 3 steps for Recursion
        1) find the base case
        2) find the relation between the problem and subproblems
        3) Generalize the relation
*/

#include <iostream>
#include <stdio.h>
using namespace std;

// Find the sum of N natural number using recursion

int sum(int n) // Problem
{
    if (n == 1) // Base
        return 1;
    else
        return n + sum(n - 1); // Sub-Problem
                               // sum(n) = n + sum(n-1) => Geleralise
    /*
        # Recursive leap of faith?
        Recursive functions require a leap of faith — you must assume that the function will work on the simpler recursive call, and if that is the case, the whole function is correctly defined.
    */
}

int power(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return a * power(a, b - 1);
}

int main()
{
    cout << "The sum of the 10 natural number is: " << sum(10) << endl;
    cout << "2^3 is: " << power(2, 3) << endl;
    return 0;
}