/*
    -> https://leetcode.com/problems/palindrome-number/
    *) Palindrome Number
        Given an integer x, return true if x is a palindrome, and false otherwise.

        Example 1:
        Input: x = 121
        Output: true
        Explanation: 121 reads as 121 from left to right and from right to left.

        Example 2:
        Input: x = -121
        Output: false
        Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

        Example 3:
        Input: x = 10
        Output: false
        Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

        Constraints:
        -231 <= x <= 231 - 1
        Follow up: Could you solve it without converting the integer to a string?
*/

#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome1(int x)
    {
        string s = to_string(x);
        for (int i = 0; i < s.size() / 2; i++)
        {
            cout << s[i] << "==" << s[s.size() - i - 1] << endl;
            if (s[i] != s[s.size() - i - 1])
            {
                return false;
            }
        }
        return true;
    }

    // another way:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        if (s.size() == 1)
            return true;
        reverse(s.begin(), s.end());
        if (to_string(x) != s)
            return false;
        return true;
    }
};
// @lc code=end

int main()
{
    string s = "123";
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}