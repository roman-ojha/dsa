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

    bool isBST(Node<DataType> *root)
    {
        // we will do a inorder traversal
        // NOTE: BST inOrder traversal will be in ascending order
        static struct node *prev = nullptr;

        if (root == nullptr)
            // if root element is null then BST is valid
            return true;

        // left
        if (!isBST(root->left))
            return false;

        // root
        // check for root element
        if (prev != nullptr && root->val <= prev->val)
            return false;

        // after visiting root because we have to compare current val with previous val we have to set root as previous
        prev = root;

        // right
        return isBST(root->right);
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
    // vector<int> nodes{1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
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
    cout << "is" << (bt.isBST(root) ? "" : " Not") << " BST" << endl;
    return 0;
}