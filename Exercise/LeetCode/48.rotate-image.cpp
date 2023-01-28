/*
    -> https://leetcode.com/problems/rotate-image/description/
    *) Rotate Image
        You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

        You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

        Example 1:
        Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
        Output: [[7,4,1],[8,5,2],[9,6,3]]

        Example 2:
        Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
        Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

        Constraints:
        n == matrix.length == matrix[i].length
        1 <= n <= 20
        -1000 <= matrix[i][j] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution
{
public:
    /*
        Solution:
        [0][0] [0][1] [0][2] -> [0][2]
                                [1][2]
                                [2][2]
    */
    void rotate(vector<vector<int>> &matrix)
    {
        // create the same n*n matrix to store rotate image
        vector<int> col(matrix[0].size(), 0);
        vector<vector<int>> rotImg(matrix.size(), col);

        // rotate image index
        int rotImgRow = 0;
        int rotImgCol = 0;
        for (int imgRow = 0; imgRow < (int)matrix.size(); imgRow++)
        {
            for (int imgCol = 0; imgCol < (int)matrix[0].size(); imgCol++)
            {
                // calculating rotating image row & col
                rotImgRow = imgCol;
                rotImgCol = matrix.size() - imgRow - 1;
                rotImg[rotImgRow][rotImgCol] = matrix[imgRow][imgCol];
            }
        }
        matrix = rotImg;
    }
};
// @lc code=end

int main()
{
    return 0;
}