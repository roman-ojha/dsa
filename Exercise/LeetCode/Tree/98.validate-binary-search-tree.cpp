/*
    -> https://leetcode.com/problems/validate-binary-search-tree/
    *) Validate Binary Search Tree
        Given the root of a binary tree, determine if it is a valid binary search tree (BST).

        A valid BST is defined as follows:

        The left subtree of a node contains only nodes with keys less than the node's key.
        The right subtree of a node contains only nodes with keys greater than the node's key.
        Both the left and right subtrees must also be binary search trees.

        Example 1:
        Input: root = [2,1,3]
        Output: true

        Example 2:
        Input: root = [5,1,4,null,null,3,6]
        Output: false
        Explanation: The root node's value is 5 but its right child's value is 4.

        Constraints:
        The number of nodes in the tree is in the range [1, 104].
        -231 <= Node.val <= 231 - 1
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

/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
private:
    TreeNode *prev = nullptr;

public:
    bool isValidBST(TreeNode *root)
    {
        // we will do a inorder traversal
        // NOTE: BST inOrder traversal will be in ascending order
        if (root == nullptr)
            // if root element is null then BST is valid
            return true;

        // left
        if (!isValidBST(root->left))
            return false;

        // root
        // check for root element
        if (prev != nullptr && root->val <= prev->val)
            return false;

        // after visiting root because we have to compare current val with previous val we have to set root as previous
        prev = root;

        // right
        return isValidBST(root->right);
    }
};
// @lc code=end

// Wrong Solution
// Check for [5,4,6,null,null,3,7]
// answer is 'true', expected is 'false'
bool isValidBST(TreeNode *root)
{
    if (root == nullptr)
        // if root doesn't exist in that case also it is a valid BST
        return true;

    // let's assume by default left and right child is valid
    bool isValidLeft = true;
    bool isValidRight = true;

    if (root->left != nullptr)
    {
        // if left child exist
        if (root->left->val < root->val)
            // if one of them return false all the will get false
            // every one of them needs to return true
            isValidLeft = isValidBST(root->left);
        else
            return false;
    }
    if (root->right != nullptr)
    {
        // if right child exist
        if (root->right->val > root->val)
            // if one of them return false all the will get false
            isValidRight = isValidBST(root->right);
        else
            return false;
    }

    // so left & rich child is valid then root is valid BST
    return isValidLeft && isValidRight;
}