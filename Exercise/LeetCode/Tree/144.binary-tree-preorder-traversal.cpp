/*
     *) Binary Tree Preorder Traversal
        Given the root of a binary tree, return the preorder traversal of its nodes' values.

        Example 1:
        Input: root = [1,null,2,3]
        Output: [1,2,3]

        Example 2:
        Input: root = []
        Output: []

        Example 3:
        Input: root = [1]
        Output: [1]

        Constraints:
        The number of nodes in the tree is in the range [0, 100].
        -100 <= Node.val <= 100

        Follow up: Recursive solution is trivial, could you do it iteratively?
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
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<int> result;
        // root
        result.push_back(root->val);
        // left
        auto leftResult = preorderTraversal(root->left);
        result.insert(result.end(), leftResult.begin(), leftResult.end());

        // right
        auto rightResult = preorderTraversal(root->right);
        result.insert(result.end(), rightResult.begin(), rightResult.end());

        return result;
    }
};
// @lc code=end

int main()
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    t1.left = nullptr;
    t1.right = &t2;
    t2.left = &t3;
    t2.right = nullptr;
    t3.left = nullptr;
    t3.right = nullptr;

    Solution s;
    auto result = s.preorderTraversal(&t1);
    for (auto elm : result)
        cout << elm << " ";
    return 0;
}
