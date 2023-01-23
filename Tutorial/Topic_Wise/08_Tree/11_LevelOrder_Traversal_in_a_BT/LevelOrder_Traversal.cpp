/*
    *) Level Order traversal:
        -> we will use iterative approach
        -> also we will use queue data structure
        ->              1
                       /  \
                      2    3
                     / \    \
                    4   5    6
                -> Queue: 1
                -> Travel:

                -> Queue: 2, 3
                -> Travel: 1

                -> Queue: 3, 4, 5
                -> Travel: 1, 2

                -> Queue: 4, 5, 6
                -> Travel: 1, 2, 3

                -> Queue: 5, 6
                -> Travel: 1, 2, 3, 4

                -> Queue: 6
                -> Travel: 1, 2, 3, 4, 5

                -> Queue:
                -> Travel: 1, 2, 3, 4, 5, 6

        -> We use BFS for the traversal
*/
#include <iostream>
#include <queue>
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
    Data index = -1;

public:
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

    void levelOrder(Node<Data> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        queue<Node<int> *> q;
        q.push(root);
        Node<Data> *elm;

        // we will check until queue is empty so that we can traversal to all the node of tree
        while (!q.empty())
        {
            // Pop current element from queue
            elm = q.front();
            cout << q.front()->data << " ";
            q.pop();

            // push adjacent node of current node into queue
            if (elm->left != nullptr)
            {
                q.push(elm->left);
            }
            if (elm->right != nullptr)
            {
                q.push(elm->right);
            }
        }
    }
};

int main()
{
    vector<int> nodes{1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BT<int> bt;
    Node<int> *root = bt.build(&nodes);
    bt.levelOrder(root);
    // 1, 2, 3, 4, 5, 6
    return 0;
}