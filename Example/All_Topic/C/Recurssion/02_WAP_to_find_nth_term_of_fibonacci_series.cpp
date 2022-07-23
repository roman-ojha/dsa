#include <iostream>
#include <stdio.h>
using namespace std;

int t = 0;

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
    int nth;
    cout << "Enter the number to find the nth fibonacci series: " << endl;
    cin >> nth;
    int fibo;
    fibo = nthFibonacii(nth);
    printf("The nth fibonacci of the %d number is: %d", nth, fibo);
    return 0;
}