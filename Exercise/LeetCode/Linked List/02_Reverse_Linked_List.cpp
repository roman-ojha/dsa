/*
    -> https://leetcode.com/problems/reverse-linked-list/description/
    *) Reverse Linked List
        Given the head of a singly linked list, reverse the list, and return the reversed list.

        Example 1:
        Input: head = [1,2,3,4,5]
        Output: [5,4,3,2,1]

        Example 2:
        Input: head = [1,2]
        Output: [2,1]

        Example 3:
        Input: head = []
        Output: []

        Constraints:
        The number of nodes in the list is the range [0, 5000].
        -5000 <= Node.val <= 5000


        Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // Iterative way to reverse linked list
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        else if (head->next == nullptr)
        {
            return head;
        }
        ListNode *first = head;
        ListNode *second = head->next;
        head->next = nullptr;
        ListNode *temp = new ListNode;
        while (temp != nullptr)
        {
            temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }
        return first;
    }
};

int main()
{

    return 0;
}