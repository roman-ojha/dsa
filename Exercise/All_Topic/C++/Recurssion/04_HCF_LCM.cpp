#include <iostream>
#include <stdio.h>
using namespace std;

int hcf(int n1, int n2)
{
    if (n2 != 0)
    {
        return hcf(n2, n1 % n2);
    }
    else
    {
        return n1;
    }
}

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

int lcm(int a, int b)
{
    // lcm of 4 & 6 is 12
    // 12 % 4 = 0 & 12 % 6 = 0
    static int temp = 1;
    if (temp % a == 0 && temp % b == 0)
    {
        return temp;
    }
    else
    {
        temp++;
        lcm(a, b);
        return temp;
    }
}

int main()
{
    cout << "HCF(15,30): " << hcf(15, 30) << endl;
    cout << "HCF(90,60): " << gcd(90, 60) << endl;
    cout << "LCM(90,60): " << lcm(90, 60) << endl;
    return 0;
}