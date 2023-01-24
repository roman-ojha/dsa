/*
    -> https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
    *) Find First and Last Position of Element in Sorted Array
        Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

        If target is not found in the array, return [-1, -1].

        You must write an algorithm with O(log n) runtime complexity.



        Example 1:
        Input: nums = [5,7,7,8,8,10], target = 8
        Output: [3,4]

        Example 2:
        Input: nums = [5,7,7,8,8,10], target = 6
        Output: [-1,-1]

        Example 3:
        Input: nums = [], target = 0
        Output: [-1,-1]


        Constraints:

        0 <= nums.length <= 105
        -109 <= nums[i] <= 109
        nums is a non-decreasing array.
        -109 <= target <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // My first approach some error is occurring
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int ai = 0, bi = 0;
        int aj = nums.size() - 1, bj = nums.size() - 1;
        int midA = 0, midB = 0;
        vector<int> result{-1, -1};
        bool found = false;
        while ((ai <= aj) && (bi <= bj))
        {
            if (!found)
            {
                midA = (ai + aj) / 2;
                if (nums[midA] > target)
                {
                    aj = midA - 1;
                }
                else if (nums[midA] < target)
                {
                    ai = midA + 1;
                }
                else
                {
                    // found the target element
                    found = true;
                    result[0] = midA;
                    result[1] = midA;
                    ai = ai;
                    bi = midA;
                    bj = aj;
                    aj = midA;
                }
            }
            else
            {
                cout << ai << aj << bi << bj << endl;
                midA = floor((float)(ai + aj) / 2);
                midB = ceil((float)(bi + bj) / 2);
                // find starting position
                if (nums[midA] > target)
                {
                    aj = midA - 1;
                }
                else if (nums[midA] < target)
                {
                    ai = midA + 1;
                }
                else
                {
                    result[0] = midA;
                    aj = midA - 1;
                }

                // finding ending position
                if (nums[midB] > target)
                {
                    bj = midB - 1;
                }
                else if (nums[midB] < target)
                {
                    bi = midB + 1;
                }
                else
                {
                    result[1] = midB;
                    bi = midB + 1;
                }
            }
        }
        return result;
    }

    // Another approach
    void startingPos(vector<int> &nums, int target, vector<int> &result)
    {
        int low = 0, high = nums.size() - 1;
        int mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                result[0] = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    void endingPos(vector<int> &nums, int target, vector<int> &result)
    {
        int low = 0, high = nums.size() - 1;
        int mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                result[1] = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    vector<int> searchRange2(vector<int> &nums, int target)
    {
        vector<int> result{-1, -1};
        startingPos(nums, target, result);
        endingPos(nums, target, result);
        return result;
    }
};

int main()
{
    // vector<int> nums{5, 7, 7, 8, 8, 10};
    // int target = 8;
    // vector<int> nums{2, 2};
    // int target = 2;
    // vector<int> nums{1, 2, 3, 3, 3, 3, 4, 5, 9};
    // int target = 3;
    vector<int> nums{0, 0, 0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 8, 8, 9, 9, 10, 10, 11, 11};
    int target = 0;
    Solution s;
    vector<int> output = s.searchRange2(nums, target);
    for (auto elm : output)
    {
        cout << elm << " ";
    }
    cout << endl;
    return 0;
}