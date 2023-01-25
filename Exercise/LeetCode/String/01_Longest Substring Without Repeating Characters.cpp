/*
    *) Longest Substring Without Repeating Characters
        Given a string s, find the length of the longest
        substring
        without repeating characters.



        Example 1:

        Input: s = "abcabcbb"
        Output: 3
        Explanation: The answer is "abc", with the length of 3.
        Example 2:

        Input: s = "bbbbb"
        Output: 1
        Explanation: The answer is "b", with the length of 1.
        Example 3:

        Input: s = "pwwkew"
        Output: 3
        Explanation: The answer is "wke", with the length of 3.
        Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


        Constraints:

        0 <= s.length <= 5 * 104
        s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string str;
        int flag = 1;
        for (int i = 0; i < (int)s.size(); i++)
        {
            flag = 1;
            for (auto c : str)
            {
                if (s[i] == c)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                cout << s[i] << endl;
                str.push_back(s[i]);
            }
        }
        return (int)str.size();
    }
};

int main()
{
    Solution s;
    string str = "pwwkew";
    vector<int> sub;
    sub.reserve(10);
    // cout << s.lengthOfLongestSubstring(str) << endl;
    sub[9] = 1;
    cout << sub[9] << endl;
    return 0;
}