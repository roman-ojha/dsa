/*
    -> https://leetcode.com/problems/median-of-two-sorted-arrays/description/
    *) Median of Two Sorted Arrays
        Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

        The overall run time complexity should be O(log (m+n)).



        Example 1:

        Input: nums1 = [1,3], nums2 = [2]
        Output: 2.00000
        Explanation: merged array = [1,2,3] and median is 2.
        Example 2:

        Input: nums1 = [1,2], nums2 = [3,4]
        Output: 2.50000
        Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


        Constraints:

        nums1.length == m
        nums2.length == n
        0 <= m <= 1000
        0 <= n <= 1000
        1 <= m + n <= 2000
        -106 <= nums1[i], nums2[i] <= 106
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> arr = nums1;
        arr.reserve(nums1.size() + nums2.size());
        // arr contain merge array

        // perform insertion sort
        int key; // targeting to first index of 'nums2'
        int ptr; // current position comparing with 'key'
        for (int i = 0; i < (int)nums2.size(); i++)
        {
            key = nums2[i];
            ptr = arr.size() - 1;
            arr.push_back(0);
            while ((ptr >= 0) && (arr[ptr] > key))
            {
                arr[ptr + 1] = arr[ptr];
                ptr--;
            }
            arr[ptr + 1] = key;
        }

        // calculating median from 'arr'
        int len = arr.size();
        double median;
        if (len % 2 == 0)
        {
            // 2 median
            median = (double)(arr[arr.size() / 2] + arr[(int)(arr.size() / 2) - 1]) / 2;
        }
        else
        {
            // 1 meidan
            median = arr[arr.size() / 2];
        }
        return median;
    }
};

int main()
{
    vector<int> nums1{1, 3, 4, 8};
    vector<int> nums2{7, 9, 10, 2};
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}