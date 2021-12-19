/*
    # String recursion:
        Q1) Palindrom string
        Q2) Pring the powerSet of a given string
        Q3) print all permutations of a given string
*/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

bool palindromString(string str, int l, int r)
{
    if (l >= r)
        return true;
    if (str[l] != str[r])
        return false;
    return palindromString(str, l + 1, r - 1);
}

void powerSet(string s, int i, string curStr)
{
    // s="abc" => {"","a","b","c","ab","bc","ac","abc"}
    if (i == s.length())
    {
        cout << "\"" << curStr << "\""
             << ", ";
        return;
    }
    powerSet(s, i + 1, curStr + s[i]);
    powerSet(s, i + 1, curStr);
    // Time Complexity: O(2^n)
}

void permutations(string s, int l, int r)
{
    // ab -> {ab,bc}
    // abc -> {abc,acb,bac,bca,cab,cba}
    if (l == r)
    {
        cout << "\"" << s << "\""
             << ", ";
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(s[i], s[l]);
        permutations(s, l + 1, r);
        swap(s[i], s[l]);
    }
    // Time Complexity is: O(n*n!)
}

int main()
{
    bool res;
    string str = "abcdeedcba";
    if (palindromString(str, 0, str.length() - 1))
    {
        cout << "given string is palindrom" << endl;
    }
    else
    {
        cout << "given string is not a palindrom" << endl;
    }
    powerSet("abc", 0, "");
    cout << endl;
    permutations("abc", 0, 2);
    return 0;
}