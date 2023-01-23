#include <iostream>
#include <vector>
using namespace std;

template <class DataType>
class Node
{
public:
    Node<DataType> *left;
    DataType data;
    Node<DataType> *right;
    Node(Node<DataType> *left, DataType data, Node<DataType> *right) : left(left), data(data), right(right) {}
    Node(DataType data) : data(data), left(nullptr), right(nullptr) {}
};

template <class DataType>
class BT
{

    DataType index = -1;

public:
    Node<DataType> *build(vector<DataType> *nodes)
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
            Node<DataType> *node = new Node<DataType>(nodes->at(index));
            node->left = build(nodes);
            node->right = build(nodes);

            // In the end it will return the root node
            return node;
        }
    }

    // Recursive approach
    void insert(Node<DataType> *root, DataType data)
    {
        if (root == nullptr)
        {
            return;
        }
        else
        {
            if (root->left == nullptr && root->data > data)
            {
                root->left = new Node<DataType>(data);
            }
            else if (root->right == nullptr && root->data < data)
            {
                root->right = new Node<DataType>(data);
            }
            else
            {
                // Key already exist
                cout << "Key already exist" << endl;
                return;
            }

            if (root->left != nullptr && root->data > data)
            {
                insert(root->left, data);
            }
            if (root->right != nullptr && root->data < data)
            {
                insert(root->right, data);
            }
        }
    }

    void inOrder(Node<DataType> *ptr)
    {
        if (ptr == nullptr)
        {
            return;
        }
        inOrder(ptr->left);
        cout << ptr->data << " ";
        inOrder(ptr->right);
    }
};

int main()
{
    vector<int> nodes{5, 3, 1, -1, -1, 4, -1, -1, 6, -1, -1};
    /*
            5
           / \
          3   6
         / \
        1   4
    */
    BT<int> bt;
    Node<int> *root = bt.build(&nodes);
    bt.inOrder(root);
    cout << endl;

    bt.insert(root, 2);
    bt.inOrder(root);
    cout << endl;

    bt.insert(root, 12);
    bt.inOrder(root);
    cout << endl;
    return 0;
}