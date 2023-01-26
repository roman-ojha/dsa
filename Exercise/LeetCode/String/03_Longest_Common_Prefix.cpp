/*
    ->https://leetcode.com/problems/longest-common-prefix/
    *) Longest Common Prefix:
        Write a function to find the longest common prefix string amongst an array of strings.

        If there is no common prefix, return an empty string "".

        Example 1:
        Input: strs = ["flower","flow","flight"]
        Output: "fl"

        Example 2:
        Input: strs = ["dog","racecar","car"]
        Output: ""
        Explanation: There is no common prefix among the input strings.

        Constraints:
        1 <= strs.length <= 200
        0 <= strs[i].length <= 200
        strs[i] consists of only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string lcp = strs[0];
        for (auto &str : strs)
        {
            string temp;
            for (int i = 0; i < str.size(); i++)
            {
                if (i > lcp.size() - 1)
                {
                    break;
                }
                if (lcp[i] == str[i])
                {
                    temp.push_back(str[i]);
                }
                else
                {
                    break;
                }
            }
            lcp = temp;
        }
        return lcp;
    }
};

int main()
{

    return 0;
}