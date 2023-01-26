/*
    -> https://leetcode.com/problems/reverse-integer/
    *) Reverse Integer:
        Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

        Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

        Example 1:
        Input: x = 123
        Output: 321

        Example 2:
        Input: x = -123
        Output: -321

        Example 3:
        Input: x = 120
        Output: 21

        Constraints:
        -231 <= x <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        // into to string
        string s = to_string(x);

        int i = 0;            // starting index
        int j = s.size() - 1; // ending index
        if (s[0] == '+' || s[0] == '-')
        {
            i = 1;
        }

        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }

        // convert s into integer it could be long long int as well
        // so that we will store it in long long int variable
        long long num = stoll(s);

        if ((num > (pow(2, 31) - 1)) || (num < pow(-2, 31)))
        {
            // out of bound
            return 0;
        }

        return num;
    }
};

int main()
{
    int x = 2147483648 - 1;
    // x = 214748364;
    x = -123;
    Solution s;
    cout << s.reverse(x) << endl;
    return 0;
}