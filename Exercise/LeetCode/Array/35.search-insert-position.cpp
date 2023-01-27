/*
    -> https://leetcode.com/problems/search-insert-position/
    *) Search Insert Position
        Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

        You must write an algorithm with O(log n) runtime complexity.

        Example 1:
        Input: nums = [1,3,5,6], target = 5
        Output: 2

        Example 2:
        Input: nums = [1,3,5,6], target = 2
        Output: 1

        Example 3:
        Input: nums = [1,3,5,6], target = 7
        Output: 4

        Constraints:
        1 <= nums.length <= 104
        -104 <= nums[i] <= 104
        nums contains distinct values sorted in ascending order.
        -104 <= target <= 104
*/

/*
    Other good solution: https://leetcode.com/problems/search-insert-position/solutions/3076012/c-binary-search-approach/
*/

#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int mid = 0;
        int index = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                index = mid;
                break;
            }
            else
            {
                if (nums[mid] > target)
                {
                    high = mid - 1;
                    index = mid;
                }
                else
                {
                    low = mid + 1;
                    index = mid + 1;
                }
            }
        }
        return index;
    }
};
// @lc code=end

int main()
{
}
