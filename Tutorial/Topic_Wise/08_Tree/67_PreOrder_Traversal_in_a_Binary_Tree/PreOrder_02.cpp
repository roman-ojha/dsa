#include <iostream>
#include <vector>
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

    void preOrder(Node<Data> *ptr)
    {
        if (ptr == nullptr)
        {
            return;
        }
        cout << ptr->data << " ";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
};

int main()
{
    // -1 == nullptr
    vector<int> nodes{1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BT<int> bt;
    Node<int> *root = bt.build(&nodes);
    bt.preOrder(root);
    // 1 2 4 5 3 6
    return 0;
}