/*
    -> https://leetcode.com/problems/same-tree/description/
    *) Same Tree
        Given the roots of two binary trees p and q, write a function to check if they are the same or not.

        Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.



        Example 1:
        Input: p = [1,2,3], q = [1,2,3]
        Output: true

        Example 2:
        Input: p = [1,2], q = [1,null,2]
        Output: false

        Example 3:
        Input: p = [1,2,1], q = [1,1,2]
        Output: false

        Constraints:
        The number of nodes in both trees is in the range [0, 100].
        -104 <= Node.val <= 104
*/

#include <iostream>
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }

    bool isSameTree2(TreeNode *p, TreeNode *q)
    {
        // Another method
        if (p == nullptr && q == nullptr)
            return true;
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
            return false;
        if (p->val != q->val)
            return false;

        // Check for the left tree
        bool isLeftSame = isSameTree(p->left, q->left);
        // Check for the right tree
        bool isRightSame = isSameTree(p->right, q->right);

        // Is left tree && right tree are same
        return isLeftSame && isRightSame;
    }
};

int main()
{

    return 0;
}