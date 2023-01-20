#include <iostream>
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
    Node<Data> *root;
    BT()
    {
        this->root = nullptr;
    }
    BT(Data data)
    {
        Node<Data> *node = new Node<Data>(data);
        this->root = node;
    }

    void insert(Data data)
    {
        if (this->root == nullptr)
        {
            // Create root node
            Node<Data> *node = new Node<Data>(data);
            this->root = node;
        }
        else
        {
            // Insert node level wise
            Node<Data> *node = new Node<Data>(data);

            // Preorder traversal and then insert
            // Node<Data> *ptr = this->root;
            while (true)
            {
                if (ptr->left == nullptr)
                {
                    ptr->left = node;
                    break;
                }
                else if (ptr->right == nullptr)
                {
                    ptr->right = node;
                    break;
                }

                ptr = ptr->left;
                ptr = ptr->right;
            }
        }
    }
};

int main()
{
    return 0;
}