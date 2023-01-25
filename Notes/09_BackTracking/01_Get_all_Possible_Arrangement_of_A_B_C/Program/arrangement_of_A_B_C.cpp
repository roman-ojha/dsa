#include <iostream>
using namespace std;

// Time complexity = O(n*n!)

void permutation(string str, string perm, int idx)
{
    if (str.length() == 0)
    {
        // When Single arrangement is done in that case 'str' length will be 0
        cout << perm << endl;
        // ABC ACB BAC BCA CAB CBA
        return; // Backtrack
    }

    long unsigned int length = str.length();
    for (long unsigned int i = 0; i < length; i++)
    {
        // Select every String from the 'str'
        // Remove the selected char fromthe 'str' and return to as new string recursively
        string newStr = str.substr(0, i) + str.substr(i + 1);
        permutation(newStr, perm + str[i], idx + 1);
    }
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    string str = "ABC";
    // Total possible arrangement:
    // int total = factorial(str.length());

    // Creating array which will contain all the possible arrangement of given string
    // string *arr = new string[total];

    permutation(str, "", 0);
    return 0;
}