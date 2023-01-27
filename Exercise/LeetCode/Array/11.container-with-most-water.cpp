#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    // Todo.. two pointer approach
    int maxArea(vector<int> &height)
    {
        // using Brute force approach
        // time complexity = O(n^2)
        // Time limit exceeded
        int maxWater = 0;
        int distance = 0;
        int leftHeight = 0;
        int rightHeight = 0;
        for (int left = 0; left < (int)height.size(); left++)
        {
            for (int right = left + 1; right < (int)height.size(); right++)
            {
                // calculate positive distance between two line
                distance = right - left;

                int tempMaxWater = 0;
                leftHeight = height[left];
                rightHeight = height[right];
                if (leftHeight <= rightHeight)
                    tempMaxWater = leftHeight * distance;
                else
                    tempMaxWater = rightHeight * distance;

                maxWater = tempMaxWater > maxWater ? tempMaxWater : maxWater;
            }
        }
        return maxWater;
    }
};
// @lc code=end

int main()
{
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.maxArea(height) << endl;
    return 0;
}