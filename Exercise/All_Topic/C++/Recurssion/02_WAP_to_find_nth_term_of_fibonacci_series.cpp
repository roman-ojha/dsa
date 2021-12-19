#include <iostream>
#include <stdio.h>
using namespace std;

int t = 0;
int fibonacci(int n, int f, int s)
{
    if (n == 2)
    {
        return t;
    }
    else
    {
        t = f + s;
        return fibonacci(n - 1, s, t);
    }
}

int main()
{
    int nth;
    cout << "Enter the number to find the nth fibonacci series: " << endl;
    cin >> nth;
    int fibo;
    if (nth == 0 || nth == 1)
    {
        fibo = 0;
    }
    else
    {

        fibo = fibonacci(nth, 0, 1);
    }
    printf("The nth fibonacci of the %d number is: %d", nth, fibo);
    return 0;
}