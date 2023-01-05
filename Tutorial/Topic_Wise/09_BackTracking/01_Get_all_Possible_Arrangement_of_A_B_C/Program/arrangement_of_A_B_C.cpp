#include <iostream>
using namespace std;

void printPermutation(string str, int n, int idx)
{
    if (str.length() == 0)
    {
    }
    for (int i = 0; i < n; i++)
    {
        // Select every String from the 'str'
        cout << str[i];
        // Remove the selected char fromthe 'str' and return to as new string recursively
        printPermutation(str.erase(i, 1), n, idx + 1);
        // str.erase(<index_position>,<no._of_char>)
    }
}

int main()
{
    string str = "ABC";
    // Total possible arrangement:
    // int total=
    // printPermutation(str, 3, 0);
    return 0;
}