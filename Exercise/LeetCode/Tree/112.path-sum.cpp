#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool dfs(TreeNode *root, int targetSum, int sum)
    {
        if (root == nullptr)
            return false;
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (sum == targetSum)
                return true;
            else
                return false;
        }
        // we will check upto every leaf node
        // after checking for every one of them
        // if one of them will be true in that case we find the path-sum
        return dfs(root->left, targetSum, sum) or dfs(root->right, targetSum, sum);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return dfs(root, targetSum, 0);
    }
};
// @lc code=end
