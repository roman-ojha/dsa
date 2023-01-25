/*
    *) Sort Colors.
        Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

        We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

        You must solve this problem without using the library's sort function.

        Example 1:
        Input: nums = [2,0,2,1,1,0]
        Output: [0,0,1,1,2,2]

        Example 2:
        Input: nums = [2,0,1]
        Output: [0,1,2]

        Constraints:
        n == nums.length
        1 <= n <= 300
        nums[i] is either 0, 1, or 2.

        Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // Overwrite array with the total number of 0's, then 1's and followed by 2's.

        int no_of_0 = 0, no_of_1 = 0, no_of_2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                no_of_0++;
            else if (nums[i] == 1)
                no_of_1++;
            else
                no_of_2++;
        }

        // override
        for (int i = 0; i < nums.size(); i++)
        {
            if (no_of_0 != 0)
            {
                nums[i] = 0;
                no_of_0--;
            }
            else if (no_of_1 != 0)
            {
                nums[i] = 1;
                no_of_1--;
            }
            else if (no_of_2 != 0)
            {
                nums[i] = 2;
                no_of_2--;
            }
        }
    }
};

int main()
{

    return 0;
}