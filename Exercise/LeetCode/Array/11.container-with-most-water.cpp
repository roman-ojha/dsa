/*
    -> https://leetcode.com/problems/container-with-most-water/description/
    *) Container With Most Water
        You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

        Find two lines that together with the x-axis form a container, such that the container contains the most water.

        Return the maximum amount of water a container can store.

        Notice that you may not slant the container.

        Example 1:
        Input: height = [1,8,6,2,5,4,8,3,7]
        Output: 49
        Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

        Example 2:
        Input: height = [1,1]
        Output: 1

        Constraints:
        n == height.length
        2 <= n <= 105
        0 <= height[i] <= 104
*/

// https://leetcode.com/problems/container-with-most-water/solutions/127443/container-with-most-water/

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
    int maxArea1(vector<int> &height)
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

    // using two pointer approach
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int maxContainer = 0;
        while (left < right)
        {
            int distance = right - left;
            int tempMax = 0;
            if (height[left] <= height[right])
            {
                // if right height is greater then calculate area according to left height
                tempMax = distance * height[left];
                // because left height is smaller we have to move towards rightwards to find bigger height
                left++;
            }
            else
            {
                // if left height is greater then calculate area according to right height
                tempMax = distance * height[right];
                // because right height is smaller we have to move backwards from right to find bigger height
                right--;
            }
            maxContainer = tempMax > maxContainer ? tempMax : maxContainer;
        }

        return maxContainer;
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