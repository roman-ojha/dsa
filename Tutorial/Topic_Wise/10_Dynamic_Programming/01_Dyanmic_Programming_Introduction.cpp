/*
    # Dynamic Programming
        => it is the way of making the algorithm efficent by storing some of the intermediate result
        => and it works really well when your algorithm has a lot of repetitive computations

*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

// calculate the nth fibonacii number

int result;
int fib(int n)
{
    if (n == 1 || n == 2)
    {
        result = 1;
    }
    else
    {
        result = fib(n - 1) + fib(n - 2);
    }
    return result;
    /*
    => Here, we need to compute the return value for fib(2) 3 times and we need to compute the return value for fib(3) 2 times, its is ok for to find 5th fibonacci number but it became issue if you want to find the fibonacii number of 100th
    T(n) = O(2^n)
    and here the dynamic programming say that store those return values ones we compute it and use that same value when we see fib(3) or fib(2) agian rather then compute it again
    */
}

int memoizedFib(int n, vector<int> memo)
{
    if (memo[n] != -1)
    {
        // it means we had already store the return value for the 'n'
        return memo[n];
    }
    if (n == 1 || n == 2)
    {
        result = 1;
    }
    else
    {
        result = memoizedFib(n - 1, memo) + memoizedFib(n - 2, memo);
    }
    memo[n] = result;
    // before return store the result in 'memo'
    return result;
    // time complexity for this algorithm is: O(n)
}

int fib_bottom_up(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    // int bottom_up[n + 1];
    int *bottom_up = new int[n + 1];
    // here we are creating the 'n+1' size of array
    bottom_up[1] = 1;
    bottom_up[2] = 1;
    // and here we store the value
    for (int i = 3; i <= n; i++)
    {
        // here we will start the for loop from 3 because we had already store the value in '1' and '2'
        bottom_up[i] = bottom_up[i - 1] + bottom_up[i - 2];
        // here we are doing sum of the two previous items
    }
    return bottom_up[n];
    // here we will return the last items it 'buttom_up'
    // time complexity for this algorithm is: O(n)
}

int main()
{
    int n = 5;
    cout << "nth fibonacii number is: " << fib(n) << endl;
    vector<int> memo(n + 1, -1);
    // here -1 represent NULL
    cout << "nth fibonacii number using memoize: " << memoizedFib(n, memo) << endl;
    cout << "nth fibonacii number using bottom up: " << fib_bottom_up(n) << endl;
    return 0;
}