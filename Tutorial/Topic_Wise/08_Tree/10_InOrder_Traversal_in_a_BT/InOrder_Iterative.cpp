// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
/*
    1) Create an empty stack S.
    2) Initialize current node as root
    3) Push the current node to S and set current = current->left until current is NULL
    4) If current is NULL and stack is not empty then
        a) Pop the top item from stack.
        b) Print the popped item, set current = popped_item->right
        c) Go to step 3.
    5) If current is NULL and stack is empty then we are done.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <class Data>
class Node
{
public:
    Node<Data> *left;
    Data data;
    Node<Data> *right;
    Node(Node<Data> *left, Data data, Node<Data> *right) : left(left), data(data), right(right) {}
    Node(Data data) : data(data), left(nullptr), right(nullptr) {}
};

template <class Data>
class BT
{
public:
    Data index = -1;
    Node<Data> *build(vector<Data> *nodes)
    {
        this->index++;
        if (nodes->at(this->index) == -1)
        {
            // When it is a leaf node we will return nullptr
            return nullptr;
        }
        else
        {
            // It is a node
            Node<Data> *node = new Node<Data>(nodes->at(index));
            node->left = build(nodes);
            node->right = build(nodes);

            // In the end it will return the root node
            return node;
        }
    }

    void inOrder(Node<Data> *root)
    {
        std::stack<Node<Data> *> S;
        Node<Data> *curr = root;
        if (curr != nullptr)
        {
            S.push(curr);
        }
        while (!S.empty())
        {
            if (curr != nullptr)
            {
                // Left
                curr = curr->left;
                if (curr != nullptr)
                {
                    S.push(curr);
                }
            }
            else
            {
                // Root
                curr = S.top();
                cout << curr->data << " ";
                S.pop();

                // Right
                curr = curr->right;
                if (curr != nullptr)
                {
                    S.push(curr);
                }
            }
        }
    }
};

int main()
{
    // -1 == nullptr
    vector<int> nodes{1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BT<int> bt;
    Node<int> *root = bt.build(&nodes);
    bt.inOrder(root);
    // 4 2 5 1 3 6
    return 0;
}