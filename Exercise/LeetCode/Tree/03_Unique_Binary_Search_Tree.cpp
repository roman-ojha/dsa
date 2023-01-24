/*
    -> https://leetcode.com/problems/unique-binary-search-trees/
    *) Unique binary Search tree:
        Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

        Example 1:
        Input: n = 3
        Output: 5

        Example 2:
        Input: n = 1
        Output: 1

        Constraints:

        1 <= n <= 19
*/

/*
            R
        /       \
    4            5
    unique       unique
    BST          BST
    -> Total number of unique BST = 4 * 5 = 20

    => If we will choose 'i' as a root node in:
        1, 2, 3, 4, 5, ..., i, i+1, ..., n
    => in that case:
        -> for the 'i' root node left subtree contain node from 1 to i-1
        -> for the 'i' root node right subtree contain node from i+1 to n

    => for f(0) = 1
    => for f(1) = 1
*/