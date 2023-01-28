/*
    -> https://leetcode.com/problems/longest-common-prefix/
    -> https://leetcode.com/problems/longest-common-prefix/solutions/127449/longest-common-prefix/
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
/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    // horizontal scanning
    // O(S) : sum of all characters in all strings
    string longestCommonPrefix1(vector<string> &strs)
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

    // Vertical scanning
    // Worst case: O(S)
    // Best case: O(row * minCol)
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        for (int col = 0; col < strs[0].size(); col++)
        {
            // scanning vertically
            char curr = strs[0][col];
            for (int row = 0; row < (int)strs.size(); row++)
            {
                if (col == strs[row].size() || strs[row][col] != curr)
                {
                    return strs[0].substr(0, col);
                }
            }
        }
        return strs[0];
    }
};
// @lc code=end

int main()
{
    string s = "abcd";
    cout << s.substr(1, 2);
    return 0;
}