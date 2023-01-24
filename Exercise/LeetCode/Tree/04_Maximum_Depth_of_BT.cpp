/*
    -> https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
    *) Maximum Depth of BT:
        Given the root of a binary tree, return its maximum depth.

        A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.



        Example 1:
        Input: root = [3,9,20,null,null,15,7]
        Output: 3

        Example 2:
        Input: root = [1,null,2]
        Output: 2


        Constraints:
        The number of nodes in the tree is in the range [0, 104].
        -100 <= Node.val <= 100
*/
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

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        // maximum depth of current node or 1 node is 1
        int max = 1;

        // get the maximum depth of left subtree
        int leftMax = maxDepth(root->left);

        // get maximum depth of right subtree
        int rightMax = maxDepth(root->right);

        // check which subtree depth is maximum
        // then add to the current node max depth
        if (leftMax > rightMax)
            max += leftMax;
        else
            max += rightMax;

        // return the max depth upto the subtree/tree that we get on 'root'
        return max;
    }

    int maxDepth2(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        return max(leftMax, rightMax) + 1;
    }
};