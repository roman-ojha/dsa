#include <iostream>
#include <stdio.h>
using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int num;
    cout << "Enter the given number to find the factorial of it:" << endl;
    scanf("%d", &num);
    int fact = factorial(num);
    printf("The factorial of the given number is: %d", fact);
    return 0;
}