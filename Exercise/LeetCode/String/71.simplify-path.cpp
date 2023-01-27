#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution
{
    stack<char> s;

public:
    string simplifyPath(string path)
    {
        string newPath = "";
        if (path[0] == '/')
        {
            newPath += '/';
            s.push('/');
        }

        for (int ch = 1; ch < (int)path.length(); ch++)
        {
            if (path[ch] == '/')
            {
                if (ch != (int)path.length() - 1 && s.top() != '/')
                {
                    newPath += path[ch];
                    s.push('/');
                }
            }
            else if (path[ch] != '.')
            {
                // found normal char
                newPath += path[ch];
                s.push(path[ch]);
                if (s.top() == '/')
                    s.pop();
            }
            else if (path[ch] == '.')
            {
                if (s.top() == '.')
                {
                    s.pop();
                    if (s.top() == '.')
                    {
                        // if two '.' exist in stack and path[ch] is '.' then it is a file/directory names.
                        newPath += "...";
                    }
                    else
                    {
                        s.push('.');
                        s.push('.');
                    }
                }
                else
                    s.push('.');
            }
        }
        return newPath;
    }
};
// @lc code=end

int main()
{
    string path = "/home/";
    path = "/../";
    path = "/home//foo/";
    path = "/.../";
    path = "/home//foo///.../roman";

    // Wrong answer for this one
    // because '.' means root directory
    // '..' means to go back
    // Expected output: '/c'
    path = "/a/./b/../../c/";
    Solution s;
    cout << s.simplifyPath(path) << endl;
    return 0;
}