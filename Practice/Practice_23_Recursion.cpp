#include <iostream>
#include <stdio.h>
using namespace std;

int nthFibonacii(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return nthFibonacii(n - 1) + nthFibonacii(n - 2);
    }
}

int main()
{
    int n = 9;
    printf("Fibonacci of %d is: %d", n, nthFibonacii(n));
    return 0;
}