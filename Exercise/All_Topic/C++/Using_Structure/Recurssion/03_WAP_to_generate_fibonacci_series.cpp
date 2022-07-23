#include <iostream>
#include <stdio.h>
using namespace std;

int f = 0, s = 1, t = 1, count = 0;
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        if (count == 0)
        {
            printf("%d, ", count);
            count++;
            return fibonacci(n - 1);
        }
        else if (count == 1)
        {
            cout << count << ", ";
            count++;
            return fibonacci(n - 1);
        }
        else
        {

            t = f + s;
            printf("%d, ", t);
            f = s;
            s = t;
            return fibonacci(n - 1);
        }
    }
}

int main()
{
    int nth;
    cout << "Enter the number to find the nth fibonacci series: " << endl;
    cin >> nth;
    if (nth == 0)
    {
        printf("Plese enter the higher number then 0");
    }
    else if (nth == 1)
    {
        printf("Fibonacci of 1: 0");
    }
    else
    {
        fibonacci(nth);
    }
    return 0;
}